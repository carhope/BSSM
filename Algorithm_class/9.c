#include <stdio.h>
#define MAX_N 10000
int absolute(int x) {
return x < 0 ? -x : x;
}
int main() {
int N, K, arr[MAX_N];
scanf("%d %d", &N, &K);
for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
int answer = arr[0];
int minDiff = absolute(arr[0] - K);
for (int i = 1; i < N; i++) {
int diff = absolute(arr[i] - K);
if (diff < minDiff ||
(diff == minDiff && arr[i] < answer)) {
minDiff = diff;
answer = arr[i];
}
}
printf("%d\n", answer);
return 0;
}