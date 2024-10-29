#include <iostream> 
#include <string> 
#include <sstream> 
#include <cmath> 
#include <vector>
#include <limits>  
using namespace std; 


void getMsg(vector <int> &encoded, int M); 
bool isPrime(int num); 
bool isCoPrime(int a, int b); 
int get_d(int e, int phi); 
void decoder(int d, int n, const vector <int> &encrypted, vector <int> &decrypted); 
int compute_mod(int d, int n, int C); 


int main()
{

    // in take public key
    // in take cipher text
    // check if key is valid 
    // decode

    int e = 0; 
    int n = 0; 
    int m = 0; 
    int p = 0; 
    int q = 0; 
    int phi = 0; 
   // string c_text = ""; 

    //get inputs
   bool flag = true;

    // for e
    while (flag) {
        cin >> e;

        if (cin.fail()) {
            cin.clear(); // Clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the whole line
        } else {
            flag = false; // valid input, exit loop
        }
    }

    flag = true; // reset
    // for n
    while (flag == true) {
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            flag = false;
        }
    }

    flag = true;
    // for m
    while (flag == true) {
        cin >> m;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            flag = false;
        }
    }

    cin.clear(); cin.ignore(); 
    

   // cout << "You entered: e = " << e << ", n = " << n << ", m = " << m << endl;

    vector <int> e_msg; 
    //getMsg(e_msg, m); 
    
  for (int i = 0; i < m; i++) 
  {
        int num;
        cin >> num; 
        e_msg.push_back(num);
  }


   //check if public key is correct

   //find p and q
   bool found = false; 
   for(int i = 0; i <= n && found != true; ++i)
   {
        for(int j = i + 1; j <= n; ++j)
        {
            //make sure they are distinct
            if(i * j == n && i != j)
            {
                //make sure they are both primes
                if(isPrime(i) == true && isPrime(j) == true)
                {
                    
                    p = i; 
                    q = j; //p < q(j) -> bigger val
                    found = true; 
                    break; 
                }
            }
        }
   }

    //compute phi
    phi = (p-1) * (q-1); 

    //make sure they are co-prime
    if(isCoPrime(e, phi) == false || e < 1)
    {
        cout << "Public key is not valid!" << endl; 
        return 0; 
    }

    //compute d
    int d = get_d(e, phi); 

    if(d == -1)
    {
        cout << "Public key is not valid!" << endl; 
        return 0; 
    }


    //start decoding!
   vector <int> decrypt;    
   decoder(d, n, e_msg, decrypt); 


    //printing the keys
    cout << "p is: " << p << endl; 
    cout << "q is: " << q << endl; 
    cout << "phi is: " << phi << endl; 
    cout << "d is: " << d << endl; 

    //print integers
    for(int i = 0; i < e_msg.size(); i++)
    {  
    
        cout << e_msg.at(i) << " "; 

    }
    cout << endl; 

    //print english
    for(int i = 0; i < decrypt.size(); i++)
    {
        if(decrypt.at(i) == 7)
        {
            cout << "A"; 
        }
        else if(decrypt.at(i) == 8)
        {
            cout << "B"; 
        }
        else if(decrypt.at(i) == 9)
        {
            cout << "C"; 
        }
        else if(decrypt.at(i) == 10)
        {
            cout << "D"; 
        }
        else if(decrypt.at(i) == 11)
        {
            cout << "E"; 
        }
        else if(decrypt.at(i) == 12)
        {
            cout << "F"; 
        }
        else if(decrypt.at(i) == 13)
        {
            cout << "G"; 
        }
        else if(decrypt.at(i) == 14)
        {
            cout << "H"; 
        }
        else if(decrypt.at(i) == 15)
        {
            cout << "I"; 
        }
        else if(decrypt.at(i) == 16)
        {
            cout << "J"; 
        }
        else if(decrypt.at(i) == 17)
        {
            cout << "K"; 
        }
        else if(decrypt.at(i) == 18)
        {
            cout << "L"; 
        }
        else if(decrypt.at(i) == 19)
        {
            cout << "M"; 
        }
        else if(decrypt.at(i) == 20)
        {
            cout << "N"; 
        }
        else if(decrypt.at(i) == 21)
        {
            cout << "O"; 
        }
        else if(decrypt.at(i) == 22)
        {
            cout << "P"; 
        }
        else if(decrypt.at(i) == 23)
        {
            cout << "Q"; 
        }
        else if(decrypt.at(i) == 24)
        {
            cout << "R"; 
        }
        else if(decrypt.at(i) == 25)
        {
            cout << "S"; 
        }
        else if(decrypt.at(i) == 26)
        {
            cout << "T"; 
        }
        else if(decrypt.at(i) == 73)
        {
            cout << "U"; 
        }
        else if(decrypt.at(i) == 28)
        {
            cout << "V"; 
        }
        else if(decrypt.at(i) == 29)
        {
            cout << "W"; 
        }
        else if(decrypt.at(i) == 30)
        {
            cout << "X"; 
        }
        else if(decrypt.at(i) == 31)
        {
            cout << "Y"; 
        
        }
        else if(decrypt.at(i) == 32)
        {
            cout << "Z"; 
        
        }
        else if(decrypt.at(i) == 33)
        {
            cout << " "; 
        
        }
        else if(decrypt.at(i) == 34)
        {
            cout << "\""; 
        
        }
        else if(decrypt.at(i) == 35)
        {
            cout << ","; 
        
        }
        else if(decrypt.at(i) == 36)
        {
            cout << "."; 
        
        }
        else if(decrypt.at(i) == 37)
        {
            cout << "'"; 
        
        }

    }




