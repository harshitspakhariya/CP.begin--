#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n+1)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/((fact(r))*(fact(n-r))));
}
ll power(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        result*=a;
        a*=a;
        b/=2;
    }
    return result;
}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
 
bool isPrime(ll n)
{
    if(n<=1)
    return false;
    if(n<=3)
    return true;

    if(n%2==0 || n%3==0 || n%5==0)
    return false;
    for(ll i=6;i<=sqrt(n);i+=5)
    {
        //for (ll i=5;i*i<=n;i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;//return true;
    }
    return true;
}

vector<ll> printDivisors(int n)
{
	// Note that this loop runs till square root
    vector<ll>req;
	for (int i=1; i<=sqrt(n); i++)
	{
		if (n%i == 0)
		{
			// If divisors are equal, print only one
			if (n/i == i)
				req.push_back(i);

			else // Otherwise print both
				{
                    req.push_back(i);
                    req.push_back(n/i);
                }
		}
	}
    return req;
}
int solve(vector<vector<string>>A)
{
    int n=A.size(),i=0,ans=0;
    map<string,multiset<int>>m;
    for(i=0;i<n;i++)
    {
        m[A[i][0]].insert(stoi(A[i][1]));
    }
    map<string,int>finalmarks;
    for(auto x:m)
    {
        int sum=0;
        for(auto y:x.second)
        {
            sum+=y;
        }
        finalmarks[x.first]=sum/x.second.size();
    }
    ans=0;
    for(auto x:finalmarks)
    {
        ans=max(ans,x.second);
    }
    return ans;
}
int main()
{
    int x=solve({{"nfa", "97"},{"nfa", "97"},{"nfa", "32"},{"nfa", "67"},{"nfa", "80"},{"nfa", "20"},{"nfa", "43"}});
    cout<<x;
}   