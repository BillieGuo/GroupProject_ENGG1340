# GroupProject_ENGG1340

### Group Member
Bao Guo(3035952458), Yucheng Guo(3035952707).

### Game description
You are going to play a role from the famous animation "名探偵コナン"（Detective Conan: The Old Blue Castle Investigation Case）. Conan(柯南), his friends and Dr Hiroshi Agasa（阿笠博士） were going to camping. They accitentally found an old castle on there way finding a night place. However there are more secrets and danger hiding in that castle...

### Game rules
Walk and Explore in the game. Finding clues to sovle the puzzle. You can talk to npcs to gain information. Discover the treasure left by the original owner of the castle.

Most of the interactions use a number of character only, but some need to enter words or a series of characters.
All you need to do is to go through the plot and find the implicit informatino to deduce the answers. Most of the questions are simple except for the last which requires some thinking.

### Game content
1: There will be 17 scenes, which are adapted from the animation, for the whole game. Scenes will be store in multiple files and vector are used for storing details of   sences and the information player have in game.

2：Character(yourself) will have an information storage. When the player want to save the game, a "save.txt" file will be created with details of which sences the character currently at and the information you have gathered. information will be stored using vector and struct and for sences will be an integer.

3: There will be two Random games

4:Dynamic memory is used for storing the player's status and for initialization of the game.

### Library list
  <iostream>
  <fstream> for file I/O
  <vector> for information storage
  <string> for interactions and storage
  <cstdlib> for random game
  <ctime> for random seed

### All source files
  Makefile
  game.cpp
  Scene1to5.cpp
  Scene6to10.cpp
  Scene11to14.cpp
  Scene15to17.cpp
  Scene1to5.h
  Scene6to10.h
  Scene11to14.h
  Scene15to17.h

### Compilation and execution instructions
  1. Download all the file into one directory
  2. Open ternimal at that directory
  3. Use command "Make game" to complie
  4. Use command "./game" to run game
  5. Use command "make clean" if you want to clean all *.o files
  
### Sample input/output file
    save.txt
    (cat save.txt (example))
    ===============
    2
    ChessBoard
    -----
    ChessBoard
    Passport
    ===============
    
    2 is scene
    ChessBoard above "-----" is clue
    below "-----" are achievements
    
    
