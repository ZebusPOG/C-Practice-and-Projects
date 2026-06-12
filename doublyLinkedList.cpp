#include <iostream>
using namespace std;
struct node{
  char info;
  node* next;
  node* prev;
};

typedef node* pNode;
typedef pNode list;

char inputInfo(char info = ' '){
  cout << "Input Info: " << endl;
  cin >> info;
  return info;
}

void inputKey(char& key){
  cout << "Input Key: " << endl;
  cin >> key;
}

void createList(list& head){
  head = NULL;
}

void createElement(pNode& pBaru){
  pBaru = new node;
  pBaru->info=inputInfo();
  pBaru->next=NULL;
  pBaru->prev=NULL;
}

void insertFirst(list& head, pNode pBaru){
  if (head == NULL){
    head = pBaru;
  }
  else {
    pBaru->next = head;
    pBaru->next->prev = pBaru;
    head = pBaru;
  }
} 

void linearSearch(list head, pNode& pCari, int& ketemu, char key){
  pCari = head;
  while (pCari != NULL){
    if (pCari->info == key){
      ketemu = 1;
      return;
    }
    pCari = pCari->next;
  }
}

void insertAfter(list& head, pNode pBaru){
  if (head == NULL){
    cout << "List kosong" << endl;
  }
  char key;
  inputKey(key);
  int ketemu = 0;
  pNode pCari;
  linearSearch(head, pCari, ketemu, key);
  if (ketemu){
    if (pCari->next == NULL){
      pCari->next = pBaru;
      pBaru->prev = pCari;
      return;
    }
    pBaru->next = pCari->next;
    pBaru->prev = pCari;
    pBaru->next->prev = pBaru;
    pBaru->prev->next = pBaru;
  }
}

void insertLast(list& head, pNode pBaru){
  if (head == NULL){
    head = pBaru;
  }
  else {
    pNode pTerakhir = head;
    while (pTerakhir->next != NULL){
      pTerakhir = pTerakhir->next;
    }
    pTerakhir->next = pBaru;
    pBaru->prev = pTerakhir;
  }
}

void deleteFirst(list& head, pNode pHapus){
  if (head == NULL){
    cout << "List kosong. " << endl;
  }
  else if (head->next==NULL){
    pHapus = head;
    head = NULL;
    delete pHapus;
  }
  else {
    pHapus = head;
    head = head->next;
    pHapus->next->prev = NULL;
    pHapus->next = NULL;
    delete pHapus;
  }
}

void deleteAfter(list& head, pNode pHapus){
  if (head == NULL){
    cout << "list kosong" << endl;
    return;
  }
  char key;
  inputKey(key);
  pNode pCari;
  int ketemu = 0;
  linearSearch(head, pCari, ketemu, key);
  if (ketemu){
    if (pCari->next == NULL){
      cout << "Tidak ada elemen setelah pCari." << endl;
    }
    else if (pCari->next->next == NULL){
      pHapus = pCari->next;
      pCari->next = NULL;
      pHapus->prev = NULL;
      delete pHapus;
    }
    else {
      pHapus = pCari->next;
      pHapus->next->prev = NULL;
      pHapus->prev->next = NULL;
      pHapus->next = NULL;
      pHapus->prev = NULL;
      delete pHapus;
    }
  }
}

void deleteLast(list& head, pNode pHapus){
  if (head == NULL){
    cout << "List kosong. " << endl;
  }
  else if (head->next == NULL){
    pHapus = head;
    head = NULL;
    delete pHapus;
  }
  else {
    pNode pTerakhir = head;
    while (pTerakhir->next != NULL){
      pTerakhir = pTerakhir->next;
    }
    pHapus = pTerakhir;
    pTerakhir->prev->next = NULL;
    pTerakhir->prev = NULL;
    delete pHapus;
  }
}

void tampilan(list head, pNode pBantu){
  if (head == NULL){
    cout << "List kosong. " << endl;
    return;
  }
  pBantu = head;
  while (pBantu != NULL){
    cout << "Info: " << pBantu->info << endl;
    pBantu = pBantu->next;
  }
}
int main(){
  list informatika;
  pNode pBantu;
  createList(informatika);

  createElement(pBantu);
  insertFirst(informatika, pBantu);
  tampilan(informatika, pBantu);

  createElement(pBantu);
  insertLast(informatika, pBantu);
  tampilan(informatika, pBantu);

  createElement(pBantu);
  insertAfter(informatika, pBantu);
  tampilan(informatika, pBantu);

  deleteLast(informatika, pBantu);
  tampilan(informatika, pBantu);
  
  deleteAfter(informatika, pBantu);
  tampilan(informatika, pBantu);
  return 0;
}