/*
  ENGG1340 Group project
  Game: Dective Conan "The Old Blue Castle Investigation Case"
  Members: Bao Guo(3035952458), Yucheng Guo(3035952707)
  */
#include <iostream>
#include <fstream>
#include <vector>
#include "Scene1to5.h"
#include "Scene6to10.h"
#include "Scene11to14.h"
using namespace std;

struct info{
  int scene;
  vector<string> clue;

  void add_clue(string c){
    clue.push_back(c);
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
    status->add_clue(x);
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
  cout << "---1. Start new game" << endl;
  cout << "---2. Load saved game" << endl;
  cout << "---3. Quit" << endl;

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
  int cho, count = 0;
  string paz;

  starts(&(*game_ini));
  //new game
  if (*game_ini == 1){
    status->scene = 1;
  }
  //saved game
  else if (*game_ini == 2){
    load_game(&(*status));
  }
  //end
  else if (*game_ini == 3){return 0;}
  delete game_ini;

  //seperator / sep
  for (int i = 0; i != 5; i++){
    cout << "..." << endl;
  }

  while (status->scene != 0){
    switch(status->scene){
      case 0:
        break;
      case 1:
        Scene_1();
        status->scene = 2;
        break;
      case 2:
        Scene_2();
        status->scene = 3;
        break;
      case 3:
        Scene_3(cho);
        if (cho == 1){status->add_clue("ChessBoard");}
        status->scene = 4;
        break;
      case 4:
        Scene_4();
        if (cho != 1){status->add_clue("ChessBoard");}
        status->scene = 5;
        break;
      case 5:
        Scene_5(count);
        status->scene = 6;
        break;
      case 6:
        Scene_6();
        status->scene = 7;
        break;
      case 7:
        Scene_7(cho);
        status->scene = 8;
        break;
      case 8:
        Scene_8();
        status->scene = 9;
        break;
      case 9:
        Scene_9();
        status->scene = 10;
        break;
      case 10:
        Scene_10();
        status->scene = 11;
        break;
      case 11:
        Scene_11();
        status->scene = 12;
        break;
      case 12:
        Scene_12();
        status->scene = 13;
        break;
      case 13:
        Scene_13();
        status->scene = 14;
        break;
      case 14:
        Scene_14();
        status->scene = 0;
        break;
    }
  }


  //end
  cout << "END..." << endl;
  cout << "Thanks for playing!" << endl;

//testing file I/O
  cout << status->scene <<endl;
  vector<string>:: iterator i;
  for (i = status->clue.begin(); i != status->clue.end(); i++){
    cout << *i<< endl;
  }
}
