/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:30:30 by sabrugie          #+#    #+#             */
/*   Updated: 2020/10/10 12:12:19 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libfts.h"

void	test_strlen(void)
{
	char	str[1024];

	printf("\n---------- STRLEN / FT_STRLEN ----------\n\n");
	bzero(str, 1024);
	printf("strlen    : %zu\n", strlen((char *)memcpy(str, "012346578901234657890", 20)));
	printf("ft_strlen : %zu\n", ft_strlen(str));
	bzero(str, 1024);
	printf("strlen    : %zu\n", strlen((char *)memcpy(str, "1", 1)));
	printf("ft_strlen : %zu\n", ft_strlen(str));
	bzero(str, 1024);
	printf("strlen    : %zu\n", strlen((char *)memcpy(str, "0123465789012346578901234567890123465790123456789012345678901234567890123456789012345678901234567890", 100)));
	printf("ft_strlen : %zu\n", ft_strlen(str));
	bzero(str, 1024);
	printf("strlen    : %zu\n", strlen(""));
	printf("ft_strlen : %zu\n", ft_strlen(""));
}

void	test_strcpy(void)
{
	char	dst[1024];
	char	src[1024];

	printf("\n---------- STRCPY / FT_STRCPY ----------\n\n");
	bzero(src, 1024);
	printf("strcpy    : [%s]\n", strcpy(dst, (char *)memcpy(src, "012346578901234657890", 20)));
	bzero(dst, 1024);
	printf("ft_strcpy : [%s]\n\n", ft_strcpy(dst, src));
	bzero(src, 1024);
	printf("strcpy    : [%s]\n", strcpy(dst, (char *)memcpy(src, "1", 1)));
	bzero(dst, 1024);
	printf("ft_strcpy : [%s]\n\n", ft_strcpy(dst, src));
	bzero(src, 1024);
	printf("strcpy    : [%s]\n", strcpy(dst, (char *)memcpy(src, "0123465789012346578901234567890123465790123456789012345678901234567890123456789012345678901234567890", 100)));
	bzero(dst, 1024);
	printf("ft_strcpy : [%s]\n\n", ft_strcpy(dst, src));
	bzero(src, 1024);
	printf("strcpy    : [%s]\n", ft_strcpy(dst, ""));
	bzero(dst, 1024);
	printf("ft_strcpy : [%s]\n", ft_strcpy(dst, ""));
}

void	test_strcmp(void)
{
	char	s1[1024];
	char	s2[1024];

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
	printf("strcmp    : %d\n", ft_strcmp(s1, s2));
	printf("ft_strcmp : %d\n\n", ft_strcmp(s1, s2));
	strcpy(s1, "abcdefghijklm");
	strcpy(s2, "abcde");
	printf("strcmp    : %d\n", ft_strcmp(s1, s2));
	printf("ft_strcmp : %d\n\n", ft_strcmp(s1, s2));
	strcpy(s1, "");
	strcpy(s2, "");
	printf("strcmp    : %d\n", ft_strcmp(s1, s2));
	printf("ft_strcmp : %d\n\n", ft_strcmp(s1, s2));
	strcpy(s1, "SamI");
	strcpy(s2, "sami");
	printf("strcmp    : %d\n", ft_strcmp(s1, s2));
	printf("ft_strcmp : %d\n", ft_strcmp(s1, s2));
}

int	main(int ac, char **av)
{
	char	*str;

	str = calloc(1, 50);
	test_strlen();
	test_strcpy();
	test_strcmp();
//	test_write();
//	test_read();
//	test_strdup();
	return (0);
}
