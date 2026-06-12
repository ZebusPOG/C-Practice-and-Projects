#include <iostream>
using namespace std;
struct node {
  char info;
  node* next;
};

typedef node* pNode;
typedef pNode Stack;

void createStack(Stack& head){
  head = NULL;
}

char inputInfo(char info = ' '){
  cout << "Masukkan info: " << endl;
  cin >> info;
  return info;
}

void createElement(pNode& pBaru){
  pBaru = new node;
  pBaru->info = inputInfo();
  pBaru->next = NULL;
}

void Push(Stack& head, pNode pBaru){
  if (head == NULL){
    head = pBaru;
  }
  else {
    pNode pTerakhir = head;
    while (pTerakhir->next != NULL){
      pTerakhir = pTerakhir->next;
    }
    pTerakhir->next = pBaru;
  }
}

void Pop(Stack& head, pNode& pHapus){
  if (head == NULL){
    cout << "List kosong. " << endl;
    return;
  }
  else if (head->next == NULL){
    pHapus = head;
    head = NULL;
  }
  else {
    pHapus = head;
    head = head->next;
    pHapus->next = NULL;
  }
}

void pindahkanStack(Stack& asal, Stack& tujuan){
  if (asal == NULL){
    cout << "Stack asal kosong sehingga proses pemindahan stack error!" << endl;
    return;
  }
  pNode pBantu;
  while (asal != NULL){
    Pop(asal, pBantu);
    Push(tujuan, pBantu);
  }
}

void tampilkan(Stack head, pNode pBantu){
  if (head == NULL){
    cout << "list kosong. " << endl;
    return;
  }
  pBantu = head;
  while (pBantu != NULL){
    cout << "\nInfo: " << pBantu->info << endl;
    pBantu = pBantu->next;
  }
}

int main(){
  Stack A, B;
  pNode pBantu;
  string pilihan;
  createStack(A);
  createStack(B);

  createElement(pBantu);
  Push(A, pBantu);

  createElement(pBantu);
  Push(A, pBantu);

  createElement(pBantu);
  Push(A, pBantu);

  createElement(pBantu);
  Push(A, pBantu);

  pindahkanStack(A, B);

  createElement(pBantu);
  Push(B, pBantu);

  createElement(pBantu);
  Push(B, pBantu);

  createElement(pBantu);
  Push(B, pBantu);


  pindahkanStack(B, A);

  Pop(A, pBantu);
  Pop(A, pBantu);
  Pop(A, pBantu);
  Pop(A, pBantu);

  tampilkan(A, pBantu);
  tampilkan(B, pBantu);
  return 0;
}