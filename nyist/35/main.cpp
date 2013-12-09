#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
int opcode(char op){
    switch(op){
        case '+':return 0;
        case '-':return 1;
        case '*':return 2;
        case '/':return 3;
        case '(':return 4;
        case ')':return 5;
        case '=':return 6;
    }
}
char preced[7][7] = {
    '>','>','<','<','<','>','>',
    '>','>','<','<','<','>','>',
    '>','>','>','>','<','>','>',
    '>','>','>','>','<','>','>',
    '<','<','<','<','<','=',' ',
    ' ',' ',' ',' ',' ',' ',' ',
    '<','<','<','<','<','<','='
};
typedef enum _TYPE{
    OP,NUM,EOS
}TYPE;
int i;
string s;
TYPE nextToken(){
    if(i==s.size())return EOS;
    if(isdigit(s[i])||s[i]=='.')return NUM;
    return OP;
}
char nextOp(){
    return s[i++];
}
double nextNum(){
    double n;
    int d;
    sscanf(&s[i],"%lf%n",&n,&d);
    i+=d;
    return n;
}
double calc(double a,double b,char ch){
    switch(ch){
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        getline(cin,s);
        stack<double> nums;
        stack<char> ops;
        ops.push('=');
        i=0;
        TYPE nt;
        while((nt=nextToken())!=EOS){
            switch(nt){
                case OP:
                    {
                        char op=nextOp();
//                        cout<<ops.top()<<' '<<op<<endl;
                        switch(preced[opcode(ops.top())][opcode(op)]){
                            case '>':{
                                double n2=nums.top();nums.pop();
                                double n1=nums.top();nums.pop();
                                double n=calc(n1,n2,ops.top());
                                ops.pop();
                                nums.push(n);
                                i--;
                                     }
                                break;
                            case '<':
                                ops.push(op);break;
                            case '=':
                                ops.pop();
                        }
                    }
                    break;
                case NUM:
                    {
                        double num=nextNum();
//                        cout<<num<<endl;
                        nums.push(num);
                    }
            }
        }
        printf("%.2lf\n",nums.top());
    }
    return 0;
}
