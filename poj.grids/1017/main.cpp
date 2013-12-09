#include<stdio.h>
int main(){
    int i1,i2,i3,i4,i5,i6;
    while(1){
        scanf("%d %d %d %d %d %d",&i1,&i2,&i3,&i4,&i5,&i6);
        if((i1|i2|i3|i4|i5|i6)==0)break;
        int val=i6+i5+i4;
        val+=((i3+3)/4);
        int i2_space=i4*5;
        switch(i3%4){
            case 1:i2_space+=5;break;
            case 2:i2_space+=3;break;
            case 3:i2_space+=1;break;
        }
        if(i2>i2_space)
            val+=(((i2-i2_space)+8)/9);

        int i1_space=val*36-i6*36-i5*25-i4*16-i3*9-i2*4;
        if(i1>i1_space){
            val+=(((i1-i1_space)+35)/36);
        }
        printf("%d\n",val);
    }
    return 0;
}
