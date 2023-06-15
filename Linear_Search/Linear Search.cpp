#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main(){
    int data[100], posisi[100], n, key, banyak, flag;
    cout << "===== PROGRAM LINEAR SEARCH C++ =====" << endl;
    cout << "=====================================" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    //Input data dari user
    cout << "Masukan jumlah data: ";
    cin >> n;

    cout << "Masukan data sebanyak " << n << ": " << endl;
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }
    cout << endl;
    cout << "Masukan data yang dicari: ";
    cin >> key;

    cout << endl;
    cout << "===== MENCETAK DATA =====" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Data: ";
    for(int i = 0; i < n; i++){
        cout << data[i] << " ";
    }

    cout << endl << endl;
    cout << "===== PROSES PENCARIAN =====" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    flag = 0;
    banyak = 0;
    for(int i = 0; i < n; i++){
        if(data[i] == key){
            flag = 1;
            posisi[banyak] = i + 1;
            banyak++;
        }
    }
    if(flag == 1){
        cout << "Data ditemukan sebanyak " << banyak << endl;
        cout << "Pada urutan ke ";
        for(int i = 0; i < banyak; i++){
            cout << posisi[i] << " ";
        }
    }
    else{
        cout << "Data " << key << " tidak ditemukan";
    }
    cout << endl;
    return 0;
}
