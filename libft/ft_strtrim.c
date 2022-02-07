/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 11:38:23 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 16:42:08 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		is_in_set(char c, char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	char	*deb_fin(void)
{
	char	*str;

	if (!(str = (char *)malloc(1 * sizeof(char))))
		return (NULL);
	*str = '\0';
	return (str);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		deb;
	size_t		fin;
	int			ind;
	char		*str;

	if (!s1)
		return (NULL);
	deb = 0;
	fin = ft_strlen(s1) - 1;
	ind = 0;
	while (is_in_set(s1[deb], set))
		deb++;
	if (deb == fin + 1)
		return (str = deb_fin());
	while (is_in_set(s1[fin], set))
		fin--;
	if (!(str = (char *)malloc((fin - deb + 2) * sizeof(char))))
		return (NULL);
	while (deb <= fin)
	{
		str[ind++] = s1[deb];
		deb++;
	}
	str[ind] = '\0';
	return (str);
}
