/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:13:58 by baptiste          #+#    #+#             */
/*   Updated: 2024/05/27 00:16:43 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/todo.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif


static size_t	ft_strle(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_nstrlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strjoin(char *src1, char *src2)
{
	char	*result;
	int		c;
	int		d;
	int		len;

	c = 0;
	d = 0;
	if (!src1 && !src2)
		return (NULL);
	len = (ft_strle(src1) + ft_strle(src2) + 1);
	result = malloc(sizeof(*result) * len);
	if (result == NULL)
		return (NULL);
	while (c < (int)ft_strle(src1))
	{
		result[c] = src1[c];
		c++;
	}
	while (c < (int)(ft_strle(src1) + ft_strle(src2)))
		result[c++] = src2[d++];
	result[c] = '\0';
	free(src1);
	return (result);
}

static char	*ft_n_copy(char *str)
{
	int		i;
	int		j;
	char	*dest;

	j = 0;
	if (!str)
		return (NULL);
	i = ft_nstrlen(str);
	dest = malloc(ft_strle(str + i) + 1);
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[j] = str[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	free(str);
	return (dest);
}

static char	*ft_get_line(char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	if (!src)
		return (NULL);
	len = ft_nstrlen(src);
	dest = malloc((sizeof(*dest) * len) + 1);
	if (!dest)
		return (NULL);
	while (i < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_read(int fd, char *buffer, char *save)
{
	int	reading;

	reading = 1;
	while (!(ft_strchr(save, '\n')) && reading > 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading <= 0)
			break ;
		buffer[reading] = '\0';
		save = ft_strjoin(save, buffer);
	}
	if (reading < 0 || (reading == 0 && !ft_strlen(save)))
	{
		free(save);
		return (NULL);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(*buffer) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	save = ft_read(fd, buffer, save);
	free(buffer);
	line = ft_get_line(save);
	save = ft_n_copy(save);
	return (line);
}