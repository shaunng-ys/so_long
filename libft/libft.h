/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sng <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:12:15 by sng               #+#    #+#             */
/*   Updated: 2025/01/25 16:12:23 by sng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <limits.h>
# define STRNULL "(null)"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl
{
	int			rv;
	char		*buffer;
	char		*ohana;
	char		*ph;
	char		*ph1;
	char		*ph2;
	size_t		i;
	size_t		n;
	char		*ptr;
}	t_gnl;

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
size_t	copier(char	*dest, char *src, char limiter);
int		buffer_check(char *buffer, size_t index);
char	*nl_split(char **leftover, char **buffer, char **ph1, char **ph2);
char	*if_else(int *rv_ptr, int *fd_ptr, char ***leftover, t_gnl *a);
char	*getme_a_nl(int rv, int fd, char **leftover, t_gnl *a);
int		ft_printf(const char *format, ...);
int		ft_printf_util1(const char *string, size_t index, va_list *args, int n);
int		ft_printf_util2(const char *string, size_t index, va_list *args, int n);
int		ft_printf_util3(const char *string, size_t index, va_list *args, int n);
size_t	itr(unsigned long nbr, char *base);
int		ft_putnbr_base(unsigned long nbr, char *base, int *d, size_t itr);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_isspace(char c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest_str, const void *src_str, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s0, const char *s1, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
