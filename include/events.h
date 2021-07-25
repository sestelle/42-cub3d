#ifndef EVENTS_H
# define EVENTS_H

void	events(char **map, t_plr *plr, t_events *events);
int		events_press(int code, t_events *events);
int		events_release(int code, t_events *events);

void	rotations(t_plr *plr, t_events *events);
void	movements(char **map, t_plr *plr, t_events *events);

#endif
