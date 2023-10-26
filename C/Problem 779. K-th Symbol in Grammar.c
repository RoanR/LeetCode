int inv(int a) 
{
	if (a == 0) {
		return 1;
	}
	return 0;
}

int kthGrammar(int n, int k)
{
	/* Base Case */
	if (n == 1) {
		return 0;
	}

	/* Step Case */
	if (k%2 == 0) {
		return (inv(kthGrammar(n-1,(k+1)/2)));
	} else {
		return kthGrammar(n-1, (k+1)/2);
	}
}