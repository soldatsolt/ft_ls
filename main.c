/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:47:18 by kmills            #+#    #+#             */
/*   Updated: 2019/05/24 23:12:44 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	struct stat		buf;
	DIR				*dir;
	int				sstat;
	struct timespec	ff;
	struct group	*grp;
	char			*timechar;

	sstat = stat("libft", &buf);
		printf("---------------------------------------------------\n");
	printf("st_atimespec.tv_nsec %30ld\n", buf.st_atimespec.tv_nsec);
		printf("---------------------------------------------------\n");
	printf("st_atimespec.tv_sec %31ld\n", buf.st_atimespec.tv_sec);
		printf("---------------------------------------------------\n");
	printf("st_birthtimespec.tv_nsec %26ld\n", buf.st_birthtimespec.tv_nsec);
		printf("---------------------------------------------------\n");
	printf("st_birthtimespec.tv_sec %27ld\n", buf.st_birthtimespec.tv_sec);
		printf("---------------------------------------------------\n");
	printf("st_blksize %40u\n", buf.st_blksize);
		printf("---------------------------------------------------\n");	
	printf("st_blocks %41llu\n", buf.st_blocks);
		printf("---------------------------------------------------\n");
	printf("st_ctimespec.tv_nsec %30ld\n", buf.st_ctimespec.tv_nsec);
		printf("---------------------------------------------------\n");
	printf("st_ctimespec.tv_sec %31ld\n", buf.st_ctimespec.tv_sec);
		printf("---------------------------------------------------\n");
	printf("st_dev %44u\n", buf.st_dev);
		printf("---------------------------------------------------\n");
	printf("st_flags %42u\n", buf.st_flags);
		printf("---------------------------------------------------\n");
	printf("st_gen %44u\n", buf.st_gen);
		printf("---------------------------------------------------\n");
	printf("st_gid %44u\n", buf.st_gid); // getgrgid - перевод в строку
		printf("---------------------------------------------------\n");
	printf("st_ino %44llu\n", buf.st_ino);
		printf("---------------------------------------------------\n");
	printf("st_lspare %41u\n", buf.st_lspare);
		printf("---------------------------------------------------\n");
	printf("st_mode %43u\n", buf.st_mode);
		printf("---------------------------------------------------\n");
	printf("st_mtimespec.tv_nsec %30ld\n", buf.st_mtimespec.tv_nsec);
		printf("---------------------------------------------------\n");
	printf("st_mtimespec.tv_sec %31ld\n", buf.st_mtimespec.tv_sec); // ctime - перевод в нормальный вид 
		printf("---------------------------------------------------\n");
	printf("st_nlink %42u\n", buf.st_nlink);
		printf("---------------------------------------------------\n");
	printf("st_qspare %41lld\n", (*buf.st_qspare));
		printf("---------------------------------------------------\n");
	printf("st_rdev %43u\n", buf.st_rdev);
		printf("---------------------------------------------------\n");
	printf("st_size %43lld\n", buf.st_size);
		printf("---------------------------------------------------\n");
	printf("st_uid %44u\n", buf.st_uid); // getpwuid - перевод в строку
		printf("---------------------------------------------------\n");
		printf("---------------------------------------------------\n");


	grp = getgrgid(buf.st_gid);

	printf("grp->gr_gid %u\n", grp->gr_gid);
	printf("grp->gr_mem %s\n", grp->gr_mem[0]);
	printf("grp->gr_name %s\n", grp->gr_name);
	printf("grp->gr_passwd %s\n", grp->gr_passwd);

	timechar = ctime(&buf.st_mtimespec.tv_sec);
	printf("---------------------------------------------------\n");
	printf("---------------------------------------------------\n");
	printf("time %47s\n", timechar);
	return (0);
}