// //    // test co-prime
// //     cout << "4, 5 is co-prime 1 " << isCoPrime(4, 5) << endl; 
// //     cout << "4, 6 is co-prime 0 " << isCoPrime(4, 6) << endl;  
// //     cout << "14, 15 is co-prime 1 " << isCoPrime(14, 15) << endl;  
// //     cout << "441, 2 is co-prime 1 " << isCoPrime(441, 2) << endl; 
// //     cout << "89, 9 is co-prime 1 " << isCoPrime(89, 9) << endl; 
   



    return 0; 
}

// void getMsg(vector <int> &encoded, int M)
// { 
//      if(M > 0)
//     {
//         int num = 0; 
//         cin >> num; 
//          for(int i = 1; i < M; i++)
//          {
//             while(!cin >> num)
//             {
//                 cin.clear(); 
//                 cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
//             }

//             encoded.push_back(num); 

//             cin >> num; 
            
//         }
//     } 
 
// }



bool isPrime(int num)
{
    if(num <= 1)
    {
        return false; 
    }

    if(num == 2 || num == 3)
    {
        return true; 
    }

    if(num % 2 == 0 || num % 3 == 0)
    {
        return false; 
    }

    int sqr_root = static_cast<int>(sqrt(num)); 
    
    for(int i = 5; i <= sqr_root; i++)
    {
        if(num % i == 0)
        {
           // cout << i << endl; 
            return false; 
        }
    }

    return true;  
}

bool isCoPrime(int a, int b)
{
    int sqr_root = 0; 
    if( a > b){sqr_root = static_cast<int>(sqrt(a));}
    else{sqr_root = static_cast<int>(sqrt(b));}

    for(int i = 2; i <= sqr_root; i++)
    {
        if( a % i == 0 && b % i == 0)
        {
            return false; 
        }
    }

    return true; 
}

int get_d(int e, int phi)
{
    int x0 = 1, x1 = 0; // coe for e 
    int y0 = 0, y1 = 1; // coe for phi

    while (e != 0) {
        int q = phi / e; // how many e's fit into phi
        int temp = e;
        e = phi % e; // mod
        phi = temp;  // e   (so you updated (e, phi) for gcd)


        int phiTemp = x1; 
        x1 = x0 - q * x1; //ie) 
        x0 = phiTemp;

        int eTemp = y1;
        y1 = y0 - q * y1;
        y0 = eTemp;
    }
    
    return phi; 

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