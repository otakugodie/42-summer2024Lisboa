/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:24:09 by diegfern          #+#    #+#             */
/*   Updated: 2024/12/03 18:11:23 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_print_char(char c, long int *counter);
void	ft_print_str(char *str, long int *counter);
void	ft_print_num(long int n, long int *counter);
void	ft_print_hex_upper(unsigned long int n, long int *counter);
void	ft_print_hex_lower(unsigned long int n, long int *counter);
void	ft_print_ptr(void *ptr, long int *counter);
void	ft_parser_args(char type_arg, va_list ap, long int *counter);

#endif