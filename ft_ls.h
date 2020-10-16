/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:44:16 by yoelguer          #+#    #+#             */
/*   Updated: 2020/01/31 00:05:48 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
    char    *name;
    char    *path;
    char    *perm;
    char    *uid;
    char    *gid;
    char    *time;
    char    *link;
    int     size;
    int     blink;
    struct  s_node  *next;
}              t_node;

typedef struct s_arg
{
    char    *flag;
    char    *name;
    struct  s_arg  *next;
}              t_arg;

void    ft_alloc(t_node **nd);
void    ft_get_perm(t_node *nd);
char    ft_file_type(size_t mode);
t_node      *ft_alloc_list(char *path);
void        error_msg(char c);

#endif
