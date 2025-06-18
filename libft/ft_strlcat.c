/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:58:10 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/02 23:02:26 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	cpy_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + src_len);
	cpy_len = size - dst_len - 1;
	if (src_len < cpy_len)
		cpy_len = src_len;
	ft_memmove(dst + dst_len, src, cpy_len);
	*(dst + dst_len + cpy_len) = '\0';
	return (dst_len + src_len);
}
