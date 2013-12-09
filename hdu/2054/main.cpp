#include<stdio.h>
#include<string.h>
char a[100000],b[100000];
char* clear(char* a){
	int len=strlen(a);
	char *end=&a[len-1];
	int i;
	bool hasdot=false;
	for(i=0;i<len;i++)if(a[i]=='.'){hasdot=true;break;}
	char sign;
	if(*a=='-'||*a=='+'){sign=*a;a++;}
	else sign='+';
	while(*a=='0'&&*a!='\0')a++;
	a--;*a=sign;
	if(hasdot)while(*end=='0'){*end='\0';end--;}
	else{end++;*end='.';end++;*end='\0';}
	return ++a;
}
int main(){
	while(scanf("%s %s",&a[1],&b[1])!=EOF){
		char*_a=clear(&a[1]),*_b=clear(&b[1]);
		printf("%s\n",(strcmp(_a,_b)?"NO":"YES"));
	}
	return 0;
}