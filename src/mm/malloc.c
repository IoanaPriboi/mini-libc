// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

/* Documentation: https://man7.org/linux/man-pages/man2/mmap.2.html, mem_list.c */
void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
    return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
    return mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
    /* Test if ptr is valid for free */
    struct mem_list *mem = mem_list_find(ptr);
    if (mem == NULL) {
        return;
    }
    mem_list_del(mem->start);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	return mmap(ptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	return mmap(ptr, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}
