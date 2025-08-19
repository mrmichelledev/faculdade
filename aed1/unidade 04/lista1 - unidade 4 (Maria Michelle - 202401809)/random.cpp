#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

const int N = 1e7;
int arr[N];

int main() {

    srand(time(0));
    for (int i = 0; i < N; ++i) {
        arr[i] = rand();
    }

    ofstream outFile("numeros_aleatorios.txt");
    
    // sort(arr, arr + N);

    for (int i = 0; i < N; ++i) {
        outFile << arr[i] << ' ';
    }
    outFile.close();
    return 0;
}