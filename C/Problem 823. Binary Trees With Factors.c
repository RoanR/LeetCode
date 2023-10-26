#include <stdio.h>
#include <stdlib.h>
#define INPUT {}

int cmpFunc(const void *a, const void *b) 
{
	return (*(int *)a - *(int *)b);
}

int binarySearch(int *arr, int target, int arrSize)
{
	int low, high; 
	low = 0; 
	high = arrSize - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		/* printf("looking for %d, currently at %d\n", target, arr[mid]); */

		if (arr[mid] == target) {
			return mid;
		}

		if (arr[mid] < target) {
			low = mid + 1; 
		} else {
			high = mid - 1; 
		}
	}

	return -1;
}

int numFactoredBinaryTrees(int *arr, int arrSize) 
{
	long long mod = 10e9+7;
	int total = 1;
	int *compArr;

	 
	for(int n = 0; n < arrSize; n++) {
		compArr[n] = 0;
	}

	/* Sort input array */
	qsort(arr, arrSize, sizeof(int), cmpFunc);

	/* Base Case */
	if (arrSize == 1) {
		return 1;
	}

	compArr[0] = 1;
	for (int n = 1; n < arrSize; n++) {
		int current = arr[n];
		/* printf("Current %d\n", current); */
		int localTotal = 1;


		for (int i = 0; i < n; i++) {
			if (current%arr[i]!=0) {
				/* printf("No pair since %d/%d != 0\n", 
					current, arr[i]); */
				continue;
			}

			int target = current/arr[i];
			if (target == arr[i]) {
				/* printf("Dual pair since %d=%dx%d\n",
					current, target, target); */ 
				localTotal += 
					(compArr[i] * compArr[i]);
				continue;
			}
			/* printf("Searching for %d\n", target); */
			target = binarySearch(arr, target, n+1);
			if (target != -1) {
				/* printf("Found pair since %d=%dx%d\n",
					current, arr[target], arr[i]); */
				localTotal += (compArr[target] * compArr[i]);
			}
		}
		compArr[n] = localTotal;
		total += localTotal%mod;
		/* printf("After %d, Total is %d\n", current, total); */
	}

	return total%mod;
}

int main()
{
	int arr[] = {};
	int total = numFactoredBinaryTrees(arr, 98);
	printf("total : %d\n", total); 
}