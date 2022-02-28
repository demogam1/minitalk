/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:08:18 by misaev            #+#    #+#             */
/*   Updated: 2021/07/05 15:34:59 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	sig_handler(int signum, siginfo_t *t, void *context)
{
	static int	i = 0;
	static char	c = 0;
	static char	d = 0;
	static int	pid = 0;

	(void)context;
	if (signum == SIGUSR1)
	{
		d = (1 << i);
		c = c | d;
	}
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			pid = t->si_pid;
			kill(pid, SIGUSR1);
		}
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	text;
	pid_t				pid;

	pid = getpid();
	sigemptyset(&text.sa_mask);
	sigaddset(&text.sa_mask, pid);
	text.sa_flags = SA_SIGINFO;
	text.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &text, NULL);
	sigaction(SIGUSR2, &text, NULL);
	ft_putnbr_fd(pid, 1 );
	write(1, " ", 1 );
	while (1)
		pause();
	return (0);
}
