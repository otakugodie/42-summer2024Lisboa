/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:26:15 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 12:40:18 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (*str)
	{
		while (*str != '\0')
		{
			str++;
			i++;
		}
	}
	return (i);
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size){
    
}



int	main(void)
{
    
	return (0);
}