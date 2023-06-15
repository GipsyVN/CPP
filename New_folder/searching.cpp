#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <conio.h>
using namespace std;


int main(){
    int pilih, data[100], n, key, pos[100], banyak = 0;
    bool flag = false;
    string x;
    srand(time(0));
    //menu
    menu:
    system("cls");
    cout << "Menu Pilihan:" << endl;
    cout << "1. Input Data" << endl;
    cout << "2. Cari Data" << endl;
    cout << "3. Tampilkan Hasil" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih: ";
    cin >> pilih;

    switch(pilih){
    case 1:
        int isi;
        system("cls");
        //Input User
        cout << "Masukan Banyak Data (Maks 100): ";
        cin >> n;
        isi:
        system("cls");
        cout << "Mode Pengisian Data: ";
        cout << "\n1. Manual";
        cout << "\n2. Otomatis" << endl;
        cout << "Pilih: ";
        cin >> isi;

        switch(isi){
        case 1:
            for(int i = 0; i < n; i++){
                cout << "Masukan Data ke " << i + 1 << ": ";
                cin >> data[i];
            }
            goto menu;
            break;

        case 2:
            for(int i = 0; i < n; i++){
                cout << "Memasukan data ke " << i + 1 << ": ";
                data[i] = rand() % n + 1;
                cout << data[i] << endl;
            }
            system("cls");
            cout << "Apakah Ingin Data Ditampilkan?? (y/n): ";
            cin >> x;
            if(x == "y" || x == "Y"){
                for(int i = 0; i < n; i++){
                    cout << "Data ke " << i + 1 << ": " << data[i] << endl;
                }
                getch();
                goto menu;
            }
            goto menu;
            break;

        default:
            cout << endl << "Tidak Ada Dalam Pilihan";
            getch();
            goto isi;
            break;
        }
        break;

    case 2:
        system("cls");
        flag = false;
        cout << "Input Data yang Dicari: ";
        cin >> key;
        //Searching
        cout << "==== SEDANG MENCARI DATA ====" << endl;
        sleep(3);
        for(int i = 0; i < n; i++){
            if(data[i] == key){
                flag = true;
                pos[banyak] = i + 1;
                banyak++;
            }
        }
        if(flag == true){
            cout << "Data Ditemukan";
            getch();
            goto menu;
        }
        else{
            cout << "Data Tidak Ditemukan";
            getch();
            goto menu;
        }
        break;

    case 3:
        system("cls");
        //Menampilkan Hasil
        cout << "====== HASIL ======" << endl;
        cout << "Data: ";
        for(int i = 0; i < n; i++){
            cout << data[i] << " ";
        }
        cout << endl << endl;
        cout << "Data yang dicari: " << key << endl << endl;
        if(flag == true){
            cout << "Data berada pada urutan ke ";
            for(int i = 0; i < banyak; i++){
                cout << pos[i] << " ";
            }
            getch();
            goto menu;
        }
        else{
            cout << "Data Tidak Ditemukan";
            getch();
            goto menu;
        }
        break;

    case 4:
        exit(0);
        break;

    default:
        cout << endl << "Tidak Ada Dalam Pilihan" << endl;
    }
}
