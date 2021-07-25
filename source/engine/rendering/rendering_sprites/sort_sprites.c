#include "cub3d.h"

static void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	t_int	counter;

	counter.x = 0;
	while (counter.x < amount)
	{
		counter.y = 0;
		while (counter.y < amount - 1)
		{
			if (orders[counter.y].first > orders[counter.y + 1].first)
			{
				tmp.first = orders[counter.y].first;
				tmp.second = orders[counter.y].second;
				orders[counter.y].first = orders[counter.y + 1].first;
				orders[counter.y].second = orders[counter.y + 1].second;
				orders[counter.y + 1].first = tmp.first;
				orders[counter.y + 1].second = tmp.second;
			}
			counter.y += 1;
		}
		counter.x += 1;
	}
}

void	sort_sprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;
	int		i;

	sprites = (t_pair *)malloc(sizeof(t_pair) * amount);
	i = 0;
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
}
