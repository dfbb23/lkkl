/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:30:40 by abmoudni          #+#    #+#             */
/*   Updated: 2024/11/18 00:45:28 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// #include <fcntl.h>
// int main(){
// char str='a';
// int d = open("txtt.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);
// ft_putchar_fd(str,d);
// }
