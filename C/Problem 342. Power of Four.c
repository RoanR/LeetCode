#include <stdbool.h>

bool isPowerOfFour(int n)
{
	int mask = 0b01010101010101010101010101010101;
	if ((n | mask) == mask) {
		if ((n-1 & n) == 0) {
			return true;
		}
	}

	if (n == 0) {
		return true;
	}

	return false;
}