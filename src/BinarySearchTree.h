/*
 * BinarySearchTree.h
 *
 *  Created on: Oct 30, 2017
 *      Author: fatma.serce
 *      Modified: sean.hardin 11/23/17
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node<T>* left;
	node<T>* right;
};

template <class T>
class BinarySearchTree{
private:
	node<T>* root;
	void inOrderT(node<T>*);
	int inOrderStop(node<T>*, T item);//method to implement filter
	void preOrderT(node<T>*);
	void postOrderT(node<T>*);
	void destroy(node<T>*);
	int treeHeight(node<T>*);
	int max(int, int);
	int treeNodeCount(node<T>*);
	int treeLeaveCount(node<T>*);
	void treeInsert(node<T>*&, T&);
	T treeSearch(node<T>*, T&);//modified to be able to check if found in the code
	node<T>* findMax(node<T>*);
	bool deletenode(node<T>*&, T&);

public:
	BinarySearchTree();
	node<T>* getRoot(){return root;}
	void inOrder(){inOrderT(root);}
	int inOrderStop(T item){return inOrderStop(root, item);}//calls private function to work recursively
	void preOrder(){preOrderT(root);}
	void postOrder(){postOrderT(root);}
	int height(){return treeHeight(root);}
	int nodeCount(){return treeNodeCount(root);}
	int leaveCount(){return treeLeaveCount(root);}
	void insert(T& item){treeInsert(root, item);}
	T search(T& item){return treeSearch(root,item);}//also modified to return item to check if found
//	void insert(T&); //non-recursive function call
	node<T>* findMax(){return findMax(root);}
	bool deleteNode(T& item){return deletenode(root, item);}
	~BinarySearchTree(){destroy(root);}

};

template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	root = NULL;
}


template <class T>
void BinarySearchTree<T>::inOrderT(node<T>* p){
	if(p!=NULL){
		inOrderT(p->left);
		cout<<p->data;
		inOrderT(p->right);
	}
}

template <class T>//same as inorderTraversal, but stops when it finds the filter value
int BinarySearchTree<T>::inOrderStop(node<T>* p, T item){
	if(p!=NULL){
		int count = 0;//used to find how many contacts were traversed in the filter
		count += inOrderStop(p->left, item);//count contacts printed in left branch
		if (p->data >= item)
			return count;//pass number from left branch up when match is found
		cout<<p->data;
		count++;//increment count once data is printed
		count += inOrderStop(p->right, item);//count contacts in right branch printed
		return count;//the sum of left branch, this node, and right branch returned
	} else return 0;//null nodes not counted so they return 0
}

//inorder traversal without recursion
//template <class T>
//void BinarySearchTree<T>::inOrderT(node<T>* p){
//	stack< node<T>* > s;
//	while(p!= NULL || !s.isEmpty())
//	if(p!= NULL){
//		s.push(p);
//		p = p->left;
//	}else{
//		p = s.pop();
//		cout<<p->data:
//		p = p->right;
//	}
//}

template <class T>
void BinarySearchTree<T>::preOrderT(node<T>* p){
	if(p!=NULL){
		cout<<p->data;
		preOrderT(p->left);
		preOrderT(p->right);
	}
}

template <class T>
void BinarySearchTree<T>::postOrderT(node<T>* p){
	if(p!=NULL){
		postOrderT(p->left);
		postOrderT(p->right);
		cout<<p->data;
	}
}
template <class T>
int BinarySearchTree<T>::max(int x, int y){
	if (x>y)
		return x;
	return y;
}

template <class T>
int BinarySearchTree<T>::treeHeight(node<T>* p){
	if(p!=NULL){
		return 1 + max(height(p->left, p->right));
	}
	return 0;
}

template <class T>
int BinarySearchTree<T>::treeNodeCount(node<T>* p){
	if(p==NULL)
		return 0;
	else
		return 1 + treeNodeCount(p->left) + treeNodeCount(p->right);
}
template <class T>
int BinarySearchTree<T>::treeLeaveCount(node<T>* p){
	if(p==NULL)
		return 0;
	else if(p->left==NULL && p->right==NULL)
		return 1;
	else
		return treeLeaveCount(p->left) + treeLeaveCount(p->right);
}
template <class T>
void BinarySearchTree<T>::destroy(node<T>* p){
	if(p!= NULL){
		destroy(p->left);
		destroy(p->right);
		delete p;
		p= NULL;
	}
}
//non recursive insert function
//template <class T>
//void BinarySearchTree<T>::insert(T& item){
//	node<T>* newnode = new node<T>();
//	newnode->data = item;
//	newnode->left = newnode->right = NULL;
//	if(root == NULL){
//		root = newnode;
//	}
//	else{
//		node<T>* p = root;
//		node<T>* q;
//		while(p!=NULL){
//			q = p;
//			if(item==p->data){
//				cout<<p->data;
//				cout<<"error"<<endl;
//				return;
//			}
//			else if (item<p->data)
//				p = p->left;
//			else
//				p = p->right;
//		}
//		if(item<q->data)
//			q->left = newnode;
//		else
//			q->right = newnode;
//	}
//
//}
template <class T>
void BinarySearchTree<T>::treeInsert(node<T>*& p, T& item){
	if(p == NULL){
		p = new node<T>;
		p->data = item;
		p->left = p->right = NULL;
	}
	else if(item<p->data){
		treeInsert(p->left, item);
	}else{
		treeInsert(p->right, item);
	}

}

template <class T>//only changed return type and made it return 2 things
T BinarySearchTree<T>::treeSearch(node<T>* p, T& item){
	if(p == NULL)
		return item;//returns passed item if no match found (has no phone data)
	else if(item<p->data)
		return treeSearch(p->left, item);
	else if(item>p->data)
		return treeSearch(p->right, item);
	return p->data;//returns full item if it is found in tree
}

template <class T>
node<T>* BinarySearchTree<T>::findMax(node<T>* p){
	if (p==NULL)
		return NULL;
	else if(p->right == NULL)
		return p;
	else
		return findMax(p->right);
}

template <class T>
bool BinarySearchTree<T>::deletenode(node<T>*& p, T& item){
	bool deleted = 0;
	//item not found, do nothing
	if(p == NULL)
		return 0;
	else if (item<p->data)	//item is on the left subtree
		deleted = deletenode(p->left, item);
	else if (item>p->data)	//item is on the right subtree
		deleted = deletenode(p->right, item);
    else{//item is equal to data,  it is found
    	deleted = 1;
		if(p->left!= NULL && p->right != NULL){	//if it is with two children
			p->data = findMax(p->left)->data;
			deletenode(p->left, p->data);
		}else{
			node<T>* old = p;
			if(p->left != NULL)
				p = p->left;
			else
				p = p->right;

			delete old;
		}
	}
	return deleted;
}



#endif /* BINARYSEARCHTREE_H_ */
