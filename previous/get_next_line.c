/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:48:35 by wchumane          #+#    #+#             */
/*   Updated: 2023/10/08 11:36:47 by wchumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	// declaration
	size_t	size;
	char	*buf; // malocc!!!!

	buf =  malloc(buf_size);
	// check fd -> if not exist, create one. if exist, point to this file
	if (fd == -1 || fd < 0)
		return (NULL);
	// malloc buffer

	// read + while loop until '\n' is found
	size = read(fd, buf, buf_size);
	printf("the number of bytes read on success: %zu\n", size);
	printf("content inside: %s\n", buf);


	// close file
	close(fd);
	// return 1 line
	return (buf);
}


int	main(void)
{
	// declaration
	size_t	fd;
	size_t	size;
	char	*str;
	// check fd

	fd = open("nango.txt", O_RDONLY, 0666);
	if (fd == -1)
		return 0;
	str = malloc(buf_size);
	str = get_next_line(fd);
	printf("output: %s\n", str);
	// malloc str, size all text file + 1 <- this int from read()
	//while loop until found '\0'
		// read line <return 1 line>
		// append '\n'
	// append '\0'

}

// print the linked list value
// void printLinkedlist(t_node *p) {
//   while (p != NULL) {
//     printf("%d ", p->str);
//     p = p->next;
//   }
// }


// int	main(void)
// {
// 	// Initialize nodes
//   t_node *head;
//   t_node *one = NULL;
//   t_node *two = NULL;
//   t_node *three = NULL;

//   // Allocate memory
//   one = malloc(sizeof(t_node));
//   two = malloc(sizeof(t_node));
//   three = malloc(sizeof(t_node));

//   // Assign value values
//   one->str = 1;
//   two->str = 2;
//   three->str = 3;

//   // Connect nodes
//   one->next = two;
//   two->next = three;
//   three->next = NULL;

//   // printing node-value
//   head = one;
//   printLinkedlist(head);
// }
