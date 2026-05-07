#include <iostream>
using namespace std;

// First Fit: Allocates the first block that is large enough
void firstFit(int b[], int m, int p[], int n) {
    int a[n];
    for (int i = 0; i < n; i++) a[i] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[j] >= p[i]) {
                a[i] = j;
                b[j] -= p[i];
                break;
            }
        }
    }
    cout << "\nFirst Fit Allocation:\n";
    for (int i = 0; i < n; i++) {
        if (a[i] != -1)
            cout << "Process " << i + 1 << " -> Block " << a[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " -> Not Allocated\n";
    }
}

// Best Fit: Allocates the smallest block that is large enough
void bestFit(int b[], int m, int p[], int n) {
    int a[n];
    for (int i = 0; i < n; i++) a[i] = -1;
    for (int i = 0; i < n; i++) {
        int idx = -1;
        for (int j = 0; j < m; j++) {
            if (b[j] >= p[i]) {
                if (idx == -1 || b[j] < b[idx])
                    idx = j;
            }
        }
        if (idx != -1) {
            a[i] = idx;
            b[idx] -= p[i];
        }
    }
    cout << "\nBest Fit Allocation:\n";
    for (int i = 0; i < n; i++) {
        if (a[i] != -1)
            cout << "Process " << i + 1 << " -> Block " << a[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " -> Not Allocated\n";
    }
}

// Worst Fit: Allocates the largest available block
void worstFit(int b[], int m, int p[], int n) {
    int a[n];
    for (int i = 0; i < n; i++) a[i] = -1;
    for (int i = 0; i < n; i++) {
        int idx = -1;
        for (int j = 0; j < m; j++) {
            if (b[j] >= p[i]) {
                if (idx == -1 || b[j] > b[idx])
                    idx = j;
            }
        }
        if (idx != -1) {
            a[i] = idx;
            b[idx] -= p[i];
        }
    }
    cout << "\nWorst Fit Allocation:\n";
    for (int i = 0; i < n; i++) {
        if (a[i] != -1)
            cout << "Process " << i + 1 << " -> Block " << a[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " -> Not Allocated\n";
    }
}

// Next Fit: Similar to First Fit but starts searching from the last allocated block
void nextFit(int b[], int m, int p[], int n) {
    int a[n];
    for (int i = 0; i < n; i++) a[i] = -1;
    int last = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        while (count < m) {
            if (b[last] >= p[i]) {
                a[i] = last;
                b[last] -= p[i];
                break;
            }
            last = (last + 1) % m;
            count++;
        }
    }
    cout << "\nNext Fit Allocation:\n";
    for (int i = 0; i < n; i++) {
        if (a[i] != -1)
            cout << "Process " << i + 1 << " -> Block " << a[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " -> Not Allocated\n";
    }
}

int main() {
    int b1[] = {100, 500, 200, 300, 600};
    int b2[] = {100, 500, 200, 300, 600};
    int b3[] = {100, 500, 200, 300, 600};
    int b4[] = {100, 500, 200, 300, 600};
    int p[] = {212, 417, 112, 426};

    firstFit(b1, 5, p, 4);
    bestFit(b2, 5, p, 4);
    worstFit(b3, 5, p, 4);
    nextFit(b4, 5, p, 4);

    return 0;
}