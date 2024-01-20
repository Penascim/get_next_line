/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penascim <penascim@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:42:19 by penascim          #+#    #+#             */
/*   Updated: 2024/01/19 21:10:05 by penascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_backup(char *each_line)
{
	char	*temp;
	int		i;

	i = 0;
	while (each_line[i] != '\n' && each_line[i] != '\0')
		i++;
	if (each_line[i] == '\0')
		return (0);
	temp = ft_substr(each_line, (i + 1), (ft_strlen(each_line) - i));
	if (*temp == '\0')
	{
		free(temp);
		temp = NULL;
	}
	each_line[i + 1] = '\0';
	return (temp);
}

static char	*get_each_line(int fd, char *buffer, char *backup)
{
	char	*temp;
	int		read_return;

	read_return = 1;
	while (read_return != '\0')
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
			return (0);
		else if (read_return == 0)
			break ;
		buffer[read_return] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*each_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	buffer = malloc((sizeof(char) * (BUFFER_SIZE + 1)));
	if (!buffer)
		return (NULL);
	each_line = get_each_line(fd, buffer, backup);
	free(buffer);
	if (!each_line)
		return (NULL);
	backup = gnl_backup(each_line);
	return (each_line);
}
