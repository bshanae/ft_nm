#ifndef ELF_DESCRIPTOR_H
#define ELF_DESCRIPTOR_H

#include <sys/mman.h>

struct mapped_file
{
	void *ptr;
	size_t size;
};

int open_mapped_file(struct mapped_file *file, const char *path);
void close_mapped_file(struct mapped_file *file);

#endif