// Vinay Parampalli
// CS20B1072
// Question)) Print Symbol table

#include <stdio.h>
#include <string.h>

struct SYMBOL_TABLE
{
    char Token[100];
    char Attribute1[100];
    char Attribute2[100];
};

int main()
{
    FILE *filepointer = fopen("t_5.txt", "r");
    struct SYMBOL_TABLE T[100];
    char te[100], te1[100], te2[100];
    char keywords[9][100] = {"#include", "<string.h>", "int", "<stdio.h>", "main", "float", "char", "double", "return"};
    char charecter;
    int f1 = 0, f = 0, f2 = 0;
    int l = 0, t = 0, x = 0, i = 0, length;
    int r = 7, c = 0;

    if (filepointer == NULL)
    {
        printf("t.txt file failed to open.");
    }
    else
    {
        do
        {
            charecter = fgetc(filepointer);
            if (charecter != ')' && charecter != '(' && charecter != '{' && charecter != '}' && charecter != ':' && charecter != '=' && charecter != ';' && charecter != ',' && charecter != ' ' && charecter != '\n')
            {
                te[i] = charecter;
                i++;
            }
            if (charecter == ',')
            {
                for (x = 0; x < i; x++)
                {
                    T[t].Token[x] = te[x];
                }
                T[t].Token[x] = '\0';
                if (f2 == 1)
                {
                    for (l = 0; l < length; l++)
                    {
                        T[t].Attribute1[l] = te1[l];
                    }
                    T[t].Attribute1[l] = '\0';
                }
                t++;
                f = 1;
            }
            if (strcmp(te, "int") == 0 || strcmp(te, "float") == 0 || strcmp(te, "char") == 0 || strcmp(te, "double") == 0)
            {
                for (l = 0; l < i; l++)
                {
                    te1[l] = te[l];
                }
                length = i;
                te1[l] = '\0';
                f2 = 1;
            }
            if (charecter == '=')
            {
                strcpy(te2, te);
                f1 = 1;
                f = 1;
            }

            if (charecter == ';')
            {
                te[i] = '\0';
                if (f1 == 1)
                {
                    for (x = 0; x < t; x++)
                    {
                        if (strcmp(te2, T[x].Token) == 0)
                        {
                            break;
                        }
                    }
                    for (l = 0; l < i; l++)
                    {
                        T[x].Attribute2[l] = te[l];
                    }
                    T[x].Attribute2[l] = '\0';
                }
                else
                {
                    for (x = 0; x < i; x++)
                    {
                        T[t].Token[x] = te[x];
                    }
                    T[t].Token[x] = '\0';

                    if (f2 == 1)
                    {
                        for (l = 0; l < length; l++)
                        {

                            T[t].Attribute1[l] = te1[l];
                        }
                        T[t].Attribute1[l] = '\0';

                        f2 = 0;
                    }
                    t++;
                }
                f = 1;
                f1 = 0;
            }

            if (f == 0)
            {
                for (int j = 0; j < r; j++)
                {
                    if (strcmp(te, keywords[j]) == 0)
                    {
                        f = 1;
                        break;
                    }
                    f = 0;
                }
            }

            if (f == 1)
            {
                for (int j = 0; j < i; j++)
                {
                    te[j] = '\0';
                }
                i = 0;
                f = 0;
            }

        } while (charecter != EOF);
        printf("---------------- The Symbol Table will be ---------------\n");
        printf("Token\t\tAttribute_1\tAttribute_2\n");
        for (l = 0; l < t - 1; l++)
        {
            printf("%s\t\t%s\t\t%s\n", T[l].Token, T[l].Attribute1, T[l].Attribute2);
        }
    }
}