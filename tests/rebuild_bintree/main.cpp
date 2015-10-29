#include<fstream>
#include<iostream>
#include<string>

using namespace std;

typedef struct _node{
    char i;
    _node* l;
    _node* r;
}node;

void inorder(node* n);
void preorder(node* n);
void postorder(node* n);

node* rebuild_inpre(string& _in,string& _pre);

node* rebuild_inpost(string& _in,string& _post);

int main(){
    string a,b;
    ifstream fin_inpre("inpre");
    ifstream fin_inpost("inpost");

    while(fin_inpre>>a>>b){
        node* n=rebuild_inpre(a,b);
        preorder(n);
        cout<<endl;
        inorder(n);
        cout<<endl;
        postorder(n);
        cout<<endl;
    }

    while(fin_inpost>>a>>b){
        node* n=rebuild_inpost(a,b);
        preorder(n);
        cout<<endl;
        inorder(n);
        cout<<endl;
        postorder(n);
        cout<<endl;
    }

    fin_inpre.close();
    fin_inpost.close();
    return 0;
}

int get_node_idx(string& _s, char c)
{
	for (int i = 0; i < _s.size(); i ++)
		if (_s.at(i) == c) return i;
	return -1;
}

node* rebuild_inpre(string& _in,int _inL,int _inR,string& _pre,int& _preIdx){
	if (_inL >= _inR || _preIdx >= _pre.size()) return NULL;
	node* n = new node;
	char c = _pre.at(_preIdx++);
	n->i = c;
	int idx = get_node_idx(_in, c);
	n->l = rebuild_inpre(_in, _inL, idx, _pre, _preIdx);
	n->r = rebuild_inpre(_in, idx + 1, _inR, _pre, _preIdx);
	return n;
}

node* rebuild_inpre(string& _in, string& _pre){
	int preIdx = 0;
	return rebuild_inpre(_in, 0, 8, _pre, preIdx);
}

node* rebuild_inpost(string& _in,int _inL, int _inR,string& _post,int& _postIdx){
	if (_inL >= _inR || _postIdx < 0) return NULL;
	node* n = new node;
	char c = _post.at(_postIdx--);
	n->i = c;
	int idx = get_node_idx(_in, c);
	n->r = rebuild_inpost(_in, idx + 1, _inR, _post, _postIdx);
	n->l = rebuild_inpost(_in, _inL, idx, _post, _postIdx);
	return n;
}

node* rebuild_inpost(string& _in,string& _post){
	int postIdx = 7;
	return rebuild_inpost(_in, 0, 8, _post, postIdx);
}

void inorder(node* n){
	if (n == NULL) return;
    inorder(n->l);
    cout<<n->i<<' ';
    inorder(n->r);
}

void preorder(node* n){
	if (n == NULL) return;
    cout<<n->i<<' ';
    preorder(n->l);
    preorder(n->r);
}

void postorder(node* n){
	if (n == NULL) return;
    postorder(n->l);
    postorder(n->r);
    cout<<n->i<<' ';
}
