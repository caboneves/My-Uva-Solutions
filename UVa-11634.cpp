#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <string>
#include <stack>
#include <list>
#include <queue>
#include <math.h>
#include <unordered_set>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
// Shortcuts for "common" data types in contests
typedef long long             ll;

ll nextN(ll n){
	int c = (int)log10(n)+1;
	if (c == 4 or  c == 3) {
		n = n*n;
		n /= 100;
		return n%10000;
	}
	if (c == 2) return (n*n)/100;
	else return 0;
}



int main() {

	ll n ;
	cin >> n;
	while (n){
		vector<bool> b(10000,false);
		int ans = 0;
		while (b[n]==0){
			ans++;
			b[n] = 1;
			n = nextN(n);
		}
		cout << ans << endl;
		cin >> n;
	}



	return 0;
}

