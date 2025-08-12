/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:32:14 by joaomaia          #+#    #+#             */
/*   Updated: 2025/08/12 18:19:49 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	num;

	i = 0;
	num = n;
	if (num < 0)
	{
		i += ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
	{
		i += ft_putnbr_fd(num / 10, fd);
		i += ft_putnbr_fd(num % 10, fd);
	}
	else
		i += ft_putchar_fd(num + '0', fd);
	return (i);
}
