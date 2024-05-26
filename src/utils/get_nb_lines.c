/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:27:17 by baptiste          #+#    #+#             */
/*   Updated: 2024/05/27 00:42:33 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/todo.h"

int get_nb_lines(t_lst *todo)
{
    int fd;
    int count;
    char *line;

    if (!todo)
        return (ERROR);
    fd = dup(todo->file_info.file_fd);
    count = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        count++;
        free(line);
    }
    free(line);
    close(fd);
    return (count);
}