/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:06:41 by sycourbi          #+#    #+#             */
/*   Updated: 2023/04/11 12:07:23 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

void	ft_first_file(char **av, t_pipex *pipex)
{
	if (pipex->heredoc == 1)
		return ;
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		ft_putstr_fd("zsh: no such file or directoyry: ", 2);
		ft_putstr_fd(av[1], 2);
		write(2, "\n", 1);
		pipex->infile = open("/tmp/pipex", O_RDONLY | O_CREAT, 0644);
	}
	dup2(pipex->infile, 0);
}

void	ft_second_file(char **av, int ac, t_pipex *pipex)
{
	if (pipex->heredoc == 1)
	{
		pipex->outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (pipex->outfile < 0)
			ft_putstr_fd("open outfile dans second_file\n", 2);
	}
	else
	{
		pipex->outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (pipex->outfile < 0)
			ft_putstr_fd("open outfile dans second_file\n", 2);
	}
}

void	ft_close_file(t_pipex *pipex)
{
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
}
