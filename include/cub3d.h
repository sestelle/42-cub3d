#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"

# include "fcntl.h"
# include "math.h"

# include "read_config.h"
# include "engine.h"

void	check_args(int argc, char *argv[], t_cfg *cfg);

void	print_error(char *error);

#endif