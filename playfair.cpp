//In the name of Allah
#include<bits/stdc++.h>

using namespace std;


typedef vector<int> vi;
typedef vector<char> vch;
typedef pair<char,char> pch;



#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

vch ch = {'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


string J_replace( string s)
{
    for(int i = 0; i < sz(s); i++){
        if(s[i] == 'j')
            s.replace(i,1,"i");
    }
    return s;
}

string char_remove(string s, char ch2)
{
    string temp_s;
    for(int i = 0; i < sz(s); i++){
        if(s[i] != ch2)
            temp_s.pb(s[i]);
    }
    return temp_s;

}

string unique_key(string key)
{
    string new_key;
    while(!key.empty()){
        char temp_c = key[0];
        new_key.pb(temp_c);
        while(key.find(temp_c) != -1){
            key.erase(key.begin()+ key.find(temp_c));
        }
    }

    return new_key;
}

pch encryption_pair(pch p,char arr[5][5])
{
    int i1,j1,i2,j2;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(arr[i][j] == p.f){
                i1 = i;
                j1 = j;
            }
            if(arr[i][j] == p.s){
                i2 = i;
                j2 = j;
            }
        }
    }

    if(i1 == i2){
        return make_pair(arr[i1][(j1+1)%5], arr[i2][(j2+1)%5]);
    }
    else if(j1 == j2){
        return make_pair(arr[(i1+1)%5][j1], arr[(i2+1)%5][j2]);
    }
    else{
        return make_pair(arr[i1][j2], arr[i2][j1]);
    }

}

pch decryption_pair(pch p,char arr[5][5])
{
    int i1,j1,i2,j2;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(arr[i][j] == p.f){
                i1 = i;
                j1 = j;
            }
            if(arr[i][j] == p.s){
                i2 = i;
                j2 = j;
            }
        }
    }

    if(i1 == i2){
        return make_pair(arr[i1][(j1-1+5)%5], arr[i2][(j2-1+5)%5]);
    }
    else if(j1 == j2){
        return make_pair(arr[(i1-1+5)%5][j1], arr[(i2-1+5)%5][j2]);
    }
    else{
        return make_pair(arr[i1][j2], arr[i2][j1]);
    }

}

int main()
{
    string key, plain;
    cout<<"Key :";
    getline(cin,key);
    string original_key = key;
    transform(key.begin(),key.end(),key.begin(), :: tolower);    //key: up-->low
    cout<<endl<<"Message : ";
    getline(cin, plain);
    string original_plain = plain;
    transform(plain.begin(),plain.end(),plain.begin(), :: tolower); //plain: up --> low
    cout<<endl;

    key = J_replace(key);                               // replacing j with i in key
    plain = J_replace(plain);                           // replacing j with i in plain-text

    string ukey = unique_key(key);
    cout<<"Unique Key: "<<ukey<<endl<<endl;

    plain = char_remove(plain,' ');                           // space remove from plain-text

    char table[5][5];                                       // 5 x 5 table creation
    vch ch1;
    for(int i=0; i<25; i++){
        if(i < sz(ukey)){
            ch1.pb(ukey[i]);
            int indx = std::find(ch.begin(),ch.end(),ukey[i]) - ch.begin();
            ch.erase(ch.begin()+indx);
        }
        else
            ch1.pb(ch[i - sz(ukey)]);
    }

    for(int i = 0; i < 5 ; i++){
        for(int j = 0; j< 5 ;j++){
            table[i][j]=ch1[i*5+j];
        }
    }

    for(int i = 0; i < 5 ; i++){
        for(int j = 0; j< 5 ;j++){
            cout<<" "<<table[i][j]<<" ";
        }
        cout<<endl<<endl;
    }

  /// Encryption
    string cipher;
    pair<char,char> p;

    for(int i=0; i<sz(plain); i+=2){
        if(i != sz(plain)-1){
            if(plain[i] != plain[i+1]){
                p = make_pair(plain[i],plain[i+1]);
                p = encryption_pair(p,table);
                cipher.pb(p.f);
                cipher.pb(p.s);
            }
            else if(plain[i] == plain[i+1]){
                if(plain[i] != 'z'){
                    p = make_pair(plain[i],'z');
                    i = i-1;
                    p = encryption_pair(p,table);
                    cipher.pb(p.f);
                    cipher.pb(p.s);
                }
                else{
                    p = make_pair(plain[i],'x');
                    i = i-1;
                    p = encryption_pair(p,table);
                    cipher.pb(p.f);
                    cipher.pb(p.s);
                }
            }
        }

        else{
            if(plain[i] != 'z'){
                p = make_pair(plain[i],'z');
                p = encryption_pair(p,table);
                cipher.pb(p.f);
                cipher.pb(p.s);
            }
            else{
                p = make_pair(plain[i],'x');
                p = encryption_pair(p,table);
                cipher.pb(p.f);
                cipher.pb(p.s);
            }
        }
    }

    cout<<"Encryption:"<<endl<<"Plain-text: "<<original_plain<<endl<<"Cipher-text: ";
    for(int i= 0 ; i< sz(cipher); i+=2){
        cout<<cipher[i]<<cipher[i+1]<<" ";
    }
    cout<<endl<<endl;


 ///decryption
    string re_plain_txt;
    for(int i=0; i< sz(cipher) ; i+=2){
        p = make_pair(cipher[i],cipher[i+1]);
        p = decryption_pair(p,table);
        re_plain_txt.pb(p.f);
        re_plain_txt.pb(p.s);
    }
    cout<<"Decryption:"<<endl<<"Cipher-text: ";
    //for(auto u:cipher) cout<<u;
    cout<<cipher<<endl;

    //cout<<re_plain_txt<<endl;
    re_plain_txt = char_remove(re_plain_txt, 'z');          //remove z
    cout<<"Plain-text: ";
    cout<<re_plain_txt<<endl;

    return 0;
}
