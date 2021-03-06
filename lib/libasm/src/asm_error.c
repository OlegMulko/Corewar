/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 16:18:44 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/11 16:01:45 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	asm_prog_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

void	asm_sys_error(void)
{
	t_string	*s_str;
	char		*error;

	error = strerror(errno);
	s_str = ft_strmulsub("Error: ?", 100, error);
	ft_putendl_fd(s_str->str, STDERR_FILENO);
	exit(1);
}

void	asm_lex_error(t_asm_string *asm_str, char *msg)
{
	t_string	*s_str;
	char		*line_num;
	char		*char_num;

	if (!(line_num = asm_ltoa((long long)asm_str->line_num)))
		asm_sys_error();
	if (!(char_num = asm_ltoa((long long)asm_str->char_num)))
		asm_sys_error();
	if (!(s_str = ft_strmulsub(ERR_TMP, STR_MALOC_SIZE,
		line_num, char_num, msg)))
		asm_sys_error();
	asm_prog_error(s_str->str);
}

void	asm_pars_error(t_asm_pars_prms *prms)
{
	t_string	*s_str;
	char		*line_num;
	char		*char_num;

	if (!(line_num = asm_ltoa((long long)prms->line_num)))
		asm_sys_error();
	if (!(char_num = asm_ltoa((long long)prms->char_num)))
		asm_sys_error();
	if (!(s_str = ft_strmulsub(ERR_TMP, STR_MALOC_SIZE,
		line_num, char_num, prms->error)))
		asm_sys_error();
	asm_prog_error(s_str->str);
}
