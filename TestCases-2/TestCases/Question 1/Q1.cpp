#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int val){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* mid = head;
    
    node->data = val;
    if (head == NULL){
        node->next = NULL;
        head = node;
        return;
    }
    struct Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    node->next = NULL;
    curr->next = node;  
    return;
}

void DELETE(){ 
    struct Node* todelete;
    if (head == NULL){
        return;
    }
    else if (head->next == NULL){
        todelete = head;
        head = NULL;
        free(todelete);
        return;
    }
    struct Node* curr = head;
    while ( curr->next->next != NULL){
        curr = curr->next;
    }
    todelete = curr->next;
    curr->next = NULL;
    free(todelete);
}

void GetTrump(){
    struct Node* fast = head;
    struct Node* slow = head;
    if (head == NULL){
        return;
    }
    else if (head->next == NULL){
        cout<<head->data<<endl;
        return;
    }
    while(fast->next != NULL && fast != NULL){
        fast = fast->next->next;
        slow  = slow->next;
    }
    cout<<slow->data<<endl;
}
void display(){
    struct Node* curr = head;

    while(curr != NULL){
        cout<<curr->data<<"->";
        curr = curr->next;
    }
}
int main(){
    string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 1/01/Test01.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 1/01/Test02.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 1/01/Test03.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 1/01/Test04.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 1/01/Test05.txt";
    string first_read;
    int val;
    ifstream in(file);
    
    while( in>>first_read ){
        if (first_read == "ADD"){
            in>>val;
            insert(val);
        }
        else if (first_read == "DELETE"){
            in.get();
            DELETE();
        }
        else if( first_read == "END"){
            display();
            cout<<"NULL"<<endl;
        }
        
    }
    GetTrump();
    in.close();
    return 0;
}