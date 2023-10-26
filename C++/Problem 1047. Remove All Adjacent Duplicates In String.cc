#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        cout << s << endl;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == s[i-1]){
                s.erase(i-1,2);
                i = i-2;
                if (i < 0){
                    i = 0;
                }
            }
        }
        return s;
    }
};