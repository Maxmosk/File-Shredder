/*!
    \file
    
    \author Maxmosk
    \brief File with main program for file shredding
    \version 1.0
    \date December, 2021
*/

#define NDEBUG
#include <assert.h>
#include <stdio.h>
#include "filecleaner.h"


/*!
    \brief Function for shredding files from command line
*/
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

