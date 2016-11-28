/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:29:51 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/28 10:29:53 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

extern char **environ;

// void		set_term(struct termios *term)
// {
// 	term->c_lflag &= ~(ICANON);
// 	term->c_lflag &= ~(ECHO);
// 	term->c_cc[VMIN] = 1;
// 	term->c_cc[VTIME] = 0;
// 	if (tcsetattr(0, TCSADRAIN, term) == -1)
// 		THROW(ERROR_SELECT);
// }

// void		aff_term(struct termios *term)
// {
// 	PUTSTR("term");
// 	ft_printf("c_iflag = %i\n", term->c_iflag);
// 	ft_printf("c_oflag = %i\n", term->c_oflag);
// 	ft_printf("c_cflag = %i\n", term->c_cflag);
// 	ft_printf("c_lflag = %i\n", term->c_lflag);
// 	ft_printf("c_ispeed = %i\n", term->c_ispeed);
// 	ft_printf("c_ospeed = %i\n", term->c_ospeed);
// }

// void		reset_term(struct termios *term)
// {
// 	PUTNBR(TCSANOW);
// 	PUTNBR(TCSADRAIN);
// 	PUTNBR(TCSAFLUSH);
// 	PUTNBR(TCSASOFT);
// 	if (tcsetattr(0, 0, term) == -1)
// 		PERROR("fucked!");
// 	else
// 		ft_printf("{g:1:%s}\n", "Success!");
// }

int		tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int		main(void)
{
	char 			*termtype;
	char			termbuffer[0x1000];
	int				error;

	termtype = getenv("TERM");
	if (!termtype)
		return (-1);
	error = tgetent(termbuffer, termtype);
	if (error < 0)
		return (1);
	if (error == 0)
		return (1);
	PUTSTR("Success");
	char *res;
	if (!(res = tgetstr("ve", NULL)))
		return (-1);
	tputs(res, 1, tputs_putchar);
	PUTSTR(res);
	return (0);
}