#include <bits/stdc++.h> 
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

// a[]
// a[0]*a[1] + a[1]*a[2] + a[2]*a[3] + ... => min

int main(int argc, char const *argv[])
{
    clock_t start = clock();

    // 0 1 2 3 4 5 6 7 8 9
    // v.1
    // 0 9 1 8 2 7 3 6 4 5
        
	while (1) {
		int n = 5;
		vector<int> a(n);
		forn(i, n)
			a[i] = rand() % 10;	

		vector<int> b;

		sort(a.begin(), a.end());
		for (int l = 0, r = n - 1; l <= r; ) {
			if (l <= r) b.push_back(a[l++]);
			if (l <= r) b.push_back(a[r--]);
		}

		auto  f = [&](vector<int> x) {
			int sum = 0;
			forn(i, n - 1)
				sum += x[i] * x[i + 1];
			return sum;
		};

		vector<int> opt_a;
		int opt = INT_MAX;

		sort(a.begin(), a.end());
		do {
			int tmp = f(a);
			if (tmp < opt)
				opt = tmp, opt_a = a;
		} while (next_permutation(a.begin(), a.end()));

		for (int x : opt_a) printf("%d ", x); 
		puts("");
		fflush(stdout);
		// random_shuffle(a.begin(), a.end());
		// random_shuffle(a, a + n);

		// bool g = f(b) <= f(a);
		// if (f(b) > f(a)) {
		// 	printf("%d %d\n", f(b), f(a));
		// 	for (int x : b) printf("%d ", x); 
		// 	puts("");
		// 	for (int x : a) printf("%d ", x); 
		// 	puts("");
		// }
		// assert(f(b) <= f(a));
		// if (g == 0) {
		// 	printf("что-то плохое");
		// 	return 1;
		// }
	}

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    return 0;
}
