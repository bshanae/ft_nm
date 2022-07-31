#include "pipeline_reading.h"

#include <stdlib.h>
#include "elf.h"
#include "libft_ft_printf.h"

void pipeline_read_file(struct pipeline_context *context)
{
	if (open_mapped_file(&context->file, context->file_name) != 0)
	{
		ft_printf("%fd_out" "nm: '%s': No such file\n", 2, context->file_name);
		exit(1);
	}

	if (context->file.size == 0)
		exit(1);

	switch (((char *)context->file.ptr)[EI_CLASS])
	{
		case ELFCLASS32:
			context->architecture = elf_x86;
			break;

		case ELFCLASS64:
			context->architecture = elf_x86_64;
			break;

		default:
			context->architecture = elf_invalid_architecture;
			break;
	}
}