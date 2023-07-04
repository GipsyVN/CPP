#include <iostream>
#include <fstream>
#include <thread>
#include <conio.h>
#define max 100

using namespace std;

struct customer{
    string nama;
    string noHp;
    string gol;
    string alamat;
};

customer antri[max], record[max];
int head = -1, tail = -1, head1 = -1, tail1 = -1;

//Pemeriksaan Dasar Array
bool isEmpty() {
    if (tail == -1)
        return true;
    else
        return false;
}

bool isEmpty1() {
    if (tail1 == -1)
        return true;
    else
        return false;
}

bool isFull() {
    if (tail == max - 1)
        return true;
    else
        return false;
}

bool isFull1(){
    if (tail1 == max - 1)
        return true;
    else
        return false;
}

//Menambah Antrian Pasien
void tambah() {
    if (isFull() == true){
        system("cls");
        cout << "Antrian penuh!!";
        cout << "\n===============================\n";
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
    }
    else {
        system("cls");
        customer baru;
        cout << "Masukan Nama\t: ";
        getline(cin, baru.nama);
        cout << "Masukan No HP\t: ";
        getline(cin, baru.noHp);
        cout << "Masukan Golongan Darah\t: ";
        getline(cin, baru.gol);
        cout << "Masukan Alamat\t: ";
        getline(cin, baru.alamat);

        // Memeriksa apakah data telah diisi dengan lengkap
        if (baru.nama.empty() || baru.noHp.empty() || baru.gol.empty() || baru.alamat.empty()) {
            cout << "Data belum diisi dengan lengkap. Silakan isi ulang.\n";
            cout << "\n===============================\n";
            cout << "Tekan Enter untuk mengisi data...";
            cin.get();
            tambah();
            return;
        }

        tail++;
        antri[tail] = baru;
        cout << "Antrian ditambahkan";
        cout << "\n===============================\n";
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
    }
}

//Proses Antrian
void proses() {
    if  (isFull() == true && head == tail){
        system("cls");
        cout << "Antrian telah ditutup";
        cout << "\n===============================\n";
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
    } else if  (isEmpty() == true || head == tail){
        system("cls");
        cout << "Antrian Kosong";
        cout << "\n===============================\n";
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
    } else {
        char p;
        do {
            system("cls");
            cout << "Sisa antrian yang tersedia: " << endl;
            //Mencetak sisa antrian pasien
            for (int i = head + 1; i <= tail; i++){
                cout << i + 1 << "\t";
            }
            cout << endl;
            cout << "No. Antrian yang akan diproses: " << head + 2 << endl;
            cout << "Nama\t\t: " << antri[head + 1].nama << endl;
            cout << "Nomor HP\t: " << antri[head + 1].noHp << endl;
            cout << "Gologan Darah\t: " << antri[head + 1].gol << endl;
            cout << "Alamat\t\t: " << antri[head + 1].alamat << endl;

            cout << "Apakah Anda yakin akan didiagnosa? [y/n/c]: ";
            cin >> p;
            if (p == 'y' || p == 'Y') {
                head++;
                tail1++;
                record[tail1] = antri[head];
                cout << "===============================\n";
                cout << "Tekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                break;
            } else if (p == 'n' || p == 'N') {
                if (tail - head >= 3){
                    customer temp = antri[head + 1];
                    antri[head + 1] = antri[head + 2];
                    antri[head + 2] = antri[head + 3];
                    antri[head + 3] = temp;
                } else if (tail - head == 2) {
                    customer temp = antri[head + 1];
                    antri[head + 1] = antri[head + 2];
                    antri[head + 2] = temp;
                }
            }
        } while (p != 'c');
    }
}

void tampilrecord(){
    if (isEmpty1() == true){
        system("cls");
        cout << "Antrian Kosong";
        cout << "\n===============================\n";
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
    }else {
        system("cls");
        cout << "Data Pelanggan: " << endl;
        for (int i = 0; i <= tail1; i++) {
            cout << "Pelanggan " << i + 1 << ":" << endl;
            cout << "Nama\t\t: " << record[i].nama << endl;
            cout << "Nomor HP\t: " << record[i].noHp << endl;
            cout << "Golongan Darah\t: " << record[i].gol << endl;
            cout << "Alamat\t\t: " << record[i].alamat << endl;
            cout << "===================================" << endl;
        }

        char p;
        cout << "Apakah Anda ingin menyimpan data ke dalam file 'record.txt'? [y/n]: ";
        cin >> p;
        if (p == 'y' || p == 'Y') {
            ofstream file("record.txt");
            if (file.is_open()) {
                for (int i = 0; i <= tail1; i++) {
                    file << "Pelanggan " << i + 1 << ":\n";
                    file << "Nama\t\t: " << record[i].nama << "\n";
                    file << "Nomor HP\t: " << record[i].noHp << "\n";
                    file << "Golongan Darah\t: " << record[i].gol << "\n";
                    file << "Alamat\t\t: " << record[i].alamat << "\n";
                    file << "===================================\n";
                }
                file.close();
                cout << "Data pelanggan disimpan ke dalam file 'record.txt'.";
                cout << "\n===============================\n";
                cout << "Tekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
            } else {
                cout << "Gagal membuka file 'record.txt' untuk penyimpanan.";
                cout << "\n===============================\n";
                cout << "Tekan Enter untuk melanjutkan...";
                cin.get();
            }
        }
    }
}

void showLoading() {
    cout << "Loading";
    for (int i = 0; i < 3; i++) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << ".";
    }
    cout << endl;
}

int main() {
    char pilihan;
    do {
        system("cls");
        cout << "=== Menu Antrian Rumah Sakit ===" << endl;
        cout << "1. Pendaftaran Pasien" << endl;
        cout << "2. Pemanggilan Pasien" << endl;
        cout << "3. Tampilkan Data Panggilan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case '1':
                system("cls");
                showLoading();
                tambah();
                break;
            case '2':
                system("cls");
                showLoading();
                proses();
                break;
            case '3':
                system("cls");
                showLoading();
                tampilrecord();
                break;
            case '0':
                cout << "Keluar dari program...";
                cout << "\n===============================\n";
                cout << "Tekan Enter untuk menutup program...";
                cin.ignore();
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.";
                cout << "\n===============================\n";
                cout << "Tekan Enter untuk melanjutkan...";
                cin.ignore();
                break;
        }
        system("cls");
    } while (pilihan != '0');
    return 0;
}

