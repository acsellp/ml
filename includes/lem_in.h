#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdlib.h>

# define ROOM 0
# define END 2
# define START 1
# define CORRECT_IN "0123456789-"
# define DEC "0123456789"
# define WSPACE(x) ((x == '\0') || (x == '\t') || (x == ' ') || (x == '\v'))

typedef struct		s_room
{
	int				x;
	int				y;
	char			*name;
	t_byte			stat;	
}					t_room;
typedef struct		s_adlist
{
	t_room			*room;
	struct s_adlist	*next;
}					t_adlist;
typedef struct		s_rlist
{
	t_room			room;
	t_adlist		*adia_list;
	struct s_rlist	*next;
}					t_rlist;


typedef struct		s_var
{
	t_byte			stat;
	t_byte			link;
	t_byte			room;
	size_t			sz;
}					t_var;








#endif
