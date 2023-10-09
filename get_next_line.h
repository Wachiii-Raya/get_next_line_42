/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:54:51 by wchumane          #+#    #+#             */
/*   Updated: 2023/10/09 00:21:13 by wchumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef	struct s_node
{
	int		fd;	// or size_t??
	char	*str;
	struct s_node	*next;
}	t_node;

int	buf_size;
buf_size = 20;
