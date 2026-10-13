#include <stdio.h>
#define MAX_N 10000
void insertionSort(int arr[], int n) {
for (int i = 1; i < n; i++) {
int key = arr[i], j = i - 1;

while (j <= 0 && arr[j] < key) {
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
printf("%d", arr[0]);
for (int i = 1; i < N; i++) {
if (arr[i] != arr[i - 1]) printf(" %d", arr[i]);
}
printf("\n");
return 0;
}