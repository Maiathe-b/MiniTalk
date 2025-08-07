/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:09:37 by jomaia            #+#    #+#             */
/*   Updated: 2025/08/07 16:24:02 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "signal.h"
#include "unistd.h"
#include "stdio.h"
#include "string.h"

static void	send_signal(int pid, unsigned char chr)
{
	int	i;
	int	test;
	
	i = 8;
	while(i > 0)
	{
		i--;
		test = chr >> i;
		if (test % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*msg;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Missing PID or message", 2);
		exit(0);
	}
	server_pid = ft_atoi(argv[1]);
	msg = argv[2];
	while(msg[i])
		send_signal(server_pid, msg[i++]);
	send_signal(server_pid, '\0');
	return (0);
}