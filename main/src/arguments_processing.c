#include "arguments.h"

#include "flags.h"

void process_arguments(struct arguments *arguments, int argc, char **argv)
{
	arguments->flags = 0;
	arguments->files = vector_create(sizeof(char *));

	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			switch (argv[i][1])
			{
				case 'g':
					arguments->flags |= NM_DISPLAY_ONLY_EXTERN_SYMBOLS;
					break;

				case 'u':
					arguments->flags |= NM_DISPLAY_ONLY_UNDEFINED_SYMBOLS;
					break;

				case 'r':
					arguments->flags |= NM_REVERSE_SORT;
					break;

				case 'p':
					arguments->flags |= NM_NO_SORT;
					break;
			}

			continue;
		}

		vector_push(arguments->files, &argv[i]);
	}

	if (arguments->files->length == 0)
	{
		static const char *default_file_name = "a.out";
		vector_push(arguments->files, &default_file_name);
	}
}

void free_arguments(struct arguments *arguments)
{
	vector_destroy(&arguments->files);
}