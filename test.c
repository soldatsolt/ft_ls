#include "ft_ls.h"

int		main()
{
	struct dirent	*struct_dirent;
	DIR				*dir;
	char			*perm;
	struct stat		buf;
	struct passwd	*pwd;
	struct group	*grp;

	dir = opendir(".");
	perm = ft_strdup("----------");

	while ((struct_dirent = readdir(dir)))
	{
		stat(struct_dirent->d_name, &buf);
		pwd = getpwuid(buf.st_uid);
		grp = getgrgid(buf.st_gid);
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
		perm = ft_strcpy(perm, "----------");
		printf("%s\n", struct_dirent->d_name);
	}
	closedir(dir);
	return (0);
}
