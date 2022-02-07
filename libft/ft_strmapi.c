/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 15:59:28 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 15:34:24 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			ind;
	char			*str;

	i = 0;
	ind = 0;
	if (!s)
		return (NULL);
	if (!(str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (ind < ft_strlen(s))
	{
		str[ind] = f(i, s[ind]);
		ind++;
		i++;
	}
	str[ind] = '\0';
	return (str);
}
