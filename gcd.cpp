#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd2(ll a, ll b)               //GCD for two values
{
    while(1){
        if(a % b == 0){
            return b;
            break;
        }
        else
            a = a % b;

        if(b % a == 0){
            return a;
            break;
        }
        else
            b = b % a;
    }
}

ll gcd3(ll a, ll b, ll c )      // GCD for three values
{
    ll temp;
    while(1){
        if( a % b == 0){
            temp = b;
            break;
        }
        else
            a = a % b;

        if(b % a == 0){
             temp = a;
             break;
        }
        else
            b = b % a;
        }

    while(1){
        if( c % temp == 0){
            return temp;
            break;
        }
        else
            c = c % temp;

        if(temp % c == 0){
             return c;
             break;
        }
        else
            temp = temp % c;
        }


}

int main()
{
    while(1){
        ll a,b,c;                                                                 // a=16, b=24, c=44
        cin>>a>>b>>c;
        cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd2(a,b)<<endl;                  //GCD for a and b

        cout<<"GCD of "<<a<<", "<<b<<" and "<<c<<" is "<<gcd3(a,b,c)<<endl;       //GCD for a, b and c

    }
    return 0;
}
