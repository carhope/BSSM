#include <stdio.h>;
#define MAX_N 10000
int main() {
int N, K, arr[MAX_N];
scanf("%d %d", &N, &K);

for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
int left = 0, right = N - 1, answer = -1;
while (left <= right) {
int mid = (left + right) / 2;
if (arr[mid] >= K) {
answer = mid;
right = mid - 1;
} else {
left = mid + 1;
}
}
if (answer == -1) printf("-1\n");
else printf("%d\n", answer + 1);
return 0;
}