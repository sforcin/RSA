#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

void getMsg(vector<int> &encoded, int M);
bool isPrime(int num);

int main() {
    // Ask user for e, n, and m, where m is the amount of numbers to decrypt, then ask for the numbers to decrypt
    int e, n, m, p = 0, q = 0, phi;
    cout << "Enter e: ";
    cin >> e;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    vector<int> encoded;
    getMsg(encoded, m);

    bool found = false;
    for (int i = 2; i <= sqrt(n) && !found; ++i) { // Start from 2 to avoid 0 and 1
        if (n % i == 0) { // i is a factor of n
            int j = n / i;
            if (isPrime(i) && isPrime(j) && i != j) { // Check if both i and j are primes
                p = i;
                q = j;
                found = true;
                break;
            }
        }
    }

    if (found) {
        cout << "p: " << p << endl;
        cout << "q: " << q << endl;
    } else {
        cout << "Failed to find distinct prime factors for n." << endl;
    }

    return 0;
}

void getMsg(vector<int> &encoded, int M) {
    int a;
    for (int i = 0; i < M; i++) {
        cout << "Enter number #" << (i + 1) << ": ";
        while (!(cin >> a)) {  // Loop until valid input
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number: ";
        }
        encoded.push_back(a);
    }
}

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2 || num == 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    int sqr_root = static_cast<int>(sqrt(num));
    for (int i = 5; i <= sqr_root; i += 2) { // Check only odd numbers beyond 2
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
