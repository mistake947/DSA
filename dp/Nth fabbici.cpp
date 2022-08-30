// Using Binet's Formula for the Nth Fibonacci involves the usage of our golden section number Phi.
// Phi = ( sqrt(5) + 1 ) / 2
// Using approximation equation is good enough here, since we know N >= 0 && N <= 30, we can safely use the following rounded function
// Fib(N) = round( ( Phi^N ) / sqrt(5) )
// Full mathematical explanation of Binet's Formula here
// Time Complexity - O(1)
// Space Complexity - O(1)

    int fib(int N) {
        double phi = (sqrt(5) + 1) / 2;     
        return round(pow(phi, N) / sqrt(5));
    }


//     Observation: Basically, we have a Matrix M = [[1,1],[1,0]], and pow(M, n), gives us that fibonacci number at M[0][0].

// Proof: by induction

// Fisrt,

// let fib[i] the fibonacci number when n = i.
// let base case: n = 2 => M = [[2,1],[1,1]],
// assume fib[i] = M[0][0], fib[i-1] = M[0][1] = M[1][0], fib[i-2] = M[1][1].

// Second,

// let n = k, M = [[fib[k], fib[k-1]],[fib[k-1], fib[k-2]]
// if n = k+1,
// M = [[fib[k]+fib[k+1], fib[k]-0],[fib[k-1]+fib[k-2], fib[k-1]]
// =[[fib[k+1], fib[k]],[fib[k], fib[k-1]]

// Therefore, by induction, fib[i] = M[0][0], fib[i-1] = M[0][1] = M[1][0], fib[i-2] = M[1][1].

int fib(int n) {
	if(n < 2) return n;
	int M[2][2] = {{1,1},{1,0}},
		F[2][2] = {{1,1},{1,0}};
	for(int i = 2; i < n; i++){
		matrixMultiplication(F,M);
	}
	return F[0][0];
}
void matrixMultiplication(int F[2][2], int M[2][2]){
	int m00 = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	int m01 = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	int m10 = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	int m11 = F[1][0] * M[0][1] + F[1][1] * M[1][1];
	F[0][0] = m00, F[0][1] = m01, F[1][0] = m10, F[1][1] = m11;
}
//Time complexity: O(n)

// Apply Exponential Ideas

// In the base idea, we want to run F*M n-1 times, right?

// Since pow(F,k) * pow(F,k) == pow(F,k*2), we optimize the base idea exponentially.

// while(k*2 still in n-1){ do multiplication; }
// otherwise, do the normal thing F*M. (just like in the base case)

int M[2][2] = {{1,1},{1,0}},
	F[2][2] = {{1,1},{1,0}};
int fib(int n) {
	if(n < 2) return n;
	power(F, n-1);
	return F[0][0];
}
void power(int F[2][2], int n){
	int cnt = 1;
	while(n >= cnt*2){
		matrixMultiplication(F,F);
		cnt = cnt*2;
	}
	while(cnt < n){
		matrixMultiplication(F,M);
		cnt++;
	}
}
void matrixMultiplication(int F[2][2], int M[2][2]){
	int m00 = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	int m01 = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	int m10 = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	int m11 = F[1][0] * M[0][1] + F[1][1] * M[1][1];
	F[0][0] = m00, F[0][1] = m01, F[1][0] = m10, F[1][1] = m11;
}
//Time complexity: O(log(n))