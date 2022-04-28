Scene1to5.o: Scene1to5.cpp Scene1to5.h
	g++ -c Scene1to5.cpp
Scene6to10.o: Scene6to10.cpp Scene6to10.h
	g++ -c Scene6to10.cpp
Scene11to14.o: Scene11to14.cpp Scene11to14.h
	g++ -c Scene11to14.cpp
game.o: game.cpp Scene1to5.h Scene6to10.h Scene11to14.h
	g++ -c game.cpp
game: game.o Scene1to5.o Scene6to10.o Scene11to14.o
	g++ game.o Scene1to5.o Scene6to10.o Scene11to14.o -o game
