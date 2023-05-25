/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:20:09 by sycourbi          #+#    #+#             */
/*   Updated: 2023/01/13 16:28:15 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_close(t_pipex pipex)
{
	if (pipex.pipefd[0] != -1)
		close(pipex.pipefd[0]);
	if (pipex.pipefd[1] != -1)
		close(pipex.pipefd[1]);
	if (pipex.infile >= 0)
		close(pipex.infile);
	if (pipex.outfile >= 0)
		close(pipex.outfile);
}

int	ft_waitpid(t_pipex pipex)
{
	int	ret_child_2;

	ret_child_2 = 0;
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, &ret_child_2, 0);
	return (ret_child_2);
}

void	ft_putstr(char *s)
{
	perror(s);
	exit(1);
}

char	**ft_search_path(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i] != NULL && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	path = ft_split(envp[i] + 5, ':');
	return (path);
}

char	*ft_path(char *cmd, char **envp)
{
	char		**path;
	char		*res;
	char		*tmp;
	int			i;

	i = 0;
	if (cmd[0] == '/' && access(cmd, F_OK) != -1)
		return (cmd);
	path = ft_search_path(envp);
	if (!path)
		return (NULL);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		res = ft_strjoin(tmp, cmd);
		if (tmp != NULL)
			free(tmp);
		if (res && access(res, F_OK) != -1)
			return (ft_free_tabtab(path), res);
		if (res != NULL)
			free(res);
		i++;
	}
	ft_free_tabtab(path);
	return (NULL);
}
