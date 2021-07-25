#ifndef READ_CONFIG_H
# define READ_CONFIG_H

# include "structs.h"

void	read_config(char *path, t_cfg *cfg);

char	**open_file(char *path);

t_res	read_resolution(char *line);
char	*read_texture(char *line);
int		read_color(char *line);
char	**read_map(char **file);
t_plr	read_plr(char **map);

void	create_map(char **map);
void	check_map(char **map, t_double pos);
void	flood_fill(char **map, t_int size, int x, int y);
char	**recreate_map(char **map, t_int *size);

int		split_size(char **split);
char	*find_line(char **file, char *key);
int		convert_rgb(int t, int r, int g, int b);

#endif
