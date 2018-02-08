#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node * left, * right;
}*root=NULL;
struct Node *newnode_fun(int val){
	struct Node * temp=new Node;
	temp->data=val;
	temp->left=temp->right=NULL;
	return temp;
}
void insert(Node * temp,int val){ 
	if(temp==NULL)
		return;
	queue<struct Node *>q;
	q.push(temp);
	while(q.empty()==false){
		struct Node * temp2=q.front();
		q.pop();
		if(temp2->left==NULL){
			temp2->left=newnode_fun(val);
			break;
		}
		else
			q.push(temp2->left);
		if(temp2->right==NULL){
			temp2->right=newnode_fun(val);
			break;
		}
		else
			q.push(temp2->right);
	}
}
void level_order(Node * root){
	if(root==NULL)
		return;
	int count=0,max=INT_MIN;
	queue<struct Node *>q;
	q.push(root);
	while(q.empty()==false){
		struct Node * temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->data>max)
			max=temp->data;
		count++;
		if(temp->left!=NULL)			
			q.push(temp->left);	
		if(temp->right!=NULL)
			q.push(temp->right);
	}
	cout<<"\n Number of Nodes "<<count+1;
	cout<<"\n Max element "<<max;
}
void preorder(Node * root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(Node * root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void postorder(Node * root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}
int main(){
	freopen("input.txt","r",stdin);
	root=newnode_fun(10);
	insert(root,20);
	insert(root,30);
	insert(root,40);
	insert(root,50);
	insert(root,60);
	insert(root,70);
	cout<<" Preorder : ";
	preorder(root);
	cout<<"\n";
	cout<<" Inorder : ";
	inorder(root);
	cout<<"\n";
	cout<<" Postorder : ";
	postorder(root);
	cout<<"\n";
	cout<<"Level Order : ";
	level_order(root);
}

