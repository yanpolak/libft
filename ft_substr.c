/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:07:36 by ymarival          #+#    #+#             */
/*   Updated: 2022/11/08 01:03:44 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*memalloc(char *str, size_t len)
{
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	if (len == 0)
		str[0] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	size_t			j;

	j = 0;
	i = -1;
	if (!s)
		return (0);
	str = NULL;
	if (start > (unsigned int)ft_strlen(s))
		return (memalloc(str, 0));
	if (len > ft_strlen(s) - start)
		str = memalloc(str, ft_strlen(s) - start);
	else
		str = memalloc(str, len);
	if (str)
	{
		while (s[++i])
			if (i >= start && j < len)
				str [j++] = s[i];
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
