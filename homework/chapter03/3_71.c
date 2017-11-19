#include <stdio.h>

#define MAX_INPUT_LENGTH 256

void good_echo()
{
    char buffer[MAX_INPUT_LENGTH];
    printf("Input:\t");
    if (fgets(buffer, MAX_INPUT_LENGTH, stdin) != NULL)
    {
        printf("Output:\t");
        fputs(buffer, stdout);
    }
    else
    {
        printf("Don't panic! Something is wrong. \n");
    }
}

int main()
{
    good_echo();

    return 0;
}
