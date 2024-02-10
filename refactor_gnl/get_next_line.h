/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <wchumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:07:31 by wchumane          #+#    #+#             */
/*   Updated: 2024/02/10 21:59:15 by wchumane         ###   ########.fr       */
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


size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strrchr(const char *s, int c);
char		*clone_case(int case_num,char **str_arr, int fd);
char		*ft_strjoin(char *s1, char const *s2);
char		*clear_array(char *str, size_t length);
char		*read_line(int fd, char *str_array, char *buffer);
char		*get_next_line(int fd);
char		*gnl_init(char	**str_arr, int fd);



# endif