// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
    char *dest = destination;
    for (; *source != '\0'; source++, dest++) {
        *dest = *source;
    }

    /* Add terminator */
    *dest = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
    char *dest = destination;
    for ( ; len > 0 && *source != '\0'; source++, dest++, len--) {
        *dest = *source;
    }

    /* if len > strlen(source) => fill the rest of destination with '\0' */
    while (len > 0) {
        *dest = '\0';
        dest++;
        len--;
    }

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
    /* Find the end of destination string */
    char *dest = destination;
    while (*dest != '\0') {
        dest++;
    }

    /* Concatenate the source to destination */
    for (; *source != '\0'; source++, dest++) {
        *dest = *source;
    }

    /* Add terminator */
    *dest = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
    /* Find the end of destination string */
    char *dest = destination;
    while (*dest != '\0') {
        dest++;
    }

    /* Concatenate the first len characters from source to destination */
    for (; len > 0 && *source != '\0'; len--, source++, dest++) {
        *dest = *source;
    }

    /* Add terminator */
    *dest = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
    for (; *str1 != '\0' && *str2 != '\0'; str1++, str2++) {
        int dif = *str1 - *str2;        /*  dif > 0 => str1 > str2
                                            dif < 0 => str1 < str2
                                            dif == 0 => *str1 == *str2  */
        if (dif != 0) {
            return dif;
        }
    }

    if (*str1 != '\0') {
        return 1;       /* str1 > str2 */
    }

    if (*str2 != '\0') {
        return -1;      /* str1 < str2 */
    }

    return 0;           /* str1 == str2 */
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
    for (; len > 0 && *str1 != '\0' && *str2 != '\0'; len--, str1++, str2++) {
        int dif = *str1 - *str2;        /*  dif > 0 => str1 > str2
                                            dif < 0 => str1 < str2
                                            dif == 0 => *str1 == *str2  */
        if (dif != 0) {
            return dif;
        }
    }

    if (len > 0 && *str1 != '\0') {
        return 1;   /* str1 > str2 */
    }

    if (len > 0 && *str2 != '\0') {
        return -1;  /* str1 < str2 */
    }

    return 0;   /* str1 == str2 */
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
    char ch = (char)c;
    for (; *str != '\0'; str++) {
        if (*str == ch)
            return (char *)str;
    }

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
    char ch = (char)c;
    char *p = NULL;     /* pointer to the last occurrence of ch */
    for (; *str != '\0'; str++) {
        if (*str == ch)
            p = (char *)str;
    }

	return p;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
    char *p = NULL;             /*  pointer to the first occurrence of
                                    needle in haystack */

    for (; *haystack != '\0'; haystack++) {
        if (*haystack == *needle) {
            p = (char*)haystack;
            char *copy_needle = (char *)needle;
            char *copy_haystack = (char *)haystack;
            int found = 1;     /* checks if we found the needle in the haystack */
            for (;*copy_needle != '\0' && *copy_haystack != '\0'; copy_haystack++, copy_needle++)
                if (*copy_needle != *copy_haystack) {
                    found = 0;
                    break;
                }
            if (found) {
                return p;
            }
        }
    }

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
    char *p = NULL;             /*  pointer to the last occurrence of
                                    needle in haystack */

    for (; *haystack != '\0'; haystack++) {
        if (*haystack == *needle) {
            char *copy_needle = (char *)needle;
            char *copy_haystack = (char *)haystack;
            int found = 1;     /* checks if we found the needle in the haystack */
            for (;*copy_needle != '\0' && *copy_haystack != '\0'; copy_haystack++, copy_needle++)
                if (*copy_needle != *copy_haystack) {
                    found = 0;
                    break;
                }

            /* Check if we found the whole needle in the haystack :) */
            if (*copy_needle != '\0') {
                found = 0;
            }
            if (found) {
                p = (char *)haystack;
            }
        }
    }

	return p;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
    char *dest = (char *)destination;
    char *src = (char *)source;

    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }

    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
    char *dest = (char *)destination;
    const char *src = (const char *)source;

    if (src < dest) {   /* src before dest*/
        for (size_t i = num; i > 0; i--) {
            dest[i-1] = src[i-1];
        }
    } else {    /* src after dest */
        for (size_t i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    }

    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
    const char *p1 = (const char *)ptr1;
    const char *p2 = (const char *)ptr2;
    for (size_t i = 0; i < num; i++){
        int dif = p1[i] - p2[i];            /*  dif > 0 => ptr1 > ptr2
                                            dif < 0 => ptr1 < ptr2
                                            dif == 0 => *ptr1 == *ptr2  */
        if (dif != 0) {
            return dif;
        }
    }

	return 0;   /* ptr1 == ptr2 */
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
    /* Documentation: https://cplusplus.com/reference/cstring/memset/ */
    char *src = (char *)source;
    unsigned char val = (unsigned char)value;
    for (size_t i = 0; i < num; i++) {
        src[i] = val;
    }

	return source;
}
