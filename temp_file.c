/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:55:33 by wchumane          #+#    #+#             */
/*   Updated: 2023/10/09 13:37:12 by wchumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main_1(void)
{
	// daclare variables
	char	filename;
	char	*c = malloc(0); // noooo
  char	*c1 = malloc(0); // noooo
  char	*c2 = malloc(0); // noooo

	int		fd;
  int		fd1;
  int		fd2;
	int		size;

	// STEP 1: open file
	fd	= open("dango.txt", O_RDONLY, 0666);
	if (fd == -1)
		return 0;			// must be NULL
	// STEP 2: read file, read(int fd, void *buffer, size_t size_of_buffer)
	// a read function returns the number of bytes read on success
	size = read(fd, c, 15);
	printf("the number of bytes read on success: %d\n", size);
	c[size] = '\0';
	printf("contents inside: %s\n", c);
	// STEP 3: close file
	close(fd);
}

// print the linked list value
void printLinkedlist(t_node *p) {
  while (p != NULL) {
    printf("%d ", p->str);
    p = p->next;
  }
}


int	main_2(void)
{
	// Initialize nodes
  t_node *head;
  t_node *one = NULL;
  t_node *two = NULL;
  t_node *three = NULL;

  // Allocate memory
  one = malloc(sizeof(t_node));
  two = malloc(sizeof(t_node));
  three = malloc(sizeof(t_node));

  // Assign value values
  one->str = 1;
  two->str = 2;
  three->str = 3;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  // printing node-value
  head = one;
  printLinkedlist(head);
}


int	main(void)
{
	// daclare variables
	char	filename;
	char	*c = malloc(0); // noooo
  char	*c1 = malloc(0); // noooo
  char	*c2 = malloc(0); // noooo

	int		fd;
  int		fd1;
  int		fd2;
  int		size;
  int		size1;
  int		size2;

	// STEP 1: open file
	fd	= open("nango.txt", O_RDONLY, 0666);
  	fd1 = open("nango.txt", O_RDONLY, 0666);
  	fd2 = open("nango.txt", O_RDONLY, 0666);
	// STEP 2: read file, read(int fd, void *buffer, size_t size_of_buffer)
	// a read function returns the number of bytes read on success
	size = read(fd1, c, 3);
	printf("fd[0]: %d\n", fd);
	printf("fd[1]: %d\n", fd1);
	printf("fd[2]: %d\n", fd2);
	size1 = read(fd1, c1, 3);
	size2 = read(fd1, c2, 3);
	printf("[0] the number of bytes read on success: %d\n", size);
	printf("[1] the number of bytes read on success: %d\n", size1);
	printf("[2] the number of bytes read on success: %d\n", size2);

	printf("[0] contents inside: %s\n", c);
	printf("[1] contents inside: %s\n", c1);
	printf("[2] contents inside: %s\n", c2);

	// STEP 3: close file
	close(fd);
}
