#include <stdio.h>
#define MAX_N 10000
void selectionSortDescending(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
int maxIndex = i;
for (int j = i + 1; j < n; j++) {
if (arr[j] > arr[maxIndex]) maxIndex = j;
}
int temp = arr[i];
arr[i] = arr[maxIndex];
arr[maxIndex] = temp;
}
}
int main() {
int N, K, arr[MAX_N];
scanf("%d %d", &N, &K);
for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
selectionSortDescending(arr, N);
printf("%d\n", arr[K - 1]);
return 0;
}