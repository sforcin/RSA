#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool is_prime(int n) {
    if (n == 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_valid(int e, int phi, int p, int q) {
    if (!is_prime(p) || !is_prime(q)) {
        return false;
    }
    if (p == q) {
        return false;
    }
    if (gcd(e, phi) != 1) {
        return false;
    }
    return true;
}

void setPQ(int n, int &p, int &q) {
    for (int i = 2; i < n; i++) {
        if (is_prime(i)) {
            if (n % i == 0) {
                p = i;
                q = n / p;
                break;
            }
        }
    }
}

int findPhi(int p, int q) {
    return (p - 1) * (q - 1);
}

int decryptionKey(int phi, int e) {
    int d = 1;
    int multiple = d * e;

    while (multiple % phi != 1) {
        d++;
        multiple = d * e;
    }
    return d;
}

vector<int> takeInput(int len) {
    int value;
    vector<int> userInput;
    for (int i = 0; i < len; i++) { // fix taking input
        cin >> value;
        userInput.push_back(value);
    }
    return userInput;
}

vector<int> decrypt(int d, int phi, vector<int> nums) {
    vector<int> newNums;
    for (int i = 0; i < nums.size(); i++) {
        unsigned int iter = d;
        int answer = 1;
        long curr = nums.at(i);

        while (iter > 0) {
            if (iter % 2 != 0) {
                answer = (answer * curr) % phi;
            }
            iter = iter / 2;
            curr = (curr * curr) % phi;
        }
        newNums.push_back(answer);
    }
    return newNums;
}

string convertToAlpha(vector<int> nums) {
    string outcome = "";
    for (int i = 0; i < nums.size(); i++) {
        if (nums.at(i) >= 7 && nums.at(i) <= 32) {
            outcome += char(58 + nums.at(i));
        }
        else if (nums.at(i) == 33) {
            outcome += " ";
        }
        else if (nums.at(i) == 34) {
            outcome += "\"";
        }
        else if (nums.at(i) == 35) {
            outcome += ",";
        }
        else if (nums.at(i) == 36) {
            outcome += ".";
        }
        else if (nums.at(i) == 37) {
            outcome += "'";
        }
    }
    return outcome;
}

void printVector(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums.at(i) << " ";
    }
    cout << endl;
}

int main() {
    int e = 0;
    int n = 0;

    cin >> e >> n;
    int m = 0;
    cin >> m;
    vector<int> usersCode = takeInput(m);

    int p = 0;
    int q = 0;
    setPQ(n, p, q);
    int phi = findPhi(p, q);

    if (!is_valid(e, phi, p, q)) {
        cout << "Public key is not valid!" << endl;
        return 0;
    }

    int d = decryptionKey(phi, e);

    cout << p << " " << q << " " << phi << " " << d << endl;

    vector<int> encrypted = decrypt(d, n, usersCode);
    printVector(encrypted);

    cout << convertToAlpha(encrypted) << endl;

    return 0;
}
