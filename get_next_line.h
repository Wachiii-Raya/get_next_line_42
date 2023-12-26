/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <wchumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:19:08 by wchumane          #+#    #+#             */
/*   Updated: 2023/12/26 16:19:26 by wchumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
# endif


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef	struct s_list
{
	char	*str;
	struct s_list	*next;
}	t_list;

char	*ft_strjoin(char const *s1, char const *s2);
int	is_newline_found(char *buffer);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s1);
void	*free_all_node(t_list **node);
char	*convert_list_to_line(t_list *node);
void	append_buffer_to_node(t_list **str, char *buffer);
void	*read_buffer(char *temp, int fd);
char	*get_next_line(int fd);

#endif

