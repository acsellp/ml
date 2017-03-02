#include "lem_in.h"

t_tree	*new_node(t_rlist *head)
{
	t_tree *n;
	
	n = (t_tree*)malloc(sizeof(t_tree));
	n->head = head;
	n->branch = NULL;
	return (n);
}

int		generate(t_tree *h, , t_rlist *list)
{
	t_adlist	ad;
	
	h->srch = 1;
	
	
	
	h->srch = 0;
	return (1);
}

t_tree	*gen_paths(t_rlist *list)
{
	t_tree	*tr;
	t_rlist *st;
	
	
	st = find_room(&list, NULL, START);
	tr = new_node(st);
	

	generate(tr, st, list);
	return (NULL);
}