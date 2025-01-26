/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:37:14 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/26 11:23:26 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]) != NULL)
		j--;
	ptr = (char *)malloc((j - i) + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + i, (j - i) + 1);
	return (ptr);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return (s);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	value;
	unsigned char	*ptr;

	i = 0;
	value = (unsigned char)c;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = value;
		i++;
	}
	return (b);
}
