#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "classes.h"
using namespace std;

class Point {
    int x = 5, y = 5;
    public:
    int MIN_X = 0;
    int MAX_X = 10;
    int MIN_Y = 0;
    int MAX_Y = 10;
    Point() {}
    Point(int new_x, int new_y) {
        x = new_x;
        y = new_y;
    }
    int get_x() {
        return x;
    }
    int get_y() {
        return y;
    }
    void set_x(int k) {
        x = k;
    }
    void set_y(int k) {
        y = k;
    }
    void i_x(){
        x++;
        if (x > MAX_X) x = MAX_X;
        if (x < MIN_X) x = MIN_X;
    }
    void d_x(){
        x--;
        if (x > MAX_X) x = MAX_X;
        if (x < MIN_X) x = MIN_X;
    }
    void i_y(){
        y++;
        if (y > MAX_Y) y = MAX_Y;
        if (y < MIN_Y) y = MIN_Y;
    }
    void d_y(){
        y--;
        if (y > MAX_Y) y = MAX_Y;
        if (y < MIN_Y) y = MIN_Y;
    }
};

void insert(pcode* temp, string new_p) {
    if(!temp) { temp = new pcode(new_p); }
    else {
        while(temp){
            if(!temp->next) {
                temp->next = new pcode(new_p);
                break;
            }
            temp = temp->next;
        }
    }
}
void print(pcode* temp){
    int i = 1;
    if(!temp) { cout << "You currently have no passwords.\n"; }
        else {
            cout << "Your passcode list.\n";
            while(temp) {
                cout << i << ") " << temp->p << endl;
                temp = temp->next;
                i++;
            }
        }
}

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
    pcode* head;
    
    string h    = "Keller";     //host
    string ft   = "Sabrina";    //fortune teller
    string kk   = "crystal";    //object

    cout << "What is your name, " << name << "?" << endl;
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
        if (c == 'Q' || c == 'q') die();
        if (c == 'W' || c == 'w') map.i_y();
        if (c == 'A' || c == 'a') map.d_x();
        if (c == 'S' || c == 's') map.d_y();
        if (c == 'D' || c == 'd') map.i_x();
        if (c == 'F' || c == 'f') {
            cout << "You found Sabrina, the best fortune teller in all of L.A." << endl;
            if (map.get_x() <= 5 && map.get_y() >= 5) {
                cout << ft << ": Go to 36 N. Ocean Ave." << endl;
            }
            if (map.get_x() <= 5 && map.get_y() < 5) {
                cout << ft << ": Go to Kerney's favorite place." << endl;
            }
            if (map.get_x() > 5 && map.get_y() <= 5) {
                cout << ft << ": Vist the year that is the title of the famous book written by George Orwell." << endl;
            }
            if (map.get_x() > 5 && map.get_y() > 5) {
                cout << ft << ": Go to the spot where in binary code it reads 'on off on off'." << endl;
            }
            cout << "Would you like to see your passcodes(y/n).\n";
            cin >> c;
            if(c == 'Y' || c == 'y') { print(head); }
            if(c == 'N' || c == 'n') { ; }
        }
        if (map.get_x() == 4 && map.get_y() == 2) {
            puzzle1.quiz();
            head = new pcode("23WESDXC");
        }
        if (map.get_x() == 10 && map.get_y() == 10) {
            puzzle2.quiz();
            insert(head, "RT56DFXC");
        }
        if (map.get_x() == 3 && map.get_y() == 6) {
            puzzle3.quiz();
            insert(head, "ZM10ALBG");
        }
        if (map.get_x() == 8 && map.get_y() == 4) {
            puzzle4.quiz();
            insert(head, "W2TVB3H7");
        }
        if (health <= 0) die();
        if (win == 4) break;
    }
    cout << "*',.'+.,'-.*.,'-',.+'-*',.+.,'-.,*',+..',.'*.+',','*+',.+" << endl;
    cout << "Congratulations, " << name << ", you found your way home!" << endl;
    cout << "*',.'+.,'-.*.,'-',.+'-*',.+.,'-.,*',+..',.'*.+',','*+',.+" << endl;
}
