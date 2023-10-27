#include <string.h>

/* returns max value of two ints */
int max(int a, int b)
{
	return a > b ? a : b;
}

/* returns length of palindrone starting at index (start/end) */
int extend(char *s, int start, int end) 
{
	int len = strlen(s);
	for (; (start >= 0) && (end < len); start--, end++){
		if (*(s+start) != *(s+end)) {
			break;
		}
	}
	return end-start-1;
}

char * longestPalindrome(char *s)
{
	int max = 0;
	int idx = 0; 
	int len = strlen(s);


	for (int i = 0; i < len; i++) {
		/* Get length of palindrone starting at index i*/
		int even = extend(s, i, i);
		int odd  = extend(s, i, i+1);

		/* Check if bigger than current and update */
		if  (max < maxVal(even, odd)) {
			idx = (even>odd)?(i-even/2):(i-odd/2+1);
			max = maxVal(even, odd);
		}
	}

	/* preparing answer */
	char *res = malloc((max+1)*sizeof(char));
	memcpy(res, &s[idx], max);
	res[max] = '\0';
	return res; 
}