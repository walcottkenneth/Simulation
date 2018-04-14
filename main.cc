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
  getline (cin, choice);
  if (!cin) die();
  if (choice == 1) {
    string ans;
    cout << "Jimmy's mother had three children. The first was called April\n";
    cout << "and the second was called May. What was the name of the third?\n";
    getline (cin, ans);
    toupper(ans);
    if(ans != 'JIMMY') {
      wrong_ans();
    //  score = score - 10; //we can change how many points the players looses depending on the difficulty of the question
    else
      correct_ans();
      }
   }
    
  if(choice == 2) {
    string ans;
    cout << " You can hold it without using your hand or your arms. What is it?\n";
    getline.(cin, ans);
    toupper(ans);
    if(ans != 'YOUR BREATH' || ans != 'BREATH') {
      wrong_ans();
    //  score = score - 10;
     }
    else
      correct_ans();
    }
    
   if (choice == 3) {
    string ans;
    cout << "234\n";
    cout << "23 \n";
    cout << "TIP:the answer is not 4\n";
    getline.(cin, ans);
    if(ans != '5') {
      wrong_ans();
     // score = score - 10;
     }
    else
      correct_ans();
    }
    
    if (choice == 4) {
    string ans;
    cout << "Given that:\n"
    cout << "1 bottle of drink + 1 bottle of drink  + 1 bottle of drink  = $30\n";
    cout << "1 bottle of drink + 1 cheeseburger     + 1 cheeseburger     = $20\n";
    cout << "1 cheeseburger    + 2 glasses of drink + 2 glasses of drink = $9\n";
    cout << "1 cheeseburger    + 1 glass of drink   × 1 bottle of drink  = $?\n";
    getline.(cin, ans);
    if (ans != '15') {
      wrong_ans();
     // score = score - 10;
     }
    else
        correct_ans();
    }
    
    if (choice == 5) {
      string ans;
      cout << "Poor people have it. Rich people need it. If you eat it you die. What is it?\n";
      getline.(cin, ans);
      toupper(ans);
      if(ans != 'NOTHING') {
        wrong_ans();
       // score = score - 10;
      }
      else
        correct_ans();
    }
  
    if(choice == 6) {
      string ans;
      cout << "What word becomes shorter after you add to letters to it?\n";
      getline.(cin, ans);
      toupper(ans);
      if(ans != 'SHORT') {
        wrong_ans();
     //   score = score - 10;
      }
      else
        correct_ans();
    }
  
    if(choice == 7) {
      string ans;
      cout << "What starts with an E, but only has one letter in it?\n";
      getline.(cin, ans);
      toupper(ans);
      if(ans != 'ENVELOPE') {
        wrong_ans();
       // score = score - 10;
      }
      else 
        correct_ans();
    }
    if(choice == 8) {
        string ans;
        cout << "I have a key but no lock, a space but no room, you can enter\n";
        cout << " but can't gp outside. What am I?\n";
        getline.(cin, ans);
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
    
