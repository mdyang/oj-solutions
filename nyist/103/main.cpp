#include<iostream>
#include<deque>
#include<string>
#include<cmath>
using namespace std;
typedef unsigned char uc;
// considers positive numbers only
class bigint{
    public:
        bigint();
        bigint(int);
        bigint(const string&);
        const bigint operator+(const bigint&)const;
        const bigint operator-(const bigint&)const;
        const bigint operator-=(const bigint&);
        const bigint operator*(int) const;
        const bigint operator*(const bigint&)const;
        const bigint operator/(const bigint&)const;
        const bigint operator=(const bigint&);
        const bigint operator+=(const bigint&);
        const bigint operator*=(int);
        const bigint operator*=(const bigint&);
        int operator<(const bigint&)const;
        int operator==(const bigint&)const;
        int operator<=(const bigint&)const;
        int operator>(const bigint&)const;
        int operator>=(const bigint&)const;
        friend ostream& operator<<(ostream&, const bigint&);

    protected:
        uc get_digit(int) const;
        void add_digit(uc);
        void shift();
        void clear_zero();

        // not used now
        bool _negative;
        deque<uc> _digits;
};

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        string s1,s2;
        cin>>s1>>s2;
        bigint i1(s1),i2(s2);
        cout<<"Case "<<i<<":\n"<<i1<<" + "<<i2<<" = "<<(i1+i2)<<endl;
    }
    return 0;
}

bigint::bigint(){}
bigint::bigint(int n){
    do{
        _digits.push_back(n%10);
        n/=10;
    }while(n);
}
bigint::bigint(const string& s){
    for(int i=s.size()-1;i>=0;i--)_digits.push_back(s.at(i)-'0');
}
const bigint bigint::operator+(const bigint& a) const{
    int len=max(_digits.size(),a._digits.size());
    bigint r;
    bool c=false;
    for(int i=0;i<len;i++){
        uc s=get_digit(i)+a.get_digit(i);
        if(c)s++;c=false;
        if(s>=10)c=true;
        r._digits.push_back(s%10);
    }
    if(c)r._digits.push_back(1);
    return r;
}
const bigint bigint::operator-=(const bigint& a){
    bigint r;
    r=*this-a;
    _digits=r._digits;
    return *this;
}
const bigint bigint::operator-(const bigint& a) const{
    bigint r;
    r=*this;
    bool c=false;
    int i;
    for(i=0;i<a._digits.size();i++){
        uc subtrahend=a._digits[i];
        if(c)subtrahend++;
        c=false;
        if(r._digits[i]<subtrahend){
            c=true;
            r._digits[i]=r._digits[i]+10-subtrahend;
        }
        else r._digits[i]-=subtrahend;
    }
    for(;i<r._digits.size();i++){
        if(!c)break;
        if(c){
            c=false;
            if(r._digits[i])r._digits[i]--;
            else{
                c=true;
                r._digits[i]=9;
            }
        }
    }
    r.clear_zero();
    return r;
}
const bigint bigint::operator*(int a)const{
    return this->operator*(bigint(a));
}
const bigint bigint::operator*(const bigint& a) const{
    bigint r(0);
    for(int i=0;i<a._digits.size();i++){
        bigint temp;
        for(int j=0;j<i;j++)temp._digits.push_back(0);
        uc c=0;
        for(int k=0;k<_digits.size();k++){
            int res=_digits[k]*a._digits[i]+c;
            c=res/10;
            temp._digits.push_back(res%10);
        }
        if(c)temp._digits.push_back(c);
        r+=temp;
    }
    return r;
}
const bigint bigint::operator/(const bigint& a) const{
    if (*this<a) return bigint(0);
    bigint dividend=*this;
    bigint r(0);
    bigint zero(0);
    bigint f(1);
    while((a*f)<=dividend)f*=10;
    f.shift();
    while(f>zero){
        if(f*a<=dividend){
            for(int i=9;i>0;i--){
                bigint quotient=f*i;
                bigint product=quotient*a;
                if(product<=dividend){
                    dividend-=product;
                    r+=quotient;
                    break;
                }
            }
        }
        f.shift();
    }
    return r;
}
const bigint bigint::operator=(const bigint& a){
    _digits.clear();
    for(int i=0;i<a._digits.size();i++)_digits.push_back(a._digits[i]);
    return *this;
}
// stupid implementation, could be optimized later
const bigint bigint::operator+=(const bigint& a){
    bigint bi;
    bi=*this+a;
    _digits=bi._digits;
    return *this;
}
const bigint bigint::operator*=(int a){
    return this->operator*=(bigint(a));
}
const bigint bigint::operator*=(const bigint& a){
    bigint bi;
    bi=*this*a;
    _digits=bi._digits;
    return *this;
}
int bigint::operator<(const bigint& a)const{
    if(_digits.size()<a._digits.size())return true;
    if(_digits.size()>a._digits.size())return false;
    for(int i=_digits.size()-1;i>=0;i--){
        if(_digits[i]>a._digits[i])return false;
        else if(_digits[i]<a._digits[i])return true;
    }
    return false;
}
int bigint::operator==(const bigint& a)const{
    if(_digits.size()!=a._digits.size())return false;
    for(int i=0;i<_digits.size();i++)
        if(_digits[i]!=a._digits[i])return false;
    return true;
}
// rely on < and ==
int bigint::operator<=(const bigint& a)const{
    return ((*this<a)||(*this==a));
}
int bigint::operator>(const bigint& a)const{
    return !(*this<=a);
}
int bigint::operator>=(const bigint& a)const{
    return !(*this<a);
}
ostream& operator<<(ostream& s,const bigint& a){
    for(int i=a._digits.size()-1;i>=0;i--)s<<(int)a._digits[i];
    return s;
}
uc bigint::get_digit(int d)const{
    if(d<_digits.size())return _digits[d];
    return 0;
}
void bigint::add_digit(uc d){
    _digits.push_back(d);
}
void bigint::shift(){
    if(_digits.size()>1)_digits.pop_front();
    else{
        _digits.clear();
        _digits.push_back(0);
    }
}
void bigint::clear_zero(){
    while(_digits.size()>0&&_digits.back()==0)_digits.pop_back();
}
