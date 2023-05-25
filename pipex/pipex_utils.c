/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:36:41 by sycourbi          #+#    #+#             */
/*   Updated: 2023/03/31 17:41:59 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_bad_cmd(t_pipex pipex)
{
	errno = 22;
	perror(pipex.com[0]);
	if (pipex.com)
		ft_free_tabtab(pipex.com);
	ft_close(pipex);
}

void	ft_bad_infile(char *av1)
{
	ft_putstr_fd("zsh: no such file or directory: ", 2);
	ft_putstr_fd(av1, 2);
	write(2, "\n", 1);
}

void	ft_bad_execve(t_pipex pipex)
{
	ft_free_tabtab(pipex.com);
	free(pipex.acce_cmd);
}
