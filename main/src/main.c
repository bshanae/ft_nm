#include "arguments.h"
#include "tools_io.h"
#include "pipeline_context.h"
#include "pipeline_reading.h"
#include "pipeline_validation32.h"
#include "pipeline_validation64.h"
#include "pipeline_symbol_collection32.h"
#include "pipeline_symbol_collection64.h"
#include "pipeline_symbol_filtering.h"
#include "pipeline_symbol_sorting.h"
#include "pipeline_symbol_printing.h"

int main(int argc, char **argv)
{
	struct arguments arguments;
	process_arguments(&arguments, argc, argv);

	for (int i = 0; i < arguments.files->length; i++)
	{
		struct pipeline_context context;
		init_pipeline_context(&context, arguments.flags, *(char **)vector_at(arguments.files, i), arguments.files->length > 1);

		pipeline_read_file(&context);

		switch (context.architecture)
		{
			case elf_x86:
				pipeline_validate32(&context);
				pipeline_collect_symbols32(&context);
				break;

			case elf_x86_64:
				pipeline_validate64(&context);
				pipeline_collect_symbols64(&context);
				break;

			default:
				exit(1);
		}

		pipeline_filter_symbols(&context);
		pipeline_sort_symbols(&context);
		pipeline_print_symbols(&context);

		free_pipeline_context(&context);
	}

	free_arguments(&arguments);

	return 0;
}
