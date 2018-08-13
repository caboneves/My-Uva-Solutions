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

typedef long long             ll;

ll func(ll x){
	ll s = 0;
	while (x!=0){
		int r = x%10;
		s += r*r;
		x/=10;
	}
	return s;
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

	int t; cin >> t;
	ll n;
	for(int i=0;i<t;i++){
		cin >> n;
		pair<ll,ll> p = findMiandLambda(n);
		cout << "Case #"<<i+1<<":"<<" ";
		if (p.first!=1) cout <<n<<" is an Unhappy number.";
		else cout << n<<" is a Happy number.";
		cout << endl;

	}



	return 0;
}

