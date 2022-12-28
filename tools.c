/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 02:38:22 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/14 21:11:50 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_splitcpy(const char *s, char c, char **str, int alloc)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			str[cnt][j] = s[i];
			i++;
			j++;
		}
		if (cnt < alloc)
			str[cnt][j] = '\0';
		cnt++;
	}
	if (i != 0 && s[i - 1] == c)
		cnt--;
	str[cnt] = NULL;
	return (str);
}

char	**ft_charcount(const char *s, char c, char **str, int alloc)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			j++;
		}
		if (cnt < alloc)
			str[cnt] = malloc(sizeof(char) * j + 1);
		if (str == NULL)
			return (0);
		j = 0;
		cnt++;
	}
	return (ft_splitcpy(s, c, str, alloc));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		cnt;
	char	**str;

	if (!s)
		return (0);
	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			cnt++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	str = malloc(sizeof(char *) * (cnt + 1));
	if (str == NULL)
		return (0);
	return (ft_charcount(s, c, str, cnt));
}

int	openfile(char *filename, int mode)
{
	if (mode == 0)
	{
		if (access(filename, F_OK))
		{
			write(STDERR, "pipex: ", 7);
			write(STDERR, filename, ft_strlen(filename));
			write(STDERR, ": No such file or directory\n", 28);
			return (STDIN);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644));
}

void	wrong_cmd(char *cmd)
{
	write(STDERR, "pipex: ", 7);
	write(STDERR, cmd, ft_strlen(cmd));
	write(STDERR, ": command not found\n", 20);
	exit(127);
}
