/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 13:41:46 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 12:45:19 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str;
	char		*to_find;

	i = 0;
	j = 0;
	str = (char *)big;
	to_find = (char *)little;
	if (to_find[0] == '\0')
		return (0);
	while (str[i] != '\0' && i < len)
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0' && i + j < len)
			j++;
		if (to_find[j] == '\0')
			return (1);
		i++;
		j = 0;
	}
	return (0);
}
