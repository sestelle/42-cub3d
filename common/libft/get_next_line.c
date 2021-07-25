/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:06:17 by sestelle          #+#    #+#             */
/*   Updated: 2020/12/13 13:48:39 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remainder(char *buf, char *remainder)
{
	char	*tmp;

	if (remainder)
	{
		tmp = ft_strjoin(remainder, buf);
		free(remainder);
		remainder = ft_strdup(tmp);
		free(tmp);
	}
	else
		remainder = ft_strdup(buf);
	return (remainder);
}

char	*ft_line(char *remainder, char **line, int read_val)
{
	int			i;
	char		*tmp;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (i < (int)ft_strlen(remainder))
	{
		*line = ft_substr(remainder, 0, i);
		tmp = ft_substr(remainder, i + 1, ft_strlen(remainder));
		free(remainder);
		remainder = ft_strdup(tmp);
		free(tmp);
	}
	else if (read_val == 0)
	{
		*line = remainder;
		remainder = NULL;
	}
	return (remainder);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			read_val;
	static char	*remainder;

	while (1)
	{
		read_val = read(fd, buf, BUFFER_SIZE);
		if (read_val == 0)
			break ;
		if (read_val == -1)
			return (-1);
		buf[read_val] = '\0';
		remainder = ft_remainder(buf, remainder);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (read_val == 0 && !remainder)
	{
		*line = ft_strdup("");
		return (read_val);
	}
	remainder = ft_line(remainder, line, read_val);
	if (read_val == 0 && !remainder)
		return (read_val);
	return (1);
}
