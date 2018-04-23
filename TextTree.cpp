#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct txnode {
    char text;
    int layer;
};
queue<txnode> tx;

template <class T>
class BinaryTreeNode
{
private:
    T  element;                                         //二叉树结点数据域
    BinaryTreeNode<T>*  left;                           //二叉树结点指向左子树的指针
    BinaryTreeNode<T>*  right;                          //二叉树结点指向左子树的指针
public:
    BinaryTreeNode();
    BinaryTreeNode(const T& ele);                       //给定数据的构造函数
    T  value() const;                                   //返回当前结点的数据
    void  setLeftchild(BinaryTreeNode<T>*);             //设置当前结点的左子树
    void  setRightchild(BinaryTreeNode<T>*);            //设置当前结点的右子树
    BinaryTreeNode<T>*  leftchild() const;              //返回当前结点指向左子树的指针
    BinaryTreeNode<T>*  rightchild() const;             //返回当前结点指向右子树的指针
};
template <class T>
class BinaryTree
{
private:
    BinaryTreeNode<T>*  root;                               //二叉树根结点指针
    vector<T> elements;  //用于保存遍历的元素
private:
    void Visit(T elem) {elements.push_back(elem);};  //遍历访问元素的值
    void PreOrder(BinaryTreeNode<T>* root); //从root前序遍历二叉树或其子树(递归部分)
    void InOrder(BinaryTreeNode<T>* root);  //从root中序遍历二叉树或其子树（递归部分）
    void PostOrder(BinaryTreeNode<T>* root); //从root后序遍历二叉树或其子树(递归部分)
    void DeleteBinaryTree(BinaryTreeNode<T>* root);     //递归删除二叉树或其子树
public:
    BinaryTree(){root=NULL;};                               //构造函数
    virtual ~BinaryTree(){DeleteBinaryTree(root);};            //析构函数
    void Initialize(BinaryTreeNode<T>* pointer) {root=pointer;};
    vector<T> traversePreOrder();  //从根节点前序遍历，以下依次对应
    vector<T> traverseInOrder();
    vector<T> traversePostOrder();
};

    //其父节点位于第i层
BinaryTreeNode<char>* createTree(int i) {
    BinaryTreeNode<char> *p;  //新建一个结点(此处使用局部变量有风险)
    if (tx.empty()) {
        return NULL;
    }
    txnode t=tx.front();
    if (t.layer-1 != i){
        return NULL;
    }
    if (t.text == '*'){
        tx.pop();
        return NULL;
    }
    p = new BinaryTreeNode<char>(t.text);
    tx.pop();
    p->setLeftchild(createTree(t.layer));
    p->setRightchild(createTree(t.layer));
    return p;
}

int main() {
    int n=0;
    cin >> n;
    while(n--) {
        string str;
        txnode t;
        while(cin>>str && str!="0") {
            t.layer = str.length()-1;
            t.text= str[str.length()-1];
            tx.push(t);
        }

        BinaryTree<char> tr;
        tr.Initialize(createTree(-1));

        vector<char> vPre = tr.traversePreOrder();
        for (int i=0; i<vPre.size(); i++) {
            cout << vPre[i];
        }
        cout << endl;
        vector<char> vPost = tr.traversePostOrder();
        for (int i=0; i<vPost.size(); i++) {
            cout << vPost[i];
        }
        cout << endl;
        vector<char> vIn = tr.traverseInOrder();
        for (int i=0; i<vIn.size(); i++) {
            cout << vIn[i];
        }
        cout << endl << endl;
    }
    return 0;
}

/*****************BinaryTreeNode类模板的实现************************/
template<class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
    left=right=NULL;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele) //给定数据的构造函数
{
    element=ele;
    left=right=NULL;
}

template<class T>
T  BinaryTreeNode<T>::value() const
{
    return element;
}

template<class T>
BinaryTreeNode<T>*  BinaryTreeNode<T>::leftchild() const
{
    return left;                                //返回当前结点指向左子树的指针
}

template<class T>
BinaryTreeNode<T>*  BinaryTreeNode<T>::rightchild() const
{
    return right;                               //返回当前结点指向右子树的指针
}

template<class T>
void  BinaryTreeNode<T>::setLeftchild(BinaryTreeNode<T>* subroot)//设置当前结点的左子树
{
    left=subroot;
}

template<class T>
void  BinaryTreeNode<T>::setRightchild(BinaryTreeNode<T>* subroot)//设置当前结点的右子树
{
    right=subroot;
}

/*****************BinaryTree类模板的实现************************/

template<class T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T>* root)       //递归删除二叉树或其子树
{
    if(root)
        {
        DeleteBinaryTree(root->leftchild());
        DeleteBinaryTree(root->rightchild());
        delete root;
        };
};


template<class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T>* root)               //前序遍历二叉树或其子树
{
    if(root!=NULL)
        {
        Visit(root->value());
        PreOrder(root->leftchild());            //访问左子树
        PreOrder(root->rightchild());           //访问右子树
        }
};
template<class T>
vector<T> BinaryTree<T>::traversePreOrder()
{
    elements.clear();
    PreOrder(root);
    return elements;
}

template<class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T>* root)                //中序遍历二叉树或其子树
{
    if(root!=NULL)
        {
        InOrder (root->leftchild());            //访问左子树
        Visit(root->value());           //访问当前结点
        InOrder (root->rightchild());           //访问右子树
        }
}
template<class T>
vector<T> BinaryTree<T>::traverseInOrder()
{
    elements.clear();
    InOrder(root);
    return elements;
}

template<class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T>* root)              //后序遍历二叉树或其子树
{
    if(root!=NULL)
        {
        PostOrder(root->leftchild());           //访问左子树
        PostOrder (root->rightchild());         //访问右子树
        Visit(root->value());           //访问当前结点
        }
}
template<class T>
vector<T> BinaryTree<T>::traversePostOrder()
{
    elements.clear();
    PostOrder(root);
    return elements;
}
