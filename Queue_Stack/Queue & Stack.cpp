#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <stack>
#include <queue>
#define max 10
#define size 10
using namespace std;
int q[size], depan = 0, ekor = 0;

//QUEUE
void menuQueue(){
    string q;
    bool a = true;
    depan = 0, ekor = 0;
    void enqueue();
    void dequeue();
    void display();
    while(a){
        system("cls");
        cout << "MENU PILIHAN QUEUE" << endl;
        cout << "1. MENAMBAHKAN ELEMEN" << endl;
        cout << "2. MENGHAPUS ELEMEN" << endl;
        cout << "3. MENAMPILKAN ELEMEN" << endl;
        cout << "4. KEMBALI" << endl;
        cout << "Pilih: ";
        cin >> q;

        if(q == "1"){
            enqueue();
        }
        else if(q == "2"){
            dequeue();
        }
        else if(q == "3"){
            display();
        }
        else if(q == "4"){
            a = false;
        }
        else{
            cout << "Tidak Berada Dalam Pilihan";
            sleep(1);
        }
    }
}
void enqueue(){
    int no;
    cout << endl;
    if(ekor == size){
        cout << "Antrian Penuh";
        sleep(1);
    }
    else{
        cout << "Masukan Nomor Antrian: ";
        cin >> no;
        q[ekor] = no;
        ekor++;
        cout << "Berhasil Menambahkan Antrian";
        sleep(1);
    }
}
void dequeue(){
    cout << endl;
    int no = q[depan];
    if(depan == ekor){
        cout << "Antrian Kosong";
        sleep(1);
    }
    else{
        for(int i = 0; i < ekor - 1; i++){
            q[i] = q[i + 1];
        }
        cout << "no. antrian " << no << " dihapus";
        ekor--;
        sleep(1);
    }
    //Akhirnya gk runtime error
}
void display(){
    int i;
    cout << endl;
    if(depan == ekor){
        cout << "Antrian Kosong";
        sleep(1);
    }
    else{
        cout << "Elemen dalam Antrian: ";
        for(i = depan; i < ekor; i++){
            cout << q[i] << " ";
        }
        getch();
    }
}

//STACK
struct tumpuk{
    int atas = -1;
    int stak[max];
}tumpuk;

void menuStack(){
    string s;
    void push(), pop(), hapus(), tampil();
    tumpuk.atas = -1;
    bool ulang = true;
    while(ulang){
        system("cls");
        cout<<"=============================="<<endl;
        cout<<"||   -:: LATIHAN STACK ::-   ||"<<endl;
        cout<<"|| = -:: MENU PILIHAN::- =   ||"<<endl;
        cout<<"=============================="<<endl;
        cout<<"|| 1. PUSH                   ||"<<endl;
        cout<<"|| 2. POP                    ||" <<endl;
        cout<<"|| 3. TAMPIL                 ||"<<endl;
        cout<<"|| 4. CLEAR                  ||"<<endl;
        cout<<"|| 5. KEMBALI                ||"<<endl;
        cout<<"=============================="<<endl;
        cout << "Pilih: ";
        cin >> s;
        if(s == "1"){
            push();
        }
        else if(s == "2"){
            pop();
        }
        else if(s == "3"){
            tampil();
        }
        else if(s == "4"){
            hapus();
        }
        else if(s == "5"){
            ulang = false;
        }
        else{
            cout << "Tidak Berada Dalam Pilihan";
            getch();
        }
    }
}

bool kosong(){
    if(tumpuk.atas == -1){
        return true;
    }
    else{
        return false;
    }
}
bool penuh(){
    if(tumpuk.atas == max - 1){
        return true;
    }
    else{
        return false;
    }
}
void push(){
    int data;
    cout << endl;
    if(!penuh()){
        tumpuk.atas++;
        cout << "Masukan data: ";
        cin >> data;
        tumpuk.stak[tumpuk.atas] = data;
        cout << "Data " << tumpuk.stak[tumpuk.atas] << " masuk ke stack";
        sleep(1);
    }
    else{
        cout << "Tumpukan Penuh";
        sleep(1);
    }
}
void pop(){
    cout << endl;
    if(!kosong()){
        cout << "Data teratas sudah diambil";
        tumpuk.atas--;
        sleep(1);
    }
    else{
        cout << "Tumpukan kosong";
        sleep(1);
    }
}
void hapus(){
    cout << endl;
    tumpuk.atas = -1;
    cout << "Berhasil menghapus tumpukan";
    sleep(1);
}
void tampil(){
    cout << endl;
    if(!kosong()){
        for(int i = tumpuk.atas; i >= 0; i--){
            cout << "Tumpukan ke " << i + 1 << ": " << tumpuk.stak[i] << endl;
        }
        getch();
    }
    else{
            cout << "Tumpukan kosong";
    }
    sleep(1);
}
main(){
    string pil;
    bool ulang = true;
    while(ulang){
        system("cls");
        cout << "=======================" << endl;
        cout << "     QUEUE & STACK     " << endl;
        cout << "=======================" << endl;
        cout << "Menu:" << endl;
        cout << "1. QUEUE" << endl;
        cout << "2. STACK" << endl;
        cout << "3. EXIT" << endl;
        cout << "Pilih: ";
        cin >> pil;

        if(pil == "1"){
            menuQueue();
        }
        else if(pil == "2"){
            menuStack();
        }
        else if(pil == "3"){
            ulang = false;
        }
        else{
            cout << "Tidak Berada Dalam Pilihan";
            getch();
        }
    }
}
