int max(int a, int b) 
{
	if (a > b) return a;
	else	   return b; 
}

int min(int a, int b) 
{
	if (a > b) return b; 
	else	   return a;
}

int maximumScore(int* nums, int numsSize, int k)
{
	int maxC;
	int minC = nums[k];

	/* Base Case */
	maxC = minC;
	int i, j;
	i = k;
	j = k;

	while (i != 0 || j != numsSize-1) {
		//printf("running for i..j: %d..%d\n", i, j);
		int maxI, maxJ;
		if (i > 0) {
			maxI = min(minC, nums[i-1]) * (j-(i-1)+1);
		} else {
			maxI = 0;
		}

		if (j < numsSize -1) {
			maxJ = min(minC, nums[j+1]) * ((j+1)-i+1);
		} else {
			maxJ = 0;
		}

		//printf("maxI: %d, maxJ: %d\n", maxI, maxJ);
		if (maxI > maxJ) {
			maxC = max(maxC, maxI);
			minC = min(minC, nums[i-1]);
			i--;
		} else {
			maxC = max(maxC, maxJ);
			minC = min(minC, nums[j+1]);
			j++;
		}
	}

	return maxC;
}