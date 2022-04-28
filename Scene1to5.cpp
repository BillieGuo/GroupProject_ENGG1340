#include <iostream>
#include <string>
#include "Scene1to5.h"
using namespace std;

void Scene_1(){
  cout << "Scene 1" << endl;
  cout << "Conan and his friends went out to camp with Dr Agasa, ";
  cout << "but had to return because Dr Agasa forgot to bring his tent. " << endl;
  cout << "On the way back, they found a blue castle.";
}
void Scene_2(){
  cout << "At the gate of the blue castle, when everyone is looking at it, ";
  cout << "George rushes over the gate and is caught by a gardener." << endl;
  cout << "With some explains, the gardener realizes it is a misunderstand ";
  cout << "and at the same time, the son of the owner of the castle appears." << endl;
  cout << "After he learned that Dr Agasa is a scientist, he decides to invite everyone to stay for one night." << endl;
}
void Scene_3(int &cho){
  cout << "Walking into the courtyard, they are greeted by many huge Chess pieces, ";
  cout << "which were built according to the wills of the Great Lord who died fifteen years ago." << endl;
  cout << "The eldest son of the Great Lord, who died of illness six years ago, instructed the housekeeper to keep these Chess pieces up. " << endl;
  cout << "The Lord(now lord) is the second husband of the Wife, and the Wife was burned to death in a fire four years earlier." << endl;
  cout << "In that year, his wife returned to the castle to celebrate the Eldest Lady's birthday. " << endl;
  cout << "His wife, his friends and servants all died in the fire, but the Eldest Lady survived as she slept in another bedroom that night because of a cold. " << endl;
  cout << "The young master (the grandson of the eldest grandfather) also survived. " << endl;
  cout << "And then Lord and the young master have been living in the castle since the fire." << endl;
  //sep+choice 1
  cout << "Now there is a choice: "<<endl;
  cout << "1. Go around the courtyard" << endl;
  cout << "2. Enter the castle" << endl;
  cout << "Your choice is: ";
  cin >> cho;
  if (cho == 1){
    cout << "You are amazed by the huge Chess pieces, and decide to record them." << endl;
    cout << "They then enter the castle." << endl;
  }
}
void Scene_4(){
  cout << "After entering the hall, Dr Agasa, Conan and his friends see the portraits of the Great Lord, son of the Great Lord and His Wife." << endl;
  cout << "At the time of the introduction by the housekeeper, the Eldest Lady comes in with a wheelchair and says that the Great Lord is just a intellectual with nonsense." << endl;
  cout << "Awaring of that Dr Agasa is a scientist, so she hopes that he could help unravel the Secret of the castle." << endl;
  cout << "The Eldest Lady says, she has got used to that the death of Great Lord, ";
  cout << "which is just like the change in the size of the passport and the change in the portrait printed on the currency.";
  cout << "During the conversation, the eldest lady mentioned that she was waiting for her daughter (the wife who died in the fire) to return." << endl;
  cout << "The Conan’s party felt pity for the mental shock suffered by the eldest wife." << endl;
  cout << "After the conversation, Conan is interested about the treasure and proposes to find a room where the whole chessboard can be seen." << endl;
}
void Scene_5(int &count){
  string paz;
  cout << "Conan discovers that the two windows against the wall of the two adjacent rooms are too far apart, ";
  cout << "and becomes suspicious that there is space between the walls." << endl;
  cout << "After investigating the clock on the wall, he finds a broken clock which is A typical trigger of a secret room." << endl;
  //slove pazzle 1 +seperator

  cout << "What is the answer to the trigger? (one word starts with \'r\')" << endl;
  cout << "Hint: what is the motion of the hands of clock?" << endl;
  while (count < 3){
    cout << "Your answer is: ";
    cin >> paz;
    count++;
    if (paz == "rotate" || paz == "rotation"){
      cout << "-----Correct!-----"<< endl;
      break;
    }
    else {
      cout << "Wrong answer! You have " << (3 - count) << " more chance(s)." << endl;
    }
    if (count == 3) {cout << "-----The answer is \"rotation\".-----" << endl;}
  }
  //seperator
  cout << "Conan opens a secret passage and fall into it, following by the close of the door." << endl;
  cout << "Later, Conan discovers a corpse as he explores the secret passage. ";
  cout << "But at the same time, a mysterious person appears and knocks Conan into unconscious." << endl;
  cout << "No one found any trace of Conan, except Anita has doubts about the clock. And just as she is preparing to check the clock, ";
  cout << "the young master appears to stop her and says that everyone could eat first and wait for Conan by the time he is hungry and he would come out. " << endl;
}
