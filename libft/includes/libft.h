/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:23:36 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/29 13:27:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_strdel(char **as);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ftmemcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
void				ft_strclr(char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstrev(t_list **alst);
void				ft_lstswap(t_list **lst1, t_list **lst2);
void				ft_swap(int *elem1, int *elem2);
void				ft_tabputint(int *tab, int len);
void				ft_addtofloat(float *nb, float add);
void				ft_intdel(int **tab);
float				ft_atof(const char *str);
int					ft_count_words(char *str);

void				ft_2dstrdel(char ***tab);
void				ft_2dputendl(const char **str);
void				ft_2dintdel(int ***atab, int len);
void				ft_2dputint(int **tab, int ilen, int jlen);
int					**ft_2dintpushback(int **tab, int size_i,
										int size_j, int *line);
char				**ft_2dstrpushback(char **tab, int size_i, char *line);
int					ft_2dstrlen(char **tab);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *str, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrcher(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_itoa(int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strcspn(const char *s, const char *charset);
size_t				ft_lstlen(t_list **alst);
size_t				ft_tablen(void **tab);

int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);
float				ft_abs(float n);
int					ft_intabs(int value);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_count_char(char *str, int c);
int					get_next_line(const int fd, char **line);
int					ft_index(const char *str, int c);
int					ft_countnumbers(char *str);
int					ft_round(float nb);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstsplit(const char *s1, char c);
t_list				*ft_create_elem(char *line);
t_list				*ft_lst_pb(t_list **begin_list, char *line);
void				ft_free_list(t_list *lst);
int					ft_content_already_inlist(t_list *lst, char *texname);

#endif
