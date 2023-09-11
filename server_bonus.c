/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:45:31 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/28 12:29:33 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb += 48;
		write(1, &nb, 1);
	}
}

int	ft_pow(int nb, int power)
{
	int	pow;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	pow = 1;
	if (power > 0)
		nb *= ft_pow(nb, power - 1);
	return (nb);
}

void	decode(int signal, siginfo_t *info, void *pu)
{
	static int	nb;
	static int	i;

	(void )pu;
	if (signal == SIGUSR2)
		nb += (ft_pow(2, i) * 1);
	i++;
	if (i == 8)
	{
		kill(info->si_pid, SIGUSR2);
		write(1, &nb, 1);
		i = 0;
		nb = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	at;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	at.sa_sigaction = decode;
	at.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &at, NULL);
	sigaction(SIGUSR2, &at, NULL);
	while (42)
		pause();
}
