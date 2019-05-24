/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:47:18 by kmills            #+#    #+#             */
/*   Updated: 2019/05/24 22:27:14 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	struct stat	buf;
	DIR			*dir;
	int			sstat;
	struct timespec	ff;

	sstat = stat("libft", &buf);
	printf("st_atimespec.tv_nsec %30ld\n", buf.st_atimespec.tv_nsec);
	printf("st_atimespec.tv_sec %31ld\n", buf.st_atimespec.tv_sec);
	printf("st_birthtimespec.tv_nsec %26ld\n", buf.st_birthtimespec.tv_nsec);
	printf("st_birthtimespec.tv_sec %27ld\n", buf.st_birthtimespec.tv_sec);
	printf("st_blksize %40u\n", buf.st_blksize);
	printf("st_blocks %41llu\n", buf.st_blocks);
	printf("st_ctimespec.tv_nsec %30ld\n", buf.st_ctimespec.tv_nsec);
	printf("st_ctimespec.tv_sec %31ld\n", buf.st_ctimespec.tv_sec);
	printf("st_dev %44u\n", buf.st_dev);
	printf("st_flags %42u\n", buf.st_flags);
	printf("st_gen %44u\n", buf.st_gen);
	printf("st_gid %44u\n", buf.st_gid);
	printf("st_ino %44llu\n", buf.st_ino);
	printf("st_lspare %41u\n", buf.st_lspare);
	printf("st_mode %43u\n", buf.st_mode);
	printf("st_mtimespec.tv_nsec %30ld\n", buf.st_mtimespec.tv_nsec);
	printf("st_mtimespec.tv_sec %31ld\n", buf.st_mtimespec.tv_sec);
	printf("st_nlink %42u\n", buf.st_nlink);
	printf("st_qspare %41lld\n", (*buf.st_qspare));
	printf("st_rdev %43u\n", buf.st_rdev);
	printf("st_size %43lld\n", buf.st_size);
	printf("st_uid %44u\n", buf.st_uid);
	ft_strlen("124");
	return (0);
}
