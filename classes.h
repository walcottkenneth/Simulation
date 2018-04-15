#include <iostream>
using namespace std;


struct xy{//This is a struct for loaction. It puts x and y
           //together to make a single, function-returnable value
  int x = 0;
  int y = 0;
}




class Player(){//This class includes:
               // location struct, health, get/set location functions, and a damage function.
  private:
    xy location;
    int health = 10;
    
   public:
   
   int get_location(){ //returns both the x and y loc values
    return location;
   }
   
   int get_x(){ //returns only x
    return location.x;
   
   }
   
   int get_y(){//returns only y
    return location.y;
   
   }
   
   void set_location(new_x, new_y){//changes location, can be implemented into movement.
      location.x = new_x;
      loaction.y = new_y;
   }
   
   void damage(){//damage function
    health--;
   }

    void heal(){//healing function
     health++;
    }
};
