#include "pipeline_context.h"

#include "symbol.h"

void init_pipeline_context(struct pipeline_context *context, unsigned flags, const char *file_name, int are_multiple_files_passed)
{
	context->flags = flags;
	context->file_name = file_name;
	context->file.ptr = NULL;
	context->file.size = 0;
	context->are_multiple_files_passed = are_multiple_files_passed;
	context->architecture = elf_invalid_architecture;
	context->symbols = vector_create(sizeof(struct symbol));
}

void free_pipeline_context(struct pipeline_context *context)
{
	vector_destroy(&context->symbols);
	close_mapped_file(&context->file);
}