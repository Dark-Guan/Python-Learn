#include<iostream>
using namespace std;
 
//二叉树结点定义
struct BinaryTreeNode
{
	int Value;
	BinaryTreeNode* Left;
	BinaryTreeNode* Right;
};
 
//创建二叉树结点
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->Value = value;
	pNode->Left = NULL;
	pNode->Right = NULL;
	return pNode;
}
 
//连接树结点
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != NULL)
	{
		pParent->Left = pLeft;
		pParent->Right = pRight;
	}
}
 
//中序遍历
void InOrderPrintTree(BinaryTreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		//遍历左边
		if (pRoot->Left != NULL)
		{
			InOrderPrintTree(pRoot->Left);
		}
		//根
		cout << "value of this node is " << pRoot->Value << endl;
		//遍历右边
		if (pRoot->Right != NULL)
		{
			InOrderPrintTree(pRoot->Right);
		}
 
	}
	else
	{
		cout << "this node is null." << endl;
	}
 
}
 
//转换排序二叉树为双向链表
void Convert(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeLnList)
{
	if (pNode == NULL)
	{
		return;
	}
 
	BinaryTreeNode* pCurrent = pNode;
 
	//左子树转换，遍历到左子树的叶子结点
	if (pCurrent->Left != NULL)
	{
		Convert(pCurrent->Left, pLastNodeLnList);
	}
	pCurrent->Left = *pLastNodeLnList;
	if ((*pLastNodeLnList) != NULL)
	{
		(*pLastNodeLnList)->Right = pCurrent;
	}
	*pLastNodeLnList = pCurrent;
 
	//右子树转换
	if (pCurrent->Right != NULL)
	{
		Convert(pCurrent->Right, pLastNodeLnList);
	}
 
}
 
//获取双向链表头结点
BinaryTreeNode* Convert(BinaryTreeNode* pRoot)
{
	//指向双向链表的尾结点
	BinaryTreeNode* pLastNodeInList = NULL;
	//转换排序二叉树为双向链表
	Convert(pRoot, &pLastNodeInList);
 
	//求双向链表的头结点
	BinaryTreeNode* pHeadOfList = pLastNodeInList;
	while (pHeadOfList!=NULL&&pHeadOfList->Left!=NULL)
	{
		pHeadOfList = pHeadOfList->Left;
	}
	return pHeadOfList;
}
 
//打印双向链表
void PrintList(BinaryTreeNode* pRoot)
{
	BinaryTreeNode* pNode = pRoot;
 
	while (pNode!=NULL)
	{
		cout << pNode->Value << "    ";
		pNode = pNode->Right;
	}
 
	cout << endl;
	cout << "PrintList ends." << endl << endl;
 
}
 
 
// ====================测试代码====================
void Test1()
{
//                 10
//              /      \
//            6        14
//           /\        /  \
//          4  8      12  16
 
	cout << "The Test1:" << endl;
 
   //创建树结点
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);
 
	//连接树结点
	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);
 
	//中序遍历
	InOrderPrintTree(pNode10);
	//获取双向链表头结点
	BinaryTreeNode* pHeadOfList = Convert(pNode10);
	//输出链表
	PrintList(pHeadOfList);
 
}
 
void Test2()
{
	//               5
	//              /
	//             4
	//            /
	//           3
	//          /
	//         2
	//        /
	//       1
 
	cout << "The Test2:" << endl;
    //创建树结点
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	
	//连接树结点
	ConnectTreeNodes(pNode5, pNode4,NULL);
	ConnectTreeNodes(pNode4, pNode3, NULL);
	ConnectTreeNodes(pNode3, pNode2, NULL);
	ConnectTreeNodes(pNode2, pNode1, NULL);
 
	//中序遍历
	InOrderPrintTree(pNode5);
	//获取双向链表头结点
	BinaryTreeNode* pHeadOfList = Convert(pNode5);
	//输出链表
	PrintList(pHeadOfList);
 
}
 
void Test3()
{
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
 
	cout << "The Test3:" << endl;
    //创建树结点
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	
	//连接树结点
	ConnectTreeNodes(pNode1, NULL, pNode2);
	ConnectTreeNodes(pNode2, NULL, pNode3);
	ConnectTreeNodes(pNode3, NULL, pNode4);
	ConnectTreeNodes(pNode4, NULL, pNode5);
 
	//中序遍历
	InOrderPrintTree(pNode1);
	//获取双向链表头结点
	BinaryTreeNode* pHeadOfList = Convert(pNode1);
	//输出链表
	PrintList(pHeadOfList);
 
}
 
void Test4()
{
  // 树中只有1个结点
 
	cout << "The Test4:" << endl;
   //创建树结点
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
 
	//连接树结点
	ConnectTreeNodes(pNode1, NULL, NULL);
 
	//中序遍历
	InOrderPrintTree(pNode1);
	//获取双向链表头结点
	BinaryTreeNode* pHeadOfList = Convert(pNode1);
	//输出链表
	PrintList(pHeadOfList);
 
}
 
void Test5()
{
   // 树中没有结点
 
	cout << "The Test5:" << endl;
    //创建树结点
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(NULL);
 
	//连接树结点
	ConnectTreeNodes(pNode1, NULL, NULL);
 
	//中序遍历
	InOrderPrintTree(pNode1);
	//获取双向链表头结点
	BinaryTreeNode* pHeadOfList = Convert(pNode1);
	//输出链表
	PrintList(pHeadOfList);
 
}
 
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	// system("pause");
}
