#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian()
{
   int multi_bytes = 1;
   unsigned char single_byte = 1;
   byte_pointer byte_ptr = (byte_pointer) &multi_bytes;

   return byte_ptr[0] = single_byte;
}

int main(void)
{
    if (is_little_endian())
    {
        printf("this is a little endian machine.\n");
    }
    else 
    {
        printf("this is a big endian machine.\n");    
    }

    return 0;
}
