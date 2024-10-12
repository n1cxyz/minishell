/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:04:55 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 14:04:56 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini.h"

void	register_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}

void	handle_sigint(int sig)
{
	(void) sig;
	g_signal_received = 1;
	ft_printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
	ft_printf("minishell: ");
}

void	handle_sigquit(int sig)
{
	(void) sig;
	if (g_signal_received == 1)
	{
		ft_printf("minishell: ");
		ft_printf("%s", rl_line_buffer);
		return ;
	}
	g_signal_received = 1;
	ft_printf("Quit\n");
}
