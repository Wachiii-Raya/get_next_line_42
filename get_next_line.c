/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <wchumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:27:09 by wchumane          #+#    #+#             */
/*   Updated: 2023/12/26 16:43:04 by wchumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*ptr;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	if (!s1 || !s2)
// 		return (ft_strdup(""));
// 	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);

// 	if (!ptr)
// 		return (NULL);
// 	while (s1[i])
// 		ptr[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		ptr[j++] = s2[i++];
// 	ptr[j] = '\0';
// 	return (ptr);
// }

// size_t	ft_strlen(const char *str)
// {
// 	int	counter;

// 	counter = 0;
// 	while (str[counter] != '\0')
// 	{
// 		counter++;
// 	}
// 	return (counter);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	if (size > 0)
// 	{
// 		while (src[i] && i < (size - 1))
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = 0;
// 	}
// 	while (src[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(const char *s1)
// {
// 	char	*ptr;
// 	size_t	len;

// 	len = ft_strlen(s1) + 1;
// 	ptr = (char *)malloc(len);
// 	if (!ptr)
// 		return (NULL);
// 	ft_strlcpy(ptr, s1, len);
// 	return (ptr);
// }

//-----------------------------------------

int	is_newline_found(char *buffer)
{
	int	is_newline;
	int	i;

	is_newline = 0;
	i = 0;
	while (buffer[i] == '\0')
	{
		if (buffer[i] == '\n')
			return	(1);
		i++;
	}
	return (0);
}

void	*free_all_node(t_list **node)
{
	t_list	*tmp;

	while (*node != NULL)
	{
		tmp = *node;
		*node = (*node)->next;
		free(tmp->str);
		free(tmp);
	}
	return (NULL);
}

// convert linked list of 1 lines to a line for return
char	*convert_list_to_line(t_list *node)
{
	char	*line;
	int		length;
	t_list	*head;
	
	if (node == NULL)
		return (NULL);
	length = 0;
	head = node;
	while (node != NULL)
	{
		length += ft_strlen(node->str);
		node = node->next;
	}
	line = (char *)malloc(sizeof(char) * (length + 1));
	if (!line)
		return (NULL);
	while (head != NULL)
	{
		line = ft_strjoin(line, head->str);
		head = head->next;
	}
	return (line);
}

void	append_buffer_to_node(t_list **str, char *buffer)
{
	t_list	*new_node;
	t_list	*previous_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->str = ft_strdup(buffer);
	new_node->next = NULL;
	previous_node = *str;
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

void	*read_buffer(char *temp, int fd)
{
	int		read_length;

	read_length = read(fd, temp, BUFFER_SIZE);
	if (read_length == 0)
		return NULL;
	*temp = *temp + '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	// step 1: define static val
	static t_list	*str_node[4095];
	char			*line;
	int				is_newline_flag;
	char			*temp;

	is_newline_flag = 0;
	// step 2: condition checking -> fd, buf_size, returned value of read() for just 1st byte
	// TODO: check that fd must be greater that 0 or 2
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, NULL, 0 ))
		return (0);
	// step 3: create node of read string ntil '\n' is found
	while (is_newline_flag != 1)
	{	
		// *read_buff = read_buffer
		temp = (char *)malloc(BUFFER_SIZE + 1);
		read_buffer(temp, fd);
		is_newline_flag = is_newline_found(temp);
		append_buffer_to_node(str_node, temp);
	}
	// step 4: convert linked list of 1 lines to a line for return
	line = convert_list_to_line(*str_node);
	// step 5: free all node
	free_all_node(str_node);	
	return (line);
}

// // ------- test: get_next_line function [/]---------
// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("test.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("str: %s\n", str);
// }

// ------- test: convert linked list to char *line aka a single line [/]---------
// int	main(void)
// {
// 	t_node	*node_1;
// 	t_node	*node_2;
// 	t_node	*node_3;
// 	char	*a_line;

// 	node_1 = (t_node *)malloc(sizeof(t_node));
// 	node_2 = (t_node *)malloc(sizeof(t_node));
// 	node_3 = (t_node *)malloc(sizeof(t_node));
// 	node_1->str = ft_strdup("hey");
// 	node_2->str = ft_strdup("gurl");
// 	node_3->str = ft_strdup("whatsup");
// 	node_1->next = node_2;
// 	node_2->next = node_3;
// 	node_3->next = NULL;

// 	a_line = convert_list_to_line(node_1);
// 	printf("line: %s\n", a_line);
// }

// ------- test: append buffer to node function [/]---------

// void print_list(t_node *node)
// {
//     while (node != NULL)
//     {
//         printf("%s\n", node->str);
//         node = node->next;
// 		printf("eiei\n");
//     }
// }

// int	main(void)
// {
// 	int	fd;
// 	t_node	*str[255];		// FD max <- fd of this pc
	
	
// fd = open("test.txt", O_RDONLY);
// 	append_buffer_to_node(str, "hey gurlll");
// 	t_node	*tmp = *str;
// 	print_list(tmp);
	
// }