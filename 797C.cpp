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
        ll s[n],f[n],d[n];
        rep(i,0,n)
        {
            cin>>s[i];
        }
        rep(i,0,n)
        {
            cin>>f[i];
        }
        d[0]=f[0]-s[0];
        rep(i,1,n)
        {
            if(s[i]>f[i-1])
            d[i]=f[i]-s[i];
            else
            d[i]=f[i]-f[i-1];
        }
        rep(i,0,n)
        cout<<d[i]<<" ";
        cout<<endl;
    }
}