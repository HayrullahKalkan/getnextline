#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_CREAT | O_RDWR , 0777);
    if (fd < 0)
    {
        perror("File opening failed");
        return 1;
    }

    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}




/*




#include <stdio.h>

int main(void)
{
    int fd1 = open("test1.txt",O_CREAT | O_RDWR , 0777);
    int fd2 = open("test2.txt", O_CREAT | O_RDWR , 0777);
    char *line1;
    char *line2;

    if (fd1 < 0 || fd2 < 0)
    {
        perror("File open error");
        return (1);
    }
while (1)
{
    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);

    if (!line1 && !line2)
        break;
    if (line1)
    {
        printf("FD1: %s", line1);
        free(line1);
    }
    if (line2)
    {
        printf("FD2: %s", line2);
        free(line2);
    }
}


    close(fd1);
    close(fd2);
    return (0);
}



*/
