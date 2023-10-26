using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int start = 0;
        int end = 31;
        while(start < end){
            int start_bit = (n >> start) & 1U;
            int end_bit = (n >> end) & 1U;
            n ^= (-end_bit ^ n) & (1UL << start);
            n ^= (-start_bit ^ n) & (1UL << end);
            start++;
            end--;
        }
        return n;
    }
};