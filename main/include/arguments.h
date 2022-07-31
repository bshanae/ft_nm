#ifndef OPTIONS_H
#define OPTIONS_H

#include "libft_vector.h"

struct arguments
{
	t_vector *files;
	unsigned flags;
};

void process_arguments(struct arguments *arguments, int argc, char **argv);
void free_arguments(struct arguments *arguments);


#endif