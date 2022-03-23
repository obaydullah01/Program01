#include<bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef double dl;
typedef vector<char> vch;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;

#define PB push_back
#define endl '\n'
#define sz(x) (int)x.size()

int main()
{
    string s;
    cout<<"Plain-text: ";
    getline(cin,s);
    transform(s.begin(),s.end(),s.begin(), :: tolower);


    vch ch = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    vch key= {'q','a','w','z','s','e','x','d','r','c','f','t','v','g','y','b','h','u','n','j','i','m','k','o','l','p'};

    cout<<"Alphabet: ";
    for(char k: ch)
        cout<<k<<" ";
    cout<<endl;

    cout<<"Key     : ";
    for(char k: key)
        cout<<k<<" ";
    cout<<endl<<endl;



    cout<<"Encryption:"<<endl;
    int indx;
    vch cipher;
    for(int i=0; i<sz(s); i++){
        if(s[i] != ' '){
            indx = std::find(ch.begin(),ch.end(),s[i]) - ch.begin();
            cipher.PB(key[indx]);
        }

        else
            continue;
            //cipher.PB(' ');

    }
    cout<<"Plain-text:  ";
    cout<<s<<endl;
    cout<<"Cipher-text: ";
    for(char u:cipher)
        cout<<u;
    cout<<endl<<endl;

    cout<<"Decryption:"<<endl;
    cout<<"Cipher-text: ";
    for(char u:cipher)
        cout<<u;
    cout<<endl;

    vch plain;
    for(int i = 0; i<sz(cipher);i++){
        if(cipher[i] != ' '){
            indx = std::find(key.begin(),key.end(),cipher[i]) - key.begin();
            plain.PB(ch[indx]);
        }

        //else
        //    plain.PB(' ')
        }
        cout<<"Plain-text:  ";
        for(char u:plain)
            cout<<u;
        cout<<endl;

    return 0;
}
