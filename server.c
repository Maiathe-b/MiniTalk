/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:16:00 by jomaia            #+#    #+#             */
/*   Updated: 2025/08/07 16:32:57 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./libft/libft.h"
#include "signal.h"
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

void	handle_signal(int signal)
{
	static char	chr;
	static int	i;

	chr |=  (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (chr == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", chr);
		i = 0;
		chr = 0;
	}
	else
		chr = chr << 1;
}

int	main()
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}