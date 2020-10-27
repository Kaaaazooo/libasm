/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:30:30 by sabrugie          #+#    #+#             */
/*   Updated: 2020/10/27 13:52:06 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include "libfts.h"

void	test_strlen(void)
{
	char	str[512];

	printf("\n---------- STRLEN / FT_STRLEN ----------\n\n");
	bzero(str, 512);
	printf("strlen    : %zu\n", strlen((char *)memcpy(str, "012346578901234657890", 20)));
	printf("ft_strlen : %zu\n", ft_strlen(str));
	bzero(str, 512);
	printf("strlen    : %zu\n", strlen((char *)memcpy(str, "1", 1)));
	printf("ft_strlen : %zu\n", ft_strlen(str));
	bzero(str, 512);
	printf("strlen    : %zu\n", strlen((char *)memcpy(str, "0123465789012346578901234567890123465790123456789012345678901234567890123456789012345678901234567890", 100)));
	printf("ft_strlen : %zu\n", ft_strlen(str));
	bzero(str, 512);
	printf("strlen    : %zu\n", strlen(""));
	printf("ft_strlen : %zu\n", ft_strlen(""));
}

void	test_strcpy(void)
{
	char	dst[512];
	char	src[512];

	printf("\n---------- STRCPY / FT_STRCPY ----------\n\n");
	bzero(src, 512);
	printf("strcpy    : [%s]\n", strcpy(dst, (char *)memcpy(src, "012346578901234657890", 20)));
	bzero(dst, 512);
	printf("ft_strcpy : [%s]\n\n", ft_strcpy(dst, src));
	bzero(src, 512);
	printf("strcpy    : [%s]\n", strcpy(dst, (char *)memcpy(src, "1", 1)));
	bzero(dst, 512);
	printf("ft_strcpy : [%s]\n\n", ft_strcpy(dst, src));
	bzero(src, 512);
	printf("strcpy    : [%s]\n", strcpy(dst, (char *)memcpy(src, "0123465789012346578901234567890123465790123456789012345678901234567890123456789012345678901234567890", 100)));
	bzero(dst, 512);
	printf("ft_strcpy : [%s]\n\n", ft_strcpy(dst, src));
	bzero(src, 512);
	printf("strcpy    : [%s]\n", strcpy(dst, ""));
	bzero(dst, 512);
	printf("ft_strcpy : [%s]\n", ft_strcpy(dst, ""));
}

void	test_strcmp(void)
{
	char	s1[512];
	char	s2[512];

	printf("\n---------- STRCMP / FT_STRCMP ----------\n\n");
	strcpy(s1, "abcdefghijklm");
	strcpy(s2, "abcdefghijklm");
	printf("strcmp    : %d\n", strcmp(s1, s2));
	printf("ft_strcmp : %d\n\n", ft_strcmp(s1, s2));
	strcpy(s1, "abcdefghijklm");
	strcpy(s2, "abcdefghijkln");
	printf("strcmp    : %d\n", strcmp(s1, s2));
	printf("ft_strcmp : %d\n\n", ft_strcmp(s1, s2));
	strcpy(s1, "abcdefghijkln");
	strcpy(s2, "abcdefghijklm");
	printf("strcmp    : %d\n", strcmp(s1, s2));
	printf("ft_strcmp : %d\n\n", ft_strcmp(s1, s2));
	strcpy(s1, "abcde");
	strcpy(s2, "abcdefghijklm");
	printf("strcmp    : %d\n", strcmp(s1, s2));
	printf("ft_strcmp : %d\n\n", ft_strcmp(s1, s2));
	strcpy(s1, "abcdefghijklm");
	strcpy(s2, "abcde");
	printf("strcmp    : %d\n", strcmp(s1, s2));
	printf("ft_strcmp : %d\n\n", ft_strcmp(s1, s2));
	strcpy(s1, "");
	strcpy(s2, "");
	printf("strcmp    : %d\n", strcmp(s1, s2));
	printf("ft_strcmp : %d\n\n", ft_strcmp(s1, s2));
	strcpy(s1, "SamI");
	strcpy(s2, "sami");
	printf("strcmp    : %d\n", strcmp(s1, s2));
	printf("ft_strcmp : %d\n", ft_strcmp(s1, s2));
}

void	test_strdup(void)
{
	char	*dst;

	printf("\n---------- STRDUP / FT_STRDUP ----------\n\n");
	printf("strdup    : [%s]\n", dst = strdup("12345678901234567890123456789012345678901234567890123456789012345678901234567890"));
	free(dst);
	printf("ft_strdup : [%s]\n\n", dst = ft_strdup("12345678901234567890123456789012345678901234567890123456789012345678901234567890"));
	free(dst);
	printf("strdup    : [%s]\n", dst = strdup(""));
	free(dst);
	printf("ft_strdup : [%s]\n\n", dst = ft_strdup(""));
	free(dst);
	printf("strdup    : [%s]\n", dst = strdup("Salut les amis !"));
	free(dst);
	printf("ft_strdup : [%s]\n\n", dst = ft_strdup("Salut les amis !"));
	free(dst);
	printf("strdup    : [%s]\n", dst = strdup("J'adore les labradors, ce sont les chiens les plus fideles et les plus braves !"));
	free(dst);
	printf("ft_strdup : [%s]\n", dst = ft_strdup("J'adore les labradors, ce sont les chiens les plus fideles et les plus braves !"));
	free(dst);
}

void	test_write(void)
{
	ssize_t	ret;
	char	str[256];

	printf("\n---------- WRITE / FT_WRITE ----------\n\n");
	strcpy(str, "Je suis un canide domestique");
	printf(" (%zd)\n", ret = write(1, str, ft_strlen(str)));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n");
	errno = 0;
	printf(" (%zd)\n", ret = ft_write(1, str, ft_strlen(str)));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n\n");
	errno = 0;
	strcpy(str, "Et j'adore les caresses, les papouilles et les calins :)");
	printf(" (%zd)\n", ret = write(1, str, ft_strlen(str)));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n");
	errno = 0;
	printf(" (%zd)\n", ret = ft_write(1, str, ft_strlen(str)));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n\n");
	errno = 0;
	strcpy(str, "A");
	printf(" (%zd)\n", ret = write(1, str, ft_strlen(str)));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n");
	errno = 0;
	printf(" (%zd)\n", ret = ft_write(1, str, ft_strlen(str)));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n\n");
	errno = 0;
	strcpy(str, "Avez vous deja vu... Un labrador qui fait du parachute ???");
	printf(" (%zd)\n", ret = write(8965, str, ft_strlen(str)));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n");
	errno = 0;
	printf(" (%zd)\n", ret = ft_write(8965, str, ft_strlen(str)));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n\n");
	errno = 0;
	strcpy(str, "Aie ! J'ai du gravier entre mes coussinets :c");
	printf(" (%zd)\n", ret = write(-1, str, ft_strlen(str)));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n");
	errno = 0;
	printf(" (%zd)\n", ret = ft_write(-1, str, ft_strlen(str)));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n\n");
	errno = 0;
	strcpy(str, "C'est bon, je l'ai enleve tout seul comme un grand !");
	printf(" (%zd)\n", ret = write(1, 0x0, ft_strlen(str)));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n");
	errno = 0;
	printf(" (%zd)\n", ret = ft_write(1, 0x0, ft_strlen(str)));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n\n");
	errno = 0;
	strcpy(str, "J'ai eu tres peur !");
	printf(" (%zd)\n", ret = write(1, str, -12));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n");
	errno = 0;
	printf(" (%zd)\n", ret = ft_write(1, str, -12));
	if (ret < 0)
		printf("[%s]", strerror(errno));
	printf("\n\n");
}

void	test_read(char *str)
{
	int		fd;
	int		fd1;
	int		ret;
	char	buf[128];

	printf("\n---------- READ / FT_READ ----------\n\n");
	fd = open(str, O_RDONLY);
	fd1 = open(str, O_RDONLY);
	printf("(%d)\n", ret = read(fd, buf, 17));
	printf("[%s]\n\n", ret < 0 ? strerror(errno) : buf);
	errno = 0;
	printf("(%d)\n", ret = ft_read(fd1, buf, 17));
	printf("[%s]\n\n", ret < 0 ? strerror(errno) : buf);
	errno = 0;
	printf("(%d)\n", ret = read(fd, buf, 54));
	printf("[%s]\n\n", ret < 0 ? strerror(errno) : buf);
	errno = 0;
	printf("(%d)\n", ret = ft_read(fd1, buf, 54));
	printf("[%s]\n\n", ret < 0 ? strerror(errno) : buf);
	errno = 0;
	printf("(%d)\n", ret = read(fd, buf, -54));
	printf("[%s]\n\n", ret < 0 ? strerror(errno) : buf);
	errno = 0;
	printf("(%d)\n", ret = ft_read(fd1, buf, -54));
	printf("[%s]\n\n", ret < 0 ? strerror(errno) : buf);
	errno = 0;
	printf("(%d)\n", ret = read(645, buf, 43));
	printf("[%s]\n\n", ret < 0 ? strerror(errno) : buf);
	errno = 0;
	printf("(%d)\n", ret = ft_read(645, buf, 43));
	printf("[%s]\n\n", ret < 0 ? strerror(errno) : buf);
	errno = 0;
	printf("(%d)\n", ret = read(fd, 0x0, 43));
	printf("[%s]\n\n", ret < 0 ? strerror(errno) : buf);
	errno = 0;
	printf("(%d)\n", ret = ft_read(fd1, 0x0, 43));
	printf("[%s]\n\n", ret < 0 ? strerror(errno) : buf);
	errno = 0;
	printf("(%d)\n", ret = read(fd, buf, 63));
	printf("[%s]\n\n", ret < 0 ? strerror(errno) : buf);
	errno = 0;
	printf("(%d)\n", ret = ft_read(fd1, buf, 63));
	printf("[%s]\n\n", ret < 0 ? strerror(errno) : buf);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf(ac < 2 ? "No argument\n" : "Too many arguments\n");
		return (1);
	}
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_strdup();
	test_write();
	test_read(av[1]);
	return (0);
}
