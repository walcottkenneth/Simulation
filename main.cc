#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<ncurses.h>
#include<utility>
#include<limits>
#include<vector>
#include<queue>
#include<set>
using namespace std;

const unsigned int UP = 65;
const unsigned int DOWN = 66;
const unsigned int RIGHT = 67;
const unsigned int LEFT = 68;
int MAX_X, MAX_Y;
int MOVE_X, MOVE_Y;

struct node{
    int piece;
    node() {}
    node(int new_piece): piece(new_piece){}
    ~node(){}
//  puzzles(int n){}
};

void die(); //declared at the bottom
void win();

int location(int x, int y) {
    while(x < 0) x+=MAX_X;
    while(y < 0) y+=MAX_Y;
    if(x >= MAX_X) x %= MAX_X;
    if(y >= MAX_Y) y %= MAX_Y;
    return (x*MAX_Y+y);
}
//beginning of puzzle function
void wrong_ans() {
  cout << "Sorry that was the wrong answer\n";
  }
 void correct_ans() {
   cout << "Good Job!\n";
 }
  
//fucntion for puzzles/riddles
//if you wanted to use this as a function of the class 
//you would have to switch this function from a int to:
//     int world::puzzles(int, int, int);
int puzzles(int x, int score, int challenge) {
  int choice = 0;
  string ans = 0;
  getline (cin, choice);
  if (!cin) die();
  if (choice == 1) {
    cout << "Jimmy's mother had three children. The first was called April\n";
    cout << "and the second was called May. What was the name of the third?\n";
    cin >> ans;
    if (!cin) die();
    toupper(ans);
    if(ans != 'JIMMY') {
      wrong_ans();
    //  score = score - 10; //we can change how many points the players looses depending on the difficulty of the question
    else
      correct_ans();
      }
   }
    
  if(choice == 2) {
    cout << " You can hold it without using your hand or your arms. What is it?\n";
    cin >> ans;
    if (!cin) die();
    toupper(ans);
    if(ans != 'YOUR BREATH' || ans != 'BREATH') {
      wrong_ans();
    //  score = score - 10;
     }
    else
      correct_ans();
    }
    
   if (choice == 3) {
    cout << "234\n";
    cout << "23 \n";
    cout << "TIP:the answer is not 4\n";
    cin >> ans;
    if (!cin) die();
    if(ans != '5') {
      wrong_ans();
     // score = score - 10;
     }
    else
      correct_ans();
    }
    
    if (choice == 4) {
    cout << "Given that:\n"
    cout << "1 bottle of drink + 1 bottle of drink  + 1 bottle of drink  = $30\n";
    cout << "1 bottle of drink + 1 cheeseburger     + 1 cheeseburger     = $20\n";
    cout << "1 cheeseburger    + 2 glasses of drink + 2 glasses of drink = $9\n";
    cout << "1 cheeseburger    + 1 glass of drink   × 1 bottle of drink  = $?\n";
    cin >> ans;
    if (!cin) die();
    if (ans != '15') {
      wrong_ans();
     // score = score - 10;
     }
    else
        correct_ans();
    }
    
    if (choice == 5) {
      cout << "Poor people have it. Rich people need it. If you eat it you die. What is it?\n";
    cin >> ans;
    if (!cin) die();
      toupper(ans);
      if(ans != 'NOTHING') {
        wrong_ans();
       // score = score - 10;
      }
      else
        correct_ans();
    }
  
    if(choice == 6) {
      cout << "What word becomes shorter after you add to letters to it?\n";
      cin >> ans;
      if (!cin) die();
      toupper(ans);
      if(ans != 'SHORT') {
        wrong_ans();
     //   score = score - 10;
      }
      else
        correct_ans();
    }
  
    if(choice == 7) {
      cout << "What starts with an E, but only has one letter in it?\n";
      cin >> ans;
      if (!cin) die();
      toupper(ans);
      if(ans != 'ENVELOPE') {
        wrong_ans();
       // score = score - 10;
      }
      else 
        correct_ans();
    }
    if(choice == 8) {
        cout << "I have a key but no lock, a space but no room, you can enter\n";
        cout << " but can't gp outside. What am I?\n";
        cin >> ans;
        if (!cin) die();
        toupper(ans);
        if(ans != 'A KEYBOARD' || ans != 'KEYBOARD')
            wrong_ans();
        else
            correct_ans();
    }
    }
    
//end of puzzle function




