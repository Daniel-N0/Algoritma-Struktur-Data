#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// Sequential Search
void sequentialSearch(const vector<int>& nums, int target) {
    vector<int> foundIndices;

    cout << "\n100 angka acak telah digenerate.\nNums:\n";
    for (int i = 0; i < nums.size(); i++) {
        cout << "[" << i << "]:" << nums[i] << " ";
    }
    cout << "\n\nMasukkan angka yang ingin dicari: ";
    cin >> target;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            foundIndices.push_back(i);
        }
    }

    if (!foundIndices.empty()) {
        cout << "\nTarget " << target << " ditemukan sebanyak " << foundIndices.size() << " kali di indeks: ";
        for (int i : foundIndices) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cout << "Target " << target << " tidak ditemukan dalam data.\n";
    }
}

// Binary Search
void binarySearch(const vector<int>& numsUnsorted, int target) {
    vector<int> nums = numsUnsorted;

    sort(nums.begin(), nums.end());

    cout << "\n" << nums.size() << " angka telah digenerate dan diurutkan.\nNums:\n";
    for (int i = 0; i < nums.size(); i++) {
        cout << "[" << i << "]:" << nums[i] << " ";
    }

    cout << "\n\nMasukkan angka yang ingin dicari: ";
    cin >> target;

    int kiri = 0, kanan = nums.size() - 1;
    int posisi = -1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (nums[tengah] == target) {
            posisi = tengah;
            break;
        } else if (target < nums[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    if (posisi != -1)
        cout << "\nTarget " << target << " ditemukan di index = " << posisi << "\n";
    else
        cout << "\nTarget tidak ditemukan dalam data.\n";
}

void clearScreen() {
    system("cls");
}

// Penjelasan
void explain() {
    cout << "\n=== PERBEDAAN SEQUENTIAL DAN BINARY SEARCHING ===\n";
    cout << "Sequential Search:\n";
    cout << "  - Tidak perlu data terurut.\n";
    cout << "  - Mencari satu-satu dari awal hingga akhir.\n";
    cout << "  - Waktu pencarian: O(n).\n\n";
    cout << "Binary Search:\n";
    cout << "  - Hanya bisa dilakukan pada data yang sudah terurut.\n";
    cout << "  - Membagi dua bagian data hingga ketemu.\n";
    cout << "  - Waktu pencarian: O(log n).\n";
}

int main() {
    int opt, target;

    do {
        cout << "\nPilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums(100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto& val : nums) {
                    val = dist(rng);
                }

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto& val : nums) {
                    val = dist(rng);
                }

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Program was made by Daniel Noprianto (2410817110010)\n";
                break;

            default:
                cout << "Opsi tidak valid. Coba lagi.\n";
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}