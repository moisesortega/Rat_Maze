#include <fstream>
#include <iostream>
using namespace std;

const int SIZEx = 8;
const int SIZEy =10;
typedef char Mazes[SIZEx][SIZEy];

struct Labs

{
       Mazes maze;
};

void readIn(Mazes maze);
void printMaze(Mazes maze);
bool outOfBounds(int x, int y);
bool exit(Labs lab, int x, int y);

int main()
{
       Mazes startingMaze = {     '.', '#', '#', '#', '#', '#', '.', '#', '.', '#',

                                                '.', '#', '.', '.', '.', '#', '.', '.', '.', '#',

                                                '.', '.', '.', '#', '.', '#', '.', '#', '.', '#',

                                                '.', '#', '.', '#', '.', '.', '.', '#', '.', '#',

                                                '#', '.', '.', '#', '.', '#', '.', '.', '.', '#',

                                                '#', '.', '#', '#', '.', '.', '.', '#', '#', '#',

                                                '#', '.', '#', '.', '.', '#', '.', '.', '.', '#',

                                                '#', '#', '#', '#', '#', '#', '#', '#', '.', 'X'};

       Labs lab;
       for(int x = 0; x <SIZEx; x++)
              {

                     for(int y = 0; y < SIZEy; y++)
                           lab.maze[x][y] = startingMaze[x][y];

              }
              printMaze(lab.maze);
              if (exit(lab, 0, 0))
                     cout << "The rat found the exit";
              else
                     cout << "No path found.";
              return 0;

}

void readIn(Mazes maze)
{
       ifstream fin;
       fin.open("ratmaze.txt");
              for( int x = 0; x < SIZEx; x++)
              {
                     for(int y = 0; y < SIZEy; y++)

                           fin >> maze [x][y];
              fin.close();
              }
}

void printMaze(Mazes maze)
{
              for(int x = 0; x < SIZEx; x++)
              {
                     for(int y = 0; y < SIZEy; y++)
                           cout << maze[x][y] << ' ';
                     cout << endl;
              }
}// End of printMaze

bool outOfBounds(int x, int y)
{
       return (x < 0 || y < 0 || x >= SIZEx || y >= SIZEy);
}

bool exit (Labs lab, int x, int y)
{
       ofstream fout;
       fout.open("ratmaze2.txt");

       if(outOfBounds(x, y))
       {
              fout << "# ";
              return false;
       }
       else if(lab.maze[x][y]== 'X')
       {
              fout << "X ";
              cout << endl;
              cout << "The rat found the exit.";
              cout << endl;
              printMaze (lab.maze);

              return true;
       }
       else if(lab.maze[x][y]!= '.')
              {
              fout << ". ";

              return false;
              }
       else
       {
              lab.maze [x][y]='@';

               return(exit(lab, x, y+1)||
                           exit(lab, x, y-1)||
                           exit(lab, x+1, y)||
                           exit(lab, x-1, y));

                      fout << "@ ";
       }
       fout.close();
}
