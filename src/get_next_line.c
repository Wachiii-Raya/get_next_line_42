/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <wchumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:35:59 by wchumane          #+#    #+#             */
/*   Updated: 2024/02/10 23:43:33 by wchumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clear_array(char *str, size_t length)
{
	char	*current_arr;
	size_t	length_new;
	size_t	length_max;
	size_t	i;

	i = 0;
	length_max = ft_strlen(str);
	length_new = length_max - length;
	current_arr = malloc(sizeof(char *) * (length_new + 1));
	if (!current_arr)
	{
		free(str);
		return (NULL);
	}
	while (i < length_new)
	{
		current_arr[i] = str[length + i + 1];
		i++;
	}
	current_arr[i] = '\0';
	free(str);
	return (current_arr);
}

char	*read_line(int fd, char *str_array, char *buffer)
{
	ssize_t	length;

	length = 1;
	while ((!(ft_strrchr(str_array, '\n'))) && (length > 0))
	{
		length = read(fd, buffer, BUFFER_SIZE);
		if (length == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[length] = '\0';
		str_array = ft_strjoin(str_array, buffer);
		if (!str_array)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (str_array);
}

char	*gnl_init(char	**str_arr, int fd)
{
	char	*buffer;

	if ((BUFFER_SIZE <= 0) || (fd < 0) || (read(fd, NULL, 0) == -1))
	{
		if (str_arr[fd])
		{
			free(str_arr[fd]);
			str_arr[fd] = NULL;
		}
		return (NULL);
	}
	if (!(str_arr[fd]))
	{
		str_arr[fd] = ft_strdup("");
		if (!str_arr[fd])
			return (NULL);
	}
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(str_arr[fd]);
		str_arr[fd] = NULL;
		return (NULL);
	}
	return (buffer);
}

char	*clone_case(int case_num, char **str_arr, int fd)
{
	if (case_num == 1)
	{
		if (!str_arr[fd])
			return (NULL);
		else
		{
			free(str_arr[fd]);
			str_arr[fd] = NULL;
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*arr[1024 + 1];
	char		*ret;
	char		*buffer;
	size_t		len_nl;

	len_nl = 0;
	arr[1024] = NULL;
	buffer = gnl_init(arr, fd);
	if (!buffer)
		return (NULL);
	arr[fd] = read_line(fd, arr[fd], buffer);
	if (arr[fd] && ft_strlen(arr[fd]) > 0)
	{
		while ((arr[fd][len_nl] != '\n') && (arr[fd][len_nl] != '\0'))
			len_nl++;
		ret = malloc(sizeof(char) * (len_nl + 1 + (arr[fd][len_nl] == '\n')));
		if (!ret)
			return (clone_case(1, arr, fd));
	}
	else
		return (clone_case(1, arr, fd));
	ft_strlcpy(ret, arr[fd], len_nl + 1 + (arr[fd][len_nl] == '\n'));
	ret[len_nl + (arr[fd][len_nl] == '\n')] = '\0';
	arr[fd] = clear_array(arr[fd], len_nl);
	return (ret);
}
