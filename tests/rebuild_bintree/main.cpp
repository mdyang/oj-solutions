#include<fstream>

using namespace std;

typedef struct _node{
    int i;
    _node* l;
    _node* r;
}node;

void inorder(node* n);
void preorder(node* n);
void postorder(node* n);

node* rebuild_inpre(string& _pre,string& _in);

node* rebuild_inpost(string& _in,string& _post);

int main(){
    string a,b;
    ifstream fin_inpre("inpre");
    ifstream fin_inpost("inpost");

    while(fin_inpre>>a>>b){
        node* n=rebuild_inpre(a,b);
        inorder(n);
        cout<<endl;
        preorder(n);
        cout<<endl;
        postorder(n);
        cout<<endl;
    }

    while(fin_inpost>>a>>b){
        node* n=rebuild_inpost(a,b);
        inorder(n);
        cout<<endl;
        preorder(n);
        cout<<endl;
        postorder(n);
        cout<<endl;
    }

    fin_inpre.close();
    fin_inpost.close();
    return 0;
}

node* rebuild_inpre(string& _pre,int _preL,int _preR,int _inL,int _inR){

}

node* rebuild_inpre(string& _pre,string& _in){

}

node* rebuild_inpost(string& _in,string& _post){
}

void inorder(node* n){
    inorder(n->l);
    cout<<n->i<<' ';
    inorder(n->r);
}

void preorder(node* n){
    cout<<n->i<<' ';
    preorder(n->l);
    preorder(n->r);
}

void postorder(node* n){
    postorder(n->l);
    postorder(n->r);
    cout<<n->i<<' ';
}
