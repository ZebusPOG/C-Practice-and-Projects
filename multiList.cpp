#include <iostream>
using namespace std;
struct nodeChild{
  string namaAnggota;
  nodeChild* nextChild;
};

typedef nodeChild* pNodeChild;

struct nodeParent{
  string departemen;
  nodeParent* nextParent;
  pNodeChild firstChild;
};

typedef nodeParent* pNodeParent;
typedef pNodeParent multiList;

string inputDepartemen(string info = " "){
  cout << "Masukkan Departemen: " << endl;
  getline(cin, info);
  return info;
}

string inputNamaAnggota(string info = " "){
  cout << "Masukkan Nama Anggota: " << endl;
  getline(cin, info);
  return info;
}

void inputKey(string& key){
  cout << "Masukkan key: " << endl;
  getline(cin, key);
}

void createMultiList(multiList& head){
  head = NULL;
}

void createElementParent(pNodeParent& pBaru){
  pBaru = new nodeParent;
  pBaru->departemen = inputDepartemen();
  pBaru->firstChild = NULL;
  pBaru->nextParent = NULL;
}

void createElementChild(pNodeChild& pBaru){
  pBaru = new nodeChild;
  pBaru->namaAnggota = inputNamaAnggota();
  pBaru->nextChild = NULL;
}

void transversalParent(multiList head, pNodeParent pBantu){
  pBantu = head;
  int index = 1;
  if (head == NULL){
    cout << "Multilist kosong. " << endl;
    return;
  }
  while (pBantu != NULL){
    cout << "Departemen ke - " << index << " : " << pBantu->departemen << endl;
    index++;
    pBantu = pBantu->nextParent;
  }
}

void linearSearch(multiList head, pNodeParent& pCari, int& ketemu, string key){
  pCari = head;
  while (pCari != NULL){
    if (pCari->departemen == key){
      ketemu = 1;
      return;
    }
    pCari = pCari->nextParent;
  }
}


void insertFirstAnak(multiList& head, pNodeChild pBaru){
  pNodeParent pCari;
  int ketemu = 0;
  string key;
  inputKey(key);
  linearSearch(head, pCari, ketemu, key);
  if (ketemu){
    if (pCari->firstChild == NULL){
      pCari->firstChild = pBaru;
    }
    else {
      pBaru->nextChild = pCari->firstChild;
      pCari->firstChild = pBaru;
    }
  }
  else {
    cout << "Departemen unknown! " << endl;
  }
}

void deleteFirstAnak(multiList& head, pNodeChild pHapus){
  pNodeParent pCari;
  int ketemu = 0;
  string key;
  inputKey(key);
  linearSearch(head, pCari, ketemu, key);
  if (ketemu){
    if (pCari->firstChild == NULL){
      cout << "Departemen ini tidak memiliki anggota. " << endl;
    }
    else if (pCari->firstChild->nextChild == NULL){
      pHapus = pCari->firstChild;
      pCari->firstChild = NULL;
      delete pHapus;
    }
    else {
      pHapus = pCari->firstChild;
      pCari->firstChild = pCari->firstChild->nextChild;
      pHapus->nextChild = NULL;
      delete pHapus;
    }
  }
  else {
    cout << "Departemen unknown! " << endl;
  }
}


void insertFirstDepartemen(multiList& head, pNodeParent pBaru){
  if (head == NULL){
    head = pBaru;
  }
  else {
    pBaru->nextParent = head;
    head = pBaru;
  }
}

void deleteFirstDepartemen(multiList& head, pNodeParent pHapus){
  if (head == NULL){
    cout << "MultiList kosong" << endl;
    return;
  }
    pNodeChild pHapusChild;
    while (head->firstChild != NULL){
      if (head->firstChild->nextChild == NULL){
        pHapusChild = head->firstChild;
        head->firstChild = NULL;
        delete pHapusChild;
      }
      else {
        pHapusChild = head->firstChild;
        head->firstChild = head->firstChild->nextChild;
        pHapusChild->nextChild = NULL;
      }
    }
    pHapus = head;
    head = head->nextParent;
    pHapus->nextParent = NULL;
    delete pHapus;
}

void tampilan(multiList head, pNodeParent pBantuParent){
  if (head == NULL){
    cout << "Multilist kosong. " << endl;
  }
  pBantuParent = head;
  pNodeChild pBantuChild;
  while (pBantuParent != NULL){
    cout << "\nDepartemen: " << pBantuParent->departemen << endl;
    pBantuChild = pBantuParent->firstChild;
    while (pBantuChild != NULL){
      cout << "Anggota : " << pBantuChild->namaAnggota << endl;
      pBantuChild = pBantuChild->nextChild;
    }
    pBantuParent = pBantuParent->nextParent;
  }
}

int main(){
  multiList google;
  pNodeParent pBantuParent;
  pNodeChild pBantuChild;
  createMultiList(google);


  createElementParent(pBantuParent);
  insertFirstDepartemen(google, pBantuParent);

  createElementParent(pBantuParent);
  insertFirstDepartemen(google, pBantuParent);

  createElementParent(pBantuParent);
  insertFirstDepartemen(google, pBantuParent);

  createElementParent(pBantuParent);
  insertFirstDepartemen(google, pBantuParent);

  transversalParent(google, pBantuParent);

  createElementChild(pBantuChild);
  insertFirstAnak(google, pBantuChild);

  createElementChild(pBantuChild);
  insertFirstAnak(google, pBantuChild);

  createElementChild(pBantuChild);
  insertFirstAnak(google, pBantuChild);

  tampilan(google, pBantuParent);
  return 0;
}