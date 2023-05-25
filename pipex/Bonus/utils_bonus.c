/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:05:08 by sycourbi          #+#    #+#             */
/*   Updated: 2023/04/11 12:06:32 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

void	ft_init(t_pipex *pipex)
{
	pipex->heredoc = 0;
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->i = 2;
	return ;
}

void	ft_bad_cmd(t_pipex pipex)
{
	errno = 22;
	perror(pipex.cmd[0]);
	if (pipex.infile != -1)
		close(pipex.infile);
	if (pipex.outfile != -1)
		close(pipex.outfile);
	if (pipex.cmd)
		ft_free(pipex.cmd);
}

void	ft_bad_execve(t_pipex pipex)
{
	if (pipex.infile != -1)
		close(pipex.infile);
	if (pipex.outfile != -1)
		close(pipex.outfile);
	if (pipex.cmd)
		ft_free(pipex.cmd);
	if (pipex.acce_cmd)
		free(pipex.acce_cmd);
}

void	ft_exec(char *av1, t_pipex pipex, char **envp)
{
	pipex.cmd = ft_split(av1, ' ');
	pipex.acce_cmd = ft_path(pipex.cmd[0], envp);
	if (!pipex.acce_cmd)
	{
		ft_bad_cmd(pipex);
		exit(1);
	}
	if (execve(pipex.acce_cmd, pipex.cmd, envp) == -1)
	{
		ft_bad_execve(pipex);
		exit(1);
	}
}
