int minVal(int a, int b) 
{
	return a < b ? a : b;
}

int minOperations(int* nums, int numsSize, int x) 
{
	int min = numsSize;

	int leftX = x;
	int leftId = 0;
	for (int i = 0; i < numsSize; i++) {
		leftX = leftX - nums[i];
		if (leftX < 0) {
			leftId = i;
			break; 
		}
	}

	/* Checks if sum(nums) > x  */
	if (leftX > 0)  return -1; 

	/* Checks if sum(nums) == x */
	if (leftX == 0) return numsSize;

	
	for (int i = leftId; leftId >= 0; i--) {
		int rightId = -1;

		while (leftX > 0) {
			rightId++;
			leftX = leftX - nums[rightId];
		}

		if (leftX == 0) {
			min = minVal(min, (i+1)+(rightId+1)); 
		}

		leftX = leftX + nums[i];
	}

	if (min == numsSize) return -1;
	else		     return min;
}