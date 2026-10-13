#include <stdio.h>;
#define MAX_N 10000
void insertionSort(int arr[], int n) {
for (int i = 1; i < n; i++) {
int key = arr[i];
int j = i - 1;
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
    for (int i = 0; i <N; i++) scanf("%d", &arr[i]);
        insertionSort(arr, N);
    for (int i = 0; i < N; i++) {
        if (i > 0) printf(" ");
    printf("%d", arr[i]);
}
printf("\n");
return 0;