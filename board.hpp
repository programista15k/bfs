#ifndef BOARD_HPP
#define BOARD_HPP
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <list>
#include <array>

// std::array<int, 2> RIGHT = {0, 1};
// std::array<int, 2> UP = {1, 0};
// std::array<int, 2> LEFT = {0, -1};
// std::array<int, 2> DOWN = {-1, 0};
// std::array<std::array<int, 2>, 4> DIRECTIONS = { RIGHT, UP, LEFT, DOWN };


 
struct Coordinate
{


    int m_x;
    int m_y;
    Coordinate * m_parent;
 
    Coordinate(int x, int y);
    Coordinate(int x, int y, Coordinate * coordinate);
    int getX();
    int getY();
    Coordinate * getParent();
};
 
class Board
{
public:
    Board();
    ~Board();
 
    void loadMap();
    void printMap();
    void initializeMap();
    int getHeight();
    int getWidth();
    int calculateDistance();
    Coordinate * getEntry();
    Coordinate * getExit();
    bool isExit(int x, int y);
    bool isStart(int x, int y);
    bool isExplored(int row, int col);
    bool isWall(int row, int col);
    void setVisited(int row, int col, bool value);
    bool isValidLocation(int row, int col);
    void printPath(std::list<Coordinate *> path);
 
 
private:
    std::vector<std::string> m_map;
    std::vector<std::vector<bool>> m_visited;
    Coordinate * m_player1_position;
    Coordinate * m_player2_position;
 
};
 
struct BFS
{
  static int const DIRECTIONS[4][2];
    std::list<Coordinate *> solve(Board & board);
 
private:
    std::list<Coordinate *> backtrackPath(Coordinate * cur);
};


// class Board;

// struct Coordinate
// {
//     int m_x;
//     int m_y;
//     Coordinate * m_parent;

//     Coordinate(int row, int col, Coordinate * coord) : m_x(row), m_y(col), m_parent(nullptr) {}
// };

// class BFS
// {

//   public:
//     static int const DIRECTIONS[4][2];
//     std::list<Coordinate*> solve(Board &board);

//   private:
//     std::list<Coordinate*> backtrackPath(Coordinate * cur);
// };

// class Board
// {
//   public:
//     Board();
//     ~Board();
//     void loadMap();
//     void printMap();
//     void setPlayer1Position();
//     void setPlayer2Position(); 
//     bool isWall(int row, int col);
//     bool isVisited(int row, int col);
//     bool isValidLocation(int row, int col);
//     bool isFound(int row, int col);
//     bool setVisited(int row, int col, bool boolean);
//     int getPlayer1Row();
//     int getPlayer2Row();
//     int getPlayer1Col();
//     int getPlayer2Col();

    
//   private:
//     std::vector<std::string> m_map;
//     std::vector<std::vector<bool>> m_visited;
//     int m_player1_position_row;
//     int m_player1_position_col;
//     int m_player2_position_row;
//     int m_player2_position_col;

// };



// class Board
// {
// public:
//   Board();
//   ~Board();
//   void readMap();
//   void printMap();
//   void setRowCol();
//   void set2PlayerRowCol();
//   bool isWall(unsigned int row, unsigned int col);
//   void move();
//   unsigned int distance(unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2);
//   std::vector<unsigned int> possibleMoves(unsigned int row1, unsigned int col1);
//   std::vector<unsigned int> possibleMoves();
//   std::vector<std::string> getm_map();
//   unsigned int getm_row();
//   unsigned int getm_col();
//   unsigned int get_2player_row();
//   unsigned int get_2player_col();
//   int BFS(unsigned int passed_row, unsigned int passed_col);
//   int BFS();
//   bool isValid(unsigned int row, unsigned int col);

// private:
//   std::vector<std::string> m_map;
//   std::vector<unsigned int> _possibleMoves;
//   unsigned int m_row; ///< rows
//   unsigned int m_col; ///< columns
//   //std::pair <int,int> _position;
//   unsigned int direction;
//   unsigned int _2player_row;
//   unsigned int _2player_col;

//   struct Point
//   {
//     unsigned int x;
//     unsigned int y;
//   };

//   struct queueNode
//   {
//     Point pt; 
//     unsigned int dist; 
//   };
// };

#endif