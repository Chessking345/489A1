#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
    
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    // Use stat instead of system to avoid any command injections
    struct stat st;
    if (stat(argv[1], &st) == 0) {
        printf("Size of %s: %ld bytes\n", argv[1], st.st_size);
    } else {
        perror("stat");
        return -1;
    }
}
