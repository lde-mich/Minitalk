/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:45:41 by lde-mich          #+#    #+#             */
/*   Updated: 2023/03/28 15:12:48 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	count;
	int	logic;

	count = 0;
	logic = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' )
	{
		logic = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = count * 10;
		count = count + (str[i] - 48);
		i++;
	}
	return (count * logic);
}

void	send_signal(pid_t pid, unsigned char *str)
{
	int		asc;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		asc = str[i];
		j = 0;
		while (j < 8)
		{
			if (asc % 2 == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			asc = asc / 2;
			j++;
			usleep(350);
		}
		i++;
	}
}

void	check(int signal)
{
	if (signal == SIGUSR2)
		write(1, "Character received\n", 19);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		exit(write(2, "Error\nInvaliD input\n", 20));
	if (!ft_atoi(argv[1]))
		exit(write(2, "Error\nInvaliD input\n", 20));
	signal(SIGUSR1, check);
	signal(SIGUSR2, check);
	send_signal(ft_atoi(argv[1]), (unsigned char *)argv[2]);
}
