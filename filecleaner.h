#ifndef FILECLEANER_INCLUDED
#define FILECLEANER_INCLUDED

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>


enum CODES
{
    SUCCESS = 0,
    ERROR_NULLPTR = 1,
    ERROR_FOPEN = 2,
    ERROR_NULLSIZE = 3,
    ERROR_BUFFER = 4,
    ERROR_ALLOC = 5,
    ERROR_FWRITE = 6,
    ERROR_RMFILE = 7,
    ERROR_NOFILE = 8
};

static const size_t BUFFER_SIZE = 1048576;


uint8_t destroy_file (const char *file_name);

uint64_t get_file_size (const char *file_name);

uint8_t fill_in_file (FILE *file, const uint64_t file_size);

char *status_description (uint8_t status_code);

#endif

