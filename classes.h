#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
using namespace std;

string name = "Player 1";
int win = 0;
int health = 10;

void die() {
    cout << "  ,'*********',  " << endl;
    cout << ".'             '." << endl;
    cout << "|     R.I.P.    |" << endl;
    cout << "| " << name << " |" << endl;
    cout << "| Gone, but not |" << endl;
    cout << "|   forgotten.  |" << endl;
    cout << "^^^^^^^^^^^^^^^^^" << endl;
    exit(1);
}

class Puzzle{
    protected://The location for the puzzles
    bool solved = false;
           
    public:
    void damage(){health--;}
    void heal(){health++;}
};

struct pcode{
    string p = " ";
    pcode* next = nullptr;
    pcode(){}
    pcode(string new_p): p(new_p){}
    ~pcode(){}
};

class puzzle1 : public Puzzle{
    public:
    string answer;
    void quiz(){
        while(solved == false) {
            cout << "Jimmy's mother had three children. The first was called April\n";
            cout << "and the second was called May. What was the name of the third?\n";
            cin >> answer;
            if(answer == "JIMMY" || answer =="jimmy" || answer == "Jimmy"){
                win++;
                solved = true;
                cout << "That is correct. You have found a crystal!\n";
            }
            else if(answer == "23WESDXC") {
                win++;
                solved = true;
                cout << "Passcode accepted. You have found a crystal!\n";
            }
            else{
                Puzzle::damage();
                cout << "That is incorrect. You lose one life point." << endl;
                cout << "You have " << health << " life points remaining." << endl;}
            if (health <= 0) die();
        }
        cout << "You have solved this puzzle." << endl;
        cout << "Here is your passcode:" <<  " 23WESDXC" <<endl;
    }
};

class puzzle2 : public Puzzle{
    public:
    string answer;
    void quiz(){
        while(solved == false) {
            cout << "It cannot be seen when it is there." << endl;
            cout << "It fills up a room, much like air." << endl;
            cout << "It cannot be touched, what is it?" << endl;
            cin >> answer;
            if(answer == "DARKNESS" || answer =="darkness"){
                win++;
                solved = true;
                cout << "That is correct. You have found a crystal!\n";
            }
            else if(answer == "RT56DFXC") {
                win++;
                solved = true;
                cout << "Passcode accepted. You have found a crystal!\n";
            }
            else {
                Puzzle:: damage();
                cout << "That is incorrect. You lose one life point." << endl;
                cout << "You have " << health << " life points remaining." << endl;
            if (health <= 0) die();
            }
        }
        cout << "You have solved this puzzle." << endl;
        cout << "Here is your passcode:" <<  " RT56DFXC" <<endl;
    }
};

class puzzle3 : public Puzzle{
    public:
    string answer;
    void quiz(){
        while(solved == false) {
            cout <<  "Poor people have it. Rich people need it. If you eat it you die. What is it?" << endl;
            cin >> answer;
            if(answer == "NOTHING" || answer =="nothing"){
                win++;
                solved = true;
                cout << "That is correct.You have found a crystal!\n";
            }
            else if(answer == "ZM10ALBG") {
                win++;
                solved = true;
                cout << "Passcode accepted. You have found a crystal!\n";
            }
            else {
                Puzzle::damage();
                cout << "That is incorrect. You lose one life point." << endl;
                cout << "You have " << health << " life points remaining." << endl;
            if (health <= 0) die();
            }
        }
        cout << "You have solved this puzzle." << endl;
        cout << "Here is your passcode:" <<  " ZM10ALBG" <<endl;
    }
};

class puzzle4 : public Puzzle{
    public:
    string answer;
    void quiz() {
        while(solved == false){
            cout << "I have keys that fit no locks, a space but no room." << endl;
            cout << "You can enter, but never leave. What am I?" << endl;
            cin >> answer;
            if(answer == "KEYBOARD" || answer == "keyboard"){
                win++;
                solved = true;
                cout << "That is correct. You have found a crystal!\n";
            }
            else if(answer == "W2TVB3H7") {
                win++;
                solved = true;
                cout << "Passcode accepted. You have found a crystal!\n";
            }
            else {
                Puzzle::damage();
                cout << "That is incorrect. You lose one life point." << endl;
                cout << "You have " << health << " life points remaining." << endl;
            if (health <= 0) die();
            }
        }
        cout << "You have solved this puzzle." << endl;
        cout << "Here is your passcode:" <<  " W2TVB3H7" <<endl;
    }
};

#endif
