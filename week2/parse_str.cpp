#include<bits/stdc++.h>
using namespace std;
int len;
string s;
void parse(int i)
{
    if(i==len||s[i]==']')
        return;
    if(s[i]=='[')
    {
        i++;
        int num=0;
        while(s[i]>='0'&&s[i]<='9')
        {
            num=num*10+s[i]-'0';
            i++;
        }
        // if s[i] is a letter, it will print num times until meets ]
        // else if it is a [, it will call parse(i) recursively
        while(num--)
        {
            parse(i);
        }
        //now we should jump to the back of matching ]
        int lb=1;
        while(lb)
        {
            if(s[i]=='[')
            {
                lb++;
            }
            else if(s[i]==']')
            {
                lb--;
            }
            //do nothing if it is a letter because we have handled it recursively
            i++;
        }
        parse(i);
    }
    else{
        // is a letter
        while(s[i]>='A'&&s[i]<='Z')
        {
            cout<<s[i];
            i++;
        }
        parse(i);
    }
}
int main()
{
    cin>>s;
    len=s.length();
    parse(0);

}