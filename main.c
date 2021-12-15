#define NDEBUG
#include <assert.h>
#include <stdio.h>
#include "filecleaner.h"


int main (int argc, char *argv[])
{
    assert (argc == 2);
    if (argc != 2)
    {
        printf ("Incorrect number of command line arguments\n");
        return 0;
    }
    
    
    printf ("%s\n", status_description (destroy_file (argv[1])));
    
    
    return 0;
}

