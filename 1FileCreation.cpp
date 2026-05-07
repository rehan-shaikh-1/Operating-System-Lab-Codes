#include <iostream>
#include <fcntl.h>    // Fixed: was "fentlh"
#include <unistd.h>

using namespace std;

int main() {
    int fd;
    
    // Fixed: O_CREAT (Letter 'O', not zero) and added O_TRUNC to refresh the file
    fd = open("demo.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    
    if (fd == -1) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    write(fd, "OS Learning Made Easy", 21); // Fixed string and byte count
    close(fd);

    cout << "File created successfully" << endl;
    return 0;
}