#include <stdio.h>

int max(int a, int b) {
  if (a >= b) {
    return a;
  } else {
    return b;
  }
}
void knapsack(int n, int W, int v[], int w[]) {
  int kptable[n + 1][W + 1];
  for (int i = 0; i <= n; i++) {
    for (int wt = 0; wt <= W; wt++) {
      if (i == 0 || wt == 0) {
        kptable[i][wt] = 0;
      } else if (w[i - 1] <= wt) {
        kptable[i][wt] = max(v[i - 1] +
          kptable[i - 1][wt - w[i - 1]], kptable[i - 1][wt]);
      } else {
        kptable[i][wt] = kptable[i - 1]
          [wt];
      }
    }
  }
  printf("%d\n", kptable[n][W]);
}
void main() {
    int n, w, values[20], weight[20];
    scanf("%d", & n);
    for (int i = 0; i < n; i++) {
      scanf("%d ", & values[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d ", & weight[i]);
    }
    scanf("%d", & w);
    knapsack(n, w, values, weight);
}
