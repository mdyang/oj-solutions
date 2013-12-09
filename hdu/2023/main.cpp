#include<stdio.h>
#include<memory.h>
double students[50];
int details[50][5];
double courses[5];
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
    memset(students,0,sizeof(students));
    memset(details,0,sizeof(details));
    memset(courses,0,sizeof(courses));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&details[i][j]);
            // course sum
            courses[j]+=details[i][j];
            // student sum
            students[i]+=details[i][j];
        }
    }
    for(int i=0;i<m;i++)courses[i]/=n;
    for(int i=0;i<n;i++)students[i]/=m;
    int excellence=0;
    for(int i=0;i<n;i++){
        bool satisfied=true;
        for(int j=0;j<m;j++){
            if(details[i][j]<courses[j]){
                satisfied=false;
                break;
            }
        }
        if(satisfied)excellence++;
    }
    printf("%.2lf",students[0]);for(int i=1;i<n;i++)printf(" %.2lf",students[i]);
    printf("\n");
    printf("%.2lf",courses[0]);for(int i=1;i<m;i++)printf(" %.2lf",courses[i]);
    printf("\n");
    printf("%d\n\n",excellence);
    }

    return 0;
}
