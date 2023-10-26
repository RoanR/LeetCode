#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        string s = word;
        int last = 0;
        int first = 0;
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                if (board[i][j] == s.at(s.length()-1)){
                    last += 1;
                } else if (board[i][j] == s.at(0)){
                    first += 1;
                }
            
            }
        }
        if (last < first){
            reverse(word.begin(), word.end());
        }
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                if (board[i][j] == word.at(0)){
                    int progress = 1; 
                    vector<vector<char>> temp = board;
                    temp[i][j] = '*';
                    if(check(temp, word, i, j, progress)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, string word, int a, int b, int progress){
        if (progress == word.length()){
            return true;
        }

        for (int i=-1; i<2; i++){
            if (i+a<0){i++;}
            if ((i+a<board.size()) && (board[i+a][b] == word.at(progress))){
                int next = progress+1; 
                vector<vector<char>> temp = board;
                temp[i+a][b] = '*';
                if(check(temp, word, i+a, b, next)){
                    return true;
                }
            }
        }
        for (int j=-1; j<2; j++){
            if (j+b<0){j++;}
            if ((j+b<board[0].size()) && (board[a][b+j] == word.at(progress))){
                int next = progress+1; 
                vector<vector<char>> temp = board;
                temp[a][j+b] = '*';
                if(check(temp, word, a, j+b, next)){
                    return true;
                }
            }
        }
        return false;
    }

};