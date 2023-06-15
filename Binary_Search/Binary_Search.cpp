#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    int n, data[100], awal, akhir, tengah, temp, key, flag;
    cout << "===== PROGRAM BINARY SEARCH C++ =====" << endl;
    cout << "=====================================" << endl;
    sleep(1);

    //Input data dari user
    cout << "Masukan jumlah data: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Masukan data ke-" << i << ": ";
        cin >> data[i];
    }
    cout << endl;
    cout << "Masukan data yang dicari: ";
    cin >> key;


    cout << endl;
    cout << "===== Proses Sorting =====" << endl;
    //Bubble Sort
    for(int i = 0; i < n; i++){
        int urut = 0;
        for(int h = 0; h < n-1; h++){
            if(data[h] > data[h+1]){
                temp = data[h];
                data[h] = data[h+1];
                data[h+1] = temp;
                urut++;
            }
        }
        if(urut == 0){
            break;
        }
        sleep(1);
        cout << "Tahap " << i + 1 << ": ";
        for(int a = 0; a < n; a++){
            cout << data[a] << " ";
        }
        cout << endl;
    }
    cout << "Hasil Urut: ";
    for(int i = 0; i < n; i++){
        cout << data[i] << " ";
    }

    cout << endl << endl;
    cout << "===== Proses Pencarian =====" << endl;
    sleep(1);
    awal = 0;
    akhir = n-1;
    flag = 0;

    while(awal <= akhir){
        tengah = (awal + akhir)/2;
        if(data[tengah] == key){
            flag = 1;
            break;
        }
        else if(data[tengah] < key){
            awal = tengah + 1;
        }
        else{
            akhir = tengah - 1;
        }
    }
    if(flag == 1){
        cout << "Data ditemukan pada index ke-" << tengah << endl;
    }
    else{
        cout << "Data tidak ditemukan" << endl;
    }
    return 0;
}