int main() {
    cout << "^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^" << endl;
    cout << "-------------------------------------------" << endl;
    cout << " - x--x-- - Lost in Los Angeles -- -x--x - " << endl;
    cout << "-------------------------------------------" << endl;
    cout << "<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<" << endl;
    cout << endl;
    
    string name = "Player 1";   //player
    string h    = "Keller";     //host
    string ft   = "Sabrina";    //fortune teller
    string kk   = "crystal";    //object
    string m    = "zombie";     //monster
        
        
    cout << "What is your name, " << name << " ?" << endl;
    getline (cin, name);
    if (!cin) die();
    cout << endl;
 
    cout << h << ": Welcome to Lost in L.A. " << name << "! My name is Keller." << endl;
    cout << h << ": You must travel through the city to find " << kk << "s to find your way home." << endl;
    cout << h << ": If you need help, just enter 'F' to visit the fortune teller, " << ft << "." << endl;
    cout << h << ": Your first task will be to visit the fortune teller." << endl;
    cout << "However, her humble abode is hidden in the mall." << endl;
  
    cout << "You found Sabrina, the best fortune teller in all of L.A." << endl;
    cout << "She will now tell your fortune based on your information." << endl;
    initscr(); //Set up NCURSES
    clear();
    noecho(); //doesnt show the char inputs to the screen
    cbreak(); //takes in the char values in real time
    if(MAX_Y < 1 || MAX_X < 1) {
        mvprintw(0,0,"Error");
        die();
    }
    //creates the map of nodes
    //if you wanted the access one of the nodes within the map
    //use:        world[a].puzzle[b] = whatever;
    node world[MAX_X * MAX_Y];
    game_on = false;
    MOVE_X = MAX_X/2; //Sets beginning position on the map
    MOVE_Y = MAX_Y/2;
    while(true) {
    int ch = getch(); //grabs char inputs
    clear(); //clears the screen
    if(ch == 'q' or ch == 'Q') die(); //press (q) to quit
    else if (ch == RIGHT) {
        MOVE_Y++;
        if(MOVE_Y >= MAX_Y) { MOVE_Y = MAX_Y - 1; }
        mvprintw(0, 0, "moved right");  // So you can see which way youve moved
    }
    else if (ch == LEFT) {
        MOVE_Y--;
        if(MOVE_Y < 0) { MOVE_Y = 0; }
        mvprintw(0, 0, "moved left");  // So you can see which way youve moved
    }
    else if (ch == UP) {
        MOVE_X--;
        if(MOVE_X < 0) { MOVE_X = 0; }
        mvprintw(0, 0, "moved up");  // So you can see which way youve moved
    }
    else if (ch == DOWN) {
        MOVE_X++;
        if(MOVE_X >= MAX_X) { MOVE_X = MAX_X - 1; }
        mvprintw(0, 0, "moved down"); // So you can see which way youve moved
    }
    else if (ch == ERR) { ; } //If nothing is inputted it does nothing
    else if (ch == '\n') {game_on = !game_on;} // If you still want to make a pause
    //I used this function to test place values on the map
    //if(location(MOVE_X, MOVE_Y) == 5){
    //    win();
    //    break;
    //}
    else world[location(MOVE_X, MOVE_Y)];
    }

    clear();
    refresh();
    endwin();
    system("clear");
    return 0;
}

//This functions are set to print in ncurses
void die() {
    mvprintw(0,0,"Gone but not forgotten!");
    exit(1);
}
void win() {
    mvprintw(0,0, "Youve won");
}

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "classes.h"
using namespace std;

int main() {
    cout << "^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^" << endl;
    cout << "-------------------------------------------" << endl;
    cout << " - x--x-- - Lost in Los Angeles -- -x--x - " << endl;
    cout << "-------------------------------------------" << endl;
    cout << "<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<>|<" << endl;
    cout << endl;

    Point map;
    puzzle1 puzzle1;
    puzzle2 puzzle2;
    puzzle3 puzzle3;
    puzzle4 puzzle4;
    Puzzle player1;

    string h    = "Keller";     //host
    string ft   = "Sabrina";    //fortune teller
    string kk   = "crystal";    //object
    string m    = "monster";     //monster

    cout << "What is your name, " << name << " ?" << endl;
    getline(cin, name);
    if (!cin) die();
    cout << endl;

    cout << h << ": Welcome to Lost in L.A. " << name << "! My name is Keller." << endl;
    cout << h << ": You must travel through the city to find " << kk << "s to find your way home." << endl;
    cout << h << ": If you need help, just enter 'F' to visit the fortune teller, " << ft << "." << endl;
    cout << h << ": " << ft << " can give you clues as to where the " << kk << "s are." << endl;
    cout << h << ": " << "Enter W,A,S,D to move." << endl;

    char c = 0;
    while (true) {
        cout << "Your coordinates are: (" << map.get_x() << ", " << map.get_y() << ")." << endl;
        cin >> c;
        if (!cin) die();
        if (c == 'W') map.i_y();
        if (c == 'A') map.d_x();
        if (c == 'S') map.d_y();
        if (c == 'D') map.i_x();
        if (c == 'F') {
            cout << "You found Sabrina, the best fortune teller in all of L.A." << endl;
            if (map.get_x() <= 5 && map.get_y() >= 5) {
                cout << "Go to 36 N. Ocean Ave." << endl;
            }
            if (map.get_x() <= 5 && map.get_y() < 5) {
                cout << "Go to Kerney's favorite place." << endl;
            }
            if (map.get_x() > 5 && map.get_y() <= 5) {
                cout << "Vist the year that is the title of the famous book written by George Orwell." << endl;
            }
            if (map.get_x() > 5 && map.get_y() > 5) {
                cout << "Go to the spot where in binary code it reads 'on off on off'." << endl;
            }
        }
        if (map.get_x() == 4 && map.get_y() == 2) {puzzle1.quiz();}
        if (map.get_x() == 10 && map.get_y() == 10) {puzzle2.quiz();}
        if (map.get_x() == 3 && map.get_y() == 6) {puzzle3.quiz();}
        if (map.get_x() == 8 && map.get_y() == 4) {puzzle4.quiz();}
        if (player1.get_health() <= 0) die();
    }
}
