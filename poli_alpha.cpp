#include<bits/stdc++.h>

using namespace std;

typedef string str;
typedef vector<char> vch;


#define pb push_back
#define sz(x) (int)x.size()

vch alpha = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


void create_table(str key)
{
    cout<< "       a b c d e f g h i j k l m n o p q r s t u v w x y z"<<endl;
    for(int i=0; i<sz(key);i++){
        int k = std::find(alpha.begin(),alpha.end(),key[i]) - alpha.begin();
        cout<<key[i]<<" ==> ";
        for(int j =0; j<26; j++){
            cout<<" "<<alpha[k++ % 26];
        }
        cout<<endl;
    }

}



str encryption(str text, str key)
{
    str cipher;
    for(int i=0 ; i<sz(key); i++){
        int indx1 = std::find(alpha.begin(),alpha.end(),text[i]) - alpha.begin();
        int indx2 = std::find(alpha.begin(),alpha.end(),key[i]) - alpha.begin();

        cipher.pb(alpha[(indx1+indx2) % 26]);

    }

    cout<<endl<<"Encryption: "<<endl<<"Key:  "<<key<<endl<<"Cipher-text: "<<cipher<<endl<<endl;
    return cipher;
}

void decryption(str cipher, str key)
{
    str plain;
    for(int i=0 ; i<sz(key); i++){
        int indx1 = std::find(alpha.begin(),alpha.end(),cipher[i]) - alpha.begin();
        int indx2 = std::find(alpha.begin(),alpha.end(),key[i]) - alpha.begin();

        plain.pb(alpha[(indx1-indx2 + 26) % 26]);
    }

    cout<<endl<<"Decryption: "<<endl<<"Cipher-text: "<<cipher<<endl<<"Plain-text:  "<<plain<<endl;

}


int main()
{
    str plain = "holiwood";
    str key = "boliwood";
    //getline(cin,plain);
    //getline(cin,key);

    create_table(key);
    decryption(encryption(plain, key),key);

    return 0;
}
