/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:33:35 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:28:17 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include "typedefs.h"
# define SPECS "pdiDoOuUxXHsScCf%"
# define PARAMS ". #0123456789-+hljz*"
# define BUFF_SIZE 32

typedef struct			s_lnparam
{
	int					sz;
	int					fd;
	int					ret;
	int					null;
	char				c;
	char				*cpy;
	struct s_lnparam	*next;
}						t_lnparam;
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef int		(*t_type)(t_ull *, va_list, uint8_t, t_ll *);
typedef struct	s_param
{
	uint8_t		*flags;
	int			width;
	uint8_t		prec;
	uint8_t		lenght;
	int			wild_card;
}				t_param;
typedef struct	s_write
{
	int			(*ftwrite)(char *, int);
	int			cnt;
	t_type		*type;
	t_param		*param;
}				t_write;
typedef void	(*t_format)(va_list, t_write *);

int				ftcolor(char *fmt);
void			ft_putwchar(wchar_t c);
int				ft_flags_wc(t_write *wr, wchar_t c, int len);
void			wchar_char(wchar_t c, int i, char *ret);
char			*wstr_to_str(wchar_t *s);
int				ft_wstrlen(wchar_t *s);
void			clear_flags(uint8_t *flags);
int				wcharlen(wchar_t wc);
int				type_hh(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll);
int				type_h(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll);
int				type_ll(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll);
int				type_l(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll);
int				type_j(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll);
int				type_z(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll);
void			flag2d(char *s, t_write *wr, int *sz);
void			flag20(char *s, t_write *wr, int *sz, int *max);
void			flag30(char *s, t_write *wr, int *sz);
void			flag2dx(char *s, t_write *wr, int *sz, int *max);
void			flag20x(char *s, t_write *wr, int *sz, int *max);
void			flag30x(char *s, t_write *wr, int *sz, int *max);
void			flag2dxx(char *s, t_write *wr, int *sz, int *max);
void			flag20xx(char *s, t_write *wr, int *sz, int *max);
void			flag30xx(char *s, t_write *wr, int *sz, int *max);
void			flag2do(char *s, t_write *wr, int *sz, int *max);
void			flag20o(char *s, t_write *wr, int *sz, int *max);
void			flag30o(char *s, t_write *wr, int *sz, int *max);
void			flag2ds(char *s, t_write *wr, int *sz, int *min);
void			flag20s(char *s, t_write *wr, int *sz, int *min);
void			flag30s(char *s, t_write *wr, int *sz, int *min);
void			ft_prec_width_wstr(char *str, t_write *wr);
void			ftreadparams(va_list ap, char *fmt, int *i, t_write *wr);
void			ftflags(char *fmt, int *i, t_write *wr);
void			ftwidth(char *fmt, int *i, t_write *wr);
void			ftprec(char *fmt, int *i, t_write *wr);
void			ftlenght(char *fmt, int *i, t_write *wr);
int				ftspec(va_list ap, char spec, t_write *wr);
int				ftspec_(va_list ap, char spec, t_write *wr);
t_write			*init_twrite(void);
void			get_params(t_write *wr, char *fmt, int *i);
void			check_specs(t_write *wr, char *fmt, int i, va_list ap);
int				islenght(char c);
int				isflag(char c);
void			format_unsign_u(va_list ap, t_write *wr);
void			format_unsign_uu(va_list ap, t_write *wr);
void			format_address(va_list ap, t_write *wr);
void			format_oct_o(va_list ap, t_write *wr);
void			format_oct_oo(va_list ap, t_write *wr);
void			format_hex_x(va_list ap, t_write *wr);
void			format_hex_xx(va_list ap, t_write *wr);
void			format_number_d(va_list ap, t_write *wr);
void			format_number_dd(va_list ap, t_write *wr);
void			format_char_c(va_list ap, t_write *wr);
void			format_char_w(va_list ap, t_write *wr);
void			format_string_s(va_list ap, t_write *wr);
void			format_string_w(va_list ap, t_write *wr);
void			format_perc(va_list ap, t_write *wr);
void			format_float(va_list ap, t_write *wr);
char			*ft_strjoindel(char const *s1, char const *s2, int vect);
int				ft_bytes(t_ull b, int i, int bits);
t_write			*ftconvert(va_list ap, char *fmt);
int				ft_printf(const char *fmt, ...);
char			*ft_itoa_base(t_ll nr, int base);
t_ll			ft_atoi_base(char *s, int base);
char			*ft_strndup_printf(char *s, size_t sz);
t_ll			ft_pow(int n, int p);
char			*ft_utoa_base(t_ull n, int base, int up);
void			pointer_address(void *p, t_write *wr);
int				ftwrite(char *s, int i);
t_type			*init_type(void);
int					get_next_line(int fd, char **line);
void				ft_fputstr(int fd, const char *s, size_t size);
int					ft_iswspace(char c);
int					ft_nbrsize(long int nr);
char				ft_getnbr(long int nr, int pos);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *d, const char *s);
char				*ft_strncpy(char *d, const char *s, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *d, const char *s, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *b, const char *l);
char				*ft_strnstr(const char *b, const char *l, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_itoa(int n);
int					ft_atoi(const char *s);
char				*ft_strnew(size_t size);
void				ft_strdel(char **s);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int st, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int nr);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *d, const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **s);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *n);

#endif
