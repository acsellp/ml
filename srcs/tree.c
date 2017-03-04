#include "lem_in.h"


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

int 	print_tree(t_tree *h)
{
	t_tree *tr;
	int		n;
		
	if (!h || !h->head || !h->branch)
		return 1;
	ft_printf("\n     %s [%p][%p][%d]:",h->head->room.name, h->branch->head, h->head,h->n);
	tr = h->branch;
	n = 0;
	while (n < h->n)
	{
		ft_printf(" %s +", (tr + n)->head->room.name);
		n++;
	}
	ft_printf("][");
	n = 0;
	while (n < h->n)
	{
		ft_printf("\n %d ... [%p]",n, (tr + n)->branch);
		ft_printf(" %s -> %s",h->head->room.name, (tr + n)->head->room.name);
		if ((tr + n)->head->room.stat != END && (tr + n)->branch)
			print_tree(tr + n);
		n++;
	}
	ft_printf("   =\n\n\n");
	return 0;
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
		if (!(h->branch + n))
			return (0);
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

int 	print_min_path(t_tree *h)
{
	int		n;

	if (!h || !h->head || !h->branch)
		return 1;
	ft_printf("\n     %s [%p][%p][%d]:",h->head->room.name, h->branch->head, h->head,h->n);
	n = 0;
	while (n < h->n)
	{
		if ((h->branch + n)->srch == 1)
			ft_printf(" %s +", (h->branch + n)->head->room.name);
		n++;
	}
	n = 0;
	while (n < h->n)
	{
		if ((h->branch + n)->srch == 1)
		{
			ft_printf("\n %d ... [%p][lvl %d]",n, (h->branch + n)->branch,(h->branch + n)->level);
			ft_printf(" %s -> %s |",h->head->room.name, (h->branch + n)->head->room.name);
		}
		if ((h->branch + n)->srch == 1 && (h->branch + n)->branch)
			print_min_path(h->branch + n);
		n++;
	}
	ft_printf("   \n\n\n");
	return 0;
}

t_tree	*gen_paths(t_rlist *list)
{
	t_tree	*tr;
	t_rlist *st;
	t_tlist	*tlist;
	
	st = find_room(&list, NULL, START);
	tr = (t_tree*)malloc(sizeof(t_tree));
	tr->head = st;
	tr->branch = NULL;
	tr->srch = 0;
	tr->level = 1;
	tlist = NULL;
	ft_printf("\n generae\n");
	generate(tr, &st->room, list, &tlist);
	ft_printf("\n /generae\n");
	print_tree(tr);
	
	ft_putstr("\n\n==================\n==================\n==================\n==================\n==================\n==================\n==================\n==================\n\n\n\n\n\n");
	min_path(tr);
	print_min_path(tr);
	if (tr->srch == 1)
		ft_printf(" \n there are paths\n\n\n");
	else
		ft_printf("\n there are no paths\n\n\n");
	del_tree(tlist);
	free(tr);
	
	return (NULL);
}