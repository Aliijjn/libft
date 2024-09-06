/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 15:36:33 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/27 11:35:22 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

void check_is_x(int (*f)(int), int (*f2)(int))
{
	for (int i = 0; i < 256; i++)
	{
		if (f(i) != f2(i))
		{
			printf("\nERROR at %i:\n", i);
			printf("%i\n", f(i));
			printf("%i\n", f2(i));
			continue;
		}
		printf("v");
	}
}

int	main(void)
{
	char nbr_str[5][121] = { "+2147483647", "-2147483648", "0", "+12-3.54", "54 3a" };
	printf("\nChecking atoi\n");
	for (int i = 0; i < 5; i++)
	{
		if (ft_atoi(nbr_str[i]) != atoi(nbr_str[i]))
		{
			printf("\nERROR at %s:\n", nbr_str[i]);
			printf("%i", ft_atoi(nbr_str[i]));
			printf("%i", atoi(nbr_str[i]));
			continue;
		}
		printf("v");
	}

	printf("\nChecking bzero\n");
	#define TEST_STRING "Hi Mom!"
	#define BZERO_LENGTH 5
	char str1[] = TEST_STRING;
	char str2[] = TEST_STRING;
	ft_bzero(str1, BZERO_LENGTH);
	bzero(str2, BZERO_LENGTH);
	for (int i = 0; i < (int)sizeof(str1); i++)
	{
		if (str1[i] != str2[i])
		{
			printf("\nERROR at %i:\n", i);
			printf("%c\n", str1[i]);
			printf("%c\n", str2[i]);
			continue;
		}
	printf("v");
	}
	
	printf("\nChecking calloc\n");
	#define CALLOC_LENGTH 8
	#define CALLOC_SIZE (int)sizeof(int)
	void *ptr1 = ft_calloc(CALLOC_LENGTH, CALLOC_SIZE);
	void *ptr2 = calloc(CALLOC_LENGTH, CALLOC_SIZE);
	for (int i = 0; i < CALLOC_LENGTH * CALLOC_SIZE; i++)
	{
		if (((char*)ptr1)[i] != ((char*)ptr2)[i])
		{
			printf("\nERROR at %i:\n", i);
			printf("%c\n", ((char*)ptr1)[i]);
			printf("%c\n", ((char*)ptr2)[i]);
			continue;
		}
	printf("v");
	}
	if (ptr1)
	{
		free(ptr1);
	}
	if (ptr2)
	{
		free(ptr2);
	}
	
	printf("\nChecking isalnum\n");
	check_is_x(&ft_isalnum, &isalnum);

	printf("\nChecking isalpha\n");
	check_is_x(&ft_isalpha, &isalpha);

	printf("\nChecking isascii\n");
	check_is_x(&ft_isascii, &isascii);

	printf("\nChecking isdigit\n");
	check_is_x(&ft_isdigit, &isdigit);

	printf("\nChecking isprint\n");
	check_is_x(&ft_isdigit, &isdigit);

	printf("\nChecking itoa\n");
	char *ptr_array[4];
	int nbr[4] = { INT_MIN, INT_MAX, 0, 1};
	for (int i = 0; i < 4; i++)
	{
		ptr_array[i] = ft_itoa(nbr[i]);
		printf("%s | %i\n", ptr_array[i], nbr[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		free(ptr_array[i]);
	}
	printf("\nChecking memchr\n");
	char str3[] = "abcdefghicj0123456789";
	printf("%s | %s\n", (char*)ft_memchr(str3, 'c', 19), (char*)memchr(str3, 'c', 19));
	printf("%s | %s\n", (char*)ft_memchr(str3, 'z', 19), (char*)memchr(str3, 'z', 19));
	
	printf("\nChecking memcmp\n");
	char str4[8][6] = {"abcd", "abcd", "abc", "abcd", "abcd", "abcde", "abcD", "abcd"};
	for (int i = 0; i < 8; i += 2)
	{
		printf("%i | %i\n", ft_memcmp(&str4[i][0], &str4[i + 1][0], 4), memcmp(&str4[i][0], &str4[i + 1][0], 4));
	}
	
	printf("\nChecking memcpy\n");
	#define TEST_ARR { 1, 2, 3, 4, 5, 6 }
	#define MEMSET_LENGTH 4
	int	arr1[] = TEST_ARR;
	int	arr2[] = TEST_ARR;
	ft_memcpy(arr1, "aaaa",MEMSET_LENGTH);
	memcpy(arr2, "aaaa",MEMSET_LENGTH);
	for (int i = 0; i < (int)sizeof(arr1) / (int)sizeof(int); i++)
	{
		if (arr1[i] != arr2[i])
		{
			printf("\nERROR at %i:\n", i);
			printf("%c\n", arr1[i]);
			printf("%c\n", arr2[i]);
			continue;
		}
		printf("ok ");
	}

	printf("\nChecking memmove\n");
	char str5[] = "1234567890";
	char str6[] = "1234567890";
	ft_memmove(str5, str5 + 4, MEMSET_LENGTH);
	memmove(str6, str6 + 4, MEMSET_LENGTH);
	for (int i = 0; i < (int)sizeof(str1); i++)
	{
		if (str5[i] != str6[i])
		{
			printf("\nERROR at %i:\n", i);
			printf("%c\n", str5[i]);
			printf("%c\n", str6[i]);
			continue;
		}
	printf("ok ");
	}

	printf("\nChecking memset\n");
	#define TEST_STRING "Hi Mom!"
	char str7[] = TEST_STRING;
	char str8[] = TEST_STRING;
	ft_memset(str7, 0, MEMSET_LENGTH);
	memset(str8, 0, MEMSET_LENGTH);
	for (int i = 0; i < (int)sizeof(str7); i++)
	{
		if (str7[i] != str8[i])
		{
			printf("\nERROR at %i:\n", i);
			printf("%c\n", str7[i]);
			printf("%c\n", str8[i]);
			continue;
		}
		printf("ok ");
	}

	printf("\nChecking df functions\n");
	int fd = open("test.txt", O_RDWR | O_CREAT);
	ft_putchar_fd('a', fd);
	close(fd);
	int fd2 = open("test3.txt", O_RDWR | O_CREAT);
	ft_putendl_fd("No time to wallow in the mire", fd2);
	close(fd2);
	int fd3 = open("test4.txt", O_RDWR | O_CREAT);
	ft_putnbr_fd(1234567890, fd3);
	close(fd3);
	int fd4 = open("test2.txt", O_RDWR | O_CREAT);
	ft_putstr_fd("No time to wallow in the mire", fd4);
	close(fd4);

	printf("\nChecking split\n");
	printf("TEST WILL GIVE SEGFAULT IF LAST PTR != 0\n");
	char **str_array = ft_split("   String1   String2 String3    ", ' ');
	int count = 0;
	for (; &str_array[count][0] != 0; count++)
	{
		printf("%s\n", &str_array[count][0]);
	}
	printf("last pointer is %p\n", &str_array[count][0]);
	for (int i = 3; i; i--)
	{
		free(str_array[i - 1]);
	}
	free(str_array);
	
	// printf("\nChecking strchr\n");
	// char str9[] = "abcdefghij0123456789";
	// printf("%s | %s\n", ft_strchr(str, '0'), strchr(str, '0'));
	// printf("%s | %s\n", ft_strchr(str, 'z'), strchr(str, 'z'));

	// printf("\nChecking strdup\n");
	// #define STRING "Hi Mom!"
	// char *str1 = ft_strdup(STRING);
	// char *str2 = strdup(STRING);
	// for (int i = 0; i < 8; i++)
	// {
	// 	if (str1[i] != str2[i])
	// 	{
	// 		printf("\nERROR at %i:\n", i);
	// 		printf("%c\n", str1[i]);
	// 		printf("%c\n", str2[i]);
	// 		continue;
	// 	}
	// printf("ok ");
	// }

	

	return (0);
}