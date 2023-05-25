/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:03:56 by sycourbi          #+#    #+#             */
/*   Updated: 2023/04/11 12:04:41 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

void	ft_free(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
		i++;
	j = 0;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}