class Solution {
public:
    //Sort vectors based on second elements
    bool static compareVector(vector<int> v1, vector<int> v2){
        return (v1[1] < v2[1]);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        //Sort Vector based on pairs second element
        sort(pairs.begin(), pairs.end(), compareVector);

        //Greedy search for chain length
        int length = 1;
        int last = pairs[0][1];
        for (auto x : pairs)
            if (x[0]>last){
                length++;
                last=x[1];
            }

        return length;
    }
};
