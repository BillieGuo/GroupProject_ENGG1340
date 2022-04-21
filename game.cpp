/*
  ENGG1340 Group project
  Game: Dective Conan "The Old Blue Castle Investigation Case"
  Members: Bao Guo(3035952458), Yucheng Guo(3035952707)
  */
#include <iostream>
using namespace std;

struct info{

};




//open file to load saved game.
void load_game(){}

//find file in the "Saves" directory, return false if no saved game.
bool check_saved_game(){}

//initialization
void starts(int *starts){

  cout << "Welcome to play the game of Dective Conan,";
  cout << "\"The Old Blue Castle Investigation Case\"." << endl;
  cout << "1. Start new game" << endl;
  cout << "2. Load saved game" << endl;
  cout << "3. Quit" << endl;

  cin >> *starts;
  if (*starts == 1){
    cout << "Loading..." << endl;
    cout << "The game will be saved automatically once you reach some CheckPoints." << endl;
}
  else if (*starts == 2){
    if (check_saved_game()){
      cout << "Game loading!" << endl;
    }
    else cout << "You do not have any saved game. Please start a new one!" << endl;
  }
  else if (*starts == 3){cout << "Game terminated." << endl;}
}


int main(){
  int *game_ini = new int;
  starts(&(*game_ini));
  //new game
  if (*game_ini == 1){

  }
  //saved game
  else if (*game_ini == 2){
    load_game();
  }
  //end
  else if (*game_ini == 3){return 0;}

}
