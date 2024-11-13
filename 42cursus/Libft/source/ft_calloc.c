/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:07:28 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/13 13:22:02 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, (nmemb * size));
	return (array);
}

/* int	main(void)
{
	int		*arr1;
	int		success;
	char	*str;
	int		*arr2;
	int		*arr2;
	int		*arr3;
	int		success;
	int		*single_int;

	// Test 1: Allocate memory for an array of 5 integers
	//and check that each element is 0
	arr1 = (int *)ft_calloc(5, sizeof(int));
	printf("Test 1: ");
	if (arr1)
	{
		success = 1;
		for (int i = 0; i < 5; i++)
		{
			if (arr1[i] != 0)
			{
				success = 0;
				break ;
			}
		}
		printf("%s\n", success ? "Success" : "Failure");
	}
	free(arr1);
	// Test 2: Allocate memory for a string of 10 characters
	//and check each byte is 0
	str = (char *)ft_calloc(10, sizeof(char));
	printf("Test 2: ");
	if (str && ft_memcmp(str, "\0\0\0\0\0\0\0\0\0\0", 10) == 0)
		printf("Success\n");
	else
		printf("Failure\n");
	free(str);
	// Test 3: Edge case, 0 elements
	arr2 = (int *)calloc(0, sizeof(int));
	printf("Test 3: %s\n", arr2 == NULL ? "Success (NULL)" : "Failure");
	free(arr2);
	// Test 3: Edge case, 0 elements
	arr2 = (int *)ft_calloc(0, sizeof(int));
	printf("Test 3: %s\n",
		//arr2 == NULL ? "NULL (as expected on some implementations)" :
		//"Non-NULL (also correct on some implementations)");
	free(arr2);
	// Test 4: Large allocation to see if it handles memory requests correctly
	arr3 = (int *)ft_calloc(1000, sizeof(int));
	printf("Test 4: ");
	if (arr3)
	{
		success = 1;
		for (int i = 0; i < 1000; i++)
		{
			if (arr3[i] != 0)
			{
				success = 0;
				break ;
			}
		}
		printf("%s\n", success ? "Success" : "Failure");
	}
	free(arr3);
	// Test 5: Allocate memory for a single integer and verify
	//it's initialized to 0
	single_int = (int *)ft_calloc(1, sizeof(int));
	printf("Test 5: ");
	if (single_int && *single_int == 0)
		printf("Success\n");
	else
		printf("Failure\n");
	free(single_int);
	return (0);
}
 */