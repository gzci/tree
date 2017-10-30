#include<iostream>
using namespace std;
class tree{
	private:
		int data;
		tree* leftchild=NULL;
		tree* rightchild=NULL;
	public:
		tree(){
		}
		tree(int data,tree* leftchild,tree* rightchild){
			this->data=data;
			this->leftchild=leftchild;
			this->rightchild=rightchild;
			
		}
		tree* insert(int x,tree*s );
		void preorder(tree *s);
		tree* swap(tree *s);
}; 
tree* tree::insert(int x,tree* p){
	
	if(!p){
		p=new tree(x,NULL,NULL);
	}else{
		if(x<p->data) p->leftchild=insert(x,p->leftchild);
		else if(x>p->data) p->rightchild=insert(x,p->rightchild);
		
		
			
		return p;
		
	}
}

void tree::preorder(tree *s){
	if(s) {
		cout<<s->data;
		preorder(s->leftchild);
		preorder(s->rightchild);	
	}
	
	
}
tree* tree::swap(tree *s){
	tree *temp=NULL;
		if(s->leftchild&&s->rightchild) {
//			cout<<"you "<<s->rightchild<<"zuo "<<s->leftchild<<endl;
			temp=s->rightchild;
			s->rightchild=s->leftchild;
			s->leftchild=temp;
//			cout<<"you "<<s->rightchild<<"zuo "<<s->leftchild<<endl; 
		swap(s->leftchild);
		swap(s->rightchild);	
	}
	
}
int main(){
	int a;
	tree *s=NULL;
	while(cin>>a)
	s=s->insert(a,s);
	cin.clear();
	s->preorder(s);
	s->swap(s);
	s->preorder(s);
	
}
