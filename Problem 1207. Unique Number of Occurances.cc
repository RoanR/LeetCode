#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurrences;
        for (int n = 0; n < arr.size(); n ++){
            occurrences[arr[n]]++;
        }
        vector<int> check(arr.size() + 1, 0);
        for (auto& itr : occurrences){
            if (check[itr.second] == 1){
                return false;
            } else {
                check[itr.second] = 1;
            }
        }
        return true; 
    }
};