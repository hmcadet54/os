#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    int file = open("data.txt", O_WRONLY | O_APPEND);
    if (file == -1) {
        perror("Error opening file");
        return 1;
    }

    if (lseek(file, 0, SEEK_END) == -1) {
        perror("Error seeking file");
        close(file);
        return 1;
    }

    // Write the string to the file
    if (write(file, argv[1], strlen(argv[1])) == -1) {
        perror("Error writing to file");
        close(file);
        return 1;
    }

    // Close the file
    if (close(file) == -1) {
        perror("Error closing file");
        return 1;
    }

    printf("String appended to file successfully.\n");

    return 0;
}
