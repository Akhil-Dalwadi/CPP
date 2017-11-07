#include "Maze.h"
#include "MazeBuilder.h"
#include "MazeGame.h"

#include <iostream>

Maze* MazeGame::CreateMaze() {

    std::cout << "MazeGame::CreateMaze()" << std::endl;

    Maze* aMaze = MakeMaze();

    Room* r1 = MakeRoom(1);
    Room* r2 = MakeRoom(2);
    Door* theDoor = MakeDoor(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, MakeWall());
    r1->SetSide(East, theDoor);
    r1->SetSide(South, MakeWall());
    r1->SetSide(West, MakeWall());

    r2->SetSide(North, MakeWall());
    r2->SetSide(East, MakeWall());
    r2->SetSide(South, MakeWall());
    r2->SetSide(West, theDoor);

    return aMaze;
}

Maze* MazeGame::CreateMaze(MazeBuilder& builder) {

    std::cout << "MazeGame::CreateMaze(MazeBuilder&)" << std::endl;

    builder.BuildMaze();

    builder.BuildRoom(1);
    builder.BuildRoom(2);
    builder.BuildDoor(1, 2);

    return builder.GetMaze();
}


Maze* MazeGame::CreateComplexMaze(MazeBuilder& builder) {

    std::cout << "MazeGame::CreateComplexMaze(MazeBuilder&)" << std::endl;

    builder.BuildRoom(1);
    // ...
    builder.BuildRoom(1001);

    return builder.GetMaze();
}
