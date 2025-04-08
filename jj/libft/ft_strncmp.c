/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:14:44 by abmoudni          #+#    #+#             */
/*   Updated: 2025/04/05 00:05:12 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	n = n - 1;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	dest[15] = "aaaezppp";
// 	char	src[10] = "aadeee";

// 	printf("%d\n", ft_strncmp(dest, src, 4));
// 	printf("%d\n", strncmp(dest, src, 4));
// }
