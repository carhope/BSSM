#include <stdio.h>
#define MAX_N 10000
void insertionSort(int arr[], int n) {
for (int i = 1; i < n; i++) {
int key = arr[i], j = i - 1;
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = key;
}
}
int main() {
int N, arr[MAX_N];
scanf("%d", &N);
for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
insertionSort(arr, N);
int bestA = arr[0], bestB = arr[1];
int minDiff = arr[1] - arr[0];
for (int i = 1; i < N - 1; i++) {
int diff = arr[i + 1] - arr[i];
if (diff < minDiff) {
minDiff = diff;
bestA = arr[i];
bestB = arr[i + 1];
}
}
printf("%d %d\n", bestA, bestB);
return 0;
}