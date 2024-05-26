/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:27:46 by baptiste          #+#    #+#             */
/*   Updated: 2024/05/27 00:46:27 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TODO_H
# define TODO_H

#	include <readline/readline.h>
#	include "colors.h"
#	include <stdlib.h> 
#	include <stdio.h>
#	include <unistd.h>
#	include <fcntl.h>
#	include <limits.h>
#	include <stdbool.h>
#	include <signal.h>

#define ERROR 1
#define SUCCESS 0
#define NOT_FOUND -10
#define FOUND 10

typedef enum s_opt
{
	ADD,
	DELETE,
	LIST,
	DONE,
	RESET,
}	t_opt;

typedef struct s_file
{
	char *filename;
	int file_fd;
	bool file_exist;
}	t_file;

typedef struct s_lst
{
	bool condition;
	t_opt option;
	t_file file_info;
}	t_lst;

/*FUNCTIONS*/
int get_user_args(char **str, t_lst *todo);
int init_stuff(t_lst *todo);
int exec_command(char **str, t_lst *todo);
int list_exec(t_lst *todo);


/*UTILS*/
int ft_strlen(char *str);
int ft_putstr_fd(int fd, char *str);
int ft_strlen(char *str);
char	*ft_itoa(int n);
int	ft_printf_fd(int fd, const char *format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_next_line(int fd);
int get_nb_lines(t_lst *todo);
void print_banner(void);

# endif