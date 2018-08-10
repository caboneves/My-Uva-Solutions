
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

typedef long long ll;


ll a,b,N;
ll func(ll X){
	return ((a*X)%N * X%N) + b%N;
}

pair<ll,ll> findMiandLambda(ll x0){
	ll turtle,rabbit,steps_taken,steps_limit;
	steps_taken = 0;
	rabbit = turtle = x0;
	steps_limit = 2;
	while (true){
		rabbit = func(rabbit);
		steps_taken++;
		if (turtle == rabbit){
			rabbit  = turtle = x0;
			int mi = 0;
			for(int i=0;i<steps_taken;i++){
				rabbit = func(rabbit);
			}
			while(rabbit!=turtle){
				rabbit = func(rabbit);
				turtle = func(turtle);
				mi++;
			}
			return pair<ll,ll>(steps_taken,mi);

		}
		if (steps_limit == steps_taken){
			steps_taken = 0;
			steps_limit *= 2;
			turtle = rabbit; // teletransport
		}
	}
}





int main() {

	cin >> N;
	while(N){
		cin >> a >> b;
		pair<ll,ll> p = findMiandLambda(0);
		cout << N - p.first<<endl;
		cin >> N;
	}



	return 0;
}

