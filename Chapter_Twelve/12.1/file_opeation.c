#include <unistd.h>

int main(int argc, char *argv[])
{
    char buffer[64];
    char* error_message = "open file error\n";
    char* success_message = "open file success\n";

    int fd = open("readme.txt", 0, 0);
    if (-1 == fd) {
        write(0, error_message, strlen(error_message));
        return -1;
    }

    write(0, success_message, strlen(success_message));

    read(fd, buffer, 64);

    closed(fd);
    return 0;
}