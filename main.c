
#include "ft_ls.h"
#include <stdio.h>

void        error_msg(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ",2);
	ft_putchar_fd(c,2);
	ft_putendl_fd("\nusage: ft_ls [-latrR] [file ...]\n", 2);
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
			error_msg(str[i]);
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

int     main(int ac, char **av)
{
	t_arg *args;

 	args = (t_arg*)malloc(sizeof(t_arg));
	args->flag = ft_strdup("......");
	(void)ac;
	get_flags(av, &args);
	ft_putstr(args->flag);
	return 0;
	// t_node  *nd;
	// if (ac < 2)
	//     nd = ft_alloc_list(".");
	// else
	//     nd = ft_alloc_list(av[1]);
	// while (nd->next)
	//     {
	//         ft_putstr(nd->perm);
	//         ft_putstr("   ");
	//         ft_putendl(nd->name);
	//         ft_putstr("   ");
	//         nd = nd->next;
	//     }
	return (0);
}