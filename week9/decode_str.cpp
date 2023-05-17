//
// Created by 田佳业 on 2023/4/30.
//
#include<bits/stdc++.h>
using namespace std;
string str1,str2;
vector<int> ch1,ch2;
int main(){
    while(cin>>str1>>str2)
    {
        ch1.clear();
        ch2.clear();
        ch1.resize(26);
        ch2.resize(26);
        if(str1.length()!=str2.length()){
            cout<<"NO"<<endl;
            continue;
        }
        for(char i : str1){
            ch1[i-'A']++;
        }
        for(char i : str2){
            ch2[i-'A']++;
        }
//         remove elements that are 0
        ch1.erase(remove(ch1.begin(),ch1.end(),0),ch1.end());
        ch2.erase(remove(ch2.begin(),ch2.end(),0),ch2.end());
        if(ch1.size()==ch2.size()){
            sort(ch1.begin(),ch1.end());
            sort(ch2.begin(),ch2.end());
            if(ch1==ch2){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else if(ch2.size()-ch1.size()==1){
            // handle the case that replacement char occurs in the origin string
            // for example:HHHH and HEHE (replace E with H)
            // it is O(n^2) but it is ok because ch1 and ch2 are small(<=26)
            int can=0;
            for(int & i : ch2){
                //find the ch2[i] in ch1 and remove it
                auto it=find(ch1.begin(),ch1.end(),i);
                if(it!=ch1.end()){
                    ch1.erase(it);
                    i=0;
                }
                else{
                    can=i;
                }
            }
            if(ch1.size()==2&&ch1[0]+ch1[1]==can){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }

        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;

}