#ifndef LIBFTS_H
# define LIBFTS_H

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
ssize_t	ft_write(int fd, char *buf, size_t count);
ssize_t	ft_read(int fd, char *buf, size_t count);

#endif
