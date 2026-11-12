#include "header.h"

void comment_removal(char *file)
{
    int ch, next, prev = 0;
    FILE *fp,*new;
    char output[100];
    char temp[100];
    char *ptr;

    fp = fopen(file, "r");

    if(fp == NULL)
    {
        printf("File not present\n");
        return;
    }

    strcpy(output, file);
    ptr = strrchr(output, '.');

    if(ptr != NULL)
        strcpy(ptr, ".temp");
    else
        strcat(output, ".temp");

    new = fopen(output, "w");

    if(new == NULL)
    {
        printf("Cannot create output file\n");
        fclose(fp);
        return;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '/')
        {
            next = fgetc(fp);

            
            if(next == '/')         //single line comment
            {
                while((ch = fgetc(fp)) != '\n' && ch != EOF);

                if(ch == '\n')
                    fputc('\n', new);
            }

            
            else if(next == '*')         //Multi line comment
            {
                prev = 0;

                while((ch = fgetc(fp)) != EOF)
                {
                    if(ch == '\n')
                        fputc('\n', new);

                    if(prev == '*' && ch == '/')
                        break;

                    prev = ch;
                }
            }

           
            else                         //Not a comment
            {
                fputc(ch, new);

                if(next != EOF)
                    ungetc(next, fp);
            }
        }
        else
        {
            fputc(ch, new);
        }
    }

    fclose(fp);
    fclose(new);

    printf("Comments removed successfully. Output: %s\n", output);
}
