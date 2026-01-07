	#include "lbt.h"
	#include <iostream>
	using namespace std;

	int main() {
		LinkedBinaryTree Tree;
		Tree.insert(35);
		Tree.insert(35);
		Tree.insert(15);
		Tree.insert(35);
		Tree.insert(8);
		Tree.insert(20);
		Tree.insert(6);
		
		cout << "Inorder: ";
		Tree.inorderPrint();
		cout << "\n";
		cout << "Postorder: ";
		Tree.postorderPrint();
		cout << "\n";
		cout << "Preorder: ";
		Tree.preorderPrint();
		cout << "\n";
		cout << "\n";
		cout << "Ascending: ";
		Tree.ascendingPrint();
		cout << "\n";
		cout << "\n";
		cout << "Descending:  ";
		Tree.descendingPrint();
		cout << "\n";
		return 0;
	}