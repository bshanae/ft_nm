#include "tools_elf.h"

static int elf_validate_indent(char *data)
{
	if (ft_memcmp(data, ELFMAG, SELFMAG) != 0)
		return 1;
	if (data[EI_CLASS] <= ELFCLASSNONE || data[EI_CLASS] > ELFCLASS64)
		return 1;
	if (data[EI_DATA] <= ELFDATANONE || data[EI_DATA] > ELFDATA2MSB)
		return 1;
	if (data[EI_VERSION] != EV_CURRENT)
		return 1;

	return 0;
}

// x86_64 //////////////////////////////////////////////////////////////////////////////////////////

enum elf_validation_result elf64_validate(Elf64_Ehdr *elf, size_t file_size)
{
	if (elf_validate_indent((char *) elf) != 0)
		return elf_invalid_unrecognized_file;

	if (elf->e_type < ET_NONE || elf->e_type > ET_CORE)
		return elf_invalid_unrecognized_file;
	if (elf->e_machine > EM_CSKY)
		return elf_invalid_unrecognized_file;
	if (elf->e_version != EV_CURRENT)
		return elf_invalid_unrecognized_file;
	if (file_size < elf->e_shoff + (elf->e_shentsize * elf->e_shnum))
		return elf_invalid_unrecognized_file;
	if (elf->e_phentsize != 0 && elf->e_phentsize != sizeof(Elf64_Phdr))
		return elf_invalid_unrecognized_file;
	if (elf->e_shentsize != sizeof(Elf64_Shdr))
		return elf_invalid_unrecognized_file;
	if (file_size < elf->e_shoff + (elf->e_shentsize * elf->e_shnum))
		return elf_invalid_unrecognized_file;

	Elf64_Word string_table_size = elf64_get_section(elf, elf->e_shstrndx)->sh_size;
	int has_symbol_table = 0;
	for (int i = 0; i < elf->e_shnum; i++)
	{
		Elf64_Shdr *section = elf64_get_section(elf, i);

		if (section->sh_type == SHT_SYMTAB)
			has_symbol_table = 1;
		if (section->sh_name >= string_table_size)
			return elf_invalid_unrecognized_file;
		if (section->sh_link >= elf->e_shnum)
			return elf_invalid_unrecognized_file;
	}

	if (!has_symbol_table)
		return elf_invalid_no_symbols;

	return elf_valid;
}

void *elf64_get_ptr(Elf64_Ehdr *elf, Elf64_Off offset)
{
	return (void *)elf + offset;
}

Elf64_Shdr *elf64_get_section(Elf64_Ehdr *elf, size_t index)
{
	return elf64_get_ptr(elf, elf->e_shoff + index * sizeof(Elf64_Shdr));
}

// x86 ////////////////////////////////////////////////////////////////////////////////////////////

enum elf_validation_result elf32_validate(Elf32_Ehdr *elf, size_t file_size)
{
	if (elf_validate_indent((char *) elf) != 0)
		return elf_invalid_unrecognized_file;

	if (elf->e_type < ET_NONE || elf->e_type > ET_CORE)
		return elf_invalid_unrecognized_file;
	if (elf->e_machine > EM_CSKY)
		return elf_invalid_unrecognized_file;
	if (elf->e_version != EV_CURRENT)
		return elf_invalid_unrecognized_file;
	if (file_size < elf->e_shoff + (elf->e_shentsize * elf->e_shnum))
		return elf_invalid_unrecognized_file;
	if (elf->e_phentsize != 0 && elf->e_phentsize != sizeof(Elf32_Phdr))
		return elf_invalid_unrecognized_file;
	if (elf->e_shentsize != sizeof(Elf32_Shdr))
		return elf_invalid_unrecognized_file;
	if (file_size < elf->e_shoff + (elf->e_shentsize * elf->e_shnum))
		return elf_invalid_unrecognized_file;

	Elf32_Word string_table_size = elf32_get_section(elf, elf->e_shstrndx)->sh_size;
	int has_symbol_table = 0;
	for (int i = 0; i < elf->e_shnum; i++)
	{
		Elf32_Shdr *section = elf32_get_section(elf, i);

		if (section->sh_type == SHT_SYMTAB)
			has_symbol_table = 1;
		if (section->sh_name >= string_table_size)
			return elf_invalid_unrecognized_file;
		if (section->sh_link >= elf->e_shnum)
			return elf_invalid_unrecognized_file;
	}

	if (!has_symbol_table)
		return elf_invalid_no_symbols;

	return elf_valid;
}

void *elf32_get_ptr(Elf32_Ehdr *elf, Elf32_Off offset)
{
	return (char *)elf + offset;
}

Elf32_Shdr *elf32_get_section(Elf32_Ehdr *elf, size_t index)
{
	return elf32_get_ptr(elf, elf->e_shoff + index * sizeof(Elf32_Shdr));
}