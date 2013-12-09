#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char buf[1024];
char standard[9];
struct node{
    char standard[9];
    int count;
    node* next;
};
node* head;
void init(){
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
}
int m[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
bool isdigit(char c){
    return (c>='0'&&c<='9');
}
bool is(char c){
    if(isdigit(c)||(c>='A'&&c<='Z')){
        return true;
    }
    return false;
}
void extract(){
    int i,j,len=strlen(buf);
    for(i=0,j=0;i<len;i++){
        if(is(buf[i])){
            if(isdigit(buf[i]))standard[j++]=buf[i];
            else standard[j++]=m[buf[i]-'A']+'0';
            if(j==3)standard[j++]='-';
        }
    }
}
void insert(node* n){
    node *newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->standard,standard);
    newnode->next=n->next;
    newnode->count=1;
    n->next=newnode;
}
void find(){
    if(head->next==NULL){
        insert(head);
        return;
    }
    node *last,*cur;
    for(last=head,cur=head->next;cur!=NULL;last=cur,cur=cur->next){
        int cmp=strcmp(standard,cur->standard);
        if(cmp<0){
            insert(last);
            return;
        }
        if(cmp==0){
            cur->count++;
            return;
        }
    }
    insert(last);
}
int main(){
    init();
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(buf);
        extract();
        find();
    }
    bool dup=false;
    for(node*cur=head->next;cur!=NULL;cur=cur->next){
        if(cur->count>1){
            dup=true;
            printf("%s %d\n",cur->standard,cur->count);
        }
    }
    if(!dup){
        printf("No duplicates.\n");
    }
    return 0;
}
