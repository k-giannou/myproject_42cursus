/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:57:47 by kgiannou          #+#    #+#             */
/*   Updated: 2024/12/24 17:28:51 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

static int	g_server_status = 0;

void	sig_handler(int signum, siginfo_t *info, void *extra_info)
{
	static int	i;

	(void)extra_info;
	(void)info;
	g_server_status = 1;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
	{
		ft_printf("Done! Bytes received: %d\n", i / 8);
		i = 0;
		exit (1);
	}
}

int	char_to_bit(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		while (g_server_status == 0)
			usleep(200);
		g_server_status = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	int					i;

	if (argc != 3 || !argv[2][0])
	{
		write(2, "Please try again: /.client <server_pid> <message>\n", 51);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error sigaction in client\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error sigaction in client\n");
	i = 0;
	while (argv[2][i] != '\0')
	{
		char_to_bit(argv[2][i], pid);
		i++;
	}
	char_to_bit('\0', pid);
	exit (1);
}
