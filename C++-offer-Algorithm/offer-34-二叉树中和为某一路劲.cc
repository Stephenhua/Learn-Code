#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include "BinaryTreeNode.h"
using namespace std;

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int& currentSum);


void FindPath1(BinaryTreeNode* pRoot, int expectedSum){
    if(pRoot == nullptr){
        return ;
    }
    std::vector<int> path;
    int sum=0;
    FindPath(pRoot,expectedSum,path,sum);
}
//采用了递归的方法进行求解
void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int& sum){
    sum+=pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);

    bool isLeaf=pRoot->m_pLeft==nullptr && pRoot->m_pRight==nullptr;

    if(sum==expectedSum&& isLeaf){
        printf("A path is found :");
        std::vector<int>::iterator iter=path.begin();
        for(;iter!=path.end();++iter){
            printf("%d\t",*iter);
        }
        printf("\n");
    }

    if(pRoot->m_pLeft!=nullptr){
        FindPath(pRoot->m_pLeft,expectedSum,path,sum);
    }
    if(pRoot->m_pRight!=nullptr){
        FindPath(pRoot->m_pRight,expectedSum,path,sum);
    }

    sum-=pRoot->m_nValue;
    path.pop_back();
}

void Test(char *testName , BinaryTreeNode* pRoot,int expectedSum){
    if(testName!=nullptr){
        printf("%s begins:\n",testName);
    }
    FindPath1(pRoot,expectedSum);

    printf("\n");
}


//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// 有两条路径上的结点和为22

void test1(){
    BinaryTreeNode* pNode10=CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5=CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12=CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4=CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7=CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10,pNode5,pNode12);
    ConnectTreeNodes(pNode5,pNode4,pNode7);

    printf("Two path should be found in Test1.\n");
    Test("Test1",pNode10,22);

    DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// 没有路径上的结点和为15
void test2(){

    BinaryTreeNode* pNode10=CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5=CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12=CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4=CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7=CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10,pNode5,pNode12);
    ConnectTreeNodes(pNode5,pNode4,pNode7);

    printf("Two path should be found in Test2.\n");
    Test("Test1",pNode10,15);

    DestroyTree(pNode10);

}


//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
// 有一条路径上面的结点和为15

void test3(){

    BinaryTreeNode* pNode5=CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4=CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3=CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2=CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1=CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5,pNode4,nullptr);
    ConnectTreeNodes(pNode4,pNode3,nullptr);
    ConnectTreeNodes(pNode3,pNode2,nullptr);
    ConnectTreeNodes(pNode2,pNode1,nullptr);

    printf("Two path should be found in Test3.\n");
    Test("Test3",pNode5,15);
     DestroyTree(pNode5);
}


// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
// 没有路径上面的结点和为16

void test4(){

    BinaryTreeNode* pNode5=CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4=CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3=CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2=CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1=CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode1,nullptr,pNode2);
    ConnectTreeNodes(pNode2,nullptr,pNode3);
    ConnectTreeNodes(pNode3,nullptr,pNode4);
    ConnectTreeNodes(pNode4,nullptr,pNode5);

    printf("Two path should be found in Test4.\n");
    Test("Test4",pNode1,16);
     DestroyTree(pNode1);
}

// 树中只有1个结点


void test5(){

    BinaryTreeNode* pNode5=CreateBinaryTreeNode(5);


    ConnectTreeNodes(pNode5,nullptr,nullptr);


    printf("Two path should be found in Test4.\n");
    Test("Test4",pNode5,16);
     DestroyTree(pNode5);
}

// 树中没有结点


void test6(){
    printf("Two path should be found in Test6.\n");
    Test("Test4",nullptr,0);

}

int main (int argc ,char *argv[]){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}