#include<iostream>
using namespace std;

void die(){
  cout << "Gone but not forgotten.\n";
  cout << "R.I.P.\n";
  exit(1);
  }
  
  class node {
    //The int will be used in the puzzle function that will be called when the character moves
    int piece;
    //These pointers will be the how you move through the "map"
    node* up = nullptr;
    node* down = nullptr;
    node* right = nullptr;
    node* left = nullptr;
    
    public:
    node() {} //Does nothing constructor
    
    /*
    check_move checks the direction the user wants to move to make sure its within the
    the designed map. If it is, it returns true. If not, tells the user its out of bounds.
    */
    
    bool check_move(node* direction){
      bool check = false;
      if(direction == nullptr) {
        cout << "Its just the woods. We cant go there.\n";
      else { check = true; }
      return check;
    }
    
    /*
    Move function will take the players current location and move in the direction of
    the input if its within the map. After it moves it will int piece from that linked
    list in the puzzle function.
    */
    
    void move (ch new_move, node* temp) {
      bool go;
      toupper(new_move)
      if (new_move == 'W') {
        go = check_move(temp->up);
        if(go == true) {
          temp = temp->up;
          cout << "Moved up.\n";
        }
      }
      if else (new_move == 'Z') {
        go = check_move(temp->down);
        if(go == true) {
          temp = temp->down;
          cout << "Moved down.\n";
        }
      }
      if else (new_move == 'A') {
        go = check_move(temp->left);
        if(go == true) {
          temp = temp->left;
          cout << "Moved left.\n";
        }
      }
      if else (new_move == 'S') {
        go = check_move(temp->up);
        if( go == true) {
          temp = temp->right;
          cout << "Moved right.\n";
        }
      }
      else die();
      puzzle(temp->piece);
    }
};
