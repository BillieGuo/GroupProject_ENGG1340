/*
  ENGG1340 Group project
  Game: Dective Conan "The Old Blue Castle Investigation Case"
  Members: Bao Guo(3035952458), Yucheng Guo(3035952707)
  */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct info{
  int scene;
  vector<string> inv;

  void add_item(string item){
    inv.push_back(item);
  }
};

//open file to load saved game.
void load_game(info *status){
  ifstream fin;
  fin.open("save.txt");
  if (fin.fail()){
    cout << "Error in loading saving!" << endl;
    exit(1);
  }
  fin >> status->scene;
  string x;
  while(fin >> x){
    status->add_item(x);
  }
  fin.close();
}

//find file in the "Saves" directory, return false if no saved game.
bool check_saved_game(){
  ifstream fin;
  fin.open("save.txt");
  if (fin.fail()){
    cout << "Error in loading saving!" << endl;
    fin.close();
    return false;
  }
  fin.close();
  return true;
}

//initialization
void starts(int *starts){
  cout << "Welcome to play the game of Dective Conan,";
  cout << "\"The Old Blue Castle Investigation Case\"." << endl;
  cout << "1. Start new game" << endl;
  cout << "2. Load saved game" << endl;
  cout << "3. Quit" << endl;

  cout << "Pleas enter a number: ";
  cin >> *starts;
  if (*starts == 1){
    cout << "Loading..." << endl;
    cout << "The game will be saved automatically once you reach some CheckPoints." << endl;
  }
  else if (*starts == 2){
    if (check_saved_game()){
      cout << "Game loading!" << endl;
    }
    else {
      cout << "You do not have any saved game. A new one is loading!" << endl;
      *starts = 1;
    }
  }
  else if (*starts == 3){cout << "Game terminated." << endl;}
}


int main(){
  int *game_ini = new int;
  info *status = new info;

  starts(&(*game_ini));
  //new game
  if (*game_ini == 1){
    status->scene = 0;
  }
  //saved game
  else if (*game_ini == 2){
    load_game(&(*status));
  }
  //end
  else if (*game_ini == 3){return 0;}
  delete game_ini;
  for (int i = 0; i != 5; i++){
    cout << "..." << endl;
  }
//part 1
  

//testing file I/O
  cout << status->scene <<endl;
  vector<string>:: iterator i;
  for (i = status->inv.begin(); i != status->inv.end(); i++){
    cout << *i<< endl;
  }
}
