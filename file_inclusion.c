#include "header.h"

void file_inclusion(char *file)
{
    FILE *fp, *new, *out;
    int c;
    char *ptr, *end, *ex;
    char line[500];
    char path[100];
    char filename[100];
    char output[100];

    fp = fopen(file, "r");

    if(fp == NULL)
    {
        printf("File not present\n");
        return;
    }

   
    strcpy(output, file);              // Generate output filename
    ex = strrchr(output, '.');

    if(ex != NULL)
        strcpy(ex, ".i");
    else
        strcat(output, ".i");

     
    out = fopen(output, "w");          // Open output file only once

    if(out == NULL)
    {
        printf("Cannot create output file\n");
        fclose(fp);
        return;
    }

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        if(strncmp(line, "#include", 8) == 0)
        {
            ptr = strchr(line, '<');

            if(ptr != NULL)
            {
                end = strchr(ptr, '>');

                if(end != NULL)
                {
                    strncpy(filename, ptr + 1, end - ptr - 1);
                    filename[end - ptr - 1] = '\0';

                    new = fopen(filename, "r");
           
 
                     if(new == NULL)
		     {
   		       strcpy(path, "/usr/include/");
    		       strcat(path, filename);
		       new = fopen(path, "r");
		     }
 
                    if(new == NULL)
                    {
                        printf("Header file not found: %s\n", filename);
                        fclose(fp);
                        fclose(out);
                        return;
                    }

                    while((c = fgetc(new)) != EOF)
                    {
                        fputc(c, out);
                    }

                    fclose(new);
                }
            }
        }
        else
        {
            fputs(line, out);
        }
    }

    fclose(fp);
    fclose(out);

    printf("File inclusion completed: %s\n", output);
}
