/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:07:27 by aainhaja          #+#    #+#             */
/*   Updated: 2022/05/11 20:07:27 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include "42-GNL/get_next_line.h"

# define STDOUT 1
# define STDIN 0
# define STDERR 2
# define SIZE 50

char	**ft_split(char const *s, char c);
char	**ft_charcount(const char *s, char c, char **str, int alloc);
char	**ft_splitcpy(const char *s, char c, char **str, int alloc);
size_t	ft_strlen(const char	*str);
int		execute(char **path, char **cmdargs, char	**envp);
void	pipex(char **av, char **envp, int c);
void	redir(char **env, char **av, int i, int f);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoine(char const *s1, char const *s2);
void	heredoc(char **env, char **av, int i);
int		openfile(char *filename, int mode);
void	wrong_cmd(char *cmd);
#endif