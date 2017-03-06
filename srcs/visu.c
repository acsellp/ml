#include "lem_in.h"

void	get_max(t_rlist *rlist, int *mx, int *my)
{
	t_rlist *l;
	
	l = rlist;
	while (l)
	{
		if (l->room.x > *mx)
			*mx = l->room.x;
		if (l->room.y > *my)
			*my = l->room.y;
		l = l->next;
	}
}

void	visu(t_rlist *rlist)
{
	int	mx;
	int	my;
	int	i;
	int	j;
	t_map **map;
	t_rlist *tt;
	
	my = 0;
	mx = 0;
	get_max(rlist, &mx, &my);
	map = (t_map**)malloc(sizeof(t_map*) * (my + 1));
	ft_printf("x %d y %d\n\n",mx,my);
	i = 0;
	while (i < my)
	{
		map[i] = (t_map*)malloc(sizeof(t_map) * (mx + 1));
		i++;
	}
	i = 0;
	while (i < my)
	{
		ft_memset(map[i], 0, mx);
		i++;
	}
	i = 0;
	while (i <= my)
	{
		j = 0;
		while (j <= mx)
		{
			tt = rlist;
			while (tt)
			{
				if (tt->room.y == i && tt->room.x == j)
				{
					ft_printf("%s",tt->room.name);
					map[i][j].str = NULL;
					break ;
				}
				tt = tt->next;
			}
			ft_putstr("  ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	i = 0;
	while (i < my)
	{
		free(map[i]);
		i++;
	}
}