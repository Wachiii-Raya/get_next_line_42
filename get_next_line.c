/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchumane <wchumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:35:59 by wchumane          #+#    #+#             */
/*   Updated: 2024/02/09 18:21:04 by wchumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)			//! recheck this condition
		return (ft_strdup(""));
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	free(s1);
	return (ptr);
}


/*
	clear_arr:  clear the result out of static str_arr and return
			    the current str_arr
	arguments: str_arr, length_nl
	output: 	current str_arr
*/
char	*clear_array(char *str, size_t length)
{
	// char	*ptr;
	char	*current_arr;
	size_t	length_new;
	size_t	length_max;
	size_t	i;

	// ptr = str;
	i = 0;
	length_max = ft_strlen(str);
	length_new = length_max - length;
	current_arr = malloc(sizeof(char *) * (length_new + 1));
	if (!current_arr)
	{
		free(str);
		return (NULL);
	}
	while (i < length_new)
	{
		current_arr[i] = str[length + i + 1];
		i++;
	}
	current_arr[i] = '\0';
	free(str);
	return (current_arr);
}

/*
	read_line: After checking does '\n' exist, and '\n' doese't exist. Then, call 
			  this function to loop read(),append read buffer to temp, and check any
			  '\n' are included in temp, if found, stop loop and pass the temp to 
			  get_line function
	argument: fd, temp[fd], buffer
	output: ptr_nl
*/
char	*read_line(int fd, char *str_array, char *buffer)
{
	ssize_t	length;

	// if (!(str_array))
	// 	str_array = ft_strdup("");
	length = 1;
	while((!(ft_strrchr(str_array, '\n'))) && (length > 0))
	{
		length = read(fd, buffer, BUFFER_SIZE);
		if (length == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[length] = '\0';
		str_array = ft_strjoin(str_array, buffer);
		if (!str_array)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (str_array);
}

/*
	get_next_line: check static *temp[FD_MAX] first, if '\n' is found
				   call get_line function, if not -> call read line
	argument: fd
	output: 1 line
*/
char	*get_next_line(int fd)
{
	static char	*str_arr[4096];
	char	*result;
	char	*buffer;
	size_t	length_nl;

	length_nl = 0;
	// step 1: check basic condition
	if ((BUFFER_SIZE <= 0) || (fd < 0) || (read(fd, NULL, 0) == -1))
	{
		if (str_arr[fd])
		{
			free(str_arr[fd]);
			str_arr[fd] = NULL;
			return (NULL);
		}
		return (NULL);
	}
	// step 2: check empty str_arry[fd]
	if (!(str_arr[fd]))
		str_arr[fd] = ft_strdup("");
	// step 3: while loop read buffer until found '\n' or end file
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	str_arr[fd] = read_line(fd, str_arr[fd], buffer);
	// step 4: copy until found '/n'
	if (ft_strlen(str_arr[fd]) > 0)
	{
		while ((str_arr[fd][length_nl] != '\n') && (str_arr[fd][length_nl] != '\0'))
			length_nl++;
		result = malloc(sizeof(char *) * (length_nl + 2));
		if (!result)
		{
			free(str_arr[fd]);
			str_arr[fd] = NULL;
			return (NULL);
		}
	}
	else
	{
		free(str_arr[fd]);
		str_arr[fd] = NULL;
		return (NULL);
	}
	ft_strlcpy(result, str_arr[fd], length_nl + 2);
	result[length_nl + 2] = '\0';
	str_arr[fd] = clear_array(str_arr[fd], length_nl);
	return (result);
}

// ------------ test: get_next_line function -----------
// int main(void)
// {
// 	int 	fd;
// 	char	*line;
	
// 	fd = open("temp.txt", O_RDONLY);
	
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("test_none: %s\n", line);
// 		free(line);
// 	}	
// 	close(fd);
// 	return (0);
// }

// -------- test: read_line function ---------------
// int	main(void)
// {
// 	int		fd;
// 	char	*ptr_nl;
// 	char	temp[20] = "abcdfg";
// 	char	*buffer;
	
// 	fd = open("test.txt", O_RDONLY);
//     buffer = malloc(0);
// 	ptr_nl = read_line(fd, temp, buffer);
// 	printf("test of read_line, return pointer to new_line as result: %s", ptr_nl);
// }

// -------- test: clear_arr function ---------------
// int	main(void)
// {
// 	char	*str_arr = "hello\nsleepy ooo";
// 	int		length_nl;
// 	char 	*result;

// 	length_nl = 0;
// 	while (str_arr[length_nl] != '\n')
// 			length_nl++;
// 	str_arr = clear_arr(str_arr, length_nl);
// }