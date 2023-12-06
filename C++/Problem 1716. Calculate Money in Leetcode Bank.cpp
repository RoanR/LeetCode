

class Solution {
public:
	int totalMoney(int n) {
		int week = n/7;
		int days = n%7;

		int total = ((week*(week-1)/2)*7);
		total += (week *28);
		total += (days*(days+1)/2)+(week*days);
		return total;
	}
};
