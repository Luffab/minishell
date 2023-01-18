/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:24:46 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 18:14:34 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*cour;
	t_list	*deb;

	cour = malloc(sizeof(t_list));
	deb = cour;
	while (lst)
	{
		if (lst->content)
			cour->content = f(lst->content);
		if (lst->next)
		{
			cour->next = malloc(sizeof(t_list));
			cour = cour->next;
		}
		else
			cour->next = NULL;
		lst = lst->next;
	}
	return (deb);
}
