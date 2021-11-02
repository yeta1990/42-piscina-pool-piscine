/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:55:47 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/11 14:15:25 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void *ft_print_memory(void *addr, unsigned int size);

int main(void)
{
    char *str = "Hola";
    void *addr;
	unsigned int p; 

	
    addr = str;
	printf("pepe\n");
    printf("%p\n", addr);
    printf("%p\n", &addr);

   	printf("%p\n", &str);
   	printf("%p\n", &str[0]);
   	printf("%p\n", &str[1]);
  	printf("%p\n", &str[2]);
  	printf("%p\n\n", &str[3]);
 	
//	printf("%x\n", str);
   	printf("%s\n", &str[0]);
   	printf("%s\n", &str[1]);
  	printf("%s\n", &str[2]);
  	printf("%s\n\n", &str[3]);
	p = (unsigned int) addr;
	printf("%u\n", p);
	printf("%x\n", p);
	write(1, p, 16);
	write(1, p, sizeof(p));	
}   

