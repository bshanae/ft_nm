#include "pipeline_validation64.h"

#include "tools_elf.h"
#include "libft_ft_printf.h"

void pipeline_validate64(struct pipeline_context *context)
{
	switch (elf64_validate((Elf64_Ehdr *)context->file.ptr, context->file.size))
	{
		case elf_valid:
			break;

		case elf_invalid_unrecognized_file:
			ft_printf("%fd_out", 2);
			ft_printf("%fd_out" "nm: %s: file format not recognized\n", 2, context->file_name);
			exit(1);

		case elf_invalid_no_symbols:
			ft_printf("%fd_out", 2);
			ft_printf("nm: %s: no symbols\n", context->file_name);
			exit(0);
	}
}