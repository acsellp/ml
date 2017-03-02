#include "lem_in.h"

void	print(t_rlist *list)
{
	t_rlist *r;
	t_adlist *ad;
	int	n;
	
	n = 0;
	r = list;
	while (r)
	{
		ft_printf("\nName:%s\nx:%d\ny:%d\nstat:%d\nants:%d\n",r->room.name,r->room.x,r->room.y,r->room.stat,r->room.ants);
		ft_printf("Adiacent list: ");
		ad = r->adia_list;
		while (ad && ++n)
		{
			ft_printf("%s ->",ad->room->name);
			ad = ad->next;
		}
		r = r->next;
		ft_printf("\n\n\n");
	}
	ft_printf("\n%d links\n\n", n / 2);
}

int		input_error(char **in, char ***param, t_rlist **list)
{
	t_rlist		*lst;
	t_adlist	*ad;
	
	ft_putstr_fd("ERROR\n", 2);
	(in && *in) ? free(*in) : 0;
	if (param && *param)
		while (*(*param))
		{
			free(*(*param));
			(*param)++;
		}
	while (*list)
	{
		lst = *list;
		*list = (*list)->next;
		while (lst->adia_list)
		{
			ad = lst->adia_list;
			lst->adia_list = lst->adia_list->next;
			free(ad);
		}
		free(lst->room.name);
		free(lst);
	}
	exit(1);
	return (0);
}

t_rlist	*find_room(t_rlist **lst, char *name, t_byte stat)
{
	t_rlist	*r;
	
	if (*lst == NULL)
		return (NULL);
	r = *lst;
	while (r)
	{
		if (stat == UNDEF && ft_strcmp(name, r->room.name) == 0)
			break ;
		else if (stat != UNDEF && r->room.stat == stat)
			break ;
		r = r->next;
	}
	return (r);
}

void	new_room(t_rlist **lst, char **rp, t_byte st, int ants)
{
	t_rlist *tm;
	t_rlist	*n;
	t_rlist *pre;
	
	if (!*lst)
	{
		*lst = (t_rlist*)malloc(sizeof(t_rlist));
		(*lst)->room.name = ft_strdup(rp[0]);
		(*lst)->room.x = ft_atoi(rp[1]);
		(*lst)->room.y = ft_atoi(rp[2]);
		(*lst)->room.stat = st;
		(*lst)->room.srch = 0;
		(*lst)->nr_ad = 0;
		(*lst)->room.ants = ants;
		(*lst)->adia_list = NULL;
		(*lst)->next = NULL;
		return ;
	}
	n = (t_rlist*)malloc(sizeof(t_rlist));
	n->room.name = ft_strdup(rp[0]);
	n->room.x = ft_atoi(rp[1]);
	n->room.y = ft_atoi(rp[2]);
	n->room.stat = st;
	n->room.srch = 0;
	n->room.ants = ants;
	n->nr_ad = 0;
	n->adia_list = NULL;
	tm = *lst;
	while (tm)
	{
		if (!ft_strcmp(tm->room.name, rp[0]))
			input_error(NULL, &rp, lst);
		if (tm->room.x == n->room.x && tm->room.y == n->room.y)
			input_error(NULL, &rp, lst);
		pre = tm;
		tm = tm->next;
	}
	pre->next = n;
	n->next = NULL;
}

void	new_link(t_rlist **lst, char **rp)
{
	t_rlist		*rm1;
	t_rlist		*rm2;
	t_adlist	*a1;
	t_adlist	*a2;
	
	rm1 = find_room(lst, rp[0], UNDEF);
	rm2 = find_room(lst, rp[1], UNDEF);
	if (!rm1 || !rm2)
		input_error(NULL, &rp, lst);
	a1 = (t_adlist*)malloc(sizeof(t_adlist));
	a1->room = &rm2->room;
	a1->next = rm1->adia_list;
	rm1->adia_list = a1;
	rm1->nr_ad++;
	
	a2 = (t_adlist*)malloc(sizeof(t_adlist));
	a2->room = &rm1->room;
	a2->next = rm2->adia_list;
	rm2->adia_list = a2;
	rm2->nr_ad++;
}

void	add_links(char *in, t_rlist **lst)
{
	size_t	i;
	char	**rp;
	
	if (!(rp = ft_strsplit(in, '-')))
		input_error(&in, &rp, lst);
	i = 0;
	while (rp[i++]);
	(i != 3) ? input_error(&in, &rp, lst) : 0;
	new_link(lst, rp);
	while (*rp)
	{
		free(*rp);
		rp++;
	}
}

void	add_rooms(char *in, t_byte st, t_rlist **lst, int ants)
{
	char	**rp;
	size_t	i;
	
	if (!(rp = ft_strsplit(in, ' ')))
		input_error(&in, &rp, lst);
	i = 0;
	while (rp[i++]);
	(i != 4) ? input_error(&in, &rp, lst) : 0;
	i = 0;
	while (rp[1][i] != '\0')
	{
		if (rp[1][i] && !ft_isdigit(rp[1][i]))
			input_error(&in, &rp, lst);
		i++;
	}
	i = 0;
	while (rp[2][i] != '\0')
	{
		if (rp[2][i] && !ft_isdigit(rp[2][i]))
			input_error(&in, &rp, lst);
		i++;
	}
	new_room(lst, rp, st, ants);
	while (*rp)
	{
		free(*rp);
		rp++;
	}
}

int		main(int ac, char **av)
{
	char		*input;
	t_var		_;
	t_rlist		*lst;
	char		*ants;

	if (get_next_line(0, &ants) <= 0)
		input_error(NULL, NULL, NULL);
	
	ft_memset(&_, 0, sizeof(t_var));
	lst = NULL;
	while (get_next_line(0, &input) > 0)
	{
		ft_printf("%s  [%d]\n",input, _.stat);
		if (*input == '#')
		{
			if (*(input + 1) == '#' && ft_strcmp(input + 2, "start") == 0)
				_.stat = START;
			if (*(input + 1) == '#' && ft_strcmp(input + 2, "end") == 0)
				_.stat = END;
		}
		else if (!WSPACE(*input))
		{
			if (*(input + 1) != '-')
			{
				(_.room == 0 && _.link == 1) ? input_error(&input, NULL, &lst) : 0;
				add_rooms(input, _.stat, &lst, (_.stat == START) ? ft_atoi(ants) : 0);
				(_.stat != ROOM) ? _.stat = ROOM : 0;
				_.room = 1;
			}
			else if (*(input + 1) == '-')
			{
				(_.room == 0 && _.link == 0) ? input_error(&input, NULL, &lst) : 0;
				(_.stat != ROOM) ? input_error(&input, NULL, &lst) : 0;
				if (_.room == 1 && _.link == 0)
				{
					_.link = 1;
					_.room = 0;
				}
				add_links(input, &lst);
			}
			else
				input_error(&input, NULL, &lst);
		}
		else
			input_error(&input, NULL, &lst);
		free(input);
	}
	print(lst);
	gen_paths(lst);
	(void)ac;
	(void)av;
	return (1);
}