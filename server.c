/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:58:59 by vpeinado          #+#    #+#             */
/*   Updated: 2025/09/17 20:33:41 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_mt	g_mt;

void	ft_handler(int signal)
{
	if (signal == SIGUSR1)
		g_mt.i = g_mt.i | (1 << g_mt.bit_shift);
	g_mt.bit_shift++;
	if (g_mt.bit_shift == 8)
	{
		
		g_mt.bit_shift = 0;
		g_mt.i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("pid: \033[0;32m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n\033[0m", 1);
	ft_putstr_fd("\033[33mCTRL + Z to close the program\033[0m\n", 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
