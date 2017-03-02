#include "lem_in.h"

t_tree	*new_node(t_room *head)
{
	t_tree *n;
	
	n = (t_tree*)malloc(sizeof(t_tree));
	n->head = head;
	n->branch = NULL;
	return (n);
}

int		generate(t_tree *h, t_room *r, t_rlist *list)
{
	t_adlist	*ad;
	t_rlist		*rl;
	
	if (!r->srch)
	rl = find_room(&list, r->name, UNDEF);
	h = new_node(&rl->room);
	h->head->srch = 1;
	ad = rl->adia_list;
	while (ad)
	{
		
		ad = ad->next;
	}
	
	h->srch = 0;
	
	
	
	
	return (1);
}

t_tree	*gen_paths(t_rlist *list)
{
	t_tree	*tr;
	t_rlist *st;
	
	st = find_room(&list, NULL, START);
	tr = NULL;
	
	generate(tr, &st->room, list);
	return (NULL);
}