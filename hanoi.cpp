#include<iostream>
#include<string>
using namespace std;
void hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    hanoi(n - 1, source, auxiliary, destination);
    std::cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    hanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    hanoi(n,'a','c','b');

    return 0;
}