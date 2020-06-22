#include "disasm.h"

void	free_buf(t_buf *buf)
{
	free(buf->bytes);
	free(buf);
}

void	free_champ(t_champ *champ)
{
	free(champ->name);
	free(champ->comment);
	if (champ->exec_code)
		free(champ->exec_code);
	free(champ);
}

void	free_op_list(t_op_list *lst)
{
	t_op_list *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}