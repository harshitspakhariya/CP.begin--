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
        ll n,i;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        cin>>arr[i];
        if(is_sorted(arr,arr+n))
        {
            rep(i,0,n)
            cout<<1<<" ";
            cout<<endl;
        }
        else{
            ll c=0,f=0;
            map<ll,ll>m1,m2;
            rep(i,0,n)
            {
                m1[arr[i]]=i+1;
            }
            rep(i,0,n)
            {
                cout<<m1[n-i]<<" ";
            }
            cout<<endl;
        }
    } 
}