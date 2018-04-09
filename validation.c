/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:42:00 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/03/17 19:42:00 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			valid(char **row, size_t col_num)
{
	size_t	i;

	i = 0;
	while (row[i])
		i++;
	if (i < col_num)
		return (0);
	return (1);
}
