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
#include "Scene15to17.h"
using namespace std;

struct info{
  int scene;
  vector<string> clue;
  vector<string> achievement;

  void add_achievement(string a){
    achievement.push_back(a);
  }

  void add_clue(string c){
    clue.push_back(c);
  }
};

//open file to load saved game.
void load_game(info *status){
  ifstream fin;
  fin.open("save.txt");
  if (fin.fail()){
    cout << "Error in opening file!" << endl;
    exit(1);
  }
  fin >> status->scene;
  string x;
  while(fin >> x){
    if (x == "-----"){break;}
    status->add_clue(x);
    fin >> x;
  }
  while(fin >> x){
    status->add_achievement(x);
  }
  fin.close();
}

//save game
void save_game(info *status){
    ofstream fout;
    fout.open("save.txt");
    if (fout.fail()){
      cout << "Error in opening file!" << endl;
      exit(1);
    }
    fout << status->scene << endl;
    vector<string>::iterator i;
    for (i = status->clue.begin(); i < status->clue.end(); i++){
      fout << *i << endl;
    }
    fout << "-----" << endl;
    for (i = status->achievement.begin(); i < status->achievement.end(); i++){
      fout << *i << endl;
    }
    fout.close();
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

//seperator
void sep(){
  for (int i = 0; i != 5; i++){
    cout << "..." << endl;
  }
}


int main(){
  int *game_ini = new int;
  info *status = new info;
  int cho, count = 0, save;
  char n;
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

  while (status->scene != 0){
    sep();
    if(status->scene == 1){
      cout << "Some choices in the game may alter the ending, choose wisely." << endl;
      cout << "Since there are hundreds of episodes of Conan after this Case, any Death of the main Characters will lead to the end of game." << endl;
      cout << "Enter \"s\" to start." << endl;
      cin >> n;
    }
    else {
      cout << "Do you want to save game?\n--1.Yes\n--2.No" << endl;
      cout << "Please enter a number: " ;
      cin >> save;
      if (save == 1){save_game(&(*status));}
      cout << "Enter \"n\" for next scene." << endl;
      cin >> n;
    }
    sep();
    switch(status->scene){
      case 0:
        cout << "END..." << endl;
        cout << "Thanks for playing!" << endl;
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
        if (cho == 1){
          status->add_clue("ChessBoard");
          status->add_achievement("ChessBoard");
        }
        status->scene = 4;
        break;
      case 4:
        Scene_4();
        if (cho != 1){
          status->add_clue("ChessBoard");
          status->add_achievement("ChessBoard");
        }
        status->scene = 5;
        break;
      case 5:
        Scene_5(count);
        status->scene = 6;
        break;
      case 6:
        Scene_6();
        status->add_clue("Passport");
        status->scene = 7;
        break;
      case 7:
        Scene_7(cho);
        if (cho == 2){
          status->scene = 15;
        }
        else {
          cout << "Back in the hall, Anita tells the Doctor that Conan is probably been killed." << endl;
          cout << "(At this time, the mysterious person overhead in the shadows and later stalked Dr Agasa)" << endl;
          status->scene = 8;
        }
        break;
      case 8:
        Scene_8(cho);
        if (cho == 1){status->scene = 9;}
        else {status->scene = 16;}
        break;
      case 9:
        Scene_9();
        status->add_achievement("LastWordsOfCorpse");
        status->add_clue("LastWordsOfCorpse");
        status->add_achievement("Doctor'sGlasses");
        status->scene = 10;
        break;
      case 10:
        Scene_10(cho);
        status->add_achievement("Conan'sGlasses");
        status->add_achievement("Newspaper");
        status->add_clue("Newspaper");
        if (cho == 1){
          cout << "Amy is eager to find her friends, so she does not run away after counting to 300 seconds, and also entered the tower." << endl;
            status->scene = 11;
        }
        else {status->scene = 17;}
        break;
      case 11:
        Scene_11();
        status->scene = 12;
        break;
      case 12:
        int result;
        Scene_12();
        sep();
        //random game
        Escape_2(result);
        status->scene = 13;
        break;
      case 13:
        Scene_13_1();
        sep();
        //find the answer for treasure
        Treasure(status->clue);
        sep();
        Scene_13_2();
        status->scene = 14;
        break;
      case 14:
        Scene_14();
        status->scene = 0;
        break;

      //one of the possible ending
      case 15:
        Scene_15();
        status->scene = 0;
        break;

      //one of the possible ending
      case 16:
        Scene_16();
        status->scene = 0;
        break;

      //one of the possible branch
      case 17:
        Escape_1(result);
        if (result == 0){
          Scene_17_1();
          status->scene = 0;
        }
        else {
          Scene_17_2();
          status->scene = 11;
        }
        break;
    }
  }
  sep();
  cout << "END..." << endl;
  cout << "Thanks for playing!" << endl;

  //delete status;
//testing file I/O
  cout << status->scene <<endl;
  vector<string>:: iterator i;
  for (i = status->clue.begin(); i != status->clue.end(); i++){
    cout << *i<< endl;
  }
  cout << "The achievement you have is/are below: " << endl;
  for (i = status->achievement.begin(); i != status->achievement.end(); i++){
    cout << *i<< endl;
  }
}
