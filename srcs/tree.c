#include "lem_in.h"

t_tree	*new_node(t_rlist *head)
{
	t_tree *n;
	
	n = (t_tree*)malloc(sizeof(t_tree));
	n->head = head;
	n->branch = NULL;
	return (n);
}


static void	print(t_tree *h)
{
	t_tree *tr;
	int		n;
		
	if (!h)
		return ;
	ft_printf(" %s ->",h->head->room.name);
	tr = h->branch;
	n = 0;
	while (n < h->head->nr_ad)
	{
		print(tr + n);
		ft_printf("\n\n\n");
		n++;
	}
}

int		generate(t_tree *h, t_room *r, t_rlist *list)
{
	t_adlist	*ad;
	int			n;

	if (r->stat == END)
		return (0);
	if (!r->srch)
	{
		h->head->room.srch = 1;
		ad = h->head->adia_list;
		h->branch = (t_tree*)malloc(sizeof(t_tree) * (h->head->nr_ad + 1));
		n = 0;
		while (ad)
		{
			(h->branch + n)->head = find_room(&list, ad->room->name, UNDEF);
			generate(h->branch + n, ad->room, list);
			ad = ad->next;
			n++;
		}
		(h->branch + n)->head = NULL;
		h->head->room.srch = 0;
	}
	return (1);
}

t_tree	*gen_paths(t_rlist *list)
{
	t_tree	*tr;
	t_rlist *st;
	
	st = find_room(&list, NULL, START);
	tr = new_node(st);
	generate(tr, &st->room, list);
	print(tr);
	free(tr);
	return (NULL);
}