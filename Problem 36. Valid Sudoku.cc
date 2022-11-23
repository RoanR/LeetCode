#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i<9; i++){
            if (!isValidSection(board[i])){
                return false;
            }
        }

        for (int i = 0; i<9; i++){
            vector<char> column;
            for (int j = 0; j<9; j++){
                column.push_back(board[j][i]);
            }
            if (!isValidSection(column)){
                return false;
            }
        }

        for (int i = 0; i<9; i+=3){
            for (int j = 0; j<9; j+=3){
                vector<char> block;
                for (int x=0; x<3; x++){
                    for (int y=0; y<3; y++){
                        block.push_back(board[i+x][j+y]);
                    }
                }
                if (!isValidSection(block)){
                    return false;
                }
            }
        }
        return true;
    }

    
    bool isValidSection(vector<char> tiles){
        vector<int> temp = {0,0,0,0,0,0,0,0,0};
        
        for (int i=0; i<tiles.size(); i++){
            int current = tiles[i];
            if (current != 46){
                current = current - 49;
                if (temp[current] != 0){
                    return false;
                } else {
                    temp[current] = 1;
                }
            }
        }
        return true;
    }
};