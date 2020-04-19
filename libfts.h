#ifndef LIBFTS_H
# define LIBFTS_H

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int	ft_strcmp(char *s1, char *s2);
ssize_t	ft_write(int fd, char *buf, size_t count);
ssize_t	ft_read(int fd, char *buf, size_t count);

#endif
