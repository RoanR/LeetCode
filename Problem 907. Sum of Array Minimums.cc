#include <vector>
#include <stack>
using namespace std; 
class Solution {
    class Pair{
        public:
            int val; 
            int count; 
            Pair(const int& val, const int& count): val(val), count(count) { }
    };
    public:
        int sumSubarrayMins(vector<int>& arr) {
            stack<Pair> left;
            stack<Pair> right;
            vector<int> leftArr(arr.size());
            vector<int> rightArr(arr.size());
            int total = 0; 

            for(int i = 0; i < arr.size(); i++){
                int count = 1;
                while (!left.empty() && arr[i] < left.top().val){
                    count += left.top().count;
                    left.pop();
                }
                Pair temp(arr[i], count);
                left.push(temp);
                leftArr[i] = count;
            }

            for(int i = arr.size()-1; i >=0 ; i--){
                int count = 1;
                while(!right.empty() && arr[i] <= right.top().val){
                    count += right.top().count;
                    right.pop();
                }
                right.push(Pair(arr[i], count));
                rightArr[i] = count;
            }

            for(int i = 0; i < arr.size(); i++){
                //cout << "( " << arr[i] <<"*"<<leftArr[i]<<"*"<<rightArr[i]<<" )"<<endl;
                long long unsigned int temp = (arr[i] * leftArr[i]);
                temp = (temp * rightArr[i])%1000000007;
                temp = temp%1000000007;
                total += temp;
                total = total%1000000007;
            }
            return total;
        }
};