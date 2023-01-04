/*1.Evaluate Reverse Polish Notation
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for(string n:tokens)
        {
            if(n=="+" || n=="-" || n=="*" || n=="/")
            {
                long long p=s.top();
                s.pop();
                long long q=s.top();
                s.pop();
                long long r;
                if(n=="+")
                    r=p+q;
                else if(n=="-")
                    r=q-p;
                else if(n=="*")
                    r=p*q;
                else if(n=="/")
                    r=(q/p);


                s.push(r);
            }
            else
            {
                long long y=stoll(n);
                s.push(y);
            }
        }
        return s.top();
    }
};
