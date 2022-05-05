#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Scene6to10.h"
using namespace std;

void Scene_6(){
  cout << "Scene 6" << endl;
  cout << "At the dinner table, Dr Agasa asks the young master and the Lord why they have been living in the castle since the fire." << endl;
  cout << "While they both giving their own reasons, the Eldest Lady on the other side of the table says contemptuously that they stay here only for the treasure left by the Grand Lord." << endl;
  cout << "(Here the eldest lady mentioned again that she had to wait for the wife to come back)" << endl;
  cout << "This raises young master's consern, and he explains that the Eldest Lady has been in the castle for the last ten years because of her legs." << endl;
  cout << "After hearing this, it increase the Anita's suspicious towards the Eldest Lady." << endl;
  cout << "Amy asks the maid for a plastic bag and says she will give Conan something to eat when she finds he." << endl;
  cout << "The Lord discovers Conan's disappearance and raises his concerns. Two years ago, a servant starved to death in the forest,";
  cout << "and the rumors among the people was that the hatred of the dead wife killed him.";
  cout << "People are scared Conan would be in the same situation and deside to find him." << endl;
  cout << "No trace of Conan was found in the castle or in the courtyard,";
  cout << "and there was no sign of anyone entering or leaving the entrance of the tower.";
  cout << "Since it was raining heavily at this time, everyone decided to call the police the next day and wait for the police to search and rescue." << endl;
}
void Scene_7(int &cho){
  cout << "Scene 7" << endl;
  cout << "Now there is a choice:\n---Should Anita tells her concerns to Dr Agasa?" << endl;
  cout << "---1.Yes\n---2.No" << endl;
  cout << "Your choice is: ";
  //enter a number
  cin >> cho;
}
void Scene_8(int &cho){
  cout << "Scene 8" << endl;
  cout << "Dr Agasa is attracted by the noise when he is about to make a phone call in the hallway.";
  cout << "Then he walks to the source to find Conan's hat, which still has blood on it." << endl;
  cout << "At this time, a secret door on the wall next to him opened. Driven by curiosity ,Dr Agasa walked in,";
  cout << "and was knocked into unconscious from behind by the mysterious person before the secret door closed." << endl;
  cout << "Later Anita finds that the doctor is also disappeared. When Anita tried to call the police herself, the Lord comes over.";
  cout << "To not to raise suspicious, since she does not know who she can trust, she hangs up the phone and goes back to the room with the others." << endl;
  cout << "Dr Agasa did returned to the room, Anita thoughts that the doctor was killed." << endl;
  cout << "Now there is a choice:\n---Should Anita investigates herself or waits until the police come in tomorrow morning?" << endl;
  cout << "---1.Go investigating\n---2.Stay in the room" << endl;
  cout << "Your choice is: ";
  //enter a number
  cin >> cho;
}
void Scene_9(){
  cout << "Scene 9" << endl;
  cout << "She desides to conduct an investigation at night,";
  cout << "and the other partners secretly follow her and are found by Anita." << endl;
  cout << "As a matter of fact, they investigat together and return to the room where Conan disappeared during the day.";
  cout << "Anita opens the secret door with the same way Conan did, and after they go in it, they find bloodstain while they exploring downwards.";
  cout << "On a staircase, Mitch finds a series of inscription from long time ago, which says,";
  cout << "---\"That person has now taken my place and wants to rob the trea of the castle.\"---";
  cout << "The last word was not written, as if the person wanted to write the treasure." << endl;
  cout << "Anita deduces that the person who carved the letter dead here, and Conan was probably killed here when he was attracted to the attention of the corpse.";
  cout << "At this time, Geroge finds a pair of glasses next to him, as if it is the doctor's." << endl;
  cout << "They then walk in to a wall, but it turns out to be the secret door.";
  cout << "And because of it, Mitch，Amy, and Anita fall out, which is where the doctor disappeared(next to the telephone)." << endl;
  cout << "The secret door is then closed, and it cannot be opened from the outside.";
  cout << "Geroge unfortunatly dose not come out and is attacked by the mysterious person." << endl;
  cout << "When the rest are tring to re-enter through the entrance, the secret door was sealed.";
  cout << "Anita deduces that someone was stalking and trying to catch them, but they somehow walked out of the dark room." << endl;
  cout << "They then travel in the castle and try to find some evidence." << endl;
}
void Scene_10(int &cho){
  cout << "Scene 10" << endl;
  cout << "While Amy and Anita are investigating in a room, Mitch finds Conan's glasses not far from the door of the room.";
  cout << "At this time, the entrance of the tower that had caught fire in the distance heard the sound of heavy doors opening." << endl;
  cout << "At the same time, Anita finds a newspaper report of a fire four years ago, which said that fifteen people had died in the fire,";
  cout << "the fire had violently burned everyone to ashes, and the identification of the remains could only be determined by the item they carried,";;
  cout << "and only one of them was missing. (He must have swapped himself with someone through the fire)" << endl;
  cout << "When Amy and Anita come out, Mitch have already disappeared. So Anita decided to enter the tower first to find Mitch,";
  cout << "and tells Amy to run away if she does not come out within three hundred seconds." << endl;
  cout << "Now there is a choice:\n---Should Amy goes in the tower or listen to Anita and run away?" << endl;
  cout << "---1. Enter the tower\n---2. Run away" << endl;
  cout << "Your choice is: ";
  //enter a number
  cin >> cho;
}

void Escape_1(int &result){
  cout << "Amy decides to run out of the forest to find the police." << endl;
  cout << "Now she needs your help to escape by winning a game." << endl;
  int count = 0, guess;
  int num;
  srand(time(0));
  num = rand() % 10;
  cout << "You need to guess a number from 0 to 9, and you have 4 chances." << endl;
  while (count < 3){
    cout << "Please enter a number: ";
    // enter a number
    cin >> guess;
    if (guess > num){
      cout << guess << " is larger, you need to guess a smaller one." << endl;
    }
    else if (guess == num){
      cout << "-----correct!-----" << endl;
      break;
    }
    else if (guess < num) {
      cout << guess << " is smaller, you need to guess a larger one." << endl;
    }
    count++;
  }
  if (count == 3){
    cout << "You lose the game and Amy fail to escape the forest." << endl;
    result = 0;
  }
  else{
    cout << "You win the game and Amy escapes the forest successfully." << endl;
    result = 1;
  }
}
