#include<iostream>
#include<fstream>
using namespace std;

struct Node{
    int TransID;
    int TransAmount;
    struct Node* next;
};
struct Node* head = NULL;

void insert(int TrasnID,int TransAmount){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    
    node->TransID = TrasnID;
    node->TransAmount = TransAmount;
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

void DELETE(int TransID){
    struct Node* curr = head;
    struct Node* todelete ;

    if (head->TransID == TransID){
        todelete = head;
        head = head->next;
        free(todelete);
        return;
    }
    while ( curr->next != NULL){
        if (curr->next->TransID == TransID){
            todelete = curr->next;
            curr->next = curr->next->next;
            free(todelete);
        }
        curr = curr->next;
    }
}
void display(){
    struct Node* curr = head;
    while(curr != NULL){
        cout<<curr->TransID<<", "<<curr->TransAmount<<endl;
        curr = curr->next;
    }
    return;
}

int main(){
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 3/03/Test01.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 3/03/Test02.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 3/03/Test03.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 3/03/Test04.txt";
    string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 3/03/Test05.txt";
    ifstream in(file);

    int NOT;
    int NOFT;
    int TransID;
    int TransAmount;
    in>>NOT;
    in>>NOFT;

    for (int i=0;i<NOT; i++){
        in>>TransID;
        in.get();
        in>>TransAmount;
        insert(TransID,TransAmount);
    }
    int todelete ;
    for (int i = 0; i<NOFT; i++){
        in>>todelete;
        DELETE(todelete);
    }
    display();
    
    return 0;
}