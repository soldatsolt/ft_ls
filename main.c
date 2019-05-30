/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:47:18 by kmills            #+#    #+#             */
/*   Updated: 2019/05/28 05:58:31 by kmills           ###   ########.fr       */
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
	char			*mtime;
	char			*birthtime;
	char			*atime;
	char			*ctimespec;
	struct passwd	*pwd;

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

	atime = ctime(&buf.st_atimespec.tv_sec);
	birthtime = ctime(&buf.st_birthtimespec.tv_sec);
	ctimespec = ctime(&buf.st_ctimespec.tv_sec);
	mtime = ctime(&buf.st_mtimespec.tv_sec);
		printf("---------------------------------------------------\n");
		printf("---------------------------------------------------\n");
	printf("atime %46s\n", atime);
		printf("---------------------------------------------------\n");
	printf("birthtime %42s\n", birthtime);
		printf("---------------------------------------------------\n");
	printf("ctime %46s\n", ctimespec);
		printf("---------------------------------------------------\n");
	printf("mtime %46s\n", mtime);
		printf("---------------------------------------------------\n");
		printf("---------------------------------------------------\n");


	pwd = getpwuid(buf.st_uid);
	printf(">pw_change %40ld\n", pwd->pw_change);
		printf("---------------------------------------------------\n");
	printf("pw_class %38s\n", pwd->pw_class);
		printf("---------------------------------------------------\n");
	printf("pw_dir %44s\n", pwd->pw_dir);
		printf("---------------------------------------------------\n");
	printf("pw_expire %41ld\n", pwd->pw_expire);
		printf("---------------------------------------------------\n");
	printf("pw_gecos %42s\n", pwd->pw_gecos);
		printf("---------------------------------------------------\n");
	printf("pw_gid %44u\n", pwd->pw_gid);
		printf("---------------------------------------------------\n");
	printf("pw_name %43s\n", pwd->pw_name);
		printf("---------------------------------------------------\n");
	printf("pw_passwd %41s\n", pwd->pw_passwd);
		printf("---------------------------------------------------\n");
	printf("pw_shell %42s\n", pwd->pw_shell);
		printf("---------------------------------------------------\n");
	printf("pw_uid %44u\n", pwd->pw_uid);
		printf("---------------------------------------------------\n");
		printf("---------------------------------------------------\n");


	printf("RIGHTS :\n"); // from http://codewiki.wikidot.com/c:system-calls:stat

	printf("File Size: \t\t%lld bytes\n", buf.st_size);
	printf("Number of Links: \t%d\n",buf.st_nlink);
	printf("File inode: \t\t%llu\n",buf.st_ino);

	printf("File Permissions: \t");
	printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
	printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
	printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
	printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
	printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
	printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
	printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
	printf( (buf.st_mode & S_IROTH) ? "r" : "-");
	printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
	printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");


	return (0);
}
