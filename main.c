
#include "ft_ls.h"
#include <stdio.h>

void        error_msg(char c)
{
	ft_putstr_fd("ft_ls: illegal option : ",2);
	ft_putchar_fd(c,2);
	ft_putendl_fd(" :\nusage: ft_ls [-latrR] [file ...]\n", 2);
	exit(0);
}

static int  check_flag(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a' || str[i] == 'l' ||
		 str[i] == 't' || str[i] == 'r' || str[i] == 'R')
			return (1);
		else
			{
				error_msg(str[i]);
				exit(0);
			}
		i++;
	}
	return (0);
}

void	get_flags(char **av, t_arg **arg)
{
	int i;
	int j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] == '-' && check_flag(&av[j][i + 1]))
			{

				(*arg) = (*arg)->next;
			}
			i++;
		}
		j++;
	}
}
int		path_or_flags(char *av)
{
	DIR *dr;
	if ((dr = opendir(av)) == NULL)
		return (0);
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

void	ft_print_ls(t_node  *nd)
{
		ft_putendl("total ");
		while (nd->next)
	    {
	        ft_putstr(nd->perm);
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
	t_arg *args;
	t_node  *nd;

 	args = (t_arg*)malloc(sizeof(t_arg));
	args->flag = ft_strdup("......");
	if (ac < 2)
	{
		nd = ft_alloc_list(".");
		ft_print(nd);
	}
	else
	{
		if (path_or_flags(av[1]) == 0)
			{
				if (av[1][0] != '-' || (av[1][0] == '-' && check_flag(&av[1][1]) != 1))
					error_msg(av[1][0]);
				nd = ft_alloc_list(".");
			}
		else
	    	nd = ft_alloc_list(av[1]);
			ft_print_ls(nd);
	}

	return (0);
}
