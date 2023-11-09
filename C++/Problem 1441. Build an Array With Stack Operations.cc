#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) 
	{
		string push = "Push";
		string pop  = "Pop";

		/* To hold answer and state */
		vector<string> answer; 
		int current = 1; 

		/* Go through target array */
		for (auto i : target) {

			/* Increase counter until current target is reached */
			while (current < i) {
				answer.push_back(push);
				answer.push_back(pop);
				current++;
			}
			answer.push_back(push);
			current++;
		}
		return answer;
	}
};