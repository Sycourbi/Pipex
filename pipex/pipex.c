/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:07:17 by sycourbi          #+#    #+#             */
/*   Updated: 2023/01/13 13:40:45 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_free_tabtab(char **split)
{
	int	tab;
	int	i;

	i = 0;
	tab = 0;
	while (split[tab])
		tab++;
	while (i < tab)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_child_one(char **av, t_pipex pipex, char **envp)
{
	if (pipex.infile < 0)
		return ;
	pipex.pid1 = fork ();
	if (pipex.pid1 == 0)
	{
		if (dup2(pipex.pipefd[1], 1) == -1
			|| close(pipex.pipefd[0]) == -1 || dup2(pipex.infile, 0) == -1)
			exit(1);
		pipex.com = ft_split(av[2], ' ');
		pipex.acce_cmd = ft_path(pipex.com[0], envp);
		if (!pipex.acce_cmd)
		{
			ft_bad_cmd(pipex);
			exit(1);
		}
		ft_close(pipex);
		if (execve(pipex.acce_cmd, pipex.com, envp) == -1)
		{	
			ft_bad_execve(pipex);
			exit(1);
		}	
	}
}

void	ft_child_two(char **av, t_pipex pipex, char **envp)
{
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
	{
		if (dup2(pipex.pipefd[0], 0) == -1
			|| close(pipex.pipefd[1]) == -1 || dup2(pipex.outfile, 1) == -1)
			exit(1);
		pipex.com = ft_split(av[3], ' ');
		pipex.acce_cmd = ft_path(pipex.com[0], envp);
		if (!pipex.acce_cmd)
		{
			ft_bad_cmd(pipex);
			exit(1);
		}
		ft_close(pipex);
		if (execve(pipex.acce_cmd, pipex.com, envp) == -1)
		{	
			ft_bad_execve(pipex);
			exit(1);
		}
	}
}

void	ft_init(t_pipex *pipex)
{
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->pid1 = -1;
	pipex->pid2 = -1;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		return (ft_putstr_fd("Invalide number of argument.\n", 1), 1);
	ft_init(&pipex);
	pipex.infile = open(av[1], O_RDONLY);
	pipex.outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.infile < 0)
		ft_bad_infile(av[1]);
	if (pipex.outfile < 0)
		ft_putstr(av[4]);
	if (pipe(pipex.pipefd) < 0)
		ft_putstr("Pipe");
	ft_child_one(av, pipex, envp);
	ft_child_two(av, pipex, envp);
	ft_close(pipex);
	if (ft_waitpid(pipex))
		return (1);
	return (0);
}
