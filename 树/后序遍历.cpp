/*
每个节点的第一个儿子是child，后面的儿子通过child后面sibling添加
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
    int nodeID;
    TreeNode *child = nullptr;
    TreeNode *sibling = nullptr;//链表连接子节点们
    TreeNode(){}
    TreeNode(int id){
        nodeID=id;
    }
    void addChild(TreeNode *);
    void addSibling(TreeNode *);
    void postOrderTraversal(TreeNode *root);
};
void TreeNode::addChild(TreeNode *node){
    if(this->child!=NULL){
        this->child->addSibling(node);
    }
    else this->child=node;//设定第一个儿子为child 
}

void TreeNode::addSibling(TreeNode *node){
    TreeNode *p=this;
    while (p->sibling){
        p=p->sibling;
    }
    p->sibling=node;
    
}

void TreeNode::postOrderTraversal(TreeNode *root){
    if(root->child==NULL){
        cout<<root->nodeID<<' ';
        return;
    }
    TreeNode *p=root->child;
    postOrderTraversal(p);
    while(p->sibling){
        postOrderTraversal(p->sibling);
        p=p->sibling;
    }
    cout<<root->nodeID<<' ';
}
int main(){
    TreeNode *root=new TreeNode(1);
    TreeNode *a=new TreeNode(2);
    TreeNode *b=new TreeNode(3);
    root->addChild(a);
    root->addChild(b);
    a->addChild(new TreeNode(4));
    a->addChild(new TreeNode(5));
    b->addChild(new TreeNode(6));
    b->addChild(new TreeNode(7));
    root->postOrderTraversal(root);
}
