//Q:https://www.codechef.com/problems/IPCTRAIN
//S:https://www.codechef.com/viewsolution/18899762

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Prof{
public:
    int s;
    int t;
    int d;
};
bool comp (Prof i,Prof j) { return (i.d<j.d); }

class Compare
{
public:
    bool operator () (Prof i, Prof j) {
        return i.s<j.s;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        vector<Prof> v;
        for (int i = 0; i != n; i++) {
            Prof obj;
            cin >> obj.d >> obj.t >> obj.s;
            v.push_back(obj);
        }
        sort(v.begin(),v.end(),comp);
        priority_queue<Prof,vector<Prof>, Compare> pq;
        for(int i=1,it=0;i<=d;i++)
        {
            while(it<n && v[it].d == i)
            {
                pq.push(v[it]);
                //cout<<i<<" "<<v[it].d<<endl;
                it++;
            }
            if(!pq.empty())
            {
                Prof obj=pq.top();
                //cout<<obj.d<<" "<<obj.t<<" "<<obj.s<<endl;
                pq.pop();
                obj.t--;
                if(obj.t>=1)
                    pq.push(obj);
            }
        }
        int l=pq.size();
        long long sad=0;
        for (int j = 0; j < l; ++j) {
            Prof obj = pq.top();
            pq.pop();
            //cout<<obj.d<<" "<<obj.t<<" "<<obj.s<<endl;
            sad+=1LL*obj.t*obj.s;
        }
        cout<<sad<<endl;
    }
}
