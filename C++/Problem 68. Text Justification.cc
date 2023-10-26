class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer;

        //Inital Vars
        int numSpaces = 0; 
        int remaining = maxWidth - words[0].length();
        string current = words[0]; //current line
        queue<string> toAdd; //Words to add to current line when spaces are realised

        for (int i=1; i<words.size(); i++){
            if (words[i].length()+1 <= remaining){
                toAdd.push(words[i]);
                remaining -= (words[i].length()+1);
                numSpaces += 1;
            } else {
                if (numSpaces > 0) { //calculating how to divide remaining space
                    int whole = (remaining / numSpaces) + 1; //base num of spaces to add
                    int extra = remaining % numSpaces; //extra spaces to add to left side
                    while(toAdd.empty() == false){ // add words one at a time
                        for (int i = 0; i < whole; i++){ //pad with spaces
                            current += " ";}
                        if (extra > 0) { //if spaces dont divide evenly pad left extra
                            current += " ";
                            extra--;}
                        current+=toAdd.front();
                        toAdd.pop();
                    }
                } else { //incase of single word lines
                    while(current.size()<maxWidth){
                        current+=" ";
                    }
                }
                answer.push_back(current);

                //Resetting initial vars
                current = words[i];
                remaining = maxWidth - words[i].length();
                numSpaces = 0;
            }
        }
        while(toAdd.empty() == false){
            current+=" ";
            current+=toAdd.front();
            toAdd.pop();
        }
        while(current.size()<maxWidth){
            current+=" ";
        }
        answer.push_back(current);
        return answer;
    }
};
Console
