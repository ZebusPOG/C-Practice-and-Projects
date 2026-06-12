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
int main(){
  return 0;
}