#ifndef ELF_TOOLS_H
#define ELF_TOOLS_H

#include <stdlib.h>
#include "libft_standart.h"
#include "elf.h"

enum elf_architecture
{
	elf_invalid_architecture,
	elf_x86,
	elf_x86_64,
};

enum elf_validation_result
{
	elf_valid,
	elf_invalid_unrecognized_file,
	elf_invalid_no_symbols
};

enum elf_validation_result elf64_validate(Elf64_Ehdr *elf, size_t file_size);
void *elf64_get_ptr(Elf64_Ehdr *elf, Elf64_Off offset);
Elf64_Shdr *elf64_get_section(Elf64_Ehdr *elf, size_t index);

enum elf_validation_result elf32_validate(Elf32_Ehdr *elf, size_t file_size);
void *elf32_get_ptr(Elf32_Ehdr *elf, Elf32_Off offset);
Elf32_Shdr *elf32_get_section(Elf32_Ehdr *elf, size_t index);

#endif
