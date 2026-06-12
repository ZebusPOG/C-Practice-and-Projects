#include <iostream>
using namespace std;
struct node {
  char info;
  int priority;
  node* next;
};

typedef node* pNode;

struct Queue {
  pNode head;
  pNode tail;
};

char inputInfo(char info=' '){
  cout << "Masukkan info: " << endl;
  cin >> info;
  return info;
}

int inputPriority(int priority=0){
  cout << "Masukkan priority: " << endl;
  cin >> priority;
  return priority;
}

void createQueue(Queue& Q){
  Q.head = NULL;
  Q.tail = NULL;
}

void createElement(pNode& pBaru){
  pBaru = new node;
  pBaru->info = inputInfo();
  pBaru->priority = inputPriority();
  pBaru->next = NULL;
}

void enqueue(Queue& Q, pNode pBaru){
  if (Q.head == NULL){
    Q.head = pBaru;
    Q.tail = pBaru;
    return;
  }
  else if (pBaru->priority < Q.head->priority){
    pBaru->next = Q.head;
    Q.head = pBaru;
    return;
  }
  pNode pCari = Q.head;
  while (pCari->next != NULL){
    if (pBaru->priority < pCari->next->priority){
      pBaru->next = pCari->next;
      pCari->next = pBaru;
      return;
    }
    pCari = pCari->next;
  }
  pCari->next = pBaru;
  Q.tail = pCari->next;
}

void dequeue(Queue& Q, pNode pHapus){
  if (Q.head == NULL){
    cout << "list kosong. " << endl;
    return;
  }
  else if (Q.head->next == NULL){
    pHapus = Q.head;
    Q.head = NULL;
    Q.tail = NULL;
    delete pHapus;
  }
  else {
    pHapus = Q.head;
    Q.head = Q.head->next;
    pHapus->next = NULL;
    delete pHapus;
  }
}

void tampilanQueue(Queue Q, pNode pBantu){
  if (Q.head == NULL){
    cout << "List kosong. " << endl;
    return;
  }
  pBantu = Q.head;
  while (pBantu != NULL){
    cout << "Info: " << pBantu->info << endl;
    cout << "Priority: " << pBantu->priority << endl;
    pBantu = pBantu->next;
  }
}

int main(){
  Queue Q;
  pNode pBantu;
  createQueue(Q);

  createElement(pBantu);
  enqueue(Q, pBantu);


  createElement(pBantu);
  enqueue(Q, pBantu);


  createElement(pBantu);
  enqueue(Q, pBantu);

  createElement(pBantu);
  enqueue(Q, pBantu);


  tampilanQueue(Q, pBantu);
  return 0;
}