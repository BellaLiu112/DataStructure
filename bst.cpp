/*
 描述
 二叉搜索树在动态查表中有特别的用处，一个无序序列可以通过构造一棵二叉搜索树变成一个有序序列，构造树的过程即为对无序序列进行排序的过程。每次插入的新的结点都是二叉搜索树上新的叶子结点，在进行插入操作时，不必移动其它结点，只需改动某个结点的指针，由空变为非空即可。

 这里，我们想探究二叉树的建立和序列输出。

 输入
 只有一行，包含若干个数字，中间用空格隔开。（数字可能会有重复）

 输出
 输出一行，对输入数字建立二叉搜索树后进行前序周游的结果。

 样例输入
 41 467 334 500 169 724 478 358 962 464 705 145 281 827 961 491 995 942 827 436
 
 样例输出
 41 467 334 169 145 281 358 464 436 500 478 491 724 705 962 827 961 942 995
 */

#include <stdio.h>
#include <iostream>
//#include <vector>
#include <cstdio>
using namespace std;

struct BSTNode{
    BSTNode *left, *right;
    int value;
    BSTNode(){left=NULL; right=NULL;};
};

class BST{
private:
    //vector<int> nums;
    BSTNode* root;
    void _insert(BSTNode* root, int number);
    void _PreOrder(BSTNode* root);
    void deleteTree(BSTNode* root);
public:
    BST(){
        root=NULL;
    };
    ~BST();
    void insert(int number);
    void PreOrder();
};

int main(int argc, char* argv[])
{
    BST bst;
    int temp;
    char ch;
    while (1) {
        cin >> temp;
        ch = cin.get();
        bst.insert(temp);
        if (ch == '\n' || cin.eof())
            break;
    }
    bst.PreOrder();
    return 0;
}

/* ************************************************************************************
 */
void BST::deleteTree(BSTNode* root)
{
    if (root->left)
        deleteTree(root->left);
    if (root->right)
        deleteTree(root->right);
    delete root;
}

BST::~BST()
{
    deleteTree(root);
}
void BST::insert(int number)
{
    if (!root) {
        root = new BSTNode;
        root->value = number;
        return;
    }
    _insert(root, number);
}
void BST::_insert(BSTNode* root, int number)
{
    if (root->value == number) {
        return;
    }
    if (number < root->value) {
        if (!root->left) {
            root->left = new BSTNode;
            root->left->value = number;
        } else {
            _insert(root->left, number);
        }
    } else {
        if (!root->right) {
            root->right = new BSTNode;
            root->right->value = number;
        } else {
            _insert(root->right, number);
        }
    }
}
void BST::PreOrder()
{
    _PreOrder(root);
    cout << endl;
}
void BST::_PreOrder(BSTNode* root)
{
    //nums.push_back(root->value);
    cout << root->value << " ";
    if (root->left)
        _PreOrder(root->left);
    if (root->right)
        _PreOrder(root->right);
}
