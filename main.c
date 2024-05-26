/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:27:17 by baptiste          #+#    #+#             */
/*   Updated: 2024/05/27 01:01:12 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/todo.h"

int main(int argc, char **argv)
{
    t_lst *todo;

    (void)argc;
    todo = calloc(1, sizeof(t_lst));
    init_stuff(todo);
    if (argc < 2)
    {
        list_exec(todo);
        return (0);
    }
    if (get_user_args(argv, todo) == NOT_FOUND)
        return (ERROR);
    exec_command(argv, todo);
    close(todo->file_info.file_fd);
    return (0);
}