#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct stack{
    int data[MAX];
    int atas;
};
stack tumpuk;

int kosong(){
    if(tumpuk.atas == -1){
        return 1; 
    }
    else{
        return 0; 
    }
}

int penuh(){
    if(tumpuk.atas == MAX-1){
        return 1; 
    }
    else{
        return 0; 
    }
}

void input(int data){
    if(kosong()==1){
        tumpuk.atas++;
        tumpuk.data[tumpuk.atas] = data;
        cout << "Data " << tumpuk.data[tumpuk.atas]
            << " Masuk ke dalam stack" << endl;
    }
    else if (penuh()==0){
        tumpuk.atas++;
        tumpuk.data[tumpuk.atas] = data;
        cout << "Data " << tumpuk.data[tumpuk.atas]
            << " Masuk ke dalam stack" << endl;
    }
    else{
        cout << "Stack sudah penuh" << endl;
    }
}

void hapus(){
    if(kosong()==0){
        cout << "Data teratas sudah diambil" << endl;
        tumpuk.atas--;
    }
    else{
        cout << "Data kosong" << endl;
    }
}

void tampil(){
    if(kosong()==0){
        for(int i = tumpuk.atas; i >= 0; i--){
            cout << "\nStack ke " << i << "=" << tumpuk.data[i];
        }
        cout << endl;
    }
    else{
        cout << "Stack kosong" << endl;
    }
}

void bersih(){
    tumpuk.atas = -1;
    cout << "Stack sudah kosong!" << endl;
}

int pil;
char pilihan[2];

void init(){
    tumpuk.atas = -1;
}

int main(){
    init();
    do{
        cout << "\nSTACK" << endl;
        cout << "================" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Cetak Stack" << endl;
        cout << "4. Bersihkan Stack" << endl;
        cout << "5. Quit" << endl;
        cout << "Pilihan Anda: "; cin >> pilihan;
        pil = atoi(pilihan);
        switch(pil){
            case 1:
                int data;
                cout << "Masukkan Nilai: "; cin >> data;
                input(data);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        cout << "\nTekan apa saja untuk melanjutkan...";
        getch();
        system("cls");
    }

    while (pil != 5);
    return 0;
}