/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:07:55 by baptiste          #+#    #+#             */
/*   Updated: 2024/05/27 00:33:33 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/todo.h"

void init_file(t_lst **todo)
{
    (*todo)->file_info.filename = ".todo";
    if (access((*todo)->file_info.filename, F_OK) != -1)
    {
        (*todo)->file_info.file_fd = open((*todo)->file_info.filename, O_RDWR | O_APPEND, 0640);
        (*todo)->file_info.file_exist = true;
    }
    else
    {
        (*todo)->file_info.file_fd = open((*todo)->file_info.filename, O_RDWR | O_CREAT | O_TRUNC, 0640);
        (*todo)->file_info.file_exist = false;
    }
}


int init_stuff(t_lst *todo)
{
    init_file(&todo);   
    return (0);
}