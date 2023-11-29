#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    // Process the read data
    close(fd);
    return 0;
}
