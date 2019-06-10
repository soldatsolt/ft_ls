/*

	https://www.ibm.com/developerworks/ru/library/au-unix-readdir/index.html

*/

/*
Используя макрос S_*() для поля st_mode, можно определить тип файла:

S_ISBLK(mode) – специальный блочный файл? (обычно это блочное устройство).
S_ISCHR(mode) – специальный символьный файл? (обычно это символьное устройство).
S_ISDIR(mode) – каталог?
S_ISFIFO(mode) – UNIX-канал (pipe) или файл типа FIFO?
S_ISLNK(mode) – символическая ссылка?
S_ISREG(mode) – обычный файл?
*/

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	struct dirent	*struct_dirent;
	DIR				*dir;
	char			*perm;
	struct stat		buf;
	struct passwd	*pwd;
	struct group	*grp;
	char			*mtime;
	char			*time;
	t_ls			ls;

	ls.f = F_X_;
	printf("%llu\n", ls.f);

	if (argc < 2)
		dir = opendir(".");
	else
		dir = opendir(argv[1]);
	
	perm = ft_strdup("----------");

	if (dir == NULL)
	{
		printf("ls: %s: No such file or directory\n", argv[1]);
		return (0);
	}
	while ((struct_dirent = readdir(dir)))
	{	//	первый if - на . и на .. TODO: мб это условие стоит убрать по дальнейшей работе
		// но для рекурсии, скорее всего, стоит оставить это условие во избежание ./././././././././
		if (!ft_strcmp(struct_dirent->d_name, ".") || !ft_strcmp(struct_dirent->d_name, ".."))
			continue ;
		stat(struct_dirent->d_name, &buf);	// FIXME: Функция stat() на большинстве
		pwd = getpwuid(buf.st_uid);			// UNIX-систем работает медленно. Для рекурсии можно
		grp = getgrgid(buf.st_gid);			// не вызывать её, если это не каталог (?) (flags?)
		mtime = ctime(&buf.st_mtimespec.tv_sec);
		time = ft_strsub(mtime, 4, 12);
		if (S_ISDIR(buf.st_mode))
			perm[0] = 'd';
		else if (S_ISCHR(buf.st_mode))
			perm[0] = 'c';
		else if (S_ISBLK(buf.st_mode))
			perm[0] = 'b';
		if (buf.st_mode & S_IRUSR)
			perm[1] = 'r';
		if (buf.st_mode & S_IWUSR)
			perm[2] = 'w';
		if (buf.st_mode & S_IXUSR)
			perm[3] = 'x';
		if (buf.st_mode & S_IRGRP)
			perm[4] = 'r';
		if (buf.st_mode & S_IWGRP)
			perm[5] = 'w';
		if (buf.st_mode & S_IXGRP)
			perm[6] = 'x';
		if (buf.st_mode & S_IROTH)
			perm[7] = 'r';
		if (buf.st_mode & S_IWOTH)
			perm[8] = 'w';
		if (buf.st_mode & S_IXOTH)
			perm[9] = 'x';
		printf("%s\t", perm);
		printf("%u\t", buf.st_nlink);
		printf("%s\t", pwd->pw_name);
		printf("%s\t", grp->gr_name);
		printf("%lld\t", buf.st_size);
		printf("%s\t", time);
		perm = ft_strcpy(perm, "----------");
		printf("%s\n", struct_dirent->d_name);
		free(time);
	}
	free(perm);
	closedir(dir);
	return (0);
}
