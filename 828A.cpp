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
        string s;
        cin>>s;
        ll f=0;
        map<ll,char>m;
        rep(i,0,n)
        {
            if(m[arr[i]])
            {
                if(m[arr[i]]!=s[i])
                {
                    f=1;
                    break;
                }
            }
            else
            m[arr[i]]=s[i];
        }
        if(f)
        PNO;
        else
        PYES;
    } 
}