/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:08:18 by misaev            #+#    #+#             */
/*   Updated: 2021/07/05 15:32:04 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum)
{
	static int	i = 0;
	static char	c = 0;
	static char	d = 0;

	if (signum == SIGUSR1)
	{									
		d = (1 << i);
		c = c | d;
	}
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	text;
	pid_t				pid;

	pid = getpid();
	sigemptyset(&text.sa_mask);
	sigaddset(&text.sa_mask, pid);
	text.sa_flags = 0;
	text.sa_handler = sig_handler;
	sigaction(SIGUSR1, &text, NULL);
	sigaction(SIGUSR2, &text, NULL);
	ft_putnbr_fd(pid, 1 );
	write(1, " ", 1);
	while (1)
		pause();
	return (0);
}
