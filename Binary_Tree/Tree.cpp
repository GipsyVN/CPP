#include <iostream>
#include <conio.h>
#include <unistd.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void clear(Node* root) {
    if (root == NULL) {
        return;
    }

    clear(root->left);
    clear(root->right);
    delete root;
}

void jalan() {
    int n;
    cout << "Masukkan jumlah node: ";
    cin >> n;

    Node* root = NULL;

    cout << "Masukkan nilai untuk setiap node:" << endl;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insertNode(root, data);
    }

    cout << "Traversal Pre-order: ";
    preOrder(root);
    cout << endl;

    cout << "Traversal Post-order: ";
    postOrder(root);
    cout << endl;

    cout << "Traversal In-order: ";
    inOrder(root);

    clear(root);

    cout << endl << endl;
}

int main(){
    jalan();
    bool ulang = true;
    char p;
    while(ulang){
        cout << "Apakah ingin mengulangi program? (y/n)? ";
        cin >> p;

        if(p == 'y' || p == 'Y'){
            system("cls");
            jalan();
        }
        else if(p == 'n' || p == 'N'){
            ulang = false;
        }
        else{
            cout << "Pilihan Salah";
            getch();
            system("cls");
        }
    }
}
