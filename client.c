/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:59:08 by vpeinado          #+#    #+#             */
/*   Updated: 2023/12/11 17:32:57 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sender(int pid, char ch)
{
	int	bit_shift;

	bit_shift = 0;
	while (bit_shift < 8)
	{
		if ((ch & (1 << bit_shift)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit_shift++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("\033[0;31mUse ./client <pid> <string>\033[0m", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_sender(pid, argv[2][i]);
		i++;
	}
	return (0);
}
