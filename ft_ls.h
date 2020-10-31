#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>

# include <pwd.h>
# include <grp.h>

# include "libft/libft.h"

typedef struct  s_recursive
{
    struct      s_node      *node;
    struct      s_recursive  *next;

}               t_recursive;

typedef struct  s_flags
{
   char        *flags;

}               t_flags;

typedef struct  s_node
{
    int         total;
    char        *name;
    char        *path;
    char        *perm;
    char        *user;
    char        *group;
    char        *uid;
    char        *gid;
    char        *time;
    char        *flags;
    char        *link;
    int         nb_links;
    int         size;
    struct      s_node  *next;
}               t_node;

void            ft_flags(t_flags	*flag);
void            ft_alloc(t_node **nd);
void            ft_get_perm(t_node *nd);
char            ft_file_type(size_t mode);
t_node          *ft_alloc_list(char *path);
void            error_msg(char c);


#endif
