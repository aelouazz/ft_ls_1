/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:09:23 by yoelguer          #+#    #+#             */
/*   Updated: 2019/04/18 00:05:07 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;
	char	*p_s2;

	i = 0;
	j = 0;
	p_s2 = (char*)s2;
	while (s1[i] != '\0')
	{
		i++;
	}
	while (p_s2[j] != '\0' && j < n)
	{
		s1[i] = p_s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
