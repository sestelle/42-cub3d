#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_cfg	cfg;

	check_args(argc, argv, &cfg);
	read_config(argv[1], &cfg);
	engine(cfg);
	return (0);
}
