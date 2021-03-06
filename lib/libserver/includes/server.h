/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:22:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/11/06 18:40:27 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdio.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <arpa/inet.h>
# include "libft.h"
# include "ft_printf.h"
# include "op.h"
# define PORT "3490"

typedef struct		s_vis_cell
{
	t_bool			is_carriage;
	uint8_t			code;
	uint8_t			player_id;
}					t_vis_cell;

typedef struct		s_vis_player
{
	int				last_live;
	int				lives_in_cur_period;
	char			name[PROG_NAME_LENGTH];
	uint8_t			id;
}					t_vis_player;

typedef struct		s_vis_arena
{
	t_vis_player	players[MAX_PLAYERS];
	t_vis_cell		arena[MEM_SIZE];
	int				cycle;
	int				cycle_to_die;
	int				cycle_delta;
	int				nbr_live;
	int				max_checks;
	uint8_t			winner_id;
}					t_vis_arena;

/*
**					connect.c
*/
int					get_socket_fd(struct addrinfo *serv_info,
											struct addrinfo **info);
int					connect_server(const char *host_name);
void				disconnect_server(int socket_fd);
/*
**					send_arena.c
*/
void				error_message(const char *msg);
void				send_arena(const t_vis_arena *arena, int socket_fd);
/*
**					serialize.c
*/
unsigned char		*serialize_arena(unsigned char *buffer,
											const t_vis_arena *value);
/*
**					deserialize.c
*/
t_vis_arena			deserialize_arena(unsigned char *buffer);
/*
**					receive_arena.c
*/
t_bool				receive_arena(t_vis_arena *arena, int socket_fd);
/*
**					create_server.c
*/
int					create_server(void);
#endif
