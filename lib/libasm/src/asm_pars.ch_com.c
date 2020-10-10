/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars.ch_com.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:46:20 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/10 21:17:52 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	asm_add_chc_to_bd(t_asm_bin_data *bin_data,
	char *name)
{
	size_t	i;

	i = 0;
	while (name[i])
		bin_data->add(bin_data, (int)name[i++], 2);
	while (i < COMMENT_LENGTH)
	{
		bin_data->add(bin_data, 0, 2);
		i++;
	}
}

int		asm_pars_champ_comment(t_asm_token **token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	char	*comment;
	size_t	size;

	(void)prms;
	(*token) = (*token)->next;
	while (asm_skip_token(token, TT_SEP))
		;
	if ((*token)->type != TT_STRING)
		return (0);
	comment = (char *)(*token)->data;
	if ((size = ft_strlen(comment)) > COMMENT_LENGTH)
		return (0);
	asm_add_chc_to_bd(bin_data, comment);
	(*token) = (*token)->next;
	while (asm_skip_token(token, TT_SEP))
		;
	if (!asm_check_nl(token, prms))
		return (0);
	return (1);
}
