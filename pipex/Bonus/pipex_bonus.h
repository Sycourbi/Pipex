/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:32:32 by sycourbi          #+#    #+#             */
/*   Updated: 2023/04/11 12:33:36 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"

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
	int		infile;
	int		outfile;
	int		heredoc;
	int		i;
	char	**cmd;
	char	*acce_cmd;

}t_pipex;

void	ft_child(t_pipex pipex, char *av, char **envp, int cc);

/*utils_bonus.c*/
void	ft_init(t_pipex *pipex);
void	ft_bad_cmd(t_pipex pipex);
void	ft_bad_execve(t_pipex pipex);
void	ft_exec(char *av1, t_pipex pipex, char **envp);

/*path_bonus.c*/
char	*ft_path(char *cmd, char **envp);
char	**ft_search_path_envp(char **envp);

/*free_bonus.c*/
void	ft_free(char **tab);

/*file_bonus.c*/
void	ft_first_file(char **av, t_pipex *pipex);
void	ft_second_file(char **av, int ac, t_pipex *pipex);
void	ft_close_file(t_pipex *pipex);

/*heredoc.c*/
int		ft_search_here_doc(char *av1, t_pipex *pipex);
void	ft_here_doc(char **argv);

#endif