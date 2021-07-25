#include "cub3d.h"

char	*find_line(char **file, char *key)
{
	char	*line;
	t_bool	flag;

	flag = false;
	line = NULL;
	while (*file)
	{
		if (ft_strncmp(*file, key, ft_strlen(key)) == 0)
		{
			if (flag == false)
			{
				flag = true;
				if (line != NULL)
					free(line);
				line = ft_strdup(*file);
			}
			else
				print_error("Double Key");
		}
		file++;
	}
	if (line == NULL)
		print_error("Can not found key");
	return (line);
}
