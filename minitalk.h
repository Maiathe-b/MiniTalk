/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:44:33 by jomaia            #+#    #+#             */
/*   Updated: 2025/08/20 16:45:30 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include "signal.h"
# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"

typedef struct s_var
{
	char	*str;
	char	c;
	int		len;
	int		i;
	int		bits_len;
	int		pos;
}	t_var;

#endif