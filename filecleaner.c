#include "filecleaner.h"


uint8_t destroy_file (const char *file_name)
{
    assert (file_name != NULL);
    if (file_name == NULL)
    {
        return ERROR_NULLPTR;
    }
    
    if (access(file_name, F_OK) == -1)
    {
        return ERROR_NOFILE;
    }
    
    
    uint64_t file_size = get_file_size (file_name);
    if (file_size == 0)
    {
        return ERROR_NULLSIZE;
    }
    
    
    FILE *file = fopen (file_name, "wb");
    if (file == NULL)
    {
        return ERROR_FOPEN;
    }
    
    uint8_t status = fill_in_file (file, file_size);
    fclose (file);
    assert (status == SUCCESS);
    
    int status_rm = remove (file_name);
    assert (status_rm == 0);
    if (status_rm)
    {
        return ERROR_RMFILE;
    }
    
    
    return status;
}


uint64_t get_file_size (const char *file_name)
{
    assert (file_name != NULL);
    if (file_name == NULL)
    {
        return 0;
    }
    
    
    struct stat buffer = {};
    int status = stat (file_name, &buffer);
    if (status != 0)
    {
        return 0;
    }
    
    
    return buffer.st_size;
}


uint8_t fill_in_file (FILE *file, const uint64_t file_size)
{
    assert (file != NULL);
    if (file == NULL)
    {
        return ERROR_NOFILE;
    }
    
    assert (file_size != 0);
    if (file_size == 0)
    {
        return ERROR_NULLSIZE;
    }
    
    
    void *buffer = calloc (BUFFER_SIZE, 1);
    assert (buffer != NULL);
    if (buffer == NULL)
    {
        return ERROR_ALLOC;
    }
    
    int status_buf = setvbuf (file, NULL, _IOFBF, BUFFER_SIZE);
    assert (status_buf == NULL);
    if (status_buf != NULL)
    {
        return ERROR_BUFFER;
    }
    
    
    size_t status = 0;
    for (uint64_t bytes_written = 0; bytes_written < file_size; bytes_written += BUFFER_SIZE)
    {
        size_t writing_size =
            (file_size - bytes_written >= BUFFER_SIZE) ? (BUFFER_SIZE) : (file_size % BUFFER_SIZE);
        
        status = fwrite (buffer, 1, writing_size, file);
        assert (status == writing_size);
        if (status != writing_size)
        {
            return ERROR_FWRITE;
        }
    }
    
    free (buffer);
    
    
    return SUCCESS;
}


const char *status_description (uint8_t status_code)
{
    switch (status_code)
    {
        case SUCCESS:
            return "Success, file destroyed";

        case ERROR_NULLPTR:
            return "Null pointer error";
            
        case ERROR_FOPEN:
            return "File opening error";

        case ERROR_NULLSIZE:
            return "File null size error";

        case ERROR_BUFFER:
            return "Buffer setting error";

        case ERROR_ALLOC:
            return "Memory allocation error";

        case ERROR_FWRITE:
            return "\'fwrite\' function erroe";

        case ERROR_RMFILE:
            return "File removing error";

        case ERROR_NOFILE:
            return "File existing error";

        default:
            return "Unknowen error";
    }
}

