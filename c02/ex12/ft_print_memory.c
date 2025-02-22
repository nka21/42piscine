/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:41:10 by nkojima           #+#    #+#             */
/*   Updated: 2025/02/22 15:48:49 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_print_hex(unsigned char c)
{
	char	*hex_digit;

	hex_digit = "0123456789abcdef";
	write(1, &hex_digit[c / 16], 1);
	write(1, &hex_digit[c % 16], 1);
}

// アドレスを16進数で出力
void	ft_print_addr(void *addr)
{
	unsigned long long	address;
	char				*hex_digit;
	char				hex[16];
	int					i;

	address = (unsigned long long)addr;
	hex_digit = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		hex[i] = hex_digit[address % 16];
		address /= 16;
		i--;
	}
	write(1, hex, 16);
	write(1, ": ", 2);
}

// メモリ内容を16進数で
void	ft_print_hex_memory(unsigned char *ptr, unsigned int size)
{
	unsigned int	cnt_byte;

	cnt_byte = 0;
	while (cnt_byte < 16)
	{
		if (cnt_byte < size)
			ft_print_hex(ptr[cnt_byte]);
		else
			write(1, "  ", 2);
		if (cnt_byte % 2)
			write(1, " ", 1);
		cnt_byte++;
	}
}

// メモリ内容をASCIIで
void	ft_print_ascii_memory(unsigned char *ptr, unsigned int size)
{
	unsigned int	cnt_byte;

	cnt_byte = 0;
	while (cnt_byte < size)
	{
		if (ptr[cnt_byte] >= 32 && ptr[cnt_byte] <= 126)
			write(1, &ptr[cnt_byte], 1);
		else
			write(1, ".", 1);
		cnt_byte++;
	}
	write(1, "\n", 1);
}

// 16バイト毎に、改行しつつ表示
void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	cnt_byte;
	unsigned int	memory_line_length;

	ptr = (unsigned char *)addr;
	cnt_byte = 0;
	while (cnt_byte < size)
	{
		if (size - cnt_byte < 16)
			memory_line_length = size - cnt_byte;
		else
			memory_line_length = 16;
		ft_print_addr(ptr + cnt_byte);
		ft_print_hex_memory(ptr + cnt_byte, memory_line_length);
		ft_print_ascii_memory(ptr + cnt_byte, memory_line_length);
		cnt_byte += 16;
	}
	return (addr);
}

int	main(void)
{
	char	data[] = "Bonjour les amis, c\tci est un test de mém";

	ft_print_memory(data, strlen(data));
	return (0);
}
