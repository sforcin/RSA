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
vector<int> decrypt(int d, int n, vector<int> nums);

int main() {
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
    for(int i = 2; i <= sqrt(n) && !found; ++i){
        if(n % i == 0){
            int j = n / i;
            if(isPrime(i) && isPrime(j) && i != j){
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
        return 0;
    }

    phi = (p-1) * (q-1); 
    cout << "phi: " << phi << endl;

    int d = modInverse(e, phi);
    if (d == -1) {
        cout << "Public key is not valid!" << endl; 
        return 0; 
    }
    cout << "d: " << d << endl;

    vector<int> decrypted;    
    decoder(d, n, encoded, decrypted); 

    cout << "Encrypted values: ";
    for(int i = 0; i < encoded.size(); i++) {
        cout << encoded.at(i) << " ";
    }
    cout << endl; 

    cout << "Decrypted values: ";
    for(int i = 0; i < decrypted.size(); i++) {
        cout << decrypted.at(i) << " ";
    }
    cout << endl;

    cout << "Decrypted message: " <<endl;
   
    for(int i = 0; i < decrypted.size(); i++) {
        int value = decrypted.at(i);
        if(value == 7) {
            cout << "A"; 
        } else if(value == 8) {
            cout << "B"; 
        } else if(value == 9) {
            cout << "C"; 
        } else if(value == 10) {
            cout << "D"; 
        } else if(value == 11) {
            cout << "E"; 
        } else if(value == 12) {
            cout << "F"; 
        } else if(value == 13) {
            cout << "G"; 
        } else if(value == 14) {
            cout << "H"; 
        } else if(value == 15) {
            cout << "I"; 
        } else if(value == 16) {
            cout << "J"; 
        } else if(value == 17) {
            cout << "K"; 
        } else if(value == 18) {
            cout << "L"; 
        } else if(value == 19) {
            cout << "M"; 
        } else if(value == 20) {
            cout << "N"; 
        } else if(value == 21) {
            cout << "O"; 
        } else if(value == 22) {
            cout << "P"; 
        } else if(value == 23) {
            cout << "Q"; 
        } else if(value == 24) {
            cout << "R"; 
        } else if(value == 25) {
            cout << "S"; 
        } else if(value == 26) {
            cout << "T"; 
        } else if(value == 27) {
            cout << "U"; 
        } else if(value == 28) {
            cout << "V"; 
        } else if(value == 29) {
            cout << "W"; 
        } else if(value == 30) {
            cout << "X"; 
        } else if(value == 31) {
            cout << "Y"; 
        } else if(value == 32) {
            cout << "Z"; 
        } else if(value == 33) {
            cout << " "; 
        } else if(value == 34) {
            cout << "\""; 
        } else if(value == 35) {
            cout << ","; 
        } else if(value == 36) {
            cout << "."; 
        } else if(value == 37) {
            cout << "'"; 
        }
    }
    cout << endl;

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

// int compute_mod(int base, int exp, int mod) {
//     long long result = 1;
//     long long baseMod = base % mod;

//     while (exp > 0) {
//         if (exp % 2 == 1) { // If exp is odd, multiply the result by baseMod
//             result = (result * baseMod) % mod;
//         }
//         baseMod = (baseMod * baseMod) % mod; // Square the base
//         exp /= 2; // Divide exp by 2
//     }
//     return static_cast<int>(result);
// }

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

vector<int> decrypt(int d, int n, vector<int> nums) {
    vector<int> newNums;
    for (int i = 0; i < nums.size(); i++) {
        long long answer = 1;
        long long curr = nums.at(i);
        long long exp = d;
        
        // Ensure curr is within modulus range initially
        curr = curr % n;
        
        while (exp > 0) {
            if (exp & 1) {  // Same as exp % 2 != 0
                answer = (answer * curr) % n;
            }
            curr = (curr * curr) % n;
            exp >>= 1;  // Same as exp / 2
        }
        newNums.push_back(static_cast<int>(answer));
    }
    return newNums;
}
