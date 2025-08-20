/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:16:00 by jomaia            #+#    #+#             */
/*   Updated: 2025/08/20 16:45:45 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_reset(t_var *v)
{
	ft_printf("%s\n", v->str);
	free(v->str);
	v->str = NULL;
	v->bits_len = 31;
	v->len = 0;
}

static int	msg(t_var *v)
{
	if (!v->str)
	{
		v->str = malloc(v->len + 1);
		if (!v->str)
			exit (1);
		v->pos = 0;
	}
	if (v->pos < v->len)
		v->str[v->pos++] = v->c;
	v->c = 0;
	v->i = 7;
	if (v->pos == v->len)
	{
		v->str[v->pos] = '\0';
		print_reset(v);
		v->pos = 0;
		return (1);
	}
	return (0);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static t_var	v = {.c = 0, .bits_len = 31, .len = 0, .i = 7};

	(void)context;
	if (v.bits_len >= 0)
		v.len |= ((sig == SIGUSR2) << v.bits_len--);
	else
	{
		if (sig == SIGUSR2)
			v.c |= (1 << v.i);
		if (v.i-- == 0)
		{
			if (msg(&v))
			{
				kill(info->si_pid, SIGUSR2);
				return ;
			}
		}
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	signal;

	signal.sa_sigaction = handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
}
