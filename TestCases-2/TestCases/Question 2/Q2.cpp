#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;
static int n = 0;

void median();

void insert(int val){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = val;
    if (head == NULL){
        node->next = NULL;
        head = node;
        n++;
        cout<<n<<endl;
        median(); 
        return;
    }
    struct Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    n++;
    node->next = NULL;
    curr->next = node;  
    median(); 
    return;
}

void insertionsort(int list[]){
    for (int i=1; i<n; i++ ){
        int j = i-1;
        int key = list[i];
        for ( ;j>=0 && list[j] > key;j--){
            list[j+1] = list[j];
        }
        list[j+1] = key;
    }
    
}

void median(){
    int list[n] ;
    struct Node* curr = head;
    for (int i=0; i<n; i++){
        list[i] = curr->data;
        curr = curr->next;
    }
    insertionsort(list);
    // for(int i= 0; i<n; i++){
    //     cout<<list[i]<<" ";
    // }
    if (n == 1){
        cout<<"The Median is "<<list[n-1]<<endl;
        return;
    }
    if ((n % 2) == 1){
        int mid = int(n/2);
        cout<<"The Median is "<<list[mid]<<endl;
        return;
    }  
    else if ((n % 2) == 0){
        int mid1 = n/2;
        int mid2 = (n/2) - 1;
        cout<<"The median is "<<(list[mid1]+ list[mid2])/2.0f<<endl;
        return;
    }
    
    return;
}
void display(){
    struct Node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

int main(){
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 2/02/Test01.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 2/02/Test02.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 2/02/Test03.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 2/02/Test04.txt";
    string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 2/02/Test05.txt";
    ifstream in(file);
    int val;

    while (in>>val){
        insert(val);
    }

    in.close(); 
    return 0;
}