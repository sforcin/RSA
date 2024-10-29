#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

void getMsg(vector<int> &encoded, int M);
bool isPrime(int num);
bool isTwoPrimes(int n);
int modInverse(int e, int phi);
void decoder(int d, int n, const vector <int> &encrypted, vector <int> &decrypted);
int compute_mod(int d, int n, int C);

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
//find p and q, using a bool to know when the values are found
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

int d = modInverse(e, phi);
cout<<"d: "<<d<<endl;

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


/*
logic:
    1. if n is less than 4, the number cannot be a product of two primes (2*2)
    2. check all numbers from 2, to sqrt(n), if i is a factor of n
    3. if i is a factor of n, then j = n/i
    4. check if i and j are primes and not the same
    5. if all conditions are met, return true
    6. otherwise,return false
*/
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

int modInverse(int e, int phi) {
    int t = 0, newT = 1;
    int r = phi, newR = e;

    while (newR != 0) {
        int quotient = r / newR;

        int tempT = newT;
        newT = t - quotient * newT;
        t = tempT;

        int tempR = newR;
        newR = r - quotient * newR;
        r = tempR;
    }

    if (r > 1) return -1; // No modular inverse if gcd(e, phi) != 1
    if (t < 0) t += phi;  // Ensure positive result
    return t;
}

void decoder(int d, int n, const vector <int> &encrypted, vector <int> &decrypted) 
{
    int num; 
    for(int i = 0; i < encrypted.size(); i++)
    {
        num = compute_mod(d, n, encrypted.at(i)); 
        decrypted.push_back(num); //create vector of decrupted integers
    }

}

int compute_mod(int d, int n, int C)
{
    vector <int> factors; 
    int base = C; //cout << "C is " << C << endl; 
    int power = d; //cout << "power is " << d << endl; 
    int mod = n; //cout << "n is " << n << endl; 
    long long int product = 1; 
    int operand = 1; 

    while(power != 2)
    {
        //base  < mod && power is big 
        //base > mod then evaluate mod
        if(base < mod)
        {
            //cout << "base < mod" << endl; 
           // cout << "base is " << base << endl << "power is " << power << endl; 
            if(power % 2 == 0) //squareing by exponentiation
            {
                //cout << "even powered " << endl << endl; 
                base = base * base;
                //cout << "base^2 is " << base << endl;  
                power = power / 2; 
               // cout << "power is " << power << endl; 
            }
            else
            {
                // cout << "odd powered " << endl << endl; 
                // cout << "base is" << base << endl; 
                factors.push_back(base); 
                power = power - 1; //if odd power -> make even
                //cout << "power is " << power << endl; 
            }
        }
        else if (base > mod)
        {
            //cout << "base > mod " << base << endl; 
            base %= mod; 
           // cout << "base modded" << base << endl; 
        }

        if(power == 1)
        {
            break; 
        }

    }

    //cout << endl << "<3<3<3<3" << endl; 

    //actually compute the number

    //multiply all the factored out numbers
    //cout << "the factors" << endl; 
    for(int i = 0; i < factors.size(); i++)
    {
        product = product * factors.at(i); 
        product %= mod; 
    }

    if(power == 1)
    {
        operand = base % mod; 
    } 
    else
    {
        operand = (base * base) % mod; 
    }

    
    product = operand * product; 
   // cout << "Product is " << product % mod << endl; 
    
    return product % mod; 

}