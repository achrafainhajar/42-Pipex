/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:12:02 by aainhaja          #+#    #+#             */
/*   Updated: 2022/05/11 20:12:02 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoine(char const *s1, char const *s2)
{
	int		i;
	char	*str;
	int		b;

	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	b = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = '/';
	while (s2[b])
	{
		str[i] = s2[b];
		i++;
		b++;
	}
	str[i] = '\0';
	return (str);
}

void	hernor(int fd[2], char **av)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (ft_strncmp(str, av[2], (int)ft_strlen(av[2])) == 0)
			exit(1);
		write(fd[1], str, ft_strlen(str));
		str = get_next_line(0);
	}
}

void	heredoc(char **env, char **av, int i)
{
	int		fd[2];
	int		pid;

	if (pipe(fd) < 0)
		perror("Error in pipe function");
	pid = fork();
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT);
		hernor(fd, av);
		pipex(av, env, i);
	}
}

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
