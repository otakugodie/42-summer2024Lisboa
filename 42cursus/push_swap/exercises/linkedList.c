/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedList.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:37:19 by diegfern          #+#    #+#             */
/*   Updated: 2025/07/27 17:49:29 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// [#, &siguiente_nodo]

typedef struct s_linkedList
{
	int value;
	int index;
	struct s_linkedList *next;

} t_linkedList;


//Radix algorithm