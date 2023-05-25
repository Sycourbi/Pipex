/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:00:53 by sycourbi          #+#    #+#             */
/*   Updated: 2023/04/11 12:01:33 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

void	here_doc_put_in(char **argv, int *p_fd)
{
	char	*ret;

	close(p_fd[0]);
	while (1)
	{
		ret = get_next_line(0);
		if (ft_strncmp(ret, argv[2], ft_strlen(argv[2])) == 0
			&& ft_strlen(argv[2]) == strlen(ret) - 1)
		{
			get_next_line(-99);
			free(ret);
			if (close(p_fd[1]) == -1)
				exit(1);
			exit(0);
		}
		ft_putstr_fd(ret, p_fd[1]);
		free(ret);
	}
}

void	ft_here_doc(char **argv)
{
	int			p_fd[2];
	pid_t		pid;

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
		here_doc_put_in(argv, p_fd);
	else
	{
		if (close(p_fd[1]) == -1 || dup2(p_fd[0], 0) == -1
			|| close(p_fd[0]) == -1)
			perror("pipex");
		wait(NULL);
	}
}

int	ft_search_here_doc(char *av1, t_pipex *pipex)
{
	if (av1 && ft_strncmp(av1, "here_doc", 8) == 0)
	{
		pipex->heredoc = 1;
		pipex->i = 3;
		return (6);
	}
	pipex->heredoc = 0;
	pipex->i = 2;
	return (5);
}
