#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>
#include <iomanip>

void getMsg(std::vector<int> &encoded, int M);

using namespace std;
int main() {
    //1. ask user for e, n and m, where m is the amount of numbers to decrypt, then ask for the numbers to decrypt
    int e, n, m;
    std::cout << "Enter e: ";
    std::cin >> e;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter m: ";
    std::cin >> m;

    std::vector<int> encoded;
    getMsg(encoded, m);


return 0;
}


void getMsg(std::vector<int> &encoded, int M) {

  int a;
  for (int i = 0; i < M; i++) {
    while (!cin >> a) {
      cin.clear();
      cin.ignore();
    }

    encoded.push_back(a);
  }
}