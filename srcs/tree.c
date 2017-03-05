#include "lem_in.h"

int		abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

t_byte	no_new_paths(t_rlist *r)
{
	t_adlist	*ad;
	
	ad = r->adia_list;
	if (!ad)
		return (1);
	while (ad)
	{
		if (ad->room->srch == 0 || ad->room->stat == END)
			return (0);
		ad = ad->next;
	}
	return (1);
}


void	add_branch(t_tlist **list, t_tree *branch)
{
	t_tlist *tm;
	
	if (!*list)
	{
		*list = (t_tlist*)malloc(sizeof(t_tlist));
		(*list)->head = branch;
		(*list)->next = NULL;
		return ;
	}
	tm = (t_tlist*)malloc(sizeof(t_tlist));
	tm->head = branch;
	tm->next = *list;
	(*list) = tm;
}

void del_tree(t_tlist *list)
{
	t_tlist	*t;

	while (list)
	{
		t = list;
		list = list->next;
		free(t->head);
		free(t);
		t = NULL;
	}
}

t_byte	generate(t_tree *h, t_room *r, t_rlist *list, t_tlist **tlist)
{
	t_adlist	*ad;
	int			n;
	t_rlist		*rm;

	if (r->stat == END || no_new_paths(h->head))
		return (0);
	if (!r->srch)
	{
		h->head->room.srch = 1;
		ad = h->head->adia_list;
		h->branch = (t_tree*)malloc(sizeof(t_tree) * (h->head->nr_ad + 1));
		add_branch(tlist, h->branch);
		n = 0;
		while (ad)
		{
			rm = find_room(&list, ad->room->name, UNDEF);
			(h->branch + n)->level = h->level + 1;
			if (rm->room.srch != 1)
			{
				(h->branch + n)->head = rm;
				generate(h->branch + n, ad->room, list, tlist);
				n++;
			}
			ad = ad->next;
		}
		h->n = n;
		//(h->branch + n + 1)->head = NULL;
		h->head->room.srch = 0;
	}
	return (1);
}

int 	min_path(t_tree *h)
{
	int		n;
		
	if (!h || !h->head || !h->branch)
		return 0;
	n = 0;
	while (n < h->n)
	{
		if (h->branch + n && (h->branch + n)->head->room.stat == END)
		{
			h->srch = 1;
			(h->branch + n)->srch = 1;
			return 1;
		}
		if (h->branch + n && (h->branch + n)->branch)
			if (min_path(h->branch + n) || (h->branch + n)->srch == 1)
				h->srch = 1;
		n++;
	}
	return 0;
}

int 	print__path(t_tree *h, int stat)
{
	int		n;

	if (!h || !h->head || !h->branch)
		return 1;
	ft_printf("\n     %s [%p][%p][%d]:",h->head->room.name, h->branch->head, h->head,h->n);
	n = 0;
	while (n < h->n)
	{
		if (stat == UNDEF || (h->branch + n)->srch == stat)
			ft_printf(" %s +", (h->branch + n)->head->room.name);
		n++;
	}
	n = 0;
	while (n < h->n)
	{
		if (stat == UNDEF || (h->branch + n)->srch == stat)
		{
			ft_printf("\n %d ... [%p][lvl %d]",n, (h->branch + n)->branch,(h->branch + n)->level);
			ft_printf(" %s -> %s |",h->head->room.name, (h->branch + n)->head->room.name);
		}
		if ((stat == UNDEF || (h->branch + n)->srch == stat) && (h->branch + n)->branch)
			print__path(h->branch + n, stat);
		n++;
	}
	ft_printf("   \n\n\n");
	return (0);
}

int 	print_ants_pos(t_tree *h)
{
	int		n;

	if (!h || !h->head || !h->branch)
		return (1);
	n = 0;
	while (n < h->n)
	{
		if ((h->branch + n)->head->room.stat == END)
		{
			if ((h->branch + n)->head->room.ants != 0)
				ft_printf("L%d-%s ", (h->branch + n)->head->room.ants, (h->branch + n)->head->room.name);
			return (1);
		}
		if ((h->branch + n)->srch == MPATH && (h->branch + n)->branch)
		{
			print_ants_pos(h->branch + n);
			if ((h->branch + n)->head->room.ants != 0)
				ft_printf("L%d-%s ", (h->branch + n)->head->room.ants, (h->branch + n)->head->room.name);
		}
		n++;
	}
	return (0);
}

