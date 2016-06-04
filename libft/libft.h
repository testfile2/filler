/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:23:59 by kcowle            #+#    #+#             */
/*   Updated: 2016/05/31 10:21:13 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2000000
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int get_next_line(const int fd, char **line);

#endif

#ifndef __LIBFT_H__
# define __LIBFT_H__

# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);
char				*ft_strchr(const char *s, int c);
int					ft_atoi(const char *src);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memchr(const void *s1, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char    			*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				**ft_strsplit(char const *s, char c);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strnew(size_t size);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strtrim(const char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				ft_strclr(char *s);
int					ft_strnqu(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
#endif
