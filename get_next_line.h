/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <wchumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:30:20 by wchumane          #+#    #+#             */
/*   Updated: 2024/01/21 18:00:41 by wchumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_line(char **temp);
char	*read_line(int fd, char *temp, char *buffer);
char	*get_next_line(int fd);


# endif