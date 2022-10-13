#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c)
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
    {
        return true;
    }
    return false;
}

string PrefixToInfix(string prefix)
{
    stack<string> s;
    for(int i=prefix.length()-1;i>=0;i--)
    {
        if(isOperand(prefix[i]))
        {
            string op(1,prefix[i]);
            s.push(op);
        }

        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string exp = "("+op1+prefix[i]+op2+")";
            s.push(exp);
        }
    }
    return s.top();
}

int main()
{
    string prefix,infix;
    cout<<"Enter PREFIX EXPRESSION :"<<endl;
    cin>>prefix;

    infix=PrefixToInfix(prefix);

    cout<<endl<<"INFIX EXPRESSION : "<<infix<<endl;
    return 0;
}