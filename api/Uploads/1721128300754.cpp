#include<bits/stdc++.h>

#define ll long long int
#define F first
#define S second
#define f(i,a,n) for(ll i=a;i<n;i++)
#define rf(i,n,a) for(ll i=n-1;i>=a;i--)
#define W() int t;cin>>t; while(t--)
#define pb push_back
#define pii pair<int,int>
#define lb lower_bound   // O(logN) auto it=lb(start,end+1,value) it will give iterator of sabse chota element jo value se equal or bra ho simillarly uppbound will give sabse chota element jo value bra ho.
#define ub upper_bound
//binary_search(st,end,value)  O(logN)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;


int main() 
{
    fast;
    ll n;
    cin>>n;
    vector<pair<ll,ll>> vec;
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        vec.pb({x,y});
    }
    sort(vec.begin(),vec.end());
    set<pair<ll,ll>> st;
    st.insert({vec[0].S,vec[0].F});
    ll ans=LLONG_MAX;
    ll j=0;
    for(ll i=1;i<n;i++)
    {
        ll dis=ceil(sqrt(ans));
        while(j<i && vec[j].F<vec[i].F-dis)
        {
            st.erase({vec[j].S,vec[j].F});
            j++;
        }
        auto low=st.lb({vec[i].S-dis,0});
        auto high=st.ub({vec[i].S+dis,0});
        for(auto it=low;it!=high;it++)
        {
            ans=min(ans,(vec[i].F-(*it).S)*(vec[i].F-(*it).S)+(vec[i].S-(*it).F)*(vec[i].S-(*it).F));
        }
        st.insert({vec[i].S,vec[i].F});
    }
    cout<<ans;
}