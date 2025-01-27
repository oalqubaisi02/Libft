/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalqubai <oalqubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:08:38 by oalqubai          #+#    #+#             */
/*   Updated: 2024/07/03 18:57:36 by oalqubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_data(char letter, int pid)
{
	int	byte;
	int	signal;

	byte = 128;
	signal = 0;
	while (byte > 0)
	{
		if ((letter & byte) == byte)
			signal = kill(pid, SIGUSR1);
		else
			signal = kill(pid, SIGUSR2);
		byte = byte / 2;
		usleep(100);
	}
	ft_check_error("", signal);
}

int	main(int argc, char **argv)
{
	int	index;
	int	pid;

	index = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][index])
			send_data(argv[2][index++], pid);
		send_data('\0', pid);
	}
	else
		write(1, "Error: Invalid number of arguments!\n", 37);
}
