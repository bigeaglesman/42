/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:44:50 by ycho2             #+#    #+#             */
/*   Updated: 2024/01/23 19:12:47 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		ft_conversion(char c, va_list ap);

int		ft_printf_char(va_list ap);
int		ft_printf_str(va_list ap);
int		ft_printf_addr(va_list ap);
int		ft_printf_dec(va_list ap);
int		ft_printf_u_dec(va_list ap);
int		ft_printf_hex(char c, va_list ap);

char	*ft_uitoa(unsigned int n);

int		ft_printf(const char *string, ...);

#endif