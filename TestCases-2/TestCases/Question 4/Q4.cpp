#include<iostream>
#include<fstream>
using namespace std;

struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;
struct Node* cursor = NULL;
static int n = 0;

void AddNumber(int val){
    struct Node* node = (struct Node* )malloc(sizeof(struct Node));
    node->val = val;
    
    if (head == NULL){
            node->next = NULL;
            node->prev = NULL;
            head = node;
            cursor = node;
            n++;
            return;
        }
        struct Node* curr = head;
        while(curr->next != NULL){
            // curr->prev = curr;
            curr = curr->next;
        }
        curr->next = node;  
        node->next = NULL;
        node->prev = curr;
        cursor = node;
        n++;
        return;
}

void AddAtindex(int val,int index){
    struct Node* node = (struct Node* )malloc(sizeof(struct Node));
    node->val = val;
    struct Node* curr = head;

    if (index < n){
        if (index == 0){
            node->next = head;
            node->prev = NULL;
            head = node;
            cursor = node;
            n++;
            return;
        }
        for(int i=0; i<index; i++){
            curr = curr->next;
        }
        node->prev = curr->prev;
        node->next = curr;
        curr->prev->next = node;
        curr->prev = node;
        cursor = node;
        n++;
        return;
    } 
    else if(index == n){
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = node;
        node->prev = curr;
        node->next = NULL;
        cursor = node;
        n++;
        return;
    }
    else if (index > n){
        cout<<"Value can not be inserted at index "<<index<<endl;
        return;
    }
}

void Delete(){
    struct Node* curr = head;
    struct Node* todelete;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    todelete = curr->next;
    curr->next = NULL;
    free(todelete);
    cursor = curr;
    n--;
    return;
}

void DeleteAtIndex(int index){
    if(index >= n){
        cout<<"There is no value at index: "<<index<<endl;
        return;
    }
    else if (index == n-1){
        Delete();
        return;
    }
    else if (index >= 0 && index <=(n-2)){
        struct Node* curr = head;
        struct Node* todelete;
        
        if (index == 0){
            todelete = head;
            head = curr->next;
            head->prev = NULL;
            free(todelete);
            cursor = head;
            n--;
            return;
        }
        else if (index == 1){
            todelete = curr->next;
            curr->next = curr->next->next;
            curr->next->prev = curr;
            free(todelete);
            cursor = curr;
            n--;
            return;
        }
        else{

            int i = 0;
            while (i < index){
                curr = curr->next;
                i++;
            }
            todelete = curr;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            cursor = curr->prev;
            free(todelete);
            n--;
            return;
        }
    }
}

void MoveForward_steps(int steps){
    int i=0;
    while (cursor->next != NULL && i<steps){
        cursor = cursor->next;
        i++;
    }
    return;
}

void MoveBackward_steps(int steps){
    int i=0;
    while (cursor->prev != NULL && i<steps){
        cursor = cursor->prev;
        i++;
    }
    return;
}

void AddImmediate_number(int val){
    struct Node* node = (struct Node* )malloc(sizeof(struct Node));
    node->val = val;
    node->next = cursor->next;
    node->prev = cursor;
    cursor->next->prev = node;
    cursor->next = node;
    cursor = node;
    n++;
    return;

}

void DeleteImmediate(){
    struct Node* todelete = cursor;
    cursor->prev->next = cursor->next;
    cursor->next->prev = cursor->prev;
    cursor = cursor->prev;
    free(todelete);
    n--;
    return;
}

void Update_index_number(int index,int val){
    struct Node* curr = head;

    if (index >=0 && index < n){
        for (int i= 0; i< index; i++){
            curr = curr->next;
        } 
        curr->val = val;
        cursor = curr;
        return;
        
    }
    else{
        cout<<"incorrect index"<<endl;
    }
}

void UpdateImmediate_number(int val){
    cursor->val = val;
    return;
}

void Shift_index(int index){
    struct Node* curr = head;
    if (index >=0 && index < n){
        for (int i= 0; i< index; i++){
            curr = curr->next;
        }

        cursor->val = curr->val;
        return;
    }
    else{
        cout<<"incorrect index"<<endl;
    }
}

void print(){
    struct Node* curr = head;
    while(curr != NULL){
        cout<<curr->val<<" <-> ";
        curr = curr->next;
    }    
    cout<<"NULL"<<endl;
}

void PrintAtCursor(){
    cout<<"Data At Cursor: "<<cursor->val<<endl;
}

int main(){
    
    string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 4/04/Test01.txt";
    ifstream in(file);

    string first_read;
    int val1;
    int val2 = 0;


    // while(in>>first_read){
    //     in>>val1;
    //     cout<<first_read<<" val1: "<<val1<<" val2: "<<val2<<endl;

    // }
    in>>first_read;
    while(in.eof()){
        in>>val2;
        if (first_read == "Add" ){
            in>>val1;
        // 
            // }
            // AddNumber(val1);
            cout<<first_read<<" val1: "<<val1<<" val2: "<<val2<<endl;
        }
        else if( first_read =="Print"){
            cout<<first_read<<" val1: "<<val1<<" val2: "<<val2<<endl;
            // print();
        }
    }

    // AddNumber(2);
    // AddNumber(4);
    // AddNumber(6);
    // AddNumber(8);
    // AddNumber(10);
    // // cout<<n<<endl;
    // // print();
    // AddAtindex(5,5);
    // AddAtindex(1,0);
    // AddAtindex(3,2);
    // print();
    // Delete();
    // // cout<<n<<endl;
    // DeleteAtIndex(6);
    // DeleteAtIndex(0);
    // // DeleteAtIndex(1);
    // print();
    
    // PrintAtCursor();
    
    // MoveForward_steps(2);
    // PrintAtCursor();
    
    // MoveBackward_steps(1);
    // PrintAtCursor();

    // AddImmediate_number(10);
    // print();
    // PrintAtCursor();

    // DeleteImmediate();
    // print();
    // PrintAtCursor();
    
    // Update_index_number(3,3);
    // print();
    // PrintAtCursor();

    // UpdateImmediate_number(10);
    // print();
    // PrintAtCursor();

    // Shift_index(1);
    // print();
    // PrintAtCursor();


    // cout<<"n = "<<n<<endl;


    return 0;
}