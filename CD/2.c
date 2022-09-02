/*
2. Write a simple C code to remove spaces and new line enter characters and comment lines of a given input C program.

Input: A text file with a C program

Output: A text file of the above C program without any space between words and the whole program is in a single line. All comments to be removed from the input.
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *filePointer, *filePointer1;
    int f = 0;
    char c;
    filePointer = fopen("t_2.c", "r");
    filePointer1 = fopen("o_2.txt", "w");
    if (filePointer == NULL)
    {
        printf("t.txt file failed to open.");
        return 0;
    }
    else
    {
        while ((c = fgetc(filePointer)) != EOF)
        {
            if ((c == '/') && (f == 0))
            {
                f = 1;
                continue;
            }
            else if ((c == '/') && (f == 1))
            {
                f = 2;
                continue;
            }
            else if ((c == '*') && (f == 1))
            {
                f = 3;
                continue;
            }
            if (f == 2)
            {
                if (c == 'n')
                {
                    f = 0;
                }
                continue;
            }
            if (f == 3)
            {
                if (c == '*')
                {
                    f = 4;
                }
                continue;
            }
            if (f == 4)
            {
                if (c == '/')
                {
                    f = 0;
                }
                continue;
            }
            if (f == 0)
            {
                if ((c == 13) || (c == 10))
                {
                    continue;
                }
                else if ((c != ' '))
                {
                    fprintf(filePointer1, "%c", c);
                }
            }
        }
    }
    printf("Process Completed Check The file");
    fclose(filePointer);
    fclose(filePointer1);
    return 0;
}