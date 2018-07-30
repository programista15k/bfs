#include "board.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>
#include <list>
#include <bits/stdc++.h>

int const BFS::DIRECTIONS[4][2] =  { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

std::list<Coordinate *> BFS::backtrackPath(Coordinate * cur)
{
        std::list<Coordinate *> path;
 
        Coordinate * iter = cur;
 
        while (iter != nullptr)
        {
            path.push_back(iter);
            iter = iter->getParent();
        }
 
        return path;
}
 
std::list<Coordinate *> BFS::solve(Board & board)
{
 
    std::list<Coordinate *> nextToVisit;
 
    Coordinate * start = board.getEntry();
    nextToVisit.push_back(start);
 
    while (!nextToVisit.empty())
    {
        Coordinate * cur = nextToVisit.front();
        nextToVisit.pop_front();
            if (!board.isValidLocation(cur->getX(), cur->getY()) || board.isExplored(cur->getX(), cur->getY()))
            {
                continue;
            }
 
            if (board.isWall(cur->getX(), cur->getY())) {
                board.setVisited(cur->getX(), cur->getY(), true);
                continue;
            }
 
            if (board.isExit(cur->getX(), cur->getY())) {
                return backtrackPath(cur);
            }
 
            for (int i =0; i< 4; ++i)
            {
                Coordinate * coordinate = new Coordinate(cur->getX() + DIRECTIONS[i][0], cur->getY() + DIRECTIONS[i][1], cur);
                nextToVisit.push_back(coordinate);
                board.setVisited(cur->getX(), cur->getY(), true);
            }
 
    }
 
 
    return std::list<Coordinate *>();
}
 
Board::Board()
{  
    m_player1_position = nullptr;
    m_player2_position = nullptr;
}
 
Board::~Board()
{
    delete m_player1_position;
    delete m_player2_position;
}
 
void Board::loadMap()
{
    std::string line;
    //std::ifstream in("../maps/empty-room.txt");
   
    std::getline(std::cin, line);
 
    while (std::getline(std::cin, line))
    {
        m_map.push_back(line);
    }
}
 
void Board::printMap()
{
    for(int i = 0; i < m_map.size(); ++i)
        std::cout << m_map[i] << "\n";
}
 
void Board::initializeMap()
{
 
    for(int i = 0; i < getHeight(); ++i)
    {
        for(int j = 0; j < getWidth(); ++j)
        {
            if(m_map[i][j] == '1')
                m_player1_position = new Coordinate(i, j);
            if(m_map[i][j] == '2')
                m_player2_position = new Coordinate(i, j);
        }
    }
   
        for(int i = 0; i < m_map.size(); ++i)
    {
        std::vector<bool> temp;
        for(int j = 0; j < m_map[0].length(); ++j)
        {
           
            temp.push_back(false);
 
        }
        m_visited.push_back(temp);
    }
 
 
 
}
 
int Board::getHeight() { return m_map.size(); }
 
int Board::getWidth() { return m_map[0].length(); }

int Board::calculateDistance()
{
    return (abs(m_player1_position->getX() - m_player2_position->getX()) + abs(m_player1_position->getY() - m_player2_position->getY()));
}
 
Coordinate * Board::getEntry() { return m_player1_position; }
 
Coordinate * Board::getExit() { return m_player2_position; }
 
bool Board::isExit(int x, int y)
{
    return x == m_player2_position->getX() && y == m_player2_position->getY();
}
 
bool Board::isStart(int x, int y)
{
    return x == m_player1_position->getX() && y == m_player1_position->getY();
}
 
bool Board::isExplored(int row, int col)
{
    return m_visited[row][col];
}
 
bool Board::isWall(int row, int col)
{
    return m_map[row][col] == '#';
}
 
void Board::setVisited(int row, int col, bool value)
{
    m_visited[row][col] = value;
}
bool Board::isValidLocation(int row, int col)
{
        if (row < 0 || row >= getHeight() || col < 0 || col >= getWidth())
        {
            return false;
        }
        return true;
}
 
void Board::printPath(std::list<Coordinate *> path)
{
 
}
 
Coordinate::Coordinate(int x, int y) : m_x(x), m_y(y), m_parent(nullptr) {}
Coordinate::Coordinate(int x, int y, Coordinate * coordinate) : m_x(x), m_y(y), m_parent(coordinate) {}
int Coordinate::getX() { return m_x; }
int Coordinate::getY() { return m_y; }
Coordinate * Coordinate::getParent() { return m_parent; }








// int const BFS::DIRECTIONS[4][2] =  { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

// Board::Board()
// {

// }

// Board::~Board()
// {

// }


// void Board::loadMap()
// {
//     std::ifstream infile("../maps/empty-room.txt");

//     std::string line;

//     std::getline(infile, line);

//     while (std::getline(infile, line))
//     {
//         m_map.push_back(line);
//     }

//     setPlayer1Position();
//     setPlayer2Position();
// }

// void Board::printMap()
// {
//     for (auto const &m : m_map)
//         std::cout << m << std::endl;

//     std::cout << m_player1_position_row << ", " << m_player1_position_col << "\n";
//     std::cout << m_player2_position_row << ", " << m_player2_position_col << "\n";
// }

// void Board::setPlayer1Position()
// {
//     for (int i = 0; i < m_map.size(); i++)
//     {
//         for (int j = 0; j < m_map[i].length(); j++)
//         {
//             if (m_map[i].at(j) == '1')
//             {
//                 m_player1_position_row = i;
//                 m_player1_position_col = j;

//                 return;
//             }
//         }
//     }
// }

// void Board::setPlayer2Position()
// {
//     for (int i = 0; i < m_map.size(); i++)
//     {
//         for (int j = 0; j < m_map[i].length(); j++)
//         {
//             if (m_map[i].at(j) == '2')
//             {
//                 m_player2_position_row = i;
//                 m_player2_position_col = j;
//                 return;
//             }
//         }
//     }
// }


// bool Board::isWall(int row, int col)
// {
//     return (m_map[row].at(col) == '#' || m_map[row].at(col) == '2') ? true : false;
// }
    
// bool Board::isVisited(int row, int col)
// {
//     return m_visited[row][col];
// }

// bool Board::isValidLocation(int row, int col)
// {
//     if(row < 0 || row >= m_map.size() || col < 0 || col >= m_map[0].size())
//         return false;

//     return true;
// }

// bool Board::isFound(int row, int col)
// { 
//     return row == getPlayer2Row() && col == getPlayer2Col();
// }

// bool Board::setVisited(int row, int col, bool value)
// {
//     m_visited[row][col] = value;
// }

// int Board::getPlayer1Row(){ return m_player1_position_row; }
// int Board::getPlayer2Row(){ return m_player2_position_row; }
// int Board::getPlayer1Col(){ return m_player1_position_col; }
// int Board::getPlayer2Col(){ return m_player2_position_col; }

// std::list<Coordinate*> BFS::solve(Board &board)
// {
//     std::list<Coordinate*> nextToVisit; 
//     Coordinate * start = new Coordinate(board.getPlayer1Row(), board.getPlayer1Col(), nullptr);

//     while(!nextToVisit.empty())
//     {
//         Coordinate * cur = new Coordinate(nextToVisit.front()->m_x, nextToVisit.front()->m_y, nextToVisit.front()->m_parent);
//         nextToVisit.pop_front();

//         if(!board.isValidLocation(cur->m_x, cur->m_y) || board.isVisited(cur->m_x, cur->m_y))
//             continue;

//         if(board.isWall(cur->m_x, cur->m_y))
//         {
//             board.setVisited(cur->m_x, cur->m_y, true);
//             continue;
//         }

//         if(board.isFound(cur->m_x, cur->m_y))
//             return backtrackPath(cur);

//         for(auto direction : DIRECTIONS)
//         {
//             Coordinate * coordinate = new Coordinate(cur->m_x + direction[0], cur->m_y + direction[1], cur);
//             nextToVisit.push_front(coordinate);
  
//         }   
//     }


// //         while (!nextToVisit.isEmpty()) {
// //             Coordinate cur = nextToVisit.remove();

// //             if (!maze.isValidLocation(cur.getX(), cur.getY()) || maze.isExplored(cur.getX(), cur.getY())) {
// //                 continue;
// //             }

// //             if (maze.isWall(cur.getX(), cur.getY())) {
// //                 maze.setVisited(cur.getX(), cur.getY(), true);
// //                 continue;
// //             }

// //             if (maze.isExit(cur.getX(), cur.getY())) {
// //                 return backtrackPath(cur);
// //             }

// //             for (int[] direction : DIRECTIONS) {
// //                 Coordinate coordinate = new Coordinate(cur.getX() + direction[0], cur.getY() + direction[1], cur);
// //                 nextToVisit.add(coordinate);
// //                 maze.setVisited(cur.getX(), cur.getY(), true);
// //             }
// //         }
// // return Collections.emptyList();

//     return nextToVisit;
// }

// std::list<Coordinate *> BFS::backtrackPath(Coordinate *cur) {
//         std::list<Coordinate *> path; 
//         Coordinate * iter = cur;

//         while (iter != nullptr) {
//             path.push_back(iter);
//             iter = iter->m_parent;
//         }
        
//         return path;
// }

#pragma region r
// Board::Board()
// {
//     direction = 1;
// }

// Board::~Board()
// {
// }

// void Board::readMap()
// {

//     // std::ifstream infile("../maps/empty-room.txt");

//     std::string line;

//     std::getline(std::cin, line);

//     while (std::getline(std::cin, line))
//     {
//         m_map.push_back(line);
//     }
// }

// void Board::printMap()
// {
//     for (auto const &m : m_map)
//         std::cout << m << std::endl;

//     std::cout << m_row << "\t" << m_col << "\n";
//     std::cout << _2player_row << "\t" << _2player_col << "\n";
//     std::cout << distance(m_row, m_col, _2player_row, _2player_col);
// }

// void Board::setRowCol()
// {
//     for (int i = 0; i < m_map.size(); i++)
//     {
//         for (int j = 0; j < m_map[i].length(); j++)
//         {
//             if (m_map[i].at(j) == '1')
//             {
//                 m_row = i;
//                 m_col = j;

//                 return;
//             }
//         }
//     }
// }

// void Board::set2PlayerRowCol()
// {
//     for (int i = 0; i < m_map.size(); i++)
//     {
//         for (int j = 0; j < m_map[i].length(); j++)
//         {
//             if (m_map[i].at(j) == '2')
//             {
//                 _2player_row = i;
//                 _2player_col = j;

//                 return;
//             }
//         }
//     }
// }

// std::vector<unsigned int> Board::possibleMoves(unsigned int row1, unsigned int col1)
// {
//     std::vector<unsigned int> possibleMoves;

//     if (isWall(m_row - 1, m_col) == false)
//         possibleMoves.push_back(1);
//     if (isWall(m_row, m_col + 1) == false)
//         possibleMoves.push_back(2);
//     if (isWall(m_row + 1, m_col) == false)
//         possibleMoves.push_back(3);
//     if (isWall(m_row, m_col - 1) == false)
//         possibleMoves.push_back(4);

//     return possibleMoves;
// }

// std::vector<unsigned int> Board::possibleMoves()
// {
//     std::vector<unsigned int> possibleMoves;

//     if (isWall(m_row - 1, m_col) == false)
//         possibleMoves.push_back(1);
//     if (isWall(m_row, m_col + 1) == false)
//         possibleMoves.push_back(2);
//     if (isWall(m_row + 1, m_col) == false)
//         possibleMoves.push_back(3);
//     if (isWall(m_row, m_col - 1) == false)
//         possibleMoves.push_back(4);

//     return possibleMoves;
// }

// bool Board::isWall(unsigned int row, unsigned int col)
// {
//     return (m_map[row].at(col) == '#' || m_map[row].at(col) == '2') ? true : false;
// }

// unsigned int Board::distance(unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2)
// {
//     return (abs(row1 - row2) + abs(col1 - col2));
// }

// std::vector<std::string> Board::getm_map()
// {
//     return m_map;
// }

// void Board::move()
// {

//     //_possibleMoves=possibleMoves();

//     if (isWall(m_row - 1, m_col) == false)
//         _possibleMoves.push_back(BFS(m_row - 1, m_col));
//     else
//         _possibleMoves.push_back(INT_MAX);

//     if (isWall(m_row, m_col + 1) == false)
//         _possibleMoves.push_back(BFS(m_row, m_col + 1));
//     else
//         _possibleMoves.push_back(INT_MAX);

//     if (isWall(m_row + 1, m_col) == false)
//         _possibleMoves.push_back(BFS(m_row + 1, m_col));
//     else
//         _possibleMoves.push_back(INT_MAX);

//     if (isWall(m_row, m_col - 1) == false)
//         _possibleMoves.push_back(BFS(m_row, m_col - 1));
//     else
//         _possibleMoves.push_back(INT_MAX);

//     auto it = std::min_element(_possibleMoves.begin(), _possibleMoves.end());
//     auto min_val = std::distance(_possibleMoves.begin(), it) + 1;

//     direction = min_val;

//     int dist = distance(getm_row(), getm_col(), get_2player_row(), get_2player_col());

//     // if (dist <= 4)
//     // {
//     //              std::random_device rd;
//     // std::mt19937 eng(rd());

//     // _possibleMoves = possibleMoves();
//     // if(_possibleMoves.size()>0)
//     // {
//     // std::uniform_int_distribution<> distr(0, _possibleMoves.size()-1);
    
//     // int randomIndex = distr(eng);
//     // std::cout << _possibleMoves[randomIndex] << '\0';
//     // }
//     // }
// // if (std::adjacent_find(_possibleMoves.begin(), _possibleMoves.end(), std::not_equal_to<int>()) == _possibleMoves.end())
// // {
// //             std::random_device rd;
// //     std::mt19937 eng(rd());
// //     if(_possibleMoves.size()>0)
// //     {
// //     std::uniform_int_distribution<> distr(0, _possibleMoves.size()-1);

// //     int randomIndex = distr(eng);
// //     std::cout << _possibleMoves[randomIndex] << '\0';
// //    }
// //    else
// //    {

// //       // std::uniform_int_distribution<> distr(1, 4);

// //     if(isWall(m_row, m_col+1)==false)
// //         direction=2;
// //     else
// //     {
// //         if(isWall(m_row-1, m_col)==false)
// //             direction=1;
// //         else if(isWall(m_row, m_col-1)==false)
// //             direction=4;
// //         else
// //             direction=3;
// //     }

// //         std::cout << direction << '\0';
// //    }

// // if(isWall(m_row, m_col+1)==false)
// //     direction=2;
// // else
// // {
// //     if(isWall(m_row-1, m_col)==false)
// //         direction=1;
// //     else if(isWall(m_row, m_col-1)==false)
// //         direction=4;
// //     else
// //         direction=3;
// // }
// // }

// std::cout << direction << '\0';

// //     std::random_device rd;
// //     std::mt19937 eng(rd());
// //     if(_possibleMoves.size()>0)
// //     {
// //     std::uniform_int_distribution<> distr(0, _possibleMoves.size()-1);

// //     int randomIndex = distr(eng);
// //     std::cout << _possibleMoves[randomIndex] << '\0';
// //    }
// //    else
// //    {

// //       // std::uniform_int_distribution<> distr(1, 4);

// //            if(isWall(m_row, m_col+1)==false)
// //         direction=2;
// //     else
// //     {
// //         if(isWall(m_row-1, m_col)==false)
// //             direction=1;
// //         else if(isWall(m_row, m_col-1)==false)
// //             direction=4;
// //         else
// //             direction=3;
// //     }

// //         std::cout << direction << '\0';
// //    }

// // if(isWall(m_row, m_col+1)==false)
// //     direction=2;
// // else
// // {
// //     if(isWall(m_row-1, m_col)==false)
// //         direction=1;
// //     else if(isWall(m_row, m_col-1)==false)
// //         direction=4;
// //     else
// //         direction=3;
// // }
// }

// unsigned int Board::getm_row() { return m_row; }
// unsigned int Board::getm_col() { return m_col; }
// unsigned int Board::get_2player_row() { return _2player_row; }
// unsigned int Board::get_2player_col() { return _2player_col; }

// int Board::BFS(unsigned int passed_row, unsigned int passed_col)
// {
//     int rowNum[] = {-1, 0, 0, 1};
//     int colNum[] = {0, -1, 1, 0};
//     Point src = {passed_row, passed_col};
//     Point dest = {get_2player_row(), get_2player_col()};

//     if ((m_map[src.x].at(src.y) == '#' && m_map[src.x].at(src.y) == '2') || (!m_map[dest.x].at(dest.y) == '#'))
//         return INT_MAX;

//     bool visited[m_map.size()][m_map[0].length()];
//     memset(visited, false, sizeof visited);

//     visited[src.x][src.y] = true;

//     std::queue<queueNode> q;

//     queueNode s = {src, 0};
//     q.push(s);

//     while (!q.empty())
//     {
//         queueNode curr = q.front();
//         Point pt = curr.pt;

//         if (pt.x == dest.x && pt.y == dest.y)
//         {
//             return curr.dist;
//         }

//         q.pop();

//         for (unsigned int i = 0; i < 4; i++)
//         {
//             unsigned int row = pt.x + rowNum[i];
//             unsigned int col = pt.y + colNum[i];

//             if (isValid(row, col) && m_map[row].at(col) &&
//                 !visited[row][col])
//             {
//                 visited[row][col] = true;
//                 queueNode Adjcell = {{row, col},
//                                      curr.dist + 1};
//                 q.push(Adjcell);
//             }
//         }
//     }

//     return INT_MAX;
// }

// bool Board::isValid(unsigned int row, unsigned int col)
// {
//     return (row >= 0) && (row < m_map.size()) &&
//            (col >= 0) && (col < m_map[0].length());
// }

// int Board::BFS()
// {
// }

#pragma endregion r