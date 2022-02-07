/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 12:10:28 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 11:11:07 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t result;

	j = 0;
	result = 0;
	result = ft_strlen(src);
	i = ft_strlen(dest);
	if (size <= i)
		return (result + size);
	else
	{
		result += i;
		while (src[j] && i + 1 < size)
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
	}
	return (result);
}
