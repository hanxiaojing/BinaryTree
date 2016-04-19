#define _CRT_SECURE_NO_WARNINGS 1


#include "BinaryTree.hpp"//引入头文件
#include<iostream>
using namespace std;


void Test()
{
	int a1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> t(a1, 10, '#');
	t.PreOrder();
	t.InOrder();
	t.PostOrder();
	t.LevelOrder();
	cout<<t.Size()<<endl;
	cout << t.Depth() << endl;
	cout << t.LeafSize() << endl;
}

int main()
{
	Test();
	system("pause");
	return 0;
}

