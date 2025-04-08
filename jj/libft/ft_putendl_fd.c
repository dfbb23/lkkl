/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:21:15 by abmoudni          #+#    #+#             */
/*   Updated: 2024/11/17 21:56:41 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
// #include <fcntl.h>
// int main(){
// char *str="abde";
// int d = open("txt.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);
// ft_putendl_fd(str,d);
// }
