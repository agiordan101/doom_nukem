#ifndef RET_ERROR_H
# define RET_ERROR_H

enum		state{SUCCESS, MALLOC_ERROR, UNDEFINED_ERROR};

/*
** ================================== Error Management ==================================
*/

int			ret_error(const char *error_msg);
void		*ret_null_error(const char *error_msg);
int			ret_perror(const char *error_msg);
void		*ret_null_perror(const char *error_msg);

#endif