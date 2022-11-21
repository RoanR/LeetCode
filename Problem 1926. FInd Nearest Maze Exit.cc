#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int COLS = maze[0].size();
        const int ROWS = maze.size();
        
        entrance.push_back(0);
        queue<vector<int>> tocheck;
        tocheck.push(entrance);
        maze[entrance[0]][entrance[1]] = '+';


        while(tocheck.size() > 0){

            vector<int> current = tocheck.front();
            tocheck.pop();
            int level = current[2];
            int x = current[1];
            int y = current[0];
            cout << "Checking ...(" << x <<","<< y<<")\n";
            if ((x != entrance[1]) || (y != entrance[0])){
                if ((x == COLS -1)||(y == ROWS -1)) {return level;}
                if ((x== 0)||(y == 0)) {return level;}
            }

            cout<<"pass_0\n";
            queueUpdate(maze, tocheck, (x-1), y, (level+1), COLS, ROWS);
            cout<<"pass_1\n";
            queueUpdate(maze, tocheck, (x+1), y, (level+1), COLS, ROWS);
            cout<<"pass_2\n";
            queueUpdate(maze, tocheck, x, (y-1), (level+1), COLS, ROWS);
            cout<<"pass_3\n";
            queueUpdate(maze, tocheck, x, (y+1), (level+1), COLS, ROWS);
            cout<<"pass_4\n";

        }
        return -1;
    }

    void queueUpdate(vector<vector<char>>& maze,queue<vector<int>>& tocheck,int x,int y,int level,int COLS, int ROWS){
        if ((-1 < x < COLS) && (-1 < y < ROWS)){
            if(maze[y][x] == '.') {
                tocheck.push({y, x, level});
                maze[y][x] = '+';
                cout << "Pushing ...(" << x <<","<< y<<")\n";
            }
        }
    }
    
};