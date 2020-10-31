#include "ft_ls.h"

//starting fags here 

int  flag_return(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
            return (1);
        i++;
	}
	return (0);
}

void    recursive_ls(t_flags	*flag)
{
    t_recursive  *rc;

    rc = (t_recursive*)malloc(sizeof(t_recursive));
    flag = NULL;
}
void    list_l(t_flags	*flag)
{
    flag = NULL;
    return;
}
void    list_normal(t_flags	*flag)
{
    flag = NULL;
    return;
}

void    ft_flags(t_flags	*flag)
{
    if (flag_return('R', flag->flags) == 1)
        recursive_ls(flag);
    if (flag_return('l', flag->flags) == 1)
        list_l(flag);
    if (flag_return('a', flag->flags) == 1 || 
        flag_return('r', flag->flags) == 1 || 
        flag_return('t', flag->flags) == 1 )
        list_normal(flag);
}