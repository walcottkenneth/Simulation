#include <iostream>
using namespace std;

void wrong_ans() {
  cout << "Sorry that was the wrong answer\n";
  }
 void correct_ans() {
   cout << "Good Job!\n";
 }
  
//fucntion for puzzles/riddles

void puzzles(int x) {
  if (choice == 1) {
    string ans;
    cout << "Jimmy's mother had three children. The first was called april and the second was called May. What was the name of the third?\n"
    ;
    getline (cin, ans);
    toupper(ans);
    if(ans != 'JIMMY') {
      wrong_ans();
      score = score - 10; //we can change how many points the players looses depending on the difficulty of the question
    else
      correct_ans();
      }
   }
    
  if(choice == 2) {
    char ans;
    cout << " You can hold it without using your hand or your arms. What is it?\n";
    cin >> ans;
    toupper(ans);
    if(ans != 'YOUR BREATH' || ans != 'BREATH') {
      wrong_ans();
      score = score - 10;
     }
    }
    
   if (choice == 3) {
    char ans;
    cout << "234\n";
    cout << "23 \n";
    cout << "TIP:the answer is not 4\n";
    cin >> ans;
    if(ans != '5') {
      wrong_ans();
      score = score - 10;
     }
    }
    
    if (choice == 4) {
    char ans;
    cout << "Given that:\n"
    cout << "1 bottle of drink + 1 bottle of drink + 1 bottle of drink = 30\n";
    cout << "1 bottle of drink + 1 cheeseburger + 1 cheeseburger = 20\n";
    cout << "1 cheeseburger + 2 glasses of drink + 2 glasses of drink = 9\n";
    cin >> ans;
    if (ans != '15) {
      wrong_ans();
      score = score - 10;
     }
    }
    
    if (choice == 5) {
      char ans;
      cout << ""
    





   
   
   
   
