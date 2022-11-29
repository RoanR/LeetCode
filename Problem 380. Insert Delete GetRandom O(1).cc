#include <algorithm>
#include <unordered_set>

using namespace std;

class RandomizedSet {
private:
    int length;
    unordered_set<int> items;
public:
    RandomizedSet() {
        length = 0;
    }
    
    bool insert(int val) {
        if (items.find(val) == items.end()){
            items.insert(val);
            length += 1;
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        
        if (items.find(val) == items.end()){
            return false;
        } else {
            items.erase(val);
            length = length -1;
            return true;
        }
    }
    
    int getRandom() {
        unordered_set<int> :: iterator itr;
        itr = items.begin();
        int random = rand() % length;
        advance(itr, random);
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */