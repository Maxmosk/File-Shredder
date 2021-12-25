/*!
    \file
    
    \author Maxmosk
    \brief File with functions for file shredding
    \version 1.0
    \date December, 2021
*/

#ifndef FILECLEANER_INCLUDED
#define FILECLEANER_INCLUDED


#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>


/*!
    \brief Enum for return codes of functions in this file
    \note Used only in functions with uint8_t type
*/
enum CODES
{
    SUCCESS = 0,        //!< Successful performance of the function
    ERROR_NULLPTR = 1,  //!< A null pointer was passed as a parameter
    ERROR_FOPEN = 2,    //!< Error in function 'fopen'
    ERROR_NULLSIZE = 3, //!< File has zero size
    ERROR_BUFFER = 4,   //!< Error in setting the buffer size for writing to a file
    ERROR_ALLOC = 5,    //!< Error in memory allocation function
    ERROR_FWRITE = 6,   //!< Error in function 'fwrite'
    ERROR_RMFILE = 7,   //!< Error in the removing file function
    ERROR_NOFILE = 8    //!< File with the specified name does not exist
};

/// Buffer size for filling the file with garbage
static const size_t BUFFER_SIZE = 1048576;


/*!
    \brief Function for destroying a file
    \param[in] file_name Name of file for destroying
    \return Code from enum CODES
*/
uint8_t destroy_file (const char *file_name);

/*!
    \brief Function for getting a file size
    \param[in] file_name Name of file for getting the size
    \return Size of file from stat or zero in case of null pointer error or stat error
*/
uint64_t get_file_size (const char *file_name);

/*!
    \brief Function for filling file by zeros
    \param[in] file Pointer to FILE for filling
    \param[in] fize_size Size of data for filling
    \return Code from enum CODES
*/
uint8_t fill_in_file (FILE *file, const uint64_t file_size);

/*!
    \brief Function for getting text description of CODES elements
    \param[in] status_code Element of CODES to get it's description
    \return Pointer to string with description of element of CODES
*/
const char *status_description (uint8_t status_code);


#endif

