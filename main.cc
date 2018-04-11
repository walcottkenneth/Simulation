#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<ncurses.h>
using namespace std;

/* const int UP = 65;
 * const int DOWN = 66;
 * const int LEFT = 68;
 * const int RIGHT = 67;
 * const MAX_X, MAX_Y;
 *
 */

struct node{
    int piece;
    node() {}
    node(int new_piece): piece(new_piece){}
};

void die() {
    cout << "Gone but not forgotten!\n";
    cout << "R.I.P.\n";
    exit(1);
}

void location(int x, int y) {
    while(x < 0) x+=MAX_X;
    while(y < 0) y+=MAX_Y;
    if(x >= MAX_X) x %= MAX_X;
    if(y >= MAX_Y) y %= MAX_Y;
    return (x*MAX_Y+x);
}

//void puzzle(){}

unsigned struct* world;


int main() {
    //srand(time(NULL));

    //Set up NCURSES
    initscr();
    clear();
    noecho();:wq
    cbreak();

    world = new unsigned struct[MAX_X * MAX_Y];
    //cout << "^L";
    game_on = false;
    while(true) {
    cout << "DIDDY SAYS TAKE THAT.\n";
    int ch = getch();
    if(ch == 'q' or ch == 'Q') die();
    /* else if (ch ==
     *
     */

  cout << "^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^" << endl;
  cout << "-------------------------------------" << endl;
  cout << "-x--x--- Lost in Los Angeles ---x--x-" << endl;
  cout << "-------------------------------------" << endl;
  cout << "<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<" << endl;
  cout << endl;
  string name = 'Player 1';
  cout << "What is your name, " << name << "?" << endl;
  cin >> name;
  if (!cin) die();
  cout << "Welcome to Lost in L.A. " << name << "! My name is Keller." << endl;
  cout << "If you want to get out alive, follow my instructions and don't mess up. " << endl;
  cout << "Your first task will be to visit the fortune teller." << endl;
  cout << "However, her humble abode is hidden in the mall." << endl;
  
  cout << "You found Sabrina, the best fortune teller in all of L.A." << endl;
  cout << "She will now tell your fortune based on your information." << endl;
}
