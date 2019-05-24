/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:47:18 by kmills            #+#    #+#             */
/*   Updated: 2019/05/24 22:16:31 by kmills           ###   ########.fr       */
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
	printf("st_atimespec.tv_nsec %ld\n", buf.st_atimespec.tv_nsec);
	printf("st_atimespec.tv_sec %ld\n", buf.st_atimespec.tv_sec);
	printf("st_birthtimespec.tv_nsec %ld\n", buf.st_birthtimespec.tv_nsec);
	printf("st_birthtimespec.tv_sec %ld\n", buf.st_birthtimespec.tv_sec);
	printf("st_blksize %u\n", buf.st_blksize);
	printf("st_blocks %llu\n", buf.st_blocks);
	printf("st_ctimespec.tv_nsec %ld\n", buf.st_ctimespec.tv_nsec);
	printf("st_ctimespec.tv_sec %ld\n", buf.st_ctimespec.tv_sec);
	printf("st_dev %u\n", buf.st_dev);
	printf("st_flags %u\n", buf.st_flags);
	printf("st_gen %u\n", buf.st_gen);
	printf("st_gid %u\n", buf.st_gid);
	printf("st_ino %llu\n", buf.st_ino);
	printf("st_lspare %u\n", buf.st_lspare);
	printf("st_mode %u\n", buf.st_mode);
	printf("st_mtimespec.tv_nsec %ld\n", buf.st_mtimespec.tv_nsec);
	printf("st_mtimespec.tv_sec %ld\n", buf.st_mtimespec.tv_sec);
	printf("st_nlink %u\n", buf.st_nlink);
	printf("st_qspare %lld\n", (*buf.st_qspare));
	printf("st_rdev %u\n", buf.st_rdev);
	printf("st_size %lld\n", buf.st_size);
	printf("st_uid %u\n", buf.st_uid);
	ft_strlen("124");
	return (0);
}
