/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <wchumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:19:08 by wchumane          #+#    #+#             */
/*   Updated: 2023/12/26 01:12:43 by wchumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#define BUFFER_SIZE 255


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
typedef	struct s_node
{
	char	*str;
	struct s_node	*next;
}	t_node;

#endif

