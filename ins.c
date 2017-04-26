#include <stdio.h>

int arr[6] = { 4, 7, 2, 6, 3, 1 };

void
push_right(int a, int b)
{
	int k;
	for (k = b; k > a; --k)
		arr[k] = arr[k - 1];
}

int
main()
{
	int i, j, l, tmp;

	for (i = 1; i < 6; ++i) {
		for (j = 0; j < i; ++j) {
			if (arr[i] < arr[j]) {
				tmp = arr[i];
				push_right(j, i);
				arr[j] = tmp;
			}
		}
	}
	printf("Sorted array:\n");
	for (i = 0; i < 6; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
