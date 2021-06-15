/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:08:32 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/15 13:34:55 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node t_node;

typedef struct s_node
{
	int		value;
	t_node *prev;
	t_node *next;
}				t_node;

typedef struct s_stack
{
	int		size;
	t_node *head;
	t_node *tail;
}				t_stack;

int		ft_atoi(const char *str);

void	ft_error(char *s);
void	addNode(t_stack *A, int value);
void    push_head(t_stack *stack, int val);
void    pop_head(t_stack *stack);
void    push_tail(t_stack *stack, int val);
void	pop_tail(t_stack *stack);

void    sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);


#endif