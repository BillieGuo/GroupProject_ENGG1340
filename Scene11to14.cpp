#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
#include "Scene11to14.h"

void Scene_11(){
  cout << "Scene 11" << endl;
  cout << "Inside the tower, Amy mistakenly enters a toilet and locks the door.";
  cout << "At this time, there was a frequent knock on the door,";
  cout << "and the door that is tried to be violently opened let her know that it was not her companion outside the door.";
  cout << "Fortunately, Anita, who is hiding inside a secret door, appears in time and saves Amy before the mysterious person open the door, and they are not been discovered." << endl;
}
void Scene_12(){
  cout << "Scene 12" << endl;
  cout << "Anita and Amy climb down a ladder to an underground passage and find a skeleton with some years of age.";
  cout << "Judging from the dust that has accumulated above, it haven't been here for long,";
  cout << "and it seemed that it was this person who had carved the words on the stairs before.";
  cout << "This was most likely discovered by Conan before being moved to this place by the Mysterious person." << endl;
  cout << "The skeleton's foot bones looks thinner than the rest of the body, and the teeth are lost, and judging by the length of the hair, it should be a woman.";
  cout << "The person who changed the identity of the skeleton may be the murderer." << endl;
  cout << "At this time, the Eldest Lady appears and asks with concern where the other friend(Mitch) who was with them,";
  cout << "and when Amy is still trying to take the Eldest Lady to hide from the mysterious person,";
  cout << "the Anita grabs Amy's hand and starts to flee, explaining that from all aspects of the skeleton:";
  cout << "this is probably the body of the Eldest Lady,";
  cout << "and the people who had just killed the Eldest Lady and groomed into the appearance of the Eldest Lady." << endl;
  cout << "When the fake Eldest Lady(the Fake) encountered the details, the Fake pretended to have a bad memory,";
  cout << "the Fake was the one who set fire to the murderer that day, and finally found that there was no way to deceive the Eldest Lady's daughter before setting fire to kill.";
  cout << "And It is not impossible to know this underground passage and come back after setting fire to kill people." << endl;
}
void Escape_2(int &result){
  int count, num;
  string ans = "", guess;
  //random seed
  srand(time(0));
  cout << "To escape from the underground passage, you need to win a game." << endl;
  cout << "You will be provided with 5 numbers, and odd numbers represent \"Left\" and even numbers represents \"right\"." << endl;
  cout << "---e.g.\n---1\n---93\n---64\n---44\n---27\n---The answer is \"LLRRL\"." << endl;
  cout << "------------------------\nNow the game starts:" << endl;
  //generate random number
  for (int i = 0; i < 5; i++){
    num = rand() % 100 + 1;
    if ((num % 2) == 0){ans += "R";}
    else{ans += "L";}
    cout << num << endl;
  }
  // enter a series of characters
  cin >> guess;
  if (guess != ans){
    result = 0;
    cout << "-----Wrong answer!-----" << endl;
    cout << "They fail to escape and are caught by the Fake." << endl;
    cout << "She then take them go to the exit." << endl;
  }
  else{
    result = 1;
    cout << "-----Correct!-----" << endl;
    cout << "They success to escape and find the exit. However, when they are climbing up to the ground, the Fake catch Anita." << endl;
  }
}
void Scene_13_1(){
  cout << "Scene 13" << endl;
  cout << "The end of the underground passage leads directly to the hall of the castle,";
  cout << "and the Fake prepare to kill Anita and Amy after the acts is discovered,";
  cout << "and when the Fake's iron rod is about to hit Anita and Amy, a flying can knocks out the Fake's weapon." << endl;
  cout << "It is Conan who saves them, this time thanks to Mitch using the tracking function of the glasses he had picked up to find Conan and George.";
  cout << "At this time, the doctor appears, and through his friendship with a cosmetic surgeon abroad,";
  cout << "he discovers the true identity of the Eldest Lady(the Fake), Miss Nishikawa Mutsumi, a former housekeeper whose whereabouts are unknown after the fire.";
  cout << "The cosmetic surgeon said there was a strange guest who asked to make herself a strange old woman." << endl;
  cout << "When Miss Nishikawa thoughts that everyone had seen the skeleton to deduce her identity,";
  cout << "Conan says that the conclusion is the same even without the corpse,";
  cout << "because the Eldest Lady, who had lived in the castle for the past ten years,";
  cout << "and had not even traveled once, would certainly not know the change of the size of the passport,";
  cout << "and it was really not expected that Miss Nishikawa would go abroad several times to carry out expensive maintenance work for this face." << endl;
}
void Treasure(vector<string> &clue){
  string command, clue_name, ans, temp;
  int count = 0;
  cout << "Conan notices that Nishikawa wants to run away, so he need to attract her attention." << endl;
  cout << "The most possible way to make her stay is tell her the answer of the Treasure." << endl;
  cout << "Now please help Conan to figure out the answer of the Treasure." << endl;
  cout << "Hint: Check the clues you have collected. Enter \"Clues\" to see the infomation you have collected.";
  cout << "Then enter the name for further details. Enter \"Quit\" to quit.(You cannot check again once you quit)" << endl;
  //enter a word--Clues
  cin >> command;
  if (command == "Clues"){
    cout << "========" << endl;
    vector<string>::iterator i;
    for (i = clue.begin(); i < clue.end(); i++){
      cout << *i << endl;
    }
    cout << "========" << endl;
  }
  //enter a word
  cin >> clue_name;
  while (clue_name != "Quit"){
    if (clue_name == "ChessBoard"){
      cout << "-----" << endl;
      cout << "Chess Board(pattern):\n";
      cout << "8 |-|-|-|O|-|-|-|-|" << endl;
      cout << "7 |O|-|X|X|X|X|-|-|" << endl;
      cout << "6 |-|X|-|-|O|-|X|-|" << endl;
      cout << "5 |-|X|-|-|-|-|X|O|" << endl;
      cout << "4 |-|X|-|X|-|-|X|-|" << endl;
      cout << "3 |-|-|X|X|-|X|O|-|" << endl;
      cout << "2 |-|X|X|X|-|-|O|-|" << endl;
      cout << "1 |-|-|-|-|O|-|-|-|" << endl;
      cout << "   A B C D E F G H " << endl;
      cout << "\"X\" for Balck Chess, \"O\" for White chess, \"-\" for empty" << endl;
      cout << "-----" << endl;
    }
    else if(clue_name == "Passport"){
      cout << "-----" << endl;
      cout << "Passport:\nThe size of passport changes within the last ten years in Japan, but it is impossible for a person who does not travel abroad to know." << endl;
      cout << "-----" << endl;
    }
    else if(clue_name == "LastWordsOfCorpse"){
      cout << "-----" << endl;
      cout << "Last Words of Corpse:\n---\"That person has now taken my place and wants to rob the trea of the castle.\"---" << endl;
      cout << "-----" << endl;
    }
    else if(clue_name == "Newspaper"){
      cout << "-----" << endl;
      cout << "Newspaper:\nOne person was missing in the fire and no remains of this person were found." << endl;
      cout << "-----" << endl;
    }
    cin >> clue_name;
  }
  cout << "With the infomation you have known, try to figure out the answer of the Treasure.(5 chances)" << endl;
  while (count < 5){
    cout << "Please enter the answer(two words in CAPITAL): ";
    //enter the first word
    cin >> temp;
    ans = temp + " ";
    //enter the second word
    cin >> temp;
    ans += temp;
    if (ans == "EGG HEAD"){
      cout << "-----Correct!-----" << endl;
      break;
    }
    else {
      cout << "Wrong answer!" << endl;
      cout << "You have " << (4 - count) << " more chances." << endl;
    }
    count++;
  }
  if (count == 5){
    cout << "Do not be frustrated, Conan will explain to you later." << endl;
  }
}
void Scene_13_2(){
  cout << "Nishikawa is about to escape, but Conan claims to have found the treasure of the castle, which makes Nishikawa shock." << endl;
  cout << "The Western chessboard is arranged from the numbers one to eight and the letters A to H, so the correct direction to watch the chessboard from the knight.";
  cout << "From this direction, reading the white pieces in order is \"EGG HEAD\".";
  cout << "Referring to the intellectuals who can only say some perverse reasoning,";
  cout << "the answer is owner of the chessboard. Then only rotates the painting of the great master in counterclockwise direction, the entrance to the secret passage will appear." << endl;
}
void Scene_14(){
  cout << "Scene 14" << endl;
  cout << "After entering the secret passage and climbing up to reach the top of the tower,";
  cout << "Nishikawa excitedly opens the door where light comes out of the crack of the door,";
  cout << "and she is greeted by the castle's best view and the most beautiful viewing position." << endl;
  cout << "While Nishikawa is still finding the treasure, Conan prompts Nishikawa to see a message on the door:" << endl;
  cout << "-----\"I would like to give this castle and this scene to the first person who find it.\"-----" << endl;
  cout << "Nishikawa is distraught and unable to accept the facts, and an hour later the police arrest the woman who has truly become an eldest lady." << endl;
}
