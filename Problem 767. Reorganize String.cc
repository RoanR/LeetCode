#include <string>
#include <iostream>       
#include <queue>          
#include <vector>  
using namespace std;

class Solution {
public:

    struct letter {
        int freq;
        char character; 
    };

    class comparison {
    public:
        bool operator() (const letter& a, const letter& b) const {
            return (a.freq <= b.freq);}
    };

    string reorganizeString(string s) {
        //Counting up inital occurances of Letters
        unordered_map<char, int> initial_map;
        for (int i = 0; i < s.size(); i++){
            initial_map[s[i]]++;
        }

        //Declaring the custom priority queue
        typedef priority_queue<letter, vector<letter>, comparison> pq_type;
        pq_type letters;

        //Populating custom proirity queue
        unordered_map<char, int>:: iterator p;
        for (p = initial_map.begin(); p != initial_map.end(); p++){
            if (p->second > ((s.size()+1)/2))
                return "";
            struct letter let;
            let.freq = p->second;
            let.character= p->first;
            letters.push(let);
        }

        string answer = "";
        letter last_letter;
        while (!letters.empty()){
            //remove top letter
            struct letter l1 = letters.top();
            letters.pop();

            //check if it was just added
            if (l1.character == last_letter.character){ 
                last_letter = letters.top();
                letters.pop();
                letters.push(l1); 
            } else {
                last_letter = l1;
            }
            
            answer += last_letter.character;
            last_letter.freq--;
            if (last_letter.freq > 0)
                letters.push(last_letter);  
        }
        return answer;
    }
};
