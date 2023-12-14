/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:49:25 by muoz              #+#    #+#             */
/*   Updated: 2023/09/25 20:45:21 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	ft_atoi(char *str)
{
	size_t	ctr;
	pid_t	pid_num;

	ctr = 0;
	pid_num = 0;
	while ((str[ctr] <= 57) && str[ctr] >= 48)
	{
		pid_num = (pid_num * 10) + (str[ctr] - 48);
		ctr++;
	}
	return (pid_num);
}

void	signal_sender(pid_t pid_holder, char *str)
{
	int		readen_bit;
	int		bit_ret;
	int		index;

	index = 0;
	while (str[index])
	{
		if ((unsigned char)str[index] <= 127)
		{
			readen_bit = 7;
			while (readen_bit >= 0)
			{
				bit_ret = ((str[index] >> readen_bit) & 1);
				if (bit_ret == 1)
					kill(pid_holder, SIGUSR1);
				else
					kill(pid_holder, SIGUSR2);
				usleep(300);
				readen_bit--;
			}
		}
		index++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		signal_sender(ft_atoi(av[1]), av[2]);
	else
	{
		write(1, "you entered wrong number of arguments please re-enter", 53);
		exit (1);
	}
	return (0);
}
