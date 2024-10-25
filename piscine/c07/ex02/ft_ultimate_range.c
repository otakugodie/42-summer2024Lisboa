/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:33:42 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/08 14:44:49 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;
	int	*buffer;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	buffer = malloc((max - min) * sizeof(int));
	if (!buffer)
	{
		*range = NULL;
		return (-1);
	}
	*range = buffer;
	index = 0;
	while (index < (max - min))
	{
		buffer[index] = min + index;
		index++;
	}
	return ((max - min));
}

/*#include <stdio.h>

int	main(void)
{
	int	min;
	int	max;
	int	*nums;
	int	size;
	int	i;

	i = 0;
	min = -5;
	max = 24;
	size = ft_ultimate_range(&nums, min, max);
	if (size == -1)
		return (1);
	while (i < size)
	{
		printf("%d ", nums[i]);
		i++;
	}
	free(nums);
	printf("\n");
	return (0);
}
 */