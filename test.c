// #include "pipex.h"

// int main(int argc, char **argv)
// {
// 	char	*fullpath;
// 	char	*cmd = argv[1];

// 	fullpath = (char *)malloc(ft_strlen("/bin/") + ft_strlen(cmd) + 1);
// 	if (!fullpath)
// 		exit(EXIT_FAILURE);
// 	ft_strncpy(fullpath, "/bin/", 6);
// 	ft_strncpy(fullpath + 6, cmd, ft_strlen(cmd));
// 	printf("Path: %s\n", fullpath);
// 	return 0;
// }
