/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmoudni <abmoudni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:19:46 by abmoudni          #+#    #+#             */
/*   Updated: 2024/11/17 21:24:26 by abmoudni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (!s)
	{
		return ;
	}
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
// #include<stdio.h>
// void toup(unsigned int i,char *s){
// 	(void)i;
// 	*s = *s +32;
// }
// int main(){
// char s[]="ABDE";
// ft_striteri(s,toup);
// printf("%s",s);
// }
