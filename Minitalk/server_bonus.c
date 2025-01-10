/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:55:00 by kgiannou          #+#    #+#             */
/*   Updated: 2024/12/25 13:14:35 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

void	bit_to_char(int signum, unsigned char *bit)
{
	if (signum == SIGUSR1)
		*bit = (*bit << 1) | 1;
	else if (signum == SIGUSR2)
		*bit = (*bit << 1);
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	byte;
	static int				i;
	static int				pid;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	bit_to_char(signum, &byte);
	i++;
	if (i == 8)
	{
		i = 0;
		if (!byte)
		{
			kill(pid, SIGUSR1);
			write(1, "\nfrom ", 6);
			ft_putnbr_fd(pid, 1);
			write(1, "\n", 1);
			return ;
		}
		write(1, &byte, 1);
		byte = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server is running. The process ID is %d.", getpid());
	ft_printf("Continue in other terminal with ./client <pid> <message>\n");
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error sigaction in server\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error sigaction in server\n");
	while (1)
		pause();
	return (0);
}
/**********************************************************************
 * INFO****************************************************************
struct	sigaction
{
	void	(*sa_handler)(int);
	sigset_t	sa_mask;
	int	sa_flags;
	void	(sa*_sigaction)(int, siginfo_t *, void *);
};

typedef	struct
{
	unsigned long	sig[__SIGSET_NWORDS];
}	sigset_t;

sa_flags: 	SA_RESTART //restart when sig_handler finish
		SA_SIGINFO //select field sagaction and
			   //not sa_handler, to see  info & context
		SA_NODEFER

sa_mask, which signals we want to block during sig_handler

struct	siginfo_t
{
	int	si_siginfo; //number of the signal
	int	si_errno;
	int	si_code;
	union
	{
		int	si_pid; //pid process who sent the signal
		int	si_uid;
		int	si_status;
		void	*si_addr;
		int	si_value;
	}	si_addr_union;
};*/
