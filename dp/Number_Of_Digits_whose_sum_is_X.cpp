// Number of digits form 0 to N whose digit sum is  equal to (sum)

#include <bits/stdc++.h>
using namespace std;
int dp[20][180][2];
int solve(int n, int sum, bool tight, string &num) {
  if (sum < 0)
    return 0;
  if (n == 1) {
    if (tight and sum >= 0 && sum <= (num[num.size() - n] - '0'))
      return 1;
    else if (!tight and sum >= 0 and sum <= 9)
      return 1;
    return 0;
  }

  if (dp[n][sum][tight] != -1)
    return dp[n][sum][tight];
  int uppper = (tight == true) ? (num[num.size() - n] - '0') : 9;
  int ans = 0;
  for (int dig = 0; dig <= uppper; dig++) {
    ans += solve(n - 1, sum - dig, (tight & (dig == uppper)), num);
  }
  return dp[n][sum][tight] = ans;
}
int main() {
  string num;
  cin >> num;
  int sum;
  cin >> sum;
  memset(dp, -1, sizeof(dp));
  int n = num.size();
  bool tight = true;
  cout << solve(n, sum, tight, num);

  return 0;
}