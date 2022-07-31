#include "pipeline_symbol_sorting.h"

#include "libft_standart.h"
#include "flags.h"
#include "symbol.h"

void bubble_sort(void *objects, size_t count, size_t object_size, int (* comparer)(void *, void *))
{
	if (count == 0)
		return;

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			void *left = objects + j * object_size;
			void *right = objects + (j + 1) * object_size;

			if (comparer(left, right) > 0)
				swap_memory(left, right, object_size);
		}
	}
}

int symbol_comparer_ascending(void *left, void *right)
{
	struct symbol *left_symbol = left;
	struct symbol *right_symbol = right;

	return ft_strcmp(left_symbol->name, right_symbol->name);
}

int symbol_comparer_descending(void *left, void *right)
{
	struct symbol *left_symbol = left;
	struct symbol *right_symbol = right;

	return -ft_strcmp(left_symbol->name, right_symbol->name);
}

void pipeline_sort_symbols(struct pipeline_context *context)
{
	if (context->flags & NM_NO_SORT)
		return;

	int (*comparer)(void *, void *) = context->flags & NM_REVERSE_SORT ? symbol_comparer_descending : symbol_comparer_ascending;
	bubble_sort(context->symbols->storage, context->symbols->length, context->symbols->element_size, comparer);
}