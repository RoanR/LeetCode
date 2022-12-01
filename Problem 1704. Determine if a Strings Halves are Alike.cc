#include <string>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size()/2;
        int count = 0; 

        for (int i = 0; i < n; i++){
            char f = s[i];
            char b  = s[n+i];

            f = tolower(f);
            b  = tolower(b); 

            if (f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u'){
                count ++; }
            if (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u'){
                count --; }
        }
        return count == 0;
    }
};