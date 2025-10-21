/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfaux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarahfer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:20:54 by sarahfer          #+#    #+#             */
/*   Updated: 2025/10/13 17:20:56 by sarahfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int letter)
{
	return (write(1, &letter, 1));
}

int	ft_print_s(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (ft_print_s("(null)"));
	while (*str != '\0')
	{
		write(1, str, 1);
			str++;
			count++;
	}	
	return (count);
}

int	ft_print_nbr(int n)
{
	char	nb;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		count++;
	}
	if (n >= 10)
		count += ft_print_nbr(n / 10);
	nb = (n % 10) + '0';
	count += write(1, &nb, 1);
	return (count);
}

int	ft_print_unbr(unsigned int n)
{
	char	nb;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_print_unbr(n / 10);
	nb = (n % 10) + '0';
	count += write(1, &nb, 1);
	return (count);
}
