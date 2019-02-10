#include<stdio.h>
int main() {
	int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 }, sum, n;
	//scanf("%d", &n);
	scanf("%d", &sum);
	n = 8;
	subArraySum(arr, n, sum);
	scanf("%d", &n);
	return 0;
}
int subArraySum(int arr[], int n, int sum)
{
	int curr_sum, i, j;

	// Pick a starting point 
	for (i = 0; i < n; i++)
	{
		curr_sum = arr[i];

		// try all subarrays starting with 'i' 
		for (j = i + 1; j <= n; j++)
		{
			if (curr_sum == sum)
			{
				printf("Sum found between indexes %d and %d", i, j - 1);
				return 1;
			}
			if (curr_sum > sum || j == n)
				break;
			curr_sum = curr_sum + arr[j];
		}
	}

	printf("No subarray found");
	return 0;
}
