#include "doom_nukem.h"

int		ret_error(const char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	return (0);
}

void	*ret_null_error(const char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	return (NULL);
}

int		ret_perror(const char *error_msg)
{
	perror(error_msg);
	return (0);
}

void    *ret_null_perror(const char *error_msg)
{
	perror(error_msg);
	return (NULL);
}