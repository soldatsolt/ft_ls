#include "ft_ls.h"

int		main()
{
	struct dirent	*struct_dirent;
	DIR				*dir;
	char			*perm;
	struct stat		buf;

	dir = opendir(".");
	perm = ft_strdup("----------");











	while ((struct_dirent = readdir(dir)))
	{
		stat(struct_dirent->d_name, &buf);
		printf("%s\n", perm);
		perm = ft_strcpy(perm, "----------");
		printf("%s\t\t", struct_dirent->d_name);
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
	}
	closedir(dir);
	return (0);
}
