//problem: http://codeforces.com/contest/687/problem/B
//solution link: http://codeforces.com/contest/687/submission/38529753

//code
#include <cstdio>
#include <map>
using namespace std;
#define N 1000001
//smallest prime factor of any number
int spf[N] = {0};
map < int, int > lcm, pf_k;

void sieve() {
	spf[0] = spf[1] = 1;
	for(int i = 2; i < N; i++) {
		if(spf[i] == 0) {
		    lcm[i] = pf_k[i] = 0;
			for(int j = i; j < N; j += i) {
				if(spf[j] == 0) {
					spf[j] = i;
				}
			}
		}
	}
}
 

void pf(int c, map<int, int>& a) {
	int temp = 1, count = 0;
	while(true) {
		if(temp != spf[c]) {
			if(a[temp] < count) {
				a[temp] = count;
			}
			temp = spf[c];
			count = 1;
		}
		else {
			count++;
		}
		if(c == 1) {
		    break;   
		}
		c = c/spf[c];
	}
}

int main() {
	sieve();
	int n,k;
	scanf("%d%d", &n ,&k);
	//special case
	if(n == 1) {
	    int c;
	    scanf("%d",&c);
	    if(c%k == 0) {
	        printf("Yes");
	    }
	    else {
	        printf("No");
	    }
	    return 0;
	} 
	while(n--) {
		int c;
		scanf("%d", &c);
		pf(c, lcm);
	}
	pf(k, pf_k);
	bool flag = true;
	for(map<int, int>::iterator i = lcm.begin(), j = pf_k.begin(); i != lcm.end() && j != pf_k.end(); i++, j++) {
	    if(j->second > i->second) {
				flag = false;
				break;
	    }
	}
	if(flag) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}