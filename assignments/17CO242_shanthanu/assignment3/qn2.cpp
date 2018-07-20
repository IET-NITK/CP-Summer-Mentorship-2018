//Problem: http://codeforces.com/problemset/problem/75/C
//solution link: http://codeforces.com/contest/75/submission/38419190

//code:

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    while(b != 0) {
       int temp = a;
       a = b;
       b = temp%b;
    }
    return a;
}

int ceilSearch(const vector<int>& arr, int low, int high, int x)
{
  int mid;
  if(x <= arr[low])
    return low;
  if(x > arr[high])
    return -1;
  mid = (low + high)/2;
  if(arr[mid] == x)
    return mid; 
  else if(arr[mid] < x)
  {
    if(mid + 1 <= high && x <= arr[mid+1])
      return mid + 1;
    else
      return ceilSearch(arr, mid+1, high, x);
  }   
  else
  {
    if(mid - 1 >= low && x > arr[mid-1])
      return mid;
    else    
      return ceilSearch(arr, low, mid - 1, x);
  }
}

int floorSearch(const vector<int>& arr, int low, int high, int x) {
    if (low > high)
        return -1;
    if (x >= arr[high])
        return high;
    int mid = (low+high)/2;
    if (arr[mid] == x)
        return mid;
    if (mid > 0 && arr[mid-1] <= x && x < arr[mid])
        return mid-1;
    if (x < arr[mid])
        return floorSearch(arr, low, mid-1, x);
    return floorSearch(arr, mid+1, high, x);
}

int main() {
	int a,b,n;
	cin>>a>>b>>n;
	int fac = gcd(a,b);
	vector<int> div;
	for(int i = 1; i <= (int)sqrt(fac); i++) {
		if(fac%i == 0) {
			div.push_back(i);
			if(i*i != fac) {
				div.push_back(fac/i);
			}
		}
	}
	sort(div.begin(), div.end());
	while(n--) {
		int low, high;
		cin>>low>>high;
		int l = ceilSearch(div, 0, div.size()-1, low);
		int h = floorSearch(div, 0, div.size()-1, high);
		if(l != -1 && l<=h) {
			cout<<div[h]<<endl;
		}
		else {
			cout<<-1<<endl;
		}
	}
}