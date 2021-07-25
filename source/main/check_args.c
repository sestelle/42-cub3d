#include "cub3d.h"

static void	check_extension(char *path)
{
	if (ft_strlen(path) > 4)
	{
		if (ft_strncmp(path + ft_strlen(path) - 4, ".cub", 4) == 0)
			return ;
	}
	print_error("Config file has invalid extension");
}

static void	check_save(char *flag, t_cfg *cfg)
{
	if (ft_strlen(flag) == 6)
	{
		if (ft_strncmp("--save", flag, 6) == 0)
		{
			cfg->save = true;
			return ;
		}
	}
	print_error("Second argument is not '--save'");
}

void	check_args(int argc, char *argv[], t_cfg *cfg)
{
	cfg->save = false;
	if (argc == 2 || argc == 3)
	{
		check_extension(argv[1]);
		if (argc == 3)
			check_save(argv[2], cfg);
	}
	else
		print_error("Invalid count arguments");
}
