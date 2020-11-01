
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
	ft_putstr_fd(": No such file or directory\n",2);
}

static int  check_flag(char *str)
{
	int i;

	i = 0;
	if ((opendir(str) != NULL))
		return (0);
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

int		path_or_flags(char **av)
{
	int i;

	i = 1;
	if ((opendir(av[i]) != NULL))
			{
				while ((opendir(av[i]) != NULL))
					{
						i++;
						if ((opendir(av[i]) == NULL) && av[i])
							error_msg_diroctory(av[i]);
					}
				return (1);
			}
	return (0);
}
size_t		ft_biggest_name_charachters(t_node *nd)
{
	size_t	count;

	count = 0;
	while (nd->next)
	    {
			if (count < ft_strlen(nd->name))
				count = ft_strlen(nd->name);
			nd = nd->next;
		}
	return (count);
}
void	ft_print(t_node  *nd, int ac)
{
	size_t i;
	int		j;
	size_t biggest;

	j = 1;
	biggest = ft_biggest_name_charachters(nd);
	while (nd->next)
	    {
			if (nd->name[0] == '.')
			 	nd = nd->next;
			else
			{
				i = 0;
				ft_putstr(nd->name);
				while (ft_strlen(nd->name) + i <= biggest)
				{
					ft_putstr(" ");
					i++;
				}
				if (j % 8 == 0  && ac >= 2)
					ft_putstr("\n");
				j++;
				nd = nd->next;
			}
		}
		ft_putstr("\n");
}

void	ft_print_a(t_node  *nd)
{
	size_t i;
	int		j;
	size_t biggest;

	j = 1;
	biggest = ft_biggest_name_charachters(nd);
	while (nd->next)
	    {
			i = 0;
			ft_putstr(nd->name);
			while (ft_strlen(nd->name) + i <= biggest)
			{
				ft_putstr(" *");
				i++;
			}
			if (j % 8 == 0)
					ft_putstr("\n");
			j++;
			nd = nd->next;
		}
		ft_putstr("\n");
}
size_t	biggest_link(t_node  *nd)
{
	size_t i;
	
	i = 0;
	while (nd->next)
	{
		if (i <= ft_strlen(ft_itoa(nd->nb_links)))
			i = ft_strlen(ft_itoa(nd->nb_links));
			nd = nd->next;
	}
	return (i);
}
size_t	biggest_size(t_node  *nd)
{
	size_t i;
	
	i = 0;
	while (nd->next)
	{
		if (i <= ft_strlen(ft_itoa(nd->size)))
			i = ft_strlen(ft_itoa(nd->size));
			nd = nd->next;
	}
	return (i);
}
void	ft_print_ls(t_node  *nd)
{
		size_t nb;
		size_t sz;
		size_t i;

		nb = biggest_link(nd);
		sz = biggest_size(nd);
		ft_putstr("total ");
		ft_putnbr(nd->total);
		ft_putendl("");
		while (nd->next)
	    {
			i = 0;
	        ft_putstr(nd->perm);
	        while ((i++ + ft_strlen(ft_itoa(nd->nb_links))) <= nb)
				ft_putstr(" ");
			ft_putnbr(nd->nb_links);
			ft_putstr(" ");
			ft_putstr(nd->user);
			ft_putstr("  ");
			ft_putstr(nd->group);
			i = 0;
			ft_putstr(" ");
			while ((i++ + ft_strlen(ft_itoa(nd->size))) <= nb)
				ft_putstr(" ");
			ft_putnbr(nd->size);
			ft_putchar(nd->SZ);
			ft_putstr(" ");
			if ( nd->year != 2020)
				ft_putnbr(nd->year);
			else
				ft_putstr(nd->date);
			ft_putstr(" ");
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
		ft_print(nd, ac);
	}
	else
	{
		if (path_or_flags(av) == 0)
			{
				while (i < ac)
					{
						if (av[i][0] != '-' || (av[i][0] == '-' && check_flag(&av[i][1]) != 0)  || 
						(av[i][0] == '-'  && av[i][1] == '\0'))
							error_msg(av[i][0]);
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
	return (0);
}

