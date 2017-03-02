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
	t_tree		*br;

	if (r->stat == END)
		return (0);
	if (!r->srch)
	{
		rl = find_room(&list, r->name, UNDEF);
		//h = new_node(&rl->room);
		// new branch list nr_ad ...
		h->head->srch = 1;
		ad = rl->adia_list;
		while (ad)
		{
			br = (t_branch*)malloc(sizeof(t_branch));
			br->room = ad->room;
			br->next = h->branch;
			h->branch = br;
			generate(br, ad->room, list);
			ad = ad->next;
		}
		h->head->srch = 0;
	}
	return (1);
}

t_tree	*gen_paths(t_rlist *list)
{
	t_tree	*tr;
	t_rlist *st;
	
	st = find_room(&list, NULL, START);
	tr = new_node(&st->room);
	//tr->head->srch = 1;
	
	generate(tr, &st->room, list);
	return (NULL);
}