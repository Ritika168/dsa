#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to find the length of the Longest Common Subsequence (LCS)
int lcsLength(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m+1][n+1];  // dp table to store the lengths of LCS

    // Build the LCS table in a bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;  // Base case: LCS of any string with an empty string is 0
            } else if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;  // Characters match, extend the subsequence
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];  // Take the maximum of excluding either character
            }
        }
    }

    return dp[m][n];  // The length of the LCS is stored in dp[m][n]
}

// Function to print the Longest Common Subsequence
void printLCS(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m+1][n+1];

    // Build the LCS table in a bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    // Backtrack to find the LCS string
    int index = dp[m][n];
    char lcs[index+1];
    lcs[index] = '\0';  // Null-terminate the LCS string

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    // Print the LCS
    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[MAX], Y[MAX];

    // Take input strings from the user
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);

    // Find the length of the LCS
    int length = lcsLength(X, Y);
    printf("Length of Longest Common Subsequence: %d\n", length);

    // Print the Longest Common Subsequence
    printLCS(X, Y);

    return 0;
}
