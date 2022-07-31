#include "pipeline_symbol_filtering.h"

#include "flags.h"
#include "symbol.h"

static void filter_out_extern_symbols(t_vector *symbols)
{
	for (int i = 0; i < symbols->length; i++)
	{
		struct symbol *symbol = vector_at(symbols, i);
		if (symbol->binding == symbol_binding_local)
		{
			vector_erase(symbols, i);
			i--;
		}
	}
}

static void filter_out_undefined_symbols(t_vector *symbols)
{
	for (int i = 0; i < symbols->length; i++)
	{
		struct symbol *symbol = vector_at(symbols, i);
		if (!symbol->is_section_undefined)
		{
			vector_erase(symbols, i);
			i--;
		}
	}
}


void pipeline_filter_symbols(struct pipeline_context *context)
{
	if (context->flags & NM_DISPLAY_ONLY_EXTERN_SYMBOLS)
		filter_out_extern_symbols(context->symbols);
	if (context->flags & NM_DISPLAY_ONLY_UNDEFINED_SYMBOLS)
		filter_out_undefined_symbols(context->symbols);
}