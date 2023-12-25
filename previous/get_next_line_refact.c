/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_refact.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:37:43 by wchumane          #+#    #+#             */
/*   Updated: 2023/10/09 00:53:43 by wchumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*allocate_buffer(size_t i, static int buf_size, char *str)
{
	// allocate according to the number of iteraion
	str = malloc(buf_size + (i * buf_size));
	

	// return a completed allocation
}

char	*get_next_line(int fd)
{
	// declare variables; content, size?
	char	*content;
	char	*temp;
	size_t	i;
	size_t	flag;
	static int	buf_iter;

	// check fd
	if (fd == -1 || fd < 0)
		return (NULL);

	// init variables
	flag = 0;

	// while loop until flag == true, iterate buf_size
	while (flag == 0)
	{
		// allocate memory for buffer [linked list]

		// function: read 1 buffer, return buffer

		// function: check that read 1 buffer is cover all for a 1 line, return flag

		// check flag + iteration
			// if false >> concatenate w/ previous content

	}

	// close by null, next point to null

	// return all content in a file
}
