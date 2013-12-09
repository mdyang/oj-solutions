#include<deque>
#include<string>
#include<iostream>
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
