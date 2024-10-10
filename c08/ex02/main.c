/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:01:25 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/09 10:38:44 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_abs.h"
#include <stdio.h>

int	main(void)
{
	int	value;
	int	absolute;

	value = -20;
	absolute = ABS(value);
	printf("%d\n", absolute);
	return (0);
}
