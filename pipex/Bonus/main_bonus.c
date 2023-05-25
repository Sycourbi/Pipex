/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:57:08 by sycourbi          #+#    #+#             */
/*   Updated: 2023/04/11 12:00:31 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

void	ft_child(t_pipex pipex, char *av, char **envp, int cc)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == 0)
	{
		if (cc)
		{
			if (dup2(cc, 1) == -1 || close(cc) == -1
				|| close(fd[0]) == -1 || close(fd[1]) == -1)
				exit(1);
		}
		else if (close(fd[0]) == -1 || dup2(fd[1], 1) == -1
			|| close(fd[1]) == -1)
			exit(1);
		return (ft_close_file(&pipex), ft_exec(av, pipex, envp));
	}
	else
	{
		if (close(fd[1]) == -1 || dup2(fd[0], 0) == -1
			|| close(fd[0]) == -1)
			exit(1);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	ft_init(&pipex);
	if (ac < ft_search_here_doc(av[1], &pipex))
		return (ft_putstr_fd("mauvais nombre d'argument\n", 2), 1);
	ft_first_file(av, &pipex);
	if (pipex.heredoc == 1)
		ft_here_doc(av);
	ft_second_file(av, ac, &pipex);
	while (pipex.i < ac - 2)
	{
		ft_child(pipex, av[pipex.i++], envp, 0);
	}
	ft_child(pipex, av[pipex.i++], envp, pipex.outfile);
	ft_close_file(&pipex);
	while (pipex.i > 0)
	{
		if (wait(NULL) != 0)
			pipex.i = pipex.i;
		pipex.i--;
	}
	return (0);
}
