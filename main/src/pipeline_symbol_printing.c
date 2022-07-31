#include "pipeline_symbol_printing.h"

#include "libft_ft_printf.h"
#include "symbol.h"

void print_symbol_value32(struct symbol *symbol)
{
	if (symbol->is_section_undefined)
		ft_printf("        ");
	else
		ft_printf("%08lx", symbol->value);
}

void print_symbol_value64(struct symbol *symbol)
{
	if (symbol->is_section_undefined)
		ft_printf("                ");
	else
		ft_printf("%016lx", symbol->value);
}

void print_symbol_character(struct symbol *symbol)
{
	static const int uppercase_offset = 'A' - 'a';
	const int uppercase_offset_if_global = symbol->binding == symbol_binding_global ? uppercase_offset : 0;

	switch (symbol->type)
	{
		case symbol_type_absolute:
			ft_printf("%c", 'a' + uppercase_offset_if_global);
			break;

		case symbol_type_uninitialized_data:
			ft_printf("%c", 'b' + uppercase_offset_if_global);
			break;

		case symbol_type_common:
			ft_printf("%c", 'c' + uppercase_offset_if_global);
			break;

		case symbol_type_initialized_data:
			ft_printf("%c", 'd' + uppercase_offset_if_global);
			break;

		case symbol_type_initialized_small_data:
			ft_printf("%c", 'g' + uppercase_offset_if_global);
			break;

		case symbol_type_indirect:
			ft_printf("%c", 'i' + uppercase_offset_if_global);
			break;

		case symbol_type_stack_unwind:
			ft_printf("%c", 'p' + uppercase_offset_if_global);
			break;

		case symbol_type_read_only_data:
			ft_printf("%c", 'r' + uppercase_offset_if_global);
			break;

		case symbol_type_uninitialized_small_data:
			ft_printf("%c", 's' + uppercase_offset_if_global);
			break;

		case symbol_type_code:
			ft_printf("%c", 't' + uppercase_offset_if_global);
			break;

		case symbol_type_undefined:
			ft_printf("U");
			break;

		case symbol_type_unique:
			ft_printf("u");
			break;

		case symbol_type_weak_object:
			ft_printf("v");
			break;

		case symbol_type_weak_object_with_default:
			ft_printf("V");
			break;

		case symbol_type_weak:
			ft_printf("w");
			break;

		case symbol_type_weak_with_default:
			ft_printf("W");
			break;

		case symbol_type_unknown:
			ft_printf("?");
			break;

	}
}

void print_symbol_name(struct symbol *symbol)
{
	ft_printf(symbol->name);
}

void pipeline_print_symbols(struct pipeline_context *context)
{
	if (context->are_multiple_files_passed)
	{
		ft_printf("\n");
		ft_printf("%s:\n", context->file_name);
	}

	for (int i = 0; i < context->symbols->length; i++)
	{
		struct symbol *symbol = vector_at(context->symbols, i);

		if (context->architecture == elf_x86)
			print_symbol_value32(symbol);
		else if (context->architecture == elf_x86_64)
			print_symbol_value64(symbol);

		ft_printf(" ");
		print_symbol_character(symbol);
		ft_printf(" ");
		print_symbol_name(symbol);
		ft_printf("\n");
	}
}