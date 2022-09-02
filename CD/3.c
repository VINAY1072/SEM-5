/*
3. Given a C program text file as input, write a C program and separate all Words and put all of them in an array.

For example if the text file has the following line "My name = Ramesh+Suresh" then the output will be

a[0]=My, a[1]=name, a[2]==, a[3]=Ramesh+Suresh

You can print the array as output on the screen.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *filePointer;
    char dataToBeRead[50];
    char c;
    char a[1000][1000];
    filePointer = fopen("t_3.c", "r");

    if (filePointer == NULL)
    {
        printf("t.txt file failed to open.");
    }
    else
    {
        int row = 0, col = 0, f = 0;
        while ((c = fgetc(filePointer)) != EOF)
        {
            if (c != ' ' && c != '\n')
            {
                a[row][col] = c;
                col++;
                f = 0;
            }
            if (f == 0 && (c == ' ' || c == '\n'))
            {
                a[row][col] = '\0';
                col = 0;
                row++;
                f = 1;
            }
        }
        a[row][col] = '\0';
        col = 0;
        row++;
        fclose(filePointer);
        printf("Array of strings are: \n");
        for (int i = 0; i < row; i++)
        {
            printf("%s\n", a[i]);
        }
    }
    return 0;
}