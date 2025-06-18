#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct TNode {
    string data;
    TNode *next;
};

TNode *head, *tail;

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {return (head == NULL);}

void tambahDepan() {
    string dataBaru;
    cout << "Masukkan data : "; cin >> dataBaru;

    TNode *baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
        tail->next = head;
    } else {
        baru->next = head;
        head = baru;
        tail->next = head;
    }

    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakang() {
    string dataBaru;
    cout << "Masukkan data : "; cin >> dataBaru;

    TNode *baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
        tail->next = head;
    } else {
        baru->next = head;
        tail->next = baru;
        tail = baru;
    }

    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian belakang." << endl;
}

void hapusDepan() {
    if (!isEmpty()) {
        TNode *hapus = head;
        string data = hapus->data;

        if (head == tail) {
            init();
        } else {
            head = head->next;
            tail->next = head;
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusBelakang() {
    if (!isEmpty()) {
        TNode *hapus = tail;
        string data = hapus->data;

        if (head == tail) {
            init();
        } else {
            TNode *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = head;
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di belakang telah berhasil dihapus." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void tampilkan() {
    if (!isEmpty()) {
        TNode *bantu = head;
        cout << "Data dalam Linked List: ";
        do {
            cout << bantu->data << " ";
            bantu = bantu->next;
        } while (bantu != head);
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void reset() {
    if (!isEmpty()) {
        TNode *bantu = head;
        do {
            TNode *hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        } while (bantu != head);

        init();
        cout << "Seluruh elemen pada Linked List telah dibersihkan." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void cariData() {
    if (!isEmpty()) {
        string cari;
        cout << "Masukkan data yang ingin dicari: "; cin >> cari;

        bool apaAda = false;
        TNode *bantu = head;
        cout << "Linked List: ";
        do {
            if (bantu->data == cari) {
                cout << "[" << bantu->data << "] ";
                apaAda = true;
            } else {
                cout << bantu->data << " ";
            }
            bantu = bantu->next;
        } while (bantu != head);

        cout << endl;

        if (!apaAda)
            cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusData() {
    if (!isEmpty()) {
        string cari;
        cout << "Masukkan data yang ingin dihapus: "; cin >> cari;

        bool apaAda = false;
        TNode *bantu = head;
        TNode *sebelum = tail;

        do {
            if (bantu->data == cari) {
                apaAda = true;
                if (bantu == head) {
                    hapusDepan();
                    bantu = head;
                    sebelum = tail;
                } else if (bantu == tail) {
                    hapusBelakang();
                    bantu = head;
                    sebelum = tail;
                } else {
                    sebelum->next = bantu->next;
                    delete bantu;
                    bantu = sebelum->next;
                }
            } else {
                sebelum = bantu;
                bantu = bantu->next;
            }
        } while (bantu != head);

        if (apaAda) cout << "Semua data \"" << cari << "\" telah dihapus dari Linked List." << endl;
        else cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void sisipkanSebelum() {
    if (!isEmpty()) {
        string nextData, dataBaru;
        cout << "Sisipkan data baru sebelum data: "; cin >> nextData;

        TNode *bantu = head;
        TNode *sebelum = tail;
        bool apaAda = false;

        do {
            if (bantu->data == nextData) {
                apaAda = true;
                break;
            }
            sebelum = bantu;
            bantu = bantu->next;
        } while (bantu != head);

        if (apaAda) {
            cout << "Masukkan data yang ingin ditambahkan: "; cin >> dataBaru;

            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu;
            sebelum->next = baru;

            if (bantu == head) head = baru;
            cout << "Data \"" << dataBaru << "\" berhasil disisipkan sebelum \"" << nextData << "\"." << endl;\

        } else cout << "Data \"" << nextData << "\" tidak ditemukan dalam Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void sisipkanSetelah() {
    if (!isEmpty()) {
        string prevData, dataBaru;
        cout << "Sisipkan data baru setelah data: "; cin >> prevData;

        TNode *bantu = head;
        bool apaAda = false;

        do {
            if (bantu->data == prevData) {
                apaAda = true;
                break;
            }
            bantu = bantu->next;
        } while (bantu != head);

        if (apaAda) {
            cout << "Masukkan data yang ingin ditambahkan: "; cin >> dataBaru;

            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu->next;
            bantu->next = baru;

            if (bantu == tail) {
                tail = baru;
            }

            cout << "Data \"" << dataBaru << "\" berhasil disisipkan setelah \"" << prevData << "\"." << endl;
        } else cout << "Data \"" << prevData << "\" tidak ditemukan dalam Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

int main() {
    init();
    int pil;

    do {
        cout << "Single Linked List Circular (SLLC)" << endl;
        cout << "==============================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Hapus Semua Elemen" << endl;
        cout << "7. Cari Data" << endl;
        cout << "8. Hapus Setiap Data Tertentu" << endl;
        cout << "9. Sisipkan Node/Data Baru Sebelum Data Tertentu" << endl;
        cout << "10. Sisipkan Node/Data Baru Setelah Data Tertentu" << endl;
        cout << "11. Quit" << endl;
        cout << "Pilihan: ";
        cin >> pil;

        switch (pil) {
            case 1: tambahDepan(); break;
            case 2: tambahBelakang(); break;
            case 3: hapusDepan(); break;
            case 4: hapusBelakang(); break;
            case 5: tampilkan(); break;
            case 6: reset(); break;
            case 7: cariData(); break;
            case 8: hapusData(); break;
            case 9: sisipkanSebelum(); break;
            case 10: sisipkanSetelah(); break;
            default:
            cout << "\nTERIMA KASIH" << endl;
            cout << "Program was made by Daniel Noprianto (2410817110010)." << endl;
        }

        cout << "\nPress any key to continue!" << endl;
        getch();
        system("cls");
        
    } while (pil != 11);

    return 0;
}