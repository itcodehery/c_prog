#include <stdio.h>
#include <string.h>

void printTable(int dp[100][100], int m, int n, char *X, char *Y) {
  printf("\nLCS Table:\n      ");
  for (int j = 0; j < n; j++) {
    printf("%c  ", Y[j]);
  }
  printf("\n");

  for (int i = 0; i <= m; i++) {
    if (i == 0)
      printf("   ");
    else
      printf("%c  ", X[i - 1]);

    for (int j = 0; j <= n; j++) {
      printf("%d  ", dp[i][j]);
    }
    printf("\n");
  }
}

int main() {
  char X[100];
  char Y[100];

  printf("Enter first string: ");
  scanf("%s", X);
  printf("Enter second string: ");
  scanf("%s", Y);

  if (strlen(X) == 0 || strlen(Y) == 0) {
    printf("Invalid or empty strings provided.\n");
    return 1;
  }

  int m = strlen(X);
  int n = strlen(Y);

  int dp[100][100];

  // main thingy
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {

      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (X[i - 1] == Y[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
      }
    }
  }

  printTable(dp, m, n, X, Y);

  int length = dp[m][n];
  printf("\nLCS Length: %d\n", length);

  char lcs[100];
  lcs[length] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (X[i - 1] == Y[j - 1]) {
      lcs[length - 1] = X[i - 1];
      i--;
      j--;
      length--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  printf("LCS: %s\n", lcs);

  return 0;
}
