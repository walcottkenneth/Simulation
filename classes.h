#include <iostream>
using namespace std;


struct xy {     //This is a struct for loaction. It puts x and y
    int x = 0;  //together to make a single, function-returnable value
    int y = 0;
};

string name = "Player 1";

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

/*class Player {  //This class includes:
                // location struct, health, get/set location functions, and a damage function.
    private:
    xy location;
    int health = 10;

    public:
    xy get_location() { //returns both the x and y loc values
        return location;}
    int get_x() { //returns only x
        return location.x;}
    int get_y() { //returns only y
        return location.y;}
    void set_location(int new_x, int new_y) {//changes location, can be implemented into movement.
        location.x = new_x;
        location.y = new_y;}
};*/

class Puzzle{
    protected://The location for the puzzles
    xy placement;       
    bool solved = false;
    int health = 10;
           
    public:
    /*xy get_placement() {//returns x and y
        return placement;}  
    int get_x() {//returns x
        return placement.x;}
    int get_y() {//returns y
        return placement.y;}                                                                         
    void set_placement(int new_x, int new_y) {//changes x and y values. Can be used manually or in a function
        if (new_x <= 0) new_x = 0;    //0 is min limit, 9 is max.
        else if (new_x >= 9) new_x = 9;
        if (new_y <= 0) new_y = 0;    //0 is min limit, 9 is max.
        else if (new_y >= 9) new_y = 9;
        placement.x = new_x;                                                                                                                                                                 placement.y = new_y;    
    }*/
    void damage(){health--;}
    void heal(){health++;}
    int get_health(){return health;}

};


class puzzle1 : public Puzzle{
    public:
    string answer;
    void quiz(){
        while(solved == false) {
            cout << "Jimmy's mother had three children. The first was called April\n";
            cout << "and the second was called May. What was the name of the third?\n";
            cin >> answer;
            if(answer == "Jimmy" || answer =="jimmy"){
                solved = true;
                cout << "That is correct.\n";
                placement.x = -1;
                placement.y = -1;}
            else{
                Puzzle::damage();
                cout << "That is incorrect. You lose one life point." << endl;
                cout << "You have " << Puzzle::get_health() << " life points remaining." << endl;}
        }
        cout << "You have solved the puzzle." << endl;
    }
};

class puzzle2 : public Puzzle{
    public:
    string answer;
    void quiz(){
        while(solved == false) {
            cout <<  "You can hold it without using your hand or your arms. What is it?" << endl;
            cin >> answer;
            if(answer == "Your breath" || answer =="your breath"){
                solved = true;
                cout << "That is correct.\n";
                placement.x = -1;
                placement.y = -1;
            }
            else {
                Puzzle:: damage();
                cout << "That is incorrect. You lose one life point." << endl;
                cout << "You have " << Puzzle :: get_health() << " life points remaining." << endl;
            }
        }
        cout << "You have solved the puzzle." << endl;
    }
};

class puzzle3 : public Puzzle{
    public:
    string answer;
    void quiz(){
        while(solved == false) {
            cout <<  "Poor people have it. Rich people need it. If you eat it you die. What is it?" << endl;
            cin >> answer;
            if(answer == "Nothing" || answer =="nothing"){
                solved = true;
                cout << "That is correct.\n";
                placement.x = -1;
                placement.y = -1;
            }
            else {
                Puzzle::damage();
                cout << "That is incorrect. You lose one life point." << endl;
                cout << "You have " << Puzzle :: get_health() << " life points remaining." << endl;
            }
        }
        cout << "You have solved the puzzle." << endl;
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
            if(answer == "A keyboard" || answer =="a keyboard" || answer == "keyboard"){
                solved = true;
                cout << "That is correct.\n";
                placement.x = -1;
                placement.y = -1;
            }
            else {
                Puzzle::damage();
                cout << "That is incorrect. You lose one life point." << endl;
                cout << "You have " << Puzzle :: get_health() << " life points remaining." << endl;
            }
        }
        cout << "You have solved the puzzle." << endl;
    }
};
