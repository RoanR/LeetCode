include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char save;
        for (int i = 0; i<s.size()/2; i++){
            save = s[i];
            s[i] = s[(s.size()-1-i)];
            s[(s.size()-1-i)] = save;
        }
    }
};
