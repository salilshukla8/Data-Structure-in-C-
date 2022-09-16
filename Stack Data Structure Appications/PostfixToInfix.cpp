#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c)
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}


string PostfixToInfix(string postfix)
{
    stack<string> s;
    for(int i=0;i<postfix.length();i++)
    {
        if(isOperand(postfix[i]))
        {
            string op(1,postfix[i]);
            s.push(op);
        }

        else
        {
            string op1=s.top();
            s.pop();
            string op2=s.top();
            s.pop();
            string exp = "("+op2+postfix[i]+op1+")";
            s.push(exp);
        }
    }
    return s.top();
}

int main()
{
    string postfix,infix;
    cout<<"ENTER A POSTFIX EXPRESSION : "<<endl;
    cin>>postfix;
    
    cout<<"POSTFIX EXPRESSION : "<<postfix<<endl;

    infix=PostfixToInfix(postfix);

    cout<<endl<<"INFIX EXPRESSION : "<<infix<<endl;
    return 0;
}