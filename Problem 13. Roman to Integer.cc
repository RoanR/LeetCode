using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        for (int i = 0; i < s.size(); i++){
            int current = charToInt(s[i]);
            int next = charToInt(s[i]);

            if (i + 1 < s.size()){
                next = charToInt(s[i+1]);
            }

            if (current < next){
                current = -current;
            } 
            total += current;
        }
        return total;
    }

    int charToInt(char c) {
       switch(c){
            case 'I': return 1; break;
            case 'V': return 5; break;
            case 'X': return 10; break;
            case 'L': return 50; break;
            case 'C': return 100; break; 
            case 'D': return 500; break;
            case 'M': return 1000; break;
       }
       return 0; 
    }
};