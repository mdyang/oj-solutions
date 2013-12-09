#include<iostream>
#include<stack>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
using namespace std;
char buf[1001];
typedef enum _TYPE{
    NUM,OP,EOS
}TYPE;
string s;
int i;
TYPE nextToken(){
    if(s[i]=='=')return EOS;
    if(s[i]=='.'||(s[i]>='0'&&s[i]<='9'))return NUM;
    return OP;
}
double nextNum(){/*
    int j=0;
    while(s[i]=='.'||(s[i]>='0'&&s[i]<='9')){
        buf[j++]=s[i++];
    }
    buf[j]=0;
    return atof(buf);*/
    int j;double r;
    sscanf(&s[i],"%lf%n",&r,&j);
    i+=j;
    return r;
}
char nextOp(){
    return s[i++];
}
double calc(double n1,double n2,char op){
    switch(op){
        case '+':return n1+n2;
        case '-':return n1-n2;
        case '*':return n1*n2;
        case '/':return n1/n2;
    }
}
bool higher(char a,char b){
    switch(a){
        case '+':
        case '-':
            switch(b){
                case '+':
                case '-':return true;
                default:return false;
            }
        case '*':
        case '/':
            switch(b){
                case '+':
                case '-':
                case '*':
                case '/':
                    return true;
                default:return false;
            }
        default:return false;
    }
}
void calc_last(deque<double>&n,deque<char>&o){
    char op=o.back();o.pop_back();
    double n2=n.back();n.pop_back();
    double n1=n.back();n.pop_back();
    n.push_back(calc(n1,n2,op));
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        getline(cin,s);
//        cout<<s<<endl;
        deque<double> nums;
        deque<char> ops;
        i=0;
        TYPE next;
        while((next=nextToken())!=EOS){
            if(next==OP){
                char op=nextOp();
//                cout<<"OP:"<<op<<endl;
                if(op==')'){
                    while(ops.back()!='('){
                        calc_last(nums,ops);
                    }
                    ops.pop_back();
                    continue;
                }
                if(ops.size()>0 && higher(ops.back(),op)){
                    calc_last(nums,ops);
                    ops.push_back(op);
                }
                else{
                    ops.push_back(op);
                }
            }
            else{ 
                double n=nextNum();
//                cout<<"NUM:"<<n<<endl;
                nums.push_back(n);
            }
        }
/*        for(int j=0;j<nums.size();j++)cout<<nums[j]<<' ';
        cout<<endl;
        for(int j=0;j<ops.size();j++)cout<<ops[j]<<' ';
        cout<<endl;*/
        while(!ops.empty())calc_last(nums,ops);
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<nums.back()<<endl;
    }
    return 0;
}
