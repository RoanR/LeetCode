class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> penalty(customers.length()+1, 0);
        int N = 0; //running total for N penalty 
        int Y = 0; //running total for Y penalty 
        for (int i = 1; i <= customers.length(); i++){
            if (customers[i-1] == 'N') N++;
            if (customers[customers.length()-i] == 'Y') Y++;
            penalty[i] += N;
            penalty[customers.length()-i] += Y;
        }

        //Find Index of first Minimum value
        N = Y; Y = 0;
        for (int i = 0; i < penalty.size(); i++){
            if (penalty[i]<N){
                Y = i;
                N = penalty[i];
            }
        }
        return Y;
    }
};
