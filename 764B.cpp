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
        ll a,b,c;
        cin>>a>>b>>c;
        if((a+c)%(2*b)==0 || (((2*b)-c)%a==0 && ((2*b)-c)>0)|| (((2*b)-a)%c==0 && ((2*b)-a)>0))
        PYES;
        else
        PNO;
    }
}