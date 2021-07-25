#include "cub3d.h"

static void	bmp_header(int fd, t_res res)
{
	char	bit_map[54];

	ft_bzero(bit_map, 54);
	bit_map[0] = 'B';
	bit_map[1] = 'M';
	*((int *)(bit_map + 2)) = res.height * res.width * 4 + 54;
	*(int *)(bit_map + 10) = 54;
	*(int *)(bit_map + 14) = 40;
	*(int *)(bit_map + 18) = res.width;
	*(int *)(bit_map + 22) = res.height;
	*(bit_map + 26) = 1;
	*(bit_map + 28) = 32;
	write(fd, bit_map, 54);
}

static void	write_in_bmp(int fd, t_res res, t_img img)
{
	int32_t	x;
	int32_t	y;
	int		color;

	y = res.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < res.width)
		{
			color = *(unsigned int *)(img.addr \
					+ (y * img.ll / 4) \
					+ x * (img.bpp / 32));
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
	close(fd);
}

void	create_screenshot(t_res res, t_img img)
{
	int		fd;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if (fd < 0)
		print_error("Can not create screenshot");
	bmp_header(fd, res);
	write_in_bmp(fd, res, img);
	exit(0);
}
