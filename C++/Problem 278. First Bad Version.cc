#include <iostream>
class Solution {
public:
    int firstBadVersion(int n) {
        int current = n/2;
        int base = 1;
        while (current != 0){
            if (isBadVersion(base + current)){
                base += 0;
                std::cout << (base + current);
                std::cout << ' is bad' << std::endl;
                current = current/2;
            } else {
                base += current;
                std::cout << (base + current);
                std::cout << ' is not bad' << std::endl;
                current += (current/2) + 1;
            }
        }
        return base; 
    }
};