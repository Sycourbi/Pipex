/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:30:37 by sycourbi          #+#    #+#             */
/*   Updated: 2023/03/31 17:41:27 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"

/*fonction open, close*/
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
/*fonction wait, waitpid*/
# include <sys/wait.h>
/*fonction malloc, free*/
# include <stdlib.h>
/*fonction fork, pipe, dup2, execve, access*/
# include <unistd.h>
/*fonction stdin, stdout, (flux d'entrees-sorties standars)*/
/*fonction perror, */
# include <stdio.h>
# include <errno.h>
/* foction strerror */
# include <string.h>

typedef struct s_pipex
{
	int		pipefd[2];
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;
	char	*acce_cmd;
	char	**com;

}t_pipex;

void	ft_bad_infile(char *av1);
char	*ft_path(char *cmd, char **envp);
void	ft_putstr(char *s);
int		ft_waitpid(t_pipex pipex);
void	ft_bad_cmd(t_pipex pipex);
void	ft_bad_execve(t_pipex pipex);
void	ft_close(t_pipex pipex);
void	ft_free_tabtab(char **split);

#endif
