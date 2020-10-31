
#include "ft_ls.h"

char    ft_file_type(size_t mode)
{
    if (S_ISFIFO(mode))
        return ('p');
    else if (S_ISSOCK(mode))
        return ('s');
    else if (S_ISLNK(mode))
        return ('l');
    else if (S_ISBLK(mode))
        return ('b');
    else if (S_ISDIR(mode))
        return ('d');
    else if (S_ISCHR(mode))
        return ('c');
    return ('-');
}

void    ft_get_perm(t_node *nd)
{
    struct stat data;

    lstat(nd->path, &data);
    nd->perm[0] = ft_file_type(data.st_mode);
    if (data.st_mode & S_IRUSR)
        nd->perm[1] = 'r';
    if (data.st_mode & S_IWUSR)
        nd->perm[2] = 'w';
    if (data.st_mode & S_IXUSR)
        nd->perm[3] = 'x';
    if (data.st_mode & S_IRGRP)
        nd->perm[4] = 'r';
    if (data.st_mode & S_IWGRP)
        nd->perm[5] = 'w';
    if (data.st_mode & S_IXGRP)
        nd->perm[6] = 'x';
    if (data.st_mode & S_IROTH)
        nd->perm[7] = 'r';
    if (data.st_mode & S_IWOTH)
        nd->perm[8] = 'w';
    if (data.st_mode & S_IXOTH)
        nd->perm[9] = 'x';

}

void    ft_alloc(t_node **nd)
{
    *nd = (t_node*)malloc(sizeof(t_node));
    (*nd)->perm = ft_strdup("----------");
    (*nd)->next = NULL;
}
void    ft_size(t_node *nd)
{
    struct stat data;
    lstat(nd->path, &data);
    nd->size = data.st_size;
}

int    ft_get_stats(t_node *nd)
{
    struct stat data;
    struct passwd *user;
    struct group *grp;
    lstat(nd->path, &data);
    user = getpwuid(data.st_uid);
    grp = getgrgid(data.st_gid);
    nd->nb_links = data.st_nlink;
    nd->user = user->pw_name;
    nd->group = grp->gr_name;

    return ((int)data.st_blocks);
}

t_node      *ft_alloc_list(char *path)
{
    DIR *dr;
    t_node *nd;
    t_node *head;
    struct dirent *dir;

    ft_alloc(&nd);
    head = nd;
    head->total = 0;
    if (!(dr = opendir(path)))
        return NULL;
    while ((dir = readdir(dr)) != NULL)
    {
        nd->name = ft_strdup(dir->d_name);
        nd->path = ft_strjoin(path, "/");
        nd->path = ft_strjoin(nd->path, dir->d_name);
        ft_get_perm(nd);
        ft_size(nd);
        head->total += ft_get_stats(nd);
        ft_alloc(&nd->next);
        nd = nd->next;
    }
    return (head);
}
