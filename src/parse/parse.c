/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:47:02 by baptiste          #+#    #+#             */
/*   Updated: 2024/05/27 00:25:06 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/todo.h"

int get_user_args(char **str, t_lst *todo)
{
    if (!str)
        return (NOT_FOUND);
    if (!strncmp(str[1], "add", 3) && strlen(str[1]) == 3)
    {
        todo->option = 1;
        return (FOUND);
    }
    else if (!strncmp(str[1], "delete", 6) && strlen(str[1]) == 6)
    {
        todo->option = 2;
        return (FOUND);
    }
    else if (!strncmp(str[1], "list", 4) && strlen(str[1]) == 4)
    {
        todo->option = 3;
        return (FOUND);
    }
    else if (!strncmp(str[1], "done", 4) && strlen(str[1]) == 4)
    {
        todo->option = 4;
        return (FOUND);
    }
    else if (!strncmp(str[1], "reset", 5) && strlen(str[1]) == 5)
    {
        todo->option = 5;
        return (FOUND);
    }
    return (NOT_FOUND);
}