#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        cin>>arr[i];
        vector<ll>one,zero;
        rep(i,0,n)
        {
            if(arr[i]==1)
            one.push_back(i);
            else
            zero.push_back(i);
        }
        if(is_sorted(arr,arr+n))
        cout<<"0\n";
        else
        {
            ll ans=0,c=zero.size();
            rep(i,0,n)
            {
                if(arr[i]==0)
                {
                    c--;
                }
                else{
                    if(c>0)
                    ans++;
                    c--;
                }
            }
            cout<<ans<<endl;
        }
    } 
}