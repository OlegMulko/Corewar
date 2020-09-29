/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_arg_sep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:16:04 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/29 19:36:06 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int			asm_lex_check_arg_sep(t_asm_string *asm_str)
{
	if (asm_str->str[asm_str->index] == SEPARATOR_CHAR)
		return (1);
	return (0);
}

t_asm_token	*asm_lex_token_arg_sep(t_asm_string *asm_str)
{
	t_asm_token	*token;

	token = asm_new_token(TT_ARG_SEP);
	return (token);
}
