/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedList.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:37:19 by diegfern          #+#    #+#             */
/*   Updated: 2025/07/28 18:04:54 by diegfern         ###   ########.fr       */
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

int main (void){

	t_linkedList *a;
	t_linkedList *b;
	t_linkedList n1;
	t_linkedList n2;
	t_linkedList n3;
	t_linkedList n4;
	t_linkedList n5;
	t_linkedList n6;

	a = &n1;
	b = NULL;

	n1.value = 42;
	n1.index = -1;
	n1.next = &n2;

	n2.value = -5;
	n2.index = -1;
	n2.next = &n3;

	n3.value = 17;
	n3.index = -1;
	n3.next = &n4;

	n4.value = 55;
	n4.index = -1;
	n4.next = &n5;

	n5.value = -42;
	n5.index = -1;
	n5.next = &n6;

	n6.value = -65;
	n6.index = -1;
	n6.next = NULL;

	return (0);
}