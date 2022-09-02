/*
1. Write a simple C code to remove spaces and new line enter characters of a given input C program.

Input: A text file with a C program

Output: A text file of the above C program without any space between words and the whole program is in a single line.

*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *filePointer, *filePointer1;
    char dataToBeRead[50];
    filePointer = fopen("t_1.c", "r");
    filePointer1 = fopen("o.txt", "w");

    if (filePointer == NULL)
    {
        printf("t.txt file failed to open.");
    }
    else
    {
        int i, k = 0;
        while (fgets(dataToBeRead, 50, filePointer) != NULL)
        {
            int l = strlen(dataToBeRead);
            for (i = 0; i < l; i++)
            {
                if (dataToBeRead[i] == ' ' || dataToBeRead[i] == '\t' || dataToBeRead[i] == '\n')
                {
                    for (int j = i; j < l; j++)
                    {
                        dataToBeRead[j] = dataToBeRead[j + 1];
                    }
                    l--;
                    i--;
                }
            }
            fprintf(filePointer1, "%s", dataToBeRead);
        }
        printf("Process Completed Check The file");
        fclose(filePointer);
        fclose(filePointer1);
    }
    return 0;
}