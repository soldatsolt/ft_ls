#include "ft_ls.h"

int		main()
{
	struct dirent	*struct_dirent;
	DIR				*dir;

	dir = opendir(".");

	while ((struct_dirent = readdir(dir)))
	{
		printf("%s\n", struct_dirent->d_name);
	}
	return (0);
}