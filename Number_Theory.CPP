//   Prime SEIVE SMALL PRIME FACTOR  FACTOR, POWER FUNCTON 
vector<bool> isPrime;
	vector<int> spf;
	vector<long long> fact, ifact;
	
	const int mod = 1e9 + 7;
	const int maxn = 1e4 + 5;

	void sieve() {
		isPrime.resize(maxn, true);
		spf.resize(maxn);
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i < maxn; i++) {
			if (isPrime[i]) {
				spf[i] = i;
				for (int j = i * i; j < maxn; j += i) {
					if (isPrime[j]) {
						isPrime[j] = false;
						spf[j] = i;
					}
				}
			}
		}
	}
	
	vector<int> factorize(int n) {
		vector<int> f;
		while (n > 1) {
			int s = spf[n], c = 0;
			while (n % s == 0) {
				n /= s;
				c++;
			}
			f.push_back(c);
		}
		return f;
	}
	
	long long modPow(int a, int n) {
		if (n == 0) return 1;
		long long e = modPow(a, n >> 1);
		e *= e;
		e %= mod;
		if (n & 1) {
			e *= a;
			e %= mod;
		}
		return e;
	}

	void factorial() {
		const int maxf = 2 * maxn;
		fact.resize(maxf);
		ifact.resize(maxf);
		fact[0] = 1;
		for (int i = 1; i < maxf; i++) {
			fact[i] = (fact[i - 1] * i) % mod;
		}
		ifact[maxf - 1] = modPow(fact[maxf - 1], mod - 2);
		for (int i = maxf - 2; i >= 1; i--) {
			ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
		}
	}
	
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        factorial();
		sieve();
		int N = queries.size();
		vector<int> ans(N);
		for (int i = 0; i < N; i++) {
			int n = queries[i][0], k = queries[i][1];
			if (k == 1 || n == 1) {
				ans[i] = 1;
				continue;
			}
			vector<int> f = factorize(k);
			long long res = 1;
			for (const int &x: f) {
				long long cur = fact[x + n - 1];
				cur *= ifact[x];
				cur %= mod;
				cur *= ifact[n - 1];
				cur %= mod;
				res *= cur;
				res %= mod;
			}
			ans[i] = res;
		}
		return ans;
    }
    
    
    
    
    
    //.........................................................................
