//In the name Of Allah
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dl;
typedef vector<char> vch;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define PB push_back
#define endl '\n'
#define sz(x) (int)x.size()

vch ch = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main()
{
    string s;
    int shift;
    cout<<"Plain-text: ";
    getline(cin,s);
    transform(s.begin(),s.end(),s.begin(),::tolower);
    cout<<"Shift Amount (Key):";
    cin>>shift;



    //cout<<sz(ch)<<endl;

    cout<<endl;
    cout<<"Plain : ";
    for(char u:ch)
        cout<<u<<" ";
    cout<<endl;

    cout<<"Cipher: ";
    for(int i=0; i< 26; i++){
        cout<<ch[(i+shift)%26]<<" ";
    }
    cout<<endl<<endl;


    cout<<"Encryption:"<<endl;
    cout<<"Plain-Text:  "<<s<<endl;
    vch cipher_txt;
    int indx;
    for(int i = 0; i< sz(s); i++){
       if(s[i] != ' '){
            indx = std::find(ch.begin(),ch.end(),s[i]) - ch.begin();
            cipher_txt.push_back(ch[(shift+indx)%26]);
       }
        else
            cipher_txt.PB(' ');
    }

    cout<<"Cipher-text: ";
    for(char k:cipher_txt)
        cout<<k;
    cout<<endl<<endl;


    cout<<"Decryption: "<<endl;
    cout<<"Cipher-text: ";
    for(char k:cipher_txt)
        cout<<k;
    cout<<endl;

    vch plain_txt;
    for(int i=0 ; i<sz(cipher_txt); i++){
        if(cipher_txt[i] != ' '){
            indx = std::find(ch.begin(),ch.end(),cipher_txt[i]) - ch.begin();
            plain_txt.PB(ch[(indx - shift + 26) % 26]);
        }
        else
            plain_txt.PB(' ');
    }
    cout<<"Plain-Text:  ";
    for(char k:plain_txt)
        cout<<k;
    cout<<endl;

    return 0;
}
