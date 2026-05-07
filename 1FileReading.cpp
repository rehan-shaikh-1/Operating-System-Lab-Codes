#include <iostream>
#include <fcntl.h>    // Fixed header name
#include <unistd.h>

using namespace std;

int main() {
    int fd;
    char buffer[50] = {0}; // Initialize with zeros to avoid "garbage" text

    // Fixed: O_RDONLY (Letter O, not zero)
    fd = open("demo.txt", O_RDONLY);
    
    if (fd == -1) {
        cerr << "Error: Could not open file. Make sure 'demo.txt' exists!" << endl;
        return 1;
    }

    // Read up to 50 bytes into the buffer
    ssize_t bytesRead = read(fd, buffer, 50);
    
    // Write the content to Standard Output (File Descriptor 1)
    write(1, buffer, bytesRead);

    close(fd);
    cout << "\n\nFile read successfully." << endl;

    return 0;
}