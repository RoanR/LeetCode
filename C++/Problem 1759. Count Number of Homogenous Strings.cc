#include <string>
using namespace std;

class Solution {
public:
	int countHomogenous(string s) 
	{
		char currLetter = ' ';
		long long currTotal = 0;
		long long total = 0;
		for (int i = 0; i <= s.length(); i++) {
			if ((s[i] != currLetter) || (i+1 > s.length())) {
				currTotal = (currTotal*(currTotal+1)/2);
				total += currTotal;
				currTotal = 1; 
				currLetter = s[i];
			} else {
				currTotal += 1;
			}
		}
		return (int) (total % (1000000007));
	}
};