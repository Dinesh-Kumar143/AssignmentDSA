#include<iostream>
#include<fstream>
using namespace std;

struct Node {
    int val;
    struct Node* next;
};
struct Node* head = NULL;
static int n = 0;

void insert(int val){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->val = val;

    if (head == NULL){
        node->next = NULL;
        n++;
        head = node;
        
        return;
    }
    struct Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    node->next = NULL;
    curr->next = node;
    n++;  
    return;
    
}

int As_the_Matter_of_Third(){
    if (n < 3){
        return -1;
    }
    struct Node* third = head;
    struct Node* curr = head->next->next;
    while(curr->next != NULL){
        curr = curr->next;
        third = third->next;
    }
    return (third->val);
}

int main(){
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 5/05/Test01.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 5/05/Test02.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 5/05/Test03.txt";
    string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 5/05/Test04.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 5/05/Test05.txt";
    ifstream in(file);
    int val;
    while(in>>val){
        insert(val);
    }
    cout<<As_the_Matter_of_Third()<<endl;;
    return 0;
}