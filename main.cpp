#include <iostream>
#include "Employee.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include "DisplayArray.h"
#include "bubbleSort.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
using namespace std;

int main()
{
  /* Sorting * ascSort = new SortAsc();
  Sorting * descSort = new SortDesc();
  int numArr[5] = {4,2,8,3,1};
  string strArr[5] = {"Ahmed", "Ibrahim", "Omar", "Hassan", "Youssef"};
  Employee empArr[5] = {Employee(5,24,10000,"Ibrahim","Gaber"),
  Employee(3,23,500,"Seif","Salem"),
  Employee(4,24,10000,"Abanoub","Medhat"),
  Employee(2,22,100,"Ahmed","Nasser"),
  Employee(1,22,100000,"Ahmed","Khaled")
  };

 mergeSort(numArr,0,4);

 displayArray(numArr,5); */

  /*  LinkedList<int> bruh;

   bruh.insert(1);
   bruh.insert(2);
   bruh.insert(3);
   bruh.insert(4);
   bruh.insert(5);

   bruh.print();


   bruh.insert(6,2);

   bruh.print(); */

  /*  Queue<int> evenNums;
   evenNums.enqueue(2);
   evenNums.enqueue(8);
   evenNums.enqueue(12);
   evenNums.enqueue(18);
   evenNums.enqueue(6);
   evenNums.enqueue(4);

   evenNums.print(); */

  /*  evenNums.dequeue();
   cout<<"after dequeue"<<endl;
   evenNums.print(); */

  /*   evenNums.front();
    cout<<"after dequeue"<<endl;
    evenNums.print(); */

  /*  evenNums.isEmpty();
  cout<<"after empty"<<endl;
  evenNums.print(); */

  BinaryTree<int> binaryTree;

  // Insert nodes into the binary tree
  binaryTree.insert(5);
  binaryTree.insert(3);
  binaryTree.insert(7);
  binaryTree.insert(1);
  binaryTree.insert(4);

  // Traverse the binary tree in-order and print the nodes
  cout << "In-order traversal: ";
  binaryTree.inOrderTraversal();

  // Search for a value in the binary tree
  int searchValue = 3;
  if (binaryTree.search(searchValue))
  {
    cout << searchValue << " is present in the binary tree." << endl;
  }
  else
  {
    cout << searchValue << " is not present in the binary tree." << endl;
  }

  // Remove a value from the binary tree
  int removeValue = 3;
  binaryTree.remove(removeValue);

  // Traverse the binary tree after removal
  cout << "In-order traversal after removing " << removeValue << ": ";
  binaryTree.inOrderTraversal();

  return 0;
}
