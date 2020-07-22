/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 01:00:23 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/22 15:51:23 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int ac, char **av)
{
	t_asm_string	*asm_str;
	t_asm_token		*tokens;

	check_inprms(ac, av);
	asm_str = asm_file_to_str(av[1]);
	tokens = asm_get_chain_tokens(asm_str);
	if (tokens->next == TT_EOF)
		asm_prog_error("the file is empty");
	ft_putendl_fd(asm_str->str, STDOUT_FILENO);
	return (0);
}
