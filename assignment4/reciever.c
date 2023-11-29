// C program to implement one side of FIFO
// This side writes first, then reads
/*#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	int fd = open("my_pipe" , O_RDONLY);
	dup2(fd , STDIN_FILENO);
	close(fd);
	execlp("sort","sort",NULL);

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
#define NUMBERS_TO_RECEIVE 10

int main() {
    int numbers[NUMBERS_TO_RECEIVE];
    int fd;

    // Create the FIFO if it doesn't exist
    mkfifo(FIFO_NAME, 0666);

    // Open the FIFO for reading
    fd = open(FIFO_NAME, O_RDONLY);

    // Read the numbers from the FIFO
    read(fd, numbers, sizeof(numbers));

    // Close the FIFO
    close(fd);

    // Sorting the received numbers
    for (int i = 0; i < NUMBERS_TO_RECEIVE - 1; i++) {
        for (int j = 0; j < NUMBERS_TO_RECEIVE - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                // Swap the numbers
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // Display the sorted numbers
    printf("Sorted Numbers: ");
    for (int i = 0; i < NUMBERS_TO_RECEIVE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

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
    while (1) {
        int fd = open("my_pipe", O_RDONLY);
        char buffer[1024];
        ssize_t bytesread = read(fd, buffer, sizeof(buffer) - 1);
        if (bytesread > 0) {
            buffer[bytesread] = '\0';
            printf("%s", buffer);
        }
        close(fd);
    }
    return 0;
}
