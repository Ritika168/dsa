#include <iostream>
using namespace std;
int max(int x, int y);


int lcs(string &S1, string &S2) {
    int m = S1.size();
    int n = S2.size();

    
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
          
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            
            else if (S1[i - 1] == S2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
   
    return dp[m][n];
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    string S1;
    string S2;
    cout<<"Enter 1st String: "<<endl;
    cin>>S1;
    cout<<"Enter 2nd String: "<<endl;
    cin>>S2;
    cout<<"Length of LCS is "<<lcs(S1, S2)<<endl;

    return 0;
}