int		no_more_ants(t_rlist *rlist)
{
	t_rlist *rl;
	
	rl = rlist;
	while (rl)
	{
		if (rl->room.stat != START && rl->room.ants != 0)
			return (0);
		rl = rl->next;
	}
	return (1);
}

int		move_ants(t_tree *h, int ants)
{
	int		n;

	if (!h || !h->head || !h->branch)
		return (0);
	n = 0;
	while (n < h->n)
	{
		if ((h->branch + n)->head->room.stat == END)
		{
			if (h->head->room.ants != 0)
			{
				(h->branch + n)->head->room.ants = h->head->room.ants;
				h->head->room.ants = 0;
			}
			if ((h->branch + n)->head->room.ants != 0)
				ft_printf("L%d-%s ",(h->branch + n)->head->room.ants, (h->branch + n)->head->room.name);
			(h->branch + n)->head->room.ants = 0;
			return (1);
		}
		if ((h->branch + n)->srch == MPATH)
		{
			move_ants(h->branch + n, ants);
			if (h->head->room.ants != 0 && h->head->room.stat != START)
			{
				(h->branch + n)->head->room.ants = h->head->room.ants;
				h->head->room.ants = 0;
			}
		}
		n++;
	}
	return (0);
}

void	gshdone(t_tree *h, int ants, t_rlist *end, t_rlist *rlist)
{
	int n;
	
	while (1)
	{
		move_ants(h, ants);
		if (h->head->room.ants > 0)
		{
			n = 0;
			while (n < h->n && h->head->room.ants > 0)
			{
				if ((h->branch + n)->srch == MPATH)
				{
					h->head->room.ants--;
					(h->branch + n)->head->room.ants = abs(h->head->room.ants - ants);
				}
				n++;
			}
		}
		print_ants_pos(h);
		ft_printf("\n");
		end->room.ants = 0;
		if (no_more_ants(rlist))
			return ;	
	}
}

int 	define_paths(t_tree *h, t_rlist *end)
{
	int		n;
	int		pos;
	int		minx;
	int		miny;
		
	if (!h || !h->head || !h->branch)
		return (0);
	n = 0;
	pos = 0;
	minx = INT_MAX;
	miny = INT_MAX;
	h->head->room.srch = MPATH;
	h->srch = MPATH;
	while (n < h->n)
	{
		if ((h->branch + n)->head->room.stat == END)
		{
			(h->branch + n)->srch = MPATH;
			(h->branch + n)->head->room.srch = MPATH;
			return (1);
		}
		if (h->branch + n && (h->branch + n)->srch == 1 && (h->branch + n)->head->room.srch != MPATH)
			if (abs((h->branch + n)->head->room.x - end->room.x) <= minx \
				&& abs((h->branch + n)->head->room.y - end->room.y) <= miny)
				pos = n;
		n++;
	}
	define_paths(h->branch + pos, end);
	return (0);
}

t_tree	*gen_paths(t_rlist *list)
{
	t_tree	*tr;
	t_rlist *st;
	t_rlist	*end;
	t_tlist	*tlist;
	int		n;
	
	st = find_room(&list, NULL, START);
	tr = (t_tree*)malloc(sizeof(t_tree));
	tr->head = st;
	tr->branch = NULL;
	tr->srch = 0;
	tr->level = 1;
	tlist = NULL;
	ft_printf("\n generate\n");
	generate(tr, &st->room, list, &tlist);
	ft_printf("\n /generate\n");
	print__path(tr, UNDEF);
	
	ft_putstr("\n\n==================\n==================\n==================\n==================\n\n\n\n\n");
	min_path(tr);
	print__path(tr, 1);
	if (tr->srch == 1)
		ft_printf(" \n there are paths \n\n\n");
	else
	{
		ft_printf("\n there are no paths\n\n\n");
		return (NULL);
	}
	end = find_room(&list, NULL, END);
	n = tr->n;
	while (n--)
		define_paths(tr, end);
	print__path(tr, MPATH);
	ft_printf("%d\n\n\n",st->room.ants);
	if (st->room.ants == 0)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	gshdone(tr, st->room.ants, end, list);
	
	del_tree(tlist);
	free(tr);
	return (NULL);
}