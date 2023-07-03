class Solution {
public:
    bool samechars(string a, string b){
        //Check if they have the same numbers of each letter
        map<char, int> occur1;
        map<char, int> occur2;
        
        for (int i=0; i<a.length(); i++) {
            occur1[a[i]]++;
            occur2[b[i]]++;
        }
            
        if(occur1 == occur2)
            return true;
        else
            return false;
    }

    bool ordered(string a){
        map<char, int> occur;
        //check that the string contains two of the same letter
        for (int i=0; i<a.length(); i++){
            if (occur[a[i]]>0)
                return true;
            occur[a[i]]++;
        } 

        return false;
    }

    bool swapable(string a, string b){
        int toSwap = 0;
        //Check how many letters need to be swapped to make same
        for (int i=0; i<a.length(); i++){
            if (a[i] != b[i])
                toSwap++;
        }
        //If its two then is possible
        if (toSwap==2)
            return true;
            
        return false;
    }

    bool buddyStrings(string s, string goal) {

        //Check length is the same
        if (s.length() != goal.length())
            return false;

        //Check same characters
        if (!samechars(s, goal))
            return false;

        //Check if sorted
        if (s == goal){
            //If sorted needs a double letter to swap
            if (ordered(s))
                return true;
            else
                return false;
        }

        if (swapable(s, goal))
            return true;

        return false; 
    }
};
