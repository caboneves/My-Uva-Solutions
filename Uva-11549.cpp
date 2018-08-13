
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
#define INF 2000000000 // 2 billion
typedef long long             ll;

ll func(ll x,int n){
	int N = (int)log10(x)+1;
	int k=0;
	while (k<N-n){
		x/=10;
		k++;
	}
	x *= x;
	N = (int)log10(x)+1;
	k=0;
	while (k<N-n){
		x/=10;
		k++;
	}
	return x;

}

ll findMiandLambda(ll x0,int n){
	ll turtle,rabbit,steps_taken,steps_limit;
	steps_taken = 0;
	rabbit = turtle = x0;
	steps_limit = 2;
	ll largest = -INF;
	while (true){
		largest = std::max(largest,rabbit);
		rabbit = func(rabbit,n);
		steps_taken++;
		if (turtle == rabbit){
			return largest;
		}
		if (steps_limit == steps_taken){
			steps_taken = 0;
			steps_limit *= 2;
			turtle = rabbit; // teletransport
		}
	}
}



int main() {

	int t; cin >> t;
	int n;ll k;
	while (t--){
		cin >> n >> k;
		cout <<findMiandLambda(k,n)<<endl;
	}



	return 0;
}
