#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdlib.h>

# define ROOM 0
# define END 2
# define START 1
# define UNDEF 255
# define WSPACE(x) ((x == '\0') || (x == '\t') || (x == ' ') || (x == '\v'))

typedef struct		s_var
{
	t_byte			stat;
	t_byte			link;
	t_byte			room;
	size_t			sz;
}					t_var;

typedef struct		s_room
{
	int				x;
	int				y;
	char			*name;
	t_byte			stat;
	t_byte			ants;
	t_byte			srch; //
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
/*
**	
*/
typedef struct		s_tree
{
	t_room			*head;
	struct s_tree	*branch;
}					t_tree;

/*
**	main.c
*/
t_rlist				*find_room(t_rlist **lst, char *name, t_byte stat);



/*
**	tree.c
*/
t_tree				*gen_paths(t_rlist *list);



#endif
