/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:02:02 by sycourbi          #+#    #+#             */
/*   Updated: 2023/04/11 12:02:33 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

char	**ft_search_path_envp(char **envp)
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
	int		i;
	char	*tmp;
	char	*res;
	char	**path;

	i = 0;
	if (cmd[0] == '/' && access(cmd, F_OK) != -1)
		return (cmd);
	path = ft_search_path_envp(envp);
	if (!path)
		return (NULL);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		res = ft_strjoin(tmp, cmd);
		if (tmp != NULL)
			free(tmp);
		if (res && access(res, F_OK) != -1)
			return (ft_free(path), res);
		if (res != NULL)
			free(res);
		i++;
	}
	ft_free(path);
	return (NULL);
}
