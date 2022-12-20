#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> bfs;
        unordered_set<int> key_set;

        bfs.push(0);
        key_set.insert(0);

        while (!bfs.empty()){
            vector<int> keys = rooms[bfs.front()];
            bfs.pop();
            

            for (int i = 0; i < keys.size(); i++){
                int current = keys[i];
                if (key_set.find(current) == key_set.end()){
                    key_set.insert(current);
                    bfs.emplace(current);
                }
            }
        }

        for (int i = 0; i < rooms.size(); i++){
            if (key_set.find(i) == key_set.end()){
                return false; 
            }
        }
        return true;
    }
};