/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/03/07 07:34:19 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <stddef.h>
# include <locale.h>
# include <limits.h>
# define BUFF_SIZE 42
# define MAX_FD 20

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_n
{
	int				ret;
	int				r;
	int				fin;
	char			*str;
}					t_n;

typedef struct		s_print
{
	va_list			arg;
	int				ret;
	char			spec;
	char			*flags;
	int				width;
	int				precision;
	char			*length;
	char			*raw;
	char			sign;
	uintmax_t		raw_i;
	intmax_t		raw_x;
	wchar_t			*raw_w;
	char			ch;
	int				pad;
	int				x;
}					t_print;

int					get_next_line(const int fd, char **line);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memcpy(void *d, const void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putnbr(int nbr);
void				ft_putstr(char *str);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strequ(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnstr(const char *big, const char *l, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strtrim(char const *s);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char *s1, char *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
char				**ft_words(char const *str, char c);
char				*ft_fill(char const *str, char *ptr, char c, int i);
char				*ft_letters(char const *str, char c, int i);
char				*ft_malloc(int size);
char				*ft_strxcpy(char *dst, const char *src, int s, int t);
char				*ft_strndup(const char *s1, size_t offset);
char				*ft_strnxdup(const char *s1, size_t offset, size_t spaces);
char				*ft_chartostr(char letter);
int					ft_sizeprintf(intmax_t nbr);
int					ft_charfind(char *str, char c);
char				*ft_strxjoin(char *s1, char *s2, int free);
char				*ft_strxnew(int letter, size_t size);
char				*ft_charset(char *str, char letter, int size);
void				ft_putwchar(wchar_t c);
void				ft_putwstr(wchar_t *str);
wchar_t				*ft_charwset(wchar_t *str, wchar_t x, int size);
void				*ft_wmemset(void *b, int c, size_t len);
wchar_t				*ft_strwdup(wchar_t *s1);
wchar_t				*ft_strwxnew(wchar_t letter, size_t size);
wchar_t				*ft_strwxjoin(wchar_t *s1, wchar_t *s2, int free);
wchar_t				*ft_strwxcpy(wchar_t *dst, wchar_t *src, int s, int t);
int					ft_strwlen(wchar_t *str);
void				ft_strwdel(wchar_t **as);
wchar_t				*ft_strwsub(wchar_t *s, unsigned int start, size_t len);
int					ft_printf(const char *format, ...);
t_print				*init(t_print *all);
void				parse(t_print *all, char *f);
void				retrieve(t_print *all, va_list arg, char c);
int					percent_found(t_print *all, char *f);
void				decimal(t_print *all);
void				format(t_print *all, char spec);
t_print				*right_align(t_print *all);
t_print				*right_align(t_print *all);
int					length(t_print *all, char *f);
void				reset_struct(t_print *all);
int					precision(t_print *all, char *f);
int					width(t_print *all, char *f);
int					gather_flags(t_print *all, char *f);
int					flags(t_print *all, char *f);
int					specifier(t_print *all, char c);
void				oct(t_print *all);
void				hex(t_print *all);
void				get_luint(t_print *all, va_list arg);
void				get_uint(t_print *all, va_list arg);
void				get_int(t_print *all, va_list arg);
void				get_hexoct(t_print *all, va_list arg);
void				w_string(t_print *all);
void				string(t_print *all);
t_print				*with_precision(t_print *all);
t_print				*left_align(t_print *all);
void				ft_putbs(t_print *all, char *str);
int					specifier(t_print *all, char c);
char				*ft_itoa(t_print *all, intmax_t nbr);
char				*ft_itoau(uintmax_t nbr);
int					ft_size(t_print *all, intmax_t nbr);
int					ft_sizeu(uintmax_t nbr);
char				*ft_loader(t_print *all, char *dst, intmax_t nbr, int size);
char				*ft_loaderu(char *dst, uintmax_t nbr, int size);
char				*ft_itoabase(t_print *all, intmax_t nbr, char c);
char				*ft_itoabasel(intmax_t nbr, char c);
int					ft_colors(char *f, int c);
char				*ft_strxdup(char *s1, int free);
char				*ft_loaderl(char *dst, int nbr, int size);
char				*ft_itoal(int nbr);
int					ft_sizel(int nbr);
char				*ft_malloc(int size);
char				**ft_strdup2d(char **str2d, int start);
void				ft_strdel2d(char **str);

#endif
