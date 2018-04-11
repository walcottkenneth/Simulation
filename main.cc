#include<iostream>
#include "lost.h"
using namespace std;
const int MAX_Y, MAX_X = 10;

/*
Location function creates the map that the user moves along. If done correctly,
hopefully we can have a easy, medium, and hard setting in int main(), that would
change the size of the map.
*/
// Just accepted how terrible of an idea this is, im going to have to switch it
// out for something easier. Sorry.
void location() {
node* head;
head = new node;
node* temp = head;
int h = 0;
while(h<MAX_Y){
  for(int i= 0; i< MAX_X; i++){
    temp.right->new node;
    node.left->temp;
    temp = temp->right;
    i++;
  }
  temp = head;
  if(temp.up == NULL){ 
    temp.up->new node;
    node.down->temp;
    temp = temp->up;
    h++;
  }
  else { temp = temp->up; }
}

int main() {
  cout << "^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^
  cout << "-------------------------------------" << endl;
  cout << "-x--x--- Lost in Los Angeles ---x--x-" << endl;
  cout << "-------------------------------------" << endl;
  cout << "<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<" << endl;
  cout << endl;
  string name = 'Player 1';
  cout << "What is your name, " << name << "?" << endl
  cin >> name;
  if (!cin) die();
  cout << "Welcome to Lost in L.A. " << name << "! My name is Keller." << endl;
  cout << "If you want to get out alive, follow my instructions and don't mess up. " << endl;
  cout << "Your first task will be to visit the fortune teller." << endl;
  cout << "However, her humble abode is hidden in the mall." << endl;
  
  cout << "You found Sabrina, the best fortune teller in all of L.A." << endl;
  cout << "She will now tell your fortune based on your information." << endl;
}
