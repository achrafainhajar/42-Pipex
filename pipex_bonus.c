/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:58:22 by aainhaja          #+#    #+#             */
/*   Updated: 2022/05/11 19:58:22 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i != n)
		return (str1[i] - str2[i]);
	return (0);
}

int	execute(char	**path, char		**cmdargs, char	**envp)
{
	int		i;
	char	*cmd;

	i = 0;
	while (path[i])
	{
		cmd = ft_strjoine(path[i], cmdargs[0]);
		if (access(cmd, F_OK) == 0)
		{
			execve(cmd, cmdargs, envp);
		}
		free (cmd);
		i++;
	}
	wrong_cmd(cmdargs[0]);
	return (0);
}

void	pipex(char **av, char **envp, int c)
{
	char	**cmdargs;
	char	**path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp (envp[i], "PATH=", 5) == 0)
		{
			break ;
		}
		i++;
	}
	envp[i] = envp[i] + 5;
	path = ft_split(envp[i], ':');
	cmdargs = ft_split(av[c], ' ');
	execute(path, cmdargs, envp);
}

void	redir(char **env, char **av, int i, int f)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) < 0)
		exit(2);
	pid = fork();
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT);
		if (f == STDIN)
			exit(2);
		pipex(av, env, i);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	f1;
	int	f2;
	int	i;

	i = 2;
	if (ac >= 5)
	{
		f2 = openfile(av[ac - 1], 1);
		dup2(f2, STDOUT);
		if (ac == 6 && ft_strncmp(av[1], "here_doc", 7) == 0)
		{
			heredoc(envp, av, 3);
			pipex(av, envp, 4);
		}
		else if (ac >= 5)
		{
			f1 = openfile(av[1], 0);
			dup2(f1, STDIN);
			while (i < ac - 2)
				redir(envp, av, i++, f1);
			pipex(av, envp, i);
		}
	}
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
}
