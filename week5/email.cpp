//
// Created by 田佳业 on 2023/4/1.
//
#include<bits/stdc++.h>
using namespace std;
string u,h,r;
bool char_valid(char c){
    if(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9'||c=='_'){
        return true;
    }
    else{
        return false;
    }
}
bool resource(){
   if(r.length()==0){
       return false;
   }
   if(!all_of(r.begin(),r.end(),char_valid)){
       return false;
   }
   return true;
}
bool username(){
    if(u.length()==0||u.length()>16){
        return false;
    }
    if(!all_of(u.begin(),u.end(),char_valid)){
        return false;
    }
    return true;
}
bool hostname(){
    int h_len=h.length();
    if(h_len==0||h_len>32){
        return false;
    }
    int p_dot=-1;
    for(int i=0;i<h_len;i++){
        if(h[i]=='.'){
            if(i-p_dot>17||i-p_dot==1){
                return false;
            }
            p_dot=i;
        }
        else if(!char_valid(h[i])){
            return false;
        }
    }
    if(h_len-p_dot>17||h_len-p_dot==1){
        return false;
    }
    return true;

}
int main()
{
    string s;
    cin>>s;
    int p_at=s.find('@');
    int p_bar=s.find('/');
    if(p_at==string::npos){
        cout<<"NO";
        return 0;
    }
    u=s.substr(0,p_at);
    if(p_bar==string::npos){
        h=s.substr(p_at+1);
    }
    else{
        h=s.substr(p_at+1,p_bar-p_at-1);
        r=s.substr(p_bar+1);
        if(!resource()){
            cout<<"NO";
            return 0;
        }
    }
    if(!username()||!hostname())
    {
        cout<<"NO";
        return 0;
    }
    else{
        cout<<"YES";
        return 0;
    }

}