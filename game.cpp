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
  //backgound info

//part 1
//s1
  cout << "Scene 1" << endl;
  cout << "Conan and his friends went out to camp with Dr Agasa, ";
  cout << "but had to return because Dr Agasa forgot to bring his tent. " << endl;
  cout << "On the way back, they found a blue castle.";
  status->scene = 2;
//s2
  cout << "At the gate of the blue castle, when everyone is looking at it, ";
  cout << "George rushes over the gate and is caught by a gardener." << endl;
  cout << "With some explains, the gardener realizes it is a misunderstand ";
  cout << "and at the same time, the son of the owner of the castle appears." << endl;
  cout << "After he learned that Dr Agasa is a scientist, he decides to invite everyone to stay for one night." << endl;
  status->scene = 3;
  //s3
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
    status->add_clue("ChessBoard");
    cout << "They then enter the castle." << endl;
  }
  status->scene = 4;
  //sep
  //s4
  cout << "After entering the hall, Dr Agasa, Conan and his friends see the portraits of the Great Lord, son of the Great Lord and His Wife." << endl;
  cout << "At the time of the introduction by the housekeeper, the Eldest Lady comes in with a wheelchair and says that the Great Lord is just a intellectual with nonsense." << endl;
  cout << "Awaring of that Dr Agasa is a scientist, so she hopes that he could help unravel the Secret of the castle." << endl;
  cout << "The Eldest Lady says, she has got used to that the death of Great Lord, ";
  cout << "which is just like the change in the size of the passport and the change in the portrait printed on the currency.";
  cout << "During the conversation, the eldest lady mentioned that she was waiting for her daughter (the wife who died in the fire) to return." << endl;
  cout << "The Conan’s party felt pity for the mental shock suffered by the eldest wife." << endl;
  cout << "After the conversation, Conan is interested about the treasure and proposes to find a room where the whole chessboard can be seen." << endl;
  if (cho != 1){status->add_clue("ChessBoard");}
  status->scene = 5;
  //s5
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
  status->scene = 6;
  //s6
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
  status->scene = 7;
  //s7
  cout << "Now there is a choice:\\n---Should Anita tells her concerns to Dr Agasa?" << endl;
  cout << "---1.Yes\n---2.No" << endl;
  cout << "Your choice is: ";
  cin >> cho;
  if (cho == 2){
    status->scene = 15;
  }
  else {
    cout << "Back in the hall, Anita tells the Doctor that Conan is probably been killed." << endl;
    cour << "(At this time, the mysterious person overhead in the shadows and later stalked Dr Agasa)" << endl;
    status->scene = 8;
  }
  //s8
  cout << "Dr Agasa is attracted by the noise when he is about to make a phone call in the hallway.";
  cout << "Then he walks to the source to find Conan's hat, which still has blood on it."; << endl;
  cout << "At this time, a secret door on the wall next to him opened. Driven by curiosity ,Dr Agasa walked in,";
  cout << "and was knocked into unconscious from behind by the mysterious person before the secret door closed." << endl;
  cout << "Later Anita finds that the doctor is also disappeared. When Anita tried to call the police herself, the Lord comes over.";
  cout << "To not to raise suspicious, since she does not know who she can trust, she hangs up the phone and goes back to the room with the others." << endl;
  status->scene = 9;
  //s9
  cout << "Dr Agasa did returned to the room, Anita thoughts that the doctor was killed, so she conducted an investigation at night,";
  cout << "and the other partners secretly follow her and are found by Anita." << endl;
  cout << "As a matter of fact, they investigat together and return to the room where Conan disappeared during the day.";
  cout << "Anita opens the secret door with the same way Conan did, and after they go in it, they find bloodstain while they exploring downwards."
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
  status->scene = 10;
  //s10
  cout << "While Amy and Anita are investigating in a room, Mitch finds Conan's glasses not far from the door of the room.";
  cout << "At this time, the entrance of the tower that had caught fire in the distance heard the sound of heavy doors opening." << endl;
  cout << "At the same time, Anita finds a newspaper report of a fire four years ago, which said that fifteen people had died in the fire,";
  cout << "the fire had violently burned everyone to ashes, and the identification of the remains could only be determined by the item they carried,";;
  cout << "and only one of them was missing. (He must have swapped himself with someone through the fire)" << endl;
  cout << "When Amy and Anita come out, Mitch have already disappeared. So Anita decided to enter the tower first to find Mitch,";
  cout << "and tells Amy to run away if she does not come out within three hundred seconds." << endl;
  cout << "Amy is eager to find her friends, so she does not run away after counting to 300 seconds, and also entered the tower." << endl;
  status->sence = 11;
  //s11
  cout << "Inside the tower, Amy mistakenly enters a toilet and locks the door.";
  cout << "At this time, there was a frequent knock on the door,";
  cout << "and the door that is tried to be violently opened let her know that it was not her companion outside the door.";
  cout << "Fortunately, Anita, who is hiding inside a secret door, appears in time and saves Amy before the mysterious person open the door, and they are not been discovered." << endl;
  status->scene = 12;
  //s12
  cout << "Anita and Amy climb down a ladder to an underground passage and find a skeleton with some years of age.";
  cout << "Judging from the dust that has accumulated above, it haven't been here for long,";
  cout << "and it seemed that it was this person who had carved the words on the stairs before.";
  cout << "This was most likely discovered by Conan before being moved to this place by the Mysterious person." << endl;
  cout << "The skeleton's foot bones looks thinner than the rest of the body, and the teeth are lost, and judging by the length of the hair, it should be a woman.";
  cout << "The person who changed the identity of the skeleton may be the murderer." << endl;
  cout << "At this time, the Eldest Lady appears and asks with concern where the other friend(Mitch) who was with them,";
  cout << "and when Amy is still trying to take the Eldest Lady to hide from the mysterious person,";
  cout << "the Anita grabs Amy's hand and starts to flee, explaining that from all aspects of the skeleton,";
  cout << "this is probably the body of the Eldest Lady,";
  cout << "and the people who had just killed the Eldest Lady and groomed into the appearance of the Eldest Lady." << endl;
  cout << "When the fake Eldest Lady(the Fake) encountered the details, the Fake pretended to have a bad memory,";
  cout << "the Fake was the one who set fire to the murderer that day, and finally found that there was no way to deceive the Eldest Lady's daughter before setting fire to kill.";
  cout << "And It is not impossible to know this underground passage and come back after setting fire to kill people." << endl;
  status->scene = 13;
  //s13
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

  cout << "Nishikawa is about to escape, but Conan claims to have found the treasure of the castle, which makes Nishikawa shock." << endl;
  cout << "The Western chessboard is arranged from the numbers one to eight and the letters A to H, so the correct direction to watch the chessboard from the knight.";
  cout << "From this direction, reading the white pieces in order is \"EGG HEAD\".";
  cout << "Referring to the intellectuals who can only say some perverse reasoning,";
  cout << "the answer is owner of the chessboard. Then only rotates the painting of the great master in counterclockwise direction, the entrance to the secret passage will appear." << endl;
  status->scene = 14;
  //s14
  cout << "After entering the secret passage and climbing up to reach the top of the tower,";
  cout << "Nishikawa excitedly opens the door where light comes out of the crack of the door,";
  cout << "and she is greeted by the castle's best view and the most beautiful viewing position." << endl;
  cout << "While Nishikawa is still finding the treasure, Conan prompts Nishikawa to see a message on the door:" << endl;
  cout << "-----\"I would like to give this castle and this scene to the first person who find it.\"-----" << endl;
  cout << "Nishikawa is distraught and unable to accept the facts, and an hour later the police arrest the woman who has truly become an eldest lady." << endl;
  status->scene = 0;
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
