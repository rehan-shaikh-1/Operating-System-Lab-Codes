#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Error handling
        cerr << "Fork failed!" << endl;
        return 1;
    } 
    else if (pid == 0) {
        // Child path
        cout << "Child Process | PID: " << getpid() << " | Parent PID: " << getppid() << endl;
    } 
    else {
        // Parent path
        cout << "Parent Process | PID: " << getpid() << " | Child PID: " << pid << endl;
    }

    return 0;
}