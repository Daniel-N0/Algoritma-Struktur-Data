#include<iostream>

using namespace std;

struct data{
    char huruf; string kata; int angka;
};

int main(){
    struct data data1;

    cout << "a. Masukkan sebuah huruf = ";cin >> data1.huruf;
    cout << "b. Masukkan sebuah kata  = ";cin >> data1.kata;
    cout << "c. Masukkan Angka  = ";cin >> data1.angka;

    cout << "d. Huruf yang Anda masukkan adalah " << data1.huruf << endl;
    cout << "e. Kata yang Anda masukkan adalah " << data1.kata << endl;
    cout << "f. Angka yang Anda masukkan adalah " << data1.angka << endl;

    return 0;
}