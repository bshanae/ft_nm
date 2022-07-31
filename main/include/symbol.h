#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdint.h>

enum symbol_type
{
	symbol_type_absolute, // aA
	symbol_type_uninitialized_data, // bB
	symbol_type_common, // cC
	symbol_type_initialized_data, // dD
	symbol_type_initialized_small_data, // gG
	symbol_type_indirect, // iI
	symbol_type_stack_unwind, // pP
	symbol_type_read_only_data, // rR
	symbol_type_uninitialized_small_data, // sS
	symbol_type_code, // tT
	symbol_type_undefined, // U
	symbol_type_unique, // u
	symbol_type_weak_object, // v
	symbol_type_weak_object_with_default, // V
	symbol_type_weak, // w
	symbol_type_weak_with_default, // W
	symbol_type_unknown // ?
};

enum symbol_binding
{
	symbol_binding_undefined,
	symbol_binding_local,
	symbol_binding_global,
	symbol_binding_weak,
	symbol_binding_unique
};

struct symbol
{
	char *name;
	uint64_t value;
	enum symbol_type type;
	enum symbol_binding binding;
	t_bool is_section_undefined;
};

#endif
