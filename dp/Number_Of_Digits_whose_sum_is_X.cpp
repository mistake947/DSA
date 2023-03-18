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

///--------------------------------------------------//


// Given a positive integer n, return the number of the integers in the range [0, n] 
// whose binary representations do not contain consecutive ones.


class Solution {
public:
    int dp[32][3][3];
    string st="";
    int solve(int idx, int small,int last)
    {
        if(idx>=st.size())return 1;
        if(dp[idx][small][last]!=-1)return dp[idx][small][last];
        
        int range=(st[idx]-'0');
        if(small==true)range=1;
        int currAns=0;
        for(int i=0;i<=range;i++)
        {
            int newSmall=((small==1)|| i!=range);
            if(last==1 and i==1)continue;
            currAns+=solve(idx+1,newSmall,i);
        }
        return dp[idx][small][last]=currAns;
        
    }
    int findIntegers(int n) {
        for(int i=0;i<=log2(n);i++)
        {
            if(n&(1<<i))st="1"+st;
            else st="0"+st;
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
        cout<<st<<endl;
        return 0;
    }
};


////--------------------------------------------------//
