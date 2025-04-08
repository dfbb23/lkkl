/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:59:47 by abmoudni          #+#    #+#             */
/*   Updated: 2024/11/17 23:54:13 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb <= 9 && nb >= 0)
	{
		ft_putchar_fd(nb + '0', fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
// #include <fcntl.h>
// int main(){
//     int number = 234;
//     int fd = open("tt.txt", O_WRONLY | O_CREAT, 0644);
//     ft_putnbr_fd(number, fd);
// 	    close(fd);
//     return (0);
// }
