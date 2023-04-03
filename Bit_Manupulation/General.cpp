//  to count the no of set bit in a number

__builtin_popcount(n)


// drops the lowest set bit.

n=n & (n - 1)
  
  // left set bit;
  n =(n  &  -n)
  // important proprtty
  (a+b)= (a^b)  +   2*(a&b)
