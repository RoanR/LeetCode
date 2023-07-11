class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int total = max(word1.size(), word2.size());
        string out = "";
        for (int i = 0; i < total; i++){
            if (i >= word2.size()){
                out.push_back(word1[i]);
                continue;
            }
            if (i >= word1.size()){
                out.push_back(word2[i]);
                continue;
            }
            out.push_back(word1[i]);
            out.push_back(word2[i]);
        }
        return out;
    }
};
