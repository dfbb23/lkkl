/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:52 by abmoudni          #+#    #+#             */
/*   Updated: 2024/11/17 22:14:07 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
// #include <fcntl.h>
// int main()
// {
//     char *message = "Hello, world!\n";
//     int fd = open("tt.txt", O_WRONLY | O_TRUNC, 0644);
//     ft_putstr_fd(message, 3);
//     close(fd);
//     return 0;
// }
