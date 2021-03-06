/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:20:36 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/10/21 09:30:01 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		while (*s1 == *s2 && *s1 && *s2)
		{
			++s1;
			++s2;
		}
		if (*s1 == '\0' && *s2 == '\0')
			return (1);
	}
	return (0);
}
