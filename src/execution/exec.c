/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:23:27 by baptiste          #+#    #+#             */
/*   Updated: 2024/05/27 00:39:44 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/todo.h"

int list_exec(t_lst *todo)
{
    char *line;
    int fd;

    fd = dup(todo->file_info.file_fd);
    while (1)
    { 
        line = get_next_line(fd);
        if (!line)
            break;
        ft_putstr_fd(1, line);
        free(line);
    }
    free(line);
    close(fd);
    return (SUCCESS);
}

static int add_exec(char **str, t_lst *todo)
{
    int i;
    int num;

    i = 2;
    num = 1;
    if (todo->file_info.file_exist == true)
        num = get_nb_lines(todo) + 1;
    while (str[i])
    {
        ft_printf_fd(todo->file_info.file_fd, "%d [ ] - ", num);
        ft_putstr_fd(todo->file_info.file_fd, str[i]);
        ft_printf_fd(todo->file_info.file_fd, "\n");
        num++;
        i++;
    }
    return (0);
}

int exec_command(char **str, t_lst *todo)
{
    if (todo->option == 1)
        add_exec(str, todo);
    else if (todo->option == 3)
        list_exec(todo);
    return (0);    
}