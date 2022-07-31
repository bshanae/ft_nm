#ifndef PIPELINE_CONTEXT_H
#define PIPELINE_CONTEXT_H

#include "libft_vector.h"
#include "tools_elf.h"
#include "tools_io.h"

struct pipeline_context
{
	unsigned flags;
	const char *file_name;
	struct mapped_file file;
	int are_multiple_files_passed;
	enum elf_architecture architecture;
	t_vector *symbols;
};

void init_pipeline_context(struct pipeline_context *context, unsigned flags, const char *file_name, int are_multiple_files_passed);
void free_pipeline_context(struct pipeline_context *context);

#endif
