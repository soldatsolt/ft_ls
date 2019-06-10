/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:46:27 by kmills            #+#    #+#             */
/*   Updated: 2019/06/10 23:20:12 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libft/libft.h"
# include <sys/stat.h>
# include <sys/xattr.h>
# include <time.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <uuid/uuid.h>

/*
**F_A - flag А (uppercase)|| F_A_ - flag a (lowercase)
*/
# define F_SOBAKA 0x1
# define F_1 0x2
# define F_A 0x4
# define F_A_ 0x8
# define F_B 0x10
# define F_B_ 0x20
# define F_C 0x40
# define F_C_ 0x80
# define F_D_ 0x100
# define F_E_ 0x200
# define F_F 0x400
# define F_F_ 0x800
# define F_G 0x1000
# define F_G_ 0x2000
# define F_H 0x4000
# define F_H_ 0x8000
# define F_I_ 0x10000
# define F_K_ 0x20000
# define F_L 0x40000
# define F_L_ 0x80000
# define F_M_ 0x100000
# define F_N_ 0x200000
# define F_O 0x400000
# define F_O_ 0x800000
# define F_P 0x1000000
# define F_P_ 0x2000000
# define F_Q_ 0x4000000
# define F_R 0x8000000
# define F_R_ 0x10000000
# define F_S 0x20000000
# define F_S_ 0x40000000
# define F_T 0x80000000
# define F_T_ 0x100000000
# define F_U_ 0x200000000
# define F_U 0x400000000
# define F_V_ 0x800000000
# define F_W 0x1000000000
# define F_W_ 0x2000000000
# define F_X_ 0x4000000000

typedef struct	s_ls
{
	u_int64_t	f;
}				t_ls;

#endif
