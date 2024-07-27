#include <stdio.h>
#include <stdlib.h>
int flag=0;
void combinationUtil(int arr[], int n, int r, int index, int data[], int i, int sum);
void printCombination(int arr[], int n, int r, int sum)
{
	int data[r];
	combinationUtil(arr, n, r, 0, data, 0, sum);
}
void combinationUtil(int arr[], int n, int r, int index,
					int data[], int i, int sum)
{
	if (index == r) {
        int s=0;
		for (int j = 0; j < r; j++)
            s+=data[j];
        if (s==sum)
        {
            flag=1;
            for (int j = 0; j < r; j++)
			    printf("%d ", data[j]);
		    printf("\n");
        }
		return;
	}
	if (i >= n)
		return;
	data[index] = arr[i];
	combinationUtil(arr, n, r, index + 1, data, i + 1, sum);
	combinationUtil(arr, n, r, index, data, i + 1, sum);
}
int main()
{
	int n, sum;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    for (int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the required sum: ");
    scanf("%d",&sum);
	for (int i=1; i<=n; i++)
    {
        printCombination(arr, n, i, sum);
        if (flag==1)
            break;
    }
	return 0;
}