#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int call(ll val, ll pow, ll mod)
{
    ll temp = 1;
    for(int i= 0; i < pow; i++){
        temp *= val;
        temp = temp % mod;
    }
    return temp % mod;
}

int main()
{
    ll p,q,n,y,e,d;
    cout<<"Enter two prime number:"<<endl;
    cin>>p>>q;

    n = p*q;
    y = (p-1)*(q-1);

    cout<<"e = ";
    for(ll i = 2; i<y; i++){
        if((__gcd(i,y) ) == 1)
            cout<<" "<<i;
    }

    cout<<endl<<"Enter e : "<<endl;
    cin>>e;

    for( ll  i=2; ;i++){
        if((i*e) % y == 1){
            d = i;
            break;
        }
    }

    cout<<"Public_Key = { "<<e<<", "<<n<< " }"<<endl<<"Private_Key = { "<<d<<", "<<n<<" }"<<endl;

    unsigned long long   m,c;
    cout<<"Enter message as a number: ";
    cin>>m;

    cout<<endl<<"Encryption:"<<endl;
    c = call(m,e,n);
    cout<<"Cipher: "<<c<<endl<<endl;

    cout<<"Decryption: "<<endl;
    m = call(c,d,n);
    cout<<"Message: "<<m<<endl;


    return 0;

}
