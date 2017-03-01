#include "lem_in.h"

int		input_error(char **in, char ***param)
{
	ft_putstr_fd("ERROR\n", 2);
	if (in && *in)
		free(*in);
	if (param && *param)
		while (*(*param))
		{
			free(*(*param));
			(*param)++;
		}
	exit(1);
	return (0);
}

t_rlist	*find_room(t_rlist **lst, char *name)
{
	t_rlist	*r;
	
	if (*room == NULL)
		return (NULL);
	r = *room;
	while (r && !ft_strcmp(name, r->name))
		r = r->next;
	return (r);
}

void	new_room(t_rlist **lst, char *rp, t_byte *st)
{
	t_rlist *tm;
	t_rlist	*n;
	
	tm = *lst;
	if (!tm)
	{
		*lst = (t_rlist*)malloc(sizeof(t_rlist));
		(*lst)->room.name = ft_strdup(rp[0]);
		(*lst)->room.x = ft_atoi(rp[1]);
		(*lst)->room.y = ft_atoi(rp[2]);
		(*lst)->room.stat = st;
		(*lst)->adia_rooms = NULL;
		(*lst)->next = NULL;
		return ;
	}
	while (tm)
		tm = tm->next;
	n = (t_rlist*)malloc(sizeof(t_rlist));
	n->room.name = ft_strdup(rp[0]);
	n->room.x = ft_atoi(rp[1]);
	n->room.y = ft_atoi(rp[2]);
	n->room.stat = st;
	n->adia_rooms = NULL;
	tm->next = n;
	n->next = NULL;
}

void	new_link(t_rlist **lst, char **rp)
{
	t_rlist	*rm1;
	t_rlist	*rm2;
	t_room	*room;
	t_room	*tmp;
	
	if (!(rm1 = find_room(lst, rp[0])))
		error(NULL, &rp);
	if (!(rm2 = find_room(lst, rp[1])))
		error(NULL, &rp);
	if (!(rm1->adia_list))
	{
		rm1->adia_list = (t_adlist*)malloc(sizeof(t_adlist));
		rm1->adia_list = rm2;
	}
	if (!(rm2->adia_list))
	{
		rm2->adia_list = (t_adlist*)malloc(sizeof(t_adlist));
		rm2->adia_list = rm1;
	}
	
	
}

void	add_links(char *in, t_rlist **lst)
{
	size_t	i;
	char	**rp;
	
	if (!(rp = ft_strsplit(in, '-')))
		input_error(&in, &rp);
	i = 0;
	while (rp[i++]);
	(i != 3) ? input_error(&in, &rp) : 0;
	i = 0;
	while (rp[0][i] || rp[1][i])
	{
		if (rp[0][i] && !(ft_strchr(DEC, rp[0][i])))
			input_error(&in, &rp);
		else if (rp[1][i] && !(ft_strchr(DEC, rp[1][i])))
			input_error(&in, &rp);
		i++;
	}
	new_list(lst, rp);
	while (*rp)
	{
		free(*rp);
		rp+;
	}
}

void	add_rooms(char *in, t_byte st, t_rlist **lst)
{
	char	**rp;
	size_t	i;
	
	if (!(rp = ft_strsplit(in, ' ')))
		input_error(&in, &rp);
	i = 0;
	while (rp[i++]);
	(i != 4) ? input_error(&in, &rp) : 0;
	i = 0;
	while (rp[1][i] || rp[2][i])
	{
		if (rp[1][i] && !(ft_strchr(DEC, rp[1][i])))
			input_error(&in, &rp);
		else if (rp[2][i] && !(ft_strchr(DEC, rp[2][i])))
			input_error(&in, &rp);
		i++;
	}
	new_room(lst, rp, st);
	while (*rp)
	{
		free(*rp);
		rp++;
	}
}

int		main(int ac, char **av)
{
	char		*input;
	t_var		v;
	t_rlist		*lst;

	v.sz = 0;
	v.room = 0;
	v.link = 0;
	v.stat = ROOM;
	lst = NULL;
	while (get_next_line(0, &input) > 0)
	{
		ft_printf("%s\n",input);
		if (*input == '#')
		{
			if (*(input + 1) == '#' && ft_strcmp(input, "##START") == 0)
				v.stat = START;
			if (*(input + 1) == '#' && ft_strcmp(input, "##END") == 0)
				v.stat = END;
		}
		else if (!WSPACE(*input))
		{
			if (*(input + 1) != '-')
			{
				(v.room == 0 && v.link == 1) ? input_error(&input, NULL) : 0;
				add_rooms(input, v.stat, lst);
				(v.stat != ROOM) ? v.stat = ROOM : 0;
				v.room = 1;
			}
			else if (*(input + 1) == '-')
			{
				(v.room == 0 && v.link == 0) ? input_error(&input, NULL) : 0;
				if (v.room == 1 && v.link == 0)
				{
					v.link = 1;
					v.room = 0;
				}
				add_links(input, lst);
			}
			else
				input_error(&input, NULL);
		}
		else
			input_error(&input, NULL);
		free(input);
	}
	
	(void)ac;
	(void)av;
	return (1);
}