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
int binarySearch(int arr[], int n, int target) {
int left = 0, right = n - 1;
while (left <= right) {
int mid = (left + right) / 2;
if (arr[mid] == target) return 1;
if (arr[mid] < target) left = mid + 1;
else right = mid - 1;
}
return 0;
}
int main() {
int N, M, arr[MAX_N];
scanf("%d", &N);
for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
insertionSort(arr, N);

scanf("%d", &M);
for (int i = 0; i < M; i++) {
int target;
scanf("%d", &target);
if (i > 0) printf(" ");
printf("%d", binarySearch(arr, N, target));
}
printf("\n");
return 0;
}