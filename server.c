/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 04:20:01 by muoz              #+#    #+#             */
/*   Updated: 2023/09/25 20:40:18 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(pid_t num)
{
	if (num >= 10)
		ft_putnbr(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}

void	ft_handle_signal(int signum)
{
	static char		character = 0;
	static int		bit_count = 0;

	if (signum == SIGUSR1)
	{
		character |= (1 << (7 - bit_count));
	}
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "Proces id: ", 11);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_handle_signal);
	signal(SIGUSR2, ft_handle_signal);
	while (1)
	{
		pause();
	}
	exit (1);
}
