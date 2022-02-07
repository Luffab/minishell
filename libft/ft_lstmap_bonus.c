/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 15:24:46 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 14:45:18 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*cour;
	t_list	*deb;

	if (!(cour = malloc(sizeof(t_list))))
		return (NULL);
	deb = cour;
	while (lst)
	{
		if (lst->content)
			cour->content = f(lst->content);
		if (lst->next)
		{
			if (!(cour->next = malloc(sizeof(t_list))))
				return (NULL);
			cour = cour->next;
		}
		else
			cour->next = NULL;
		lst = lst->next;
	}
	return (deb);
}
