#ifndef __DISASM_H__
#define __DISASM_H__

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>

#include "op.h"
#include "libft.h"

#define USAGE "usage: disasm [file.cor]"
#define BUF_SIZE 4096
#define NULL_RANGE_BYTES 4
#define EXEC_CODE_SIZE_BYTES 4
#define MAGIC_HEADER_SIZE_BYTES 4

typedef enum
{
	false,
	true
}	t_bool;


typedef struct		s_buf
{
	u_int8_t 		*bytes;
	size_t			size;
}					t_buf;

typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_num;
	t_bool		args_types_code;
	uint8_t		args_types[3];
	uint8_t		t_dir_size;
}				t_op;

typedef struct		s_champ
{
	unsigned		id;
	unsigned char 	*name;
	unsigned char	*comment;
	size_t			exec_code_size;
	t_op			*exec_code;
}					t_champ;

t_champ	*validate_and_parse(char *fname);

/*
 * err
 */
void	fatal_error(char *mes);
void	file_error(const char *fname, const char *mes);

/*
 * util
 */
void	*xmalloc(size_t size);

/*
 * free_func
 */
void	free_buf(t_buf *buf);
void	free_champ(t_champ *champ);

/*
 * convert_bytes
 */
uint32_t to_uint32(uint8_t *mas);

/*
 * parse_champ
 */
t_champ 	*parse_champ(t_buf *buf);

#endif