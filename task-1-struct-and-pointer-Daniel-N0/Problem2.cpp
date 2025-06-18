#include<iostream>

using namespace std;

struct kendaraan{
    string plat, jenis, pemilik, alamat, kota;
};

int main(){
    struct kendaraan kendaraan1 ={""
    "DA1234MK", "RUSH", "Andika Hartanto", "Jl. Kayu Tangi 1", "Banjarmasin"
    };
    
    cout << "a. Plat Nomor Kendaraan    : " << kendaraan1.plat << endl;
    cout << "b. Jenis Kendaraan         : " << kendaraan1.jenis << endl;
    cout << "c. Nama Pemilik            : " << kendaraan1.pemilik << endl;
    cout << "d. Alamat                  : " << kendaraan1.alamat << endl;
    cout << "e. Kota                    : " << kendaraan1.kota << endl;
    
    return 0;
}