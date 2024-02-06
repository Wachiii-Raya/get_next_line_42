/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <wchumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:35:59 by wchumane          #+#    #+#             */
/*   Updated: 2024/01/21 21:58:37 by wchumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "get_next_line.h"        

// char	*ft_strjoin(char const *s1, char const *s2)

// {
// 	char	*ptr;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	if (!s1 || !s2)			//! recheck this condition
// 		return (ft_strdup(""));
// 	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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

// /* 
// 	get_line: After append the read line based on BUFFER_SIZE to *temp[4096]
// 			 extract 1 line from 2 dimensional array, temp
// 	argument: *temp, *ptr_nl (which is the pointer point to '\n', output form read_line func.)
// 			 , char *line (for return as an output)
// 	output: extracted line
// */
// char	*get_line(char **temp55)
// {
// 	char	*line;
// 	size_t	length;
// 	char	*temp1;
	
// 	length = 0;
// 	while ((*temp55)[length] != '\n')
// 		length++;
// 	line = malloc(sizeof(char *) * (length + 1));
// 	if (!line)
// 		return (NULL);
// 	line = ft_substr(*temp55, 0, length+1);
// 	if (!line)
// 	{
// 		free(line);
// 		return (NULL);		//! Null terminate
// 	}
// 	// TODO: 
// 	temp1 = *temp55;
// 	*temp55 = *temp55 + length;
// 	**temp55 = '\0';
// 	(*temp55)++;
// 	// free(temp1);
// 	return (line);
// }

// /*
// 	read_line: After checking does '\n' exist, and '\n' doese't exist. Then, call 
// 			  this function to loop read(),append read buffer to temp, and check any
// 			  '\n' are included in temp, if found, stop loop and pass the temp to 
// 			  get_line function
// 	argument: fd, temp[fd], buffer
// 	output: ptr_nl
// */
// char	*read_line(int fd, char *temp, char *buffer)
// {
// 	ssize_t	length;
// 	char *temp1;

// 	length = 1;
// 	while (!(ft_strrchr(temp, '\n')) || length <= 0)
// 	{
// 		length = read(fd, buffer, BUFFER_SIZE);
// 		if (length == 0)
// 			return (NULL);
// 		if (length == -1)
// 		{
// 			free(buffer);
// 			return (NULL);		//! Null terminate
// 		}
// 		buffer[length] = '\0';
// 		temp = ft_strjoin(temp, buffer);
// 		if (!temp)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 	}
// 	free(buffer);
// 	return (temp);
// }

// /*
// 	get_next_line: check static *temp[FD_MAX] first, if '\n' is found
// 				   call get_line function, if not -> call read line
// 	argument: fd
// 	output: 1 line
// */
// char	*get_next_line(int fd)
// {
// 	static	char	*temp[4096];		//TODO: change to FD_MAX
// 	char			*buffer;
// 	char			*line;
	
// 	// step 1: check temp, if temp == null -> temp = strdup("")
// 	if (!temp[fd])  //? 
// 		temp[fd] = ft_strdup("");
// 	// step 2: check '\n' in temp
// 	if ((ft_strrchr(temp[fd], '\n')))
// 		return (get_line(&temp[fd]));
// 	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 	{
// 		free(temp[fd]);
// 		return (NULL);
// 	}
// 	temp[fd] = read_line(fd, temp[fd], buffer);
// 	if (temp[fd] == NULL)
// 	{
// 		free(temp[fd]);
// 		free(buffer);
// 		return (NULL);
// 	}
// 	line = get_line(&temp[fd]);
// 	if (!line)
// 	{
// 		free(temp[fd]);
// 		free(buffer);
// 		return (NULL);
// 	}
// 	return (line);
// }

// ---------- test: get_line function --------------
// int	main(void)
// {	
// 	char	temp[20] = "abcd\nfg";
// 	char	*ptr_nl;
// 	char	*line;

// 	ptr_nl = ft_strrchr(temp, '\n');

// 	line = get_line(temp, ptr_nl);
// 	printf("test of get_line, extracted line: %s", line);
// }

// -------- test: read_line function ---------------
// int	main(void)
// {
// 	int		fd;
// 	char	*ptr_nl;
// 	char	temp[20] = "abcdfg";
// 	char	*buffer;
	
// 	fd = open("test.txt", O_RDONLY);
// 	ptr_nl = read_line(fd, temp, buffer);
// 	printf("test of read_line, return pointer to new_line as result: %s", ptr_nl);
// }

// // ------- test: get_next_line function -----------
// int main(void)
// {
// 	int fd;
// 	char	*line;
	
// 	fd = open("temp.txt", O_RDONLY);
	
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("test: %s\n", line);
// 		free(line);
// 	}	
// 	close(fd);
// 	return (0);
// }
