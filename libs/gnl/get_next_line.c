/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:14:17 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/03 16:41:21 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*clean_stash_buf(char **buffer, char **stash)
{
	free(*buffer);
	*buffer = NULL;
	free(*stash);
	*stash = NULL;
	return (NULL);
}

int	extract_line(char **stash, char **line)
{
	char	*temp;
	int		nl_pos;

	nl_pos = search_newline(*stash);
	if (nl_pos >= 0)
	{
		*line = gnl_substr(*stash, 0, nl_pos + 1);
		temp = gnl_substr(*stash, nl_pos + 1, gnl_strlen(*stash) - nl_pos - 1);
		free(*stash);
		*stash = temp;
		return (1);
	}
	return (0);
}

void	check_eof(int bytes_read, char **stash, char **line)
{
	if (bytes_read == 0)
	{
		if (*stash && **stash != 0)
			*line = gnl_strdup(*stash);
		else
			*line = NULL;
		free(*stash);
		*stash = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	int			bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (clean_stash_buf(&buffer, &stash));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (clean_stash_buf(&buffer, &stash));
		buffer[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buffer);
		if (extract_line(&stash, &line))
			break ;
		check_eof(bytes_read, &stash, &line);
	}
	free(buffer);
	return (line);
}
