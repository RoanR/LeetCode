#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer{};
        for(int i = numbers.size() -1; i>0; i--){
            for(int x=0;x<numbers.size(); x++){
                if ((numbers[i] + numbers[x])>target){
                    break;
                } else if((numbers[i] + numbers[x])==target){
                    answer.push_back(x + 1);
                    answer.push_back(i + 1);
                    return answer;
                }
            }
        }
        return answer;
    }
};
