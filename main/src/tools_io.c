#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "tools_io.h"

int open_mapped_file(struct mapped_file *file, const char *path)
{
	file->ptr = NULL;
	file->size = 0;

	int fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		return -1;
	}

	struct stat stat;
	int status = fstat(fd, &stat);
	if (status != 0)
	{
		close(fd);
		return -1;
	}

	off_t size = stat.st_size;
	if (size == 0)
	{
		close(fd);
		return 0;
	}

	char *ptr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (ptr == MAP_FAILED)
	{
		close(fd);
		return -1;
	}

	close(fd);

	file->ptr = ptr;
	file->size = size;
	return 0;
}

void close_mapped_file(struct mapped_file *file)
{
	munmap(file->ptr, file->size);

	file->ptr = NULL;
	file->size = -1;
}
