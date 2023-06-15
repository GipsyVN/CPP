#include <iostream>
using namespace std;

int main(){
    string nama, alamat, nik, jurusan;
    cout << "DATA MAHASISWA" << endl;
    cout << "---------------------" << endl;
    //Input data
    cout << "Masukan Nama\t: ";
    getline(cin, nama);
    cout << "Masukan Alamat\t: ";
    getline(cin, alamat);
    cout << "Masukan NIK\t: ";
    getline(cin, nik);
    cout << "Masukan Jurusan\t: ";
    getline(cin, jurusan);

    //Print data
    system("cls");
    cout << "DATA MAHASISWA" << endl;
    cout << "---------------------" << endl;
    cout << "Nama\t: " << nama << endl;
    cout << "Alamat\t: " << alamat << endl;
    cout << "NIK\t: " << nik << endl;
    cout << "Jurusan\t: " << jurusan << endl;
}
