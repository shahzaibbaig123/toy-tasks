#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 8192

int main(int argc, char *argv[])
{

    FILE *fp;
    char *line = NULL;

    // size of input buffer
    size_t len = 0;
    ssize_t read;
    int lineNo = 1;

    fp = fopen(argv[2], "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1)
    {
        // read, %zu is contains the length of c
        // printf("Retrieved line of length %zu:\n", read);
        // printf("%s", line);

        if (strstr(line, argv[1]) != NULL)
        {
            printf("%d - %s", lineNo, line);
        }
        lineNo = lineNo + 1;
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
