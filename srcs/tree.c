#include "lem_in.h"

t_tree	*new_node(t_rlist *head)
{
	t_tree *n;
	
	n = (t_tree*)malloc(sizeof(t_tree));
	n->head = head;
	n->branch = NULL;
	return (n);
}

int 	print_tree(t_tree *h)
{
	t_tree *tr;
	int		n;
		
	if (!h || !h->head)
		return 1;
	ft_printf("\n     %s [%p][%p][%d]:",h->head->room.name, h->branch->head, h->head,h->n);
	tr = h->branch;
	n = 0;
	while (n < h->n)
	{
		ft_printf(" %s +", (tr + n)->head->room.name);
		n++;
	}
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

int		generate(t_tree *h, t_room *r, t_rlist *list)
{
	t_adlist	*ad;
	int			n;
	t_rlist		*rm;

	if (r->stat == END)
		return (0);
	if (!r->srch)
	{
		h->head->room.srch = 1;
		ad = h->head->adia_list;
		ft_printf("\nhead %s ->  ", h->head->room.name);
		h->branch = (t_tree*)malloc(sizeof(t_tree) * (h->head->nr_ad + 1));
		n = 0;
		while (ad)
		{
			
			rm = find_room(&list, ad->room->name, UNDEF);
			if (rm->room.srch != 1)
			{
				(h->branch + n)->head = rm;
				//(h->branch + n)->head->room.srch = 1;
				//ft_printf(" %s -> ",(h->branch + n)->head->room.name);
				generate(h->branch + n, ad->room, list);
				//(h->branch + n)->head->room.srch = 0;
				n++;
			}
			ad = ad->next;
		}
		//ft_printf("\n\n\n");
		h->n = n;
		(h->branch + n + 1)->head = NULL;
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
	
	//tr = (tr->branch)->branch;
	print_tree(tr);
	//free(tr);
	return (NULL);
}