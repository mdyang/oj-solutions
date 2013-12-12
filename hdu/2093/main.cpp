#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<algorithm>
using namespace std;
typedef struct _p{
	char name[11];
	int solved;
	int time;
}p;
p people[128];
char temp[16];
int n,m;
bool operator<(p&a1,p&a2){
	if(a1.solved==a2.solved){
		if(a1.time==a2.time){
			return !strcmp(a1.name,a2.name);
		}
		return a1.time<a2.time;
	}
	return a1.solved>a2.solved;
}
void process(p& pep){
	if(temp[0]=='-'||temp[0]=='0')return;
	pep.solved++;
	int i=0,time=temp[i]-'0',len=strlen(temp);
	while(++i<len&&temp[i]!='(')time=time*10+temp[i]-'0';
	pep.time+=time;
	if(i<len){
		i++;
		time=temp[i]-'0';
		while(temp[++i]!=')')time=time*10+temp[i]-'0';
		pep.time+=(time*m);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	memset(people,0,sizeof(people));
	int i;
	for(i=0;scanf("%s",people[i].name)!=EOF;i++){
		for(int j=0;j<n;j++){
			scanf("%s",temp);
			process(people[i]);
		}
	}
	sort(people,people+i);
	for(int j=0;j<i;j++){
		printf("%-10s %2d %4d\n",people[j].name,people[j].solved,people[j].time);
	}
	
	return 0;
}