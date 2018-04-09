#include<iostream>
#include "lost.h"
using namespace std;
const int MAX_Y, MAX_X = 10;

void location() {
node* head;
head->new node;
node* temp = head;
int h = 0;
while(h<MAX_Y){
  for(int i= 0; i< MAX_X; i++){
    temp.right->new node;
    temp = temp->right;
    i++;
  }
  temp = head;
  if(temp.up == NULL){ 
    temp.up->new node;
    temp = temp->up;
    h++;
  }
  else { temp = temp->up; }
}

int main() {

return 0;
}
