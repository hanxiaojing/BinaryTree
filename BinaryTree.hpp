#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __TREE_H__	//��ֹ��ΰ���
#define __TREE_H__
#include<iostream>
using namespace std;
#include<queue>
template <class T>
struct BinaryTreeNode
{
	BinaryTreeNode<T>* _left;	//������
	BinaryTreeNode<T>* _right;	//������
	T _data;
	BinaryTreeNode(const T& x)
		:_left(NULL)
		, _right(NULL)
		, _data(x)
	{}
};

template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;	//������������򻯴��룬���������
public:
	BinaryTree()
		:_root(NULL)
	{}

	BinaryTree(const T* a, size_t size, const T& invalid)
		:_root(NULL)
	{
		size_t index = 0;
		_root = _CreateTree(a, size, invalid, index);
	}
	
	BinaryTree<T>(const BinaryTree<T>& t)
		: _root(NULL)
	{
		_Copy(t._root);
	}

	BinaryTree<T>& operator=(const BinaryTree<T>& t)
	{
		if (&t != this)
		{
			_Copy(t._root);
			_Destroy(_root);
		}
		return *this;
	}

	~BinaryTree()
	{
		if (_root)
		{
			_Destroy(_root);
		}
	}

	//ǰ�����
	void PreOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}

	//�������
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	//�������
	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}

	//��α���
	void LevelOrder()
	{
		_LevelOrder(_root);
		cout << endl;
	}


	//�ڵ���
	size_t Size()
	{
		return _Size(_root);
	}

	//��ȣ��߶ȣ�
	size_t Depth()
	{
		return _Depth(_root);
	}

	//Ҷ�ӽڵ���
	size_t LeafSize()
	{
		return _LeafSize(_root);
	}
protected:
	void _Destroy(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		if (root->_left == NULL && root->_right == NULL)
		{
			delete root;
			root = NULL;
			return;
		}
		_Destroy(root->_left);
		_Destroy(root->_right);
	}

	void _Copy(Node* troot)
	{
		if (troot == NULL)
		{
			return;
		}
		if (troot->_left == NULL&&troot->_right == NULL)
		{
			Node* root = new Node(troot->_data);
			return;
		}
		root->_left = _Copy(troot->_left);
		root->_right = _Copy(troot->_right);
	}

	//����1��
	/*size_t _LeafSize(Node* root)
	{
		static int size = 0;
		if (root == NULL)
		{ 
			return size;
		}
		if (root->_left == NULL && root->_right == NULL)
		{
			size++;
			return size;
		}	
		_LeafSize(root->_left);
		_LeafSize(root->_right);
	}*/

	//����2��
	size_t _LeafSize(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (root->_left == NULL &&root->_right == NULL)
		{
			return 1;
		}
		return _LeafSize(root->_left) + _LeafSize(root->_right);
	}

	size_t _Size(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	size_t _Depth(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int LeftDepth = _Depth(root->_left);
		int RightDepth = _Depth(root->_right);
		return LeftDepth > RightDepth ? LeftDepth +1: RightDepth+1;
	}

	Node* _CreateTree(const T* a, size_t size, const T& invalid, size_t& index)
	{
		Node* root = NULL;
		if (index < size && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _CreateTree(a, size, invalid, ++index);
			root->_right = _CreateTree(a, size, invalid, ++index);
		}
		return root;
	}


	//ǰ����������ʸ��ڵ�->������->������
	void _PrevOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->_data << "  ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}

	//�������������������->���ڵ�->������
	void _InOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_data << "  ";
		_InOrder(root->_right);
	}

	//�������������������->������->���ڵ�
	void _PostOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << "  ";
	}

	void _LevelOrder(Node* root)
	{
		queue<Node*> q;
		if (root == NULL)
		{
			return;
		}
		q.push(root);
		while (!q.empty())
		{
			if (q.front()->_left != NULL)
			{
				q.push(q.front()->_left);

			}
			if (q.front()->_right != NULL)
			{
				q.push(q.front()->_right);

			}
			cout << q.front()->_data<< "  ";
			q.pop();
		}		
	}
protected:
	Node* _root;
};

#endif	//__TREE_H__