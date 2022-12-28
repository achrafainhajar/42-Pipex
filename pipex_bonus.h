/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:09:42 by aainhaja          #+#    #+#             */
/*   Updated: 2022/05/11 20:09:42 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"

void	heredoc(char **env, char **av, int i);
int		ft_strcmp(char *s1, char *s2);
void	hernor(int fd[2], char **av);
#endif