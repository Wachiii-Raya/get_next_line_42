/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <wchumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:10:06 by wchumane          #+#    #+#             */
/*   Updated: 2023/12/26 01:09:22 by wchumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	is_newline_found()

size_t	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

// string duplicate from libft
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1) + 1;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len);
	return (ptr);
}


//append the read buffer into t_node *str[4095]
void	append_buffer_to_node(t_node **str, char *buffer)
{
	t_node	*new_node;
	t_node	*previous_node;

	// duplicate buffer 
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->str = ft_strdup(buffer);
	new_node->next = NULL;
	
	// add new_node at the end of previous node, but if this is 1st node -> return ; if not, 
	// point next of the previous node to head of new_node
	if (*str == NULL)
	{
		*str = new_node;
		return ;
	}
	else
	{
		while (!(previous_node->next))
			previous_node = previous_node->next;
		previous_node->next = new_node;
	}
}

void	*read_line_to_node(t_node **str, int fd)
{
	char	*buffer;
	int		read_length;

	// memory allocation
	buffer = malloc(BUFFER_SIZE + 1);
	read_length = read(fd, buffer, BUFFER_SIZE);
	if (read_length == 0)
		return (0);
	// printf("buffer: %s", buffer); << then put this string to linked list
	// TODO: reduce buffer size <- no need to define a large number
	*buffer = *buffer + '\0';
	// printf("buffer: %s", buffer);
	
}

char	*get_next_line(int fd)
{
	// step 1: define static val
	static t_node	*str[4095];
	char			*line;
	int				is_newline_found;

	is_newline_found = 0;
	// step 2: condition checking -> fd, buf_size, returned value of read() for just 1st byte
	// TODO: check that fd must be greater that 0 or 2
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, NULL, 0 ))
		return (0);
	// step 3: create node of read string ntil '\n' is found
	// while (is_newline_found != 1)
	// {
		
	// }
	
}

/*
int	main(void)
{

	int		fd;
	char	buf[255];
	int		size;

	fd = open("test.txt", O_RDONLY);
	// printf("fd: %d\n", fd);
	if (fd == -1)
		return 0;
	char	*str = malloc(0);
	str = get_next_line(fd);
}
*/

// ------- test: read line function [/]---------

// int	main(void)
// {
// 	int	fd;
// 	t_node	*str[255];

// 	fd = open("test.txt", O_RDONLY);
// 	read_line_to_node(str, fd);
// }

void print_list(t_node *node)
{
    while (node != NULL)
    {
        printf("%s\n", node->str);
        node = node->next;
    }
}

// ------- test: append buffer to node function [/]---------
int	main(void)
{
	int	fd;
	t_node	*str[255];
	
	
	// fd = open("test.txt", O_RDONLY);
	append_buffer_to_node(str, "hey gurlll");
	t_node	*tmp = *str;
	print_list(tmp);
	
}