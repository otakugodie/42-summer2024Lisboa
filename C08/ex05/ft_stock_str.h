/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:33:56 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/10 01:34:22 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_STACK_STR_H
# define FT_STACK_STR_H

typedef struct s_stock_str
{
int size;
char *str;
char *copy;
} t_stock_str;

#endif