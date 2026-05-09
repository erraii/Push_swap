/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:13:28 by ecakiray          #+#    #+#             */
/*   Updated: 2026/05/07 14:32:27 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(char *)s++ = '\0';
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	src_len;
	char	*d;
	char	*s;

	src_len = 0;
	d = (char *)dest;
	s = (char *)src;
	if (!d && !s)
		return (0);
	while ((src_len < n))
	{
		*(d + src_len) = *(s + src_len);
		src_len++;
	}
	return (d);
}

int	ft_isdigit(int c)
{
	if (!(('0' <= c) && (c <= '9')))
		return (0);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	str_len;

	str_len = 0;
	while (*(s1 + str_len) && *(s2 + str_len) && ((*(s1 + str_len) - *(s2
					+ str_len)) == 0) && (str_len < (n - 1)))
		str_len++;
	if ((*(s1 + str_len) == *(s2 + str_len)) || (n == 0) || str_len == n)
		return (0);
	else
		return ((unsigned char)*(s1 + str_len) - (unsigned char)*(s2
				+ str_len));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (*(src + src_len))
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (*(src + i) && (i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
