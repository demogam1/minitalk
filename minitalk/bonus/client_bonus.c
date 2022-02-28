/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:08:20 by misaev            #+#    #+#             */
/*   Updated: 2021/06/30 10:39:35 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	check_error(int ac, char *str)
{
	int	i;

	if (ac != 3)
	{
		ft_putstr_fd("Minitalk needs 2 arguments(PID, String).\n", 1);
		return (0);
	}
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			write(1, "PID must be a number.\n", 22);
			return (0);
		}	
		i++;
	}
	return (1);
}

void	handler(int signum)
{
	if (signum)
		ft_putstr_fd("Signal received !\n", 1);
}

void	send_char(char c, pid_t pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if ((c >> j) & 1)
		{
			usleep(100);
			kill(pid, SIGUSR1);
		}	
		else
		{
			usleep(100);
			kill(pid, SIGUSR2);
		}
		usleep(50);
		j++;
	}
}

int	main(int ac, char **argv)
{
	pid_t	pid;
	int		i;

	if (check_error(ac, argv[1]) == 0)
		return (0);
	i = 0;
	signal(SIGUSR1, handler);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_char(argv[2][i], pid);
		i++;
	}
	send_char('\0', pid);
	return (0);
}
