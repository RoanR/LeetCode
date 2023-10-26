#include <vector>
using namespace std; 

class StockSpanner {
public:
    vector<int> prevPrices;
    vector<int> span;
    StockSpanner() {
        this->prevPrices = {};
        this->span = {};
    }
    
    int next(int price) {
        this->prevPrices.push_back(price);
        int total = 1;
        for (int i = this->prevPrices.size()-2; i >= 0; i--){
            if (this->prevPrices[i] > price){
                break; 
            } else if (this->prevPrices[i] == price){
                total += this->span[i];
                break;
            } else {
                total += this->span[i];
                i = i - (this->span[i]-1);
            }   
        }
        this->span.push_back(total);
        return total;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */