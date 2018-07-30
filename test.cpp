#include "board.hpp"
#include <iostream>

int main()
{
    
    Board board;
    board.loadMap();
    //board.printMap();
    
    board.initializeMap();
 
    BFS bfs;
    std::list<Coordinate *> path = bfs.solve(board);
 
    int x,y;

    for (std::list<Coordinate *>::iterator i = path.begin(), j =--path.end(); i != j; ++i)
    {
        //std::cout << (*i)->getX() <<" , " << (*i)->getY() <<  std::endl;
        x=(*i)->getX();
        y=(*i)->getY();
    }
    
    if(path.empty() || board.calculateDistance() < 5)
    {
      
            int direction;
    if(board.isWall(board.getEntry()->getX()+1, board.getEntry()->getY())==false)
        direction=3;
    else
    {
        if(board.isWall(board.getEntry()->getX()-1, board.getEntry()->getY())==false)
            direction=1;
        else if(board.isWall(board.getEntry()->getX(), board.getEntry()->getY()-1)==false)
            direction=4;
        else
            direction=2;
    }

        std::cout << direction << '\0';
    }

  
 

    if((board.getEntry()->getX() - x == 0) && (board.getEntry()->getY() - y == -1) )
        std::cout << "2\0";
    if((board.getEntry()->getX() - x == -1) && (board.getEntry()->getY() - y == 0) )
        std::cout << "3\0";
    if((board.getEntry()->getX() - x == 1) && (board.getEntry()->getY() - y == 0) )
        std::cout << "1\0";
    if((board.getEntry()->getX() - x == 0) && (board.getEntry()->getY() - y == 1) )
        std::cout << "4\0";


//     Board board;
//     board.readMap();
//     //bot.printMap();
//     board.setRowCol();
//     board.set2PlayerRowCol();
//    // board.printMap();
//     board.move();
    
    // Board board;
    // board.loadMap();
    // board.printMap();
    // BFS bfs;
    // bfs.solve(board);
    
}
