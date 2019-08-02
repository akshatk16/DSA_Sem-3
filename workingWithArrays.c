#include<stdio.h>

int main()
{

	//input array length
	int arr[100], n;
	printf("Enter number of elements: ");
	scanf("%d", &n);

	//input array elements
	printf("Enter elements in increasing order only.\n\n");
	for(int i=0; i<n; i++)
	{
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr[i]);
	}

	//traversing
	printf("\nThe elements in the array are:\n");
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);

	//sum of elements
	int sum=0;
	for(int i=0; i<n; i++)
		sum += arr[i];

	printf("\n\nThe sum of elements in the array is: %d\n", sum);

	//linear search
	printf("\nEnter element to be searched: ");
	int inp;
	int flag=0;
	scanf("%d", &inp);

	for(int i=0; i<n; i++)
	{
		if(inp==arr[i])
		{
			flag=1;
			printf("Found at position %d\n", i+1);
			break;
		}
	}
	if(flag==0)
		printf("%d not found in array\n", inp);


	//binary search
	printf("\nEnter element to be searched: ");
	int item;
	int flagB=0;
	scanf("%d", &item);

	int start = 0;
	int end = n-1;
	int mid;

	while(start<=end)
	{
		mid = (start + end)/2;

		if(item==arr[mid])
		{
			flagB=1;
			printf("Found at position %d\n", mid+1);
			break;
		}
		else if(inpB < arr[mid])
			end = mid-1;

		else
			start = mid+1;
	}

	if(flagB==0)
		printf("%d not found in array\n", inpB);


	return 0;
}
