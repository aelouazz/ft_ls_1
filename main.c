
#include "ft_ls.h"
#include <stdio.h>

void        error_msg(char c)
{
	ft_putstr_fd("ft_ls: illegal option : ",2);
	ft_putchar_fd(c,2);
	ft_putendl_fd(" :\nusage: ft_ls [-latrR] [file ...]\n", 2);
	exit(0);
}
void        error_msg_diroctory(char *str)
{
	ft_putstr_fd(str,2);
	ft_putstr_fd(": No such file or directory",2);
}

static int  check_flag(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a' || str[i] == 'l' ||
		 str[i] == 't' || str[i] == 'r' || str[i] == 'R')
			i++;
		else
			{
				error_msg(str[i]);
				exit(0);
			}
	}
	return (0);
}

void	get_flags(char **av, t_node  *nd)
{
	int i;
	int j;
	int k;

	j = 1;
	k = 0;
	nd->flags = ft_strdup("\0");
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] == '-' && check_flag(&av[j][i + 1]) == 0)
			{
				while (av[j][i + 1])
				{
					nd->flags[k] = av[j][i + 1];
					k++;
					i++;
				}
			}
			i++;
		}
		j++;
	}
	nd->flags[k] = '\0';
}

int		path_or_flags(char *av)
{
	if ((opendir(av) == NULL))
			{
				error_msg_diroctory(av);
				return (0);
			}
	return (1);
}

void	ft_print(t_node  *nd)
{
	while (nd->next)
	    {
			if (nd->name[0] == '.')
			 	nd = nd->next;
			else
			{
			ft_putstr(nd->name);
	        ft_putstr("   ");
			nd = nd->next;
			}
		}
		ft_putstr("\n");
}

void	ft_print_a(t_node  *nd)
{
	while (nd->next)
	    {
			ft_putstr(nd->name);
	        ft_putstr("   ");
			nd = nd->next;
		}
		ft_putstr("\n");
}

void	ft_print_ls(t_node  *nd)
{
		ft_putstr("total ");
		ft_putnbr(nd->total);
		ft_putendl("");
		while (nd->next)
	    {
	        ft_putstr(nd->perm);
	        ft_putstr("   ");
			ft_putnbr(nd->nb_links);
			ft_putstr("   ");
			ft_putstr(nd->user);
			ft_putstr("   ");
			ft_putstr(nd->group);
			ft_putstr("   ");
			ft_putnbr(nd->size);
	        ft_putstr("   ");
			ft_putendl(nd->name);
	        nd = nd->next;
	    }
		ft_putstr("\n");
}

int     main(int ac, char **av)
{
	int 	i;
	t_node  *nd;
	
	nd = NULL;
	i = 1;
	if (ac < 2)
	{
		nd = ft_alloc_list(".");
		ft_print(nd);
	}
	else
	{
		if (path_or_flags(av[1]) == 0)
			{
				while (i < ac)
					{
						if (av[i][0] != '-' || (av[i][0] == '-' && check_flag(&av[1][1]) != 0)  || 
						(av[i][0] == '-'  && av[i][1] == '\0'))
							error_msg(av[1][0]);
						else
							i++;
					}	
				nd = ft_alloc_list(".");
				get_flags(av, nd);	
				ft_print_ls(nd);
			}
		else
	    	{
				nd = ft_alloc_list(av[1]);
				ft_print_ls(nd);
			}
	}
	ft_putendl("*****************");
	ft_putendl(nd->flags);
	return (0);
}

