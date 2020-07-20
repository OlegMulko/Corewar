/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_strs_realoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 09:55:05 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/20 09:58:26 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void		asm_str_realoc(t_asm_string *asm_str)
{
	char	*newstr;

	if (!(newstr = (char*)malloc(sizeof(char) * (asm_str->m_size * 2 + 1))))
		asm_sys_error();
	ft_memcpy(newstr, asm_str->str, asm_str->size + 1);
	free(asm_str->str);
	asm_str->str = newstr;
	asm_str->m_size *= 2;
}
