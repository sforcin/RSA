#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

void getMsg(vector<int> &encoded, int M);
bool isPrime(int num);
bool isTwoPrimes(int n);

int main() {
    // Ask user for e, n, and m, where m is the amount of numbers to decrypt, then ask for the numbers to decrypt
    int e, n, m, p = 0, q = 0, phi;
    cout << "Enter e: ";
    cin >> e;
    if(e < 1){
        cout << "e is not valid!" << endl;
        return 0;
    }
    cout << "Enter n: ";
    cin >> n;

    if (!isTwoPrimes(n)) {
        cout << "n is not a product of two distinct primes" << endl;
        return 0;
    }

    cout << "Enter m: ";
    cin >> m;

    vector<int> encoded;
    getMsg(encoded, m);

   bool found = false; 
   for(int i = 0; i <= n && found != true; ++i){
        for(int j = i + 1; j <= n; ++j){
            //make sure they are distinct
            if(i * j == n && i != j){
                //make sure they are both primes
                if(isPrime(i) == true && isPrime(j) == true){
                    p = i; 
                    q = j; //p < q(j) -> bigger val
                    found = true; 
                    break; 
                }
            }
        }
   }
    if (found) {
        cout << "p: " << p << endl;
        cout << "q: " << q << endl;
    } else {
        cout << "Failed to find distinct prime factors for n." << endl;
    }

        phi = (p-1) * (q-1); 
        cout<<"phi: "<<phi<<endl;

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
        return false; // 0 and 1 are not prime
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

bool isTwoPrimes(int n) {
    if (n < 4) return false;  
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {  // if i is a factor
            int j = n / i;  // divide to get j, then check if j and i are primes and not the same
            if (isPrime(i) && isPrime(j) && i != j) {
                return true;
            }
        }
    }
    return false;
}