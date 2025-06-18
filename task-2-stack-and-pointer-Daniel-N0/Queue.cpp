#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct queue{
    int front, rear, size;
    int q[MAX];
};
queue antrian;

int isEmpty(){
    if(antrian.front == antrian.rear){ 
        return 1; 
    }
    else{
        return 0; 
    }
}

int isFull(){
    if((antrian.rear + 1)% antrian.size == antrian.front){ 
        return 1; 
    }
    else{
        return 0; 
    }
}

void INSERT(int x){
    if(isFull() == 1){
        cout << "Queue sudah penuh" << endl;
    }
    else{
        antrian.q[antrian.rear] = x;
        cout << "Data: " << antrian.q[antrian.rear] << " Masuk ke dalam Queue" << endl;
        antrian.rear = (antrian.rear + 1) % antrian.size;
    }
}

void DELETE(){
    if(isEmpty() == 1){
        cout << "Queue kosong" << endl;
    }
    else{
        cout << "Data yang dihapus: " << antrian.q[antrian.front] << endl;
        antrian.front = (antrian.front + 1) % antrian.size;
    }
}

void CETAKLAYAR(){
    if(isEmpty() == 1){
        cout << "Queue kosong" << endl;
    } 
    else{
        int i = antrian.front;
        int nomor = 0;
        while (i != antrian.rear){
            cout << "Queue ke-" << nomor << " = " << antrian.q[i] << endl;
            i = (i + 1) % antrian.size;
            nomor++;
        }
    }
}

void RESET(){
    antrian.front = 0;
    antrian.rear = 0;
    cout << "Queue sudah direset" << endl;
}

void Inisialisasi(){
    antrian.front = 0;
    antrian.rear = 0;
    antrian.size = MAX;
}

int pil;
char pilihan[2];

int main(){
    Inisialisasi();
    do{
        cout << "\nQUEUE" << endl;
        cout << "===========" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET QUEUE" << endl;
        cout << "5. QUIT" << endl;
        cout << "Pilihan Anda: "; cin >> pilihan;
        pil = atoi(pilihan);
        switch(pil){
            case 1:
                int x;
                cout << "Masukkan Nilai: "; cin >> x;
                INSERT(x);
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            case 4:
                RESET();
                break;
            case 5:
                cout << "Terima kasih" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
        cout << "Tekan Apa saja untuk melanjutkan...";
        getch();
        system("cls");
    } 
    while (pil != 5 );
    return 0;
}