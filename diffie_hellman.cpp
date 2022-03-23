#include<bits/stdc++.h>

using namespace std;

typedef string str;
typedef long long ll;
typedef vector<int> vi;
typedef vector<str> vs;

#define pb push_back
#define sz(x) (int)x.size()

int call(ll val, ll pow, ll mod)
{
    ll temp = 1;
    for(int i= 0; i < pow; i++){
        temp *= val;
        temp = temp % mod;
    }
    return temp % mod;
}

vi primitive_root(int n)
{
    vi p_root;
    for(int a = 2; a< n;a++){
        vi temp;

        for(int j =1; j < n; j++){
            temp.pb(call(a,j,n));
        }

        int counter = 0;
        sort(temp.begin(),temp.end());
        for(int i = 0; i<n-2; i++){
            if(temp[i] != temp[i+1]){
                counter++;
            }
        }
        if(counter == n-2){
            p_root.pb(a);
        }
    }
     return p_root;
}

int main()
{
    int q;
    ll a,xa,xb,ya,yb,ka,kb;
    cout<<"Enter a prime number: ";
    cin>>q;

    vi p_root = primitive_root(q);
    for(auto u: p_root)
        cout<<" "<<u<<" ";
    cout<<endl<<endl;

    cout<<"Enter a: "<<endl;
    cin>>a;
    cout<<"Enter XA: "<<endl;
    cin>>xa;
    cout<<"Enter XB: "<<endl;
    cin>>xb;

    ya = call(a,xa,q);
    yb = call(a,xb,q);

    ka = call(yb,xa,q);
    kb = call(ya,xb,q);

    cout<<"User A Key Generation: "<<ya<<endl;
    cout<<"User B Key Generation: "<<yb<<endl;
    cout<<"Secret Key by User A: "<<ka<<endl;
    cout<<"Secret Key by User A: "<<kb<<endl;

    return 0;
}
