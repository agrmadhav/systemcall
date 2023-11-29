// C program to implement one side of FIFO
// This side reads first, then reads
/*#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
int main()
{
	mkfifo("my_pipe", 0666);
	int fd = open("my_pipe",O_WRONLY);
	dup2(fd , STDOUT_FILENO);
	close(fd);
	execlp("ls","ls","-l",NULL) ;
	return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"
#define NUMBERS_TO_SEND 10

int main() {
    int numbers[NUMBERS_TO_SEND] = {5, 3, 8, 1, 9, 2, 7, 4, 10, 6};
    int fd;

    // Create the FIFO if it doesn't exist
    mkfifo(FIFO_NAME, 0666);

    // Open the FIFO for writing
    fd = open(FIFO_NAME, O_WRONLY);

    // Write the numbers to the FIFO
    write(fd, numbers, sizeof(numbers));

    // Close the FIFO
    close(fd);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main() {
    mkfifo("my_pipe", 0777);
    while (1) {
        char *message;
        message = (char *)malloc(100 * sizeof(char));
        fgets(message, 100, stdin);
        int fd = open("my_pipe", O_WRONLY);
        write(fd, message, strlen(message));
        close(fd);
        free(message);
    }
    return 0;
}
