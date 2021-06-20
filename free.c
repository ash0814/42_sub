/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:26:47 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/20 19:04:09 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_node **node)
{
	t_node **now;
	t_node *tmp;

	now = node;
	while (*now)
	{
		tmp = *now;
		*now = (*now)->next;
		free(tmp);
		tmp = 0;
	}
}

void	free_stack(t_stack *a)
{
	free_node(&a->head);
	free(a);
	a = 0;
}