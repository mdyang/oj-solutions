#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
float angle_diff(float,float);
bool isok(int h,int m,int s,float diff){
    float s_angle=6*s;
    float m_angle=6*m+float(s)/60*6;
    float h_angle=30*h+float(m)/60*30+float(s)/3600*30;
    if(angle_diff(s_angle,m_angle)>=diff&&
            angle_diff(s_angle,h_angle)>=diff&&
            angle_diff(m_angle,h_angle)>=diff)return true;
    return false;
}
float angle_diff(float a,float b){
    float diff=fabs(a-b);
    if(diff>180)diff=360-diff;
    return diff;
}
int main(){
    float a;
    while(1){
        cin>>a;
        if(a<0)break;
        bool prev_ok;
        int count=0;
        for(int h=0;h<12;h++)
            for(int m=0;m<60;m++)
                for(int s=0;s<60;s++)
                    if(isok(h,m,s,a))count++;
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<float(count)/432<<endl;
    }
    return 0;
}
