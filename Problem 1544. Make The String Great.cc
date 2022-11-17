#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    string makeGood(string s) {
        cout << "testing " << s << endl;
        bool changes = true; 
        string::iterator it = s.begin();
        while(changes == true){
            changes = false; 
            for (int i =0; i<s.size()-1; i++){
                if ((s[i] != s[i+1]) && (toupper(s[i]) == toupper(s[i+1]))){
                    changes = true;
                    cout << "removing " << s[i] << " and " << s[i+1];
                    s.erase(i, 2);
                    cout << ", result: " << s << endl;
                    if (s == "") { 
                        return s;
                    }
                }
            }
        }
        return s;
    }
};