


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>
#include <stack>
#include <queue>
#include <stdio.h>
#include <typeinfo>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <ctype.h>
#include <unordered_set>
//1 2 3 4 5 6 7 8
using namespace std;
#define pb push_back
#define PRETO 1
#define BRANCO 0
#define CINZA 2
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<float,int> fi;
typedef long long ll;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<vector<int>> graph;




#define INF 2000 // 2 billion


vi primes;
bitset<10000010> bs;
ll sieve_size;
void sieve(ll upperbound){
	sieve_size = upperbound+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2;i<sieve_size;i++){
		if(bs[i]){
			primes.pb(i);
			for(ll j = i*i;j<sieve_size;j+=i) bs[j] = 0;
		}
	}
}

bool isPrime(ll N){
	if (N < sieve_size) return bs[N];
	for (int p :primes){
		if (N%p == 0) return false;
	}
	return true;
}

int main() {

	sieve(10000000);

	string line;
	cin >> line;
	while (line != "0"){
		int size = 5;
		ll p = -INF;
		while (size>=1){
			for(int i=0;i+size<line.length();i++){
				string sub = line.substr(i,size);
				ll tmp = stoi(sub);
				if(isPrime(tmp)){
					p = std::max(p,tmp);
				}
			}
			if (p!=-INF) {
				cout << p << endl;
				break;
			}
			else size--;
		}
		cin >> line;
	}

	return 0;
}
