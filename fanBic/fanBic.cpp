#include <bits/stdc++.h>

using namespace std;
#define ll long long

// fanbic tree update and give sum in log ( n )
//  table[i] = sum of the range between [l+1, to i]   where l is turn off right
//  most set bit of i, which is l= i- (i & -i);

// intitialy table is filled with zero than update the table
// element which is present at ith index effect all the index which contain ith
// elenment;

// which are i=i + (i & -i)  jb tak karo jb tak pur array na bhar jaye

// if i want sum of 1 to 13 index which is  1101 binary
// sum(1---13)= fantable[1101 ] + fantable[1100] + fantable[1000]
// +fantable[00000] har baar righrmst set bit ko 0 karate jao jb tak 0 na ho
// jaye number
int N = 100000 + 5;
int fen[N];

void upadate(int i, int add) {
  while (i < N) {
    fen[i] += add;
    i += (i & (-i));
  }
}

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += fen[i];
    i -= (i & (-i));
  }
  return s;
}

int sumRange(int l, int r)
{
  return sum(r)-sum(l-1);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}