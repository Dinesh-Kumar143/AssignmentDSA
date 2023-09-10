#include<iostream>
#include<fstream>
#include<sstream>
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
        // cursor = node;
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
            // cursor = node;
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
        // cursor = node;
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
    cout<<"Cursor moved forward by "<< steps<<" step(s)"<<endl;
    return;
}

void MoveBackward_steps(int steps){
    int i=0;
    while (cursor->prev != NULL && i<steps){
        cursor = cursor->prev;
        i++;
    }
    cout<<"Cursor moved backword by "<< steps<<" step(s)"<<endl;

    return;
}

void AddImmediate_number(int val){
    struct Node* node = (struct Node* )malloc(sizeof(struct Node));
    node->val = val;
    node->next = cursor->next;
    node->prev = cursor;
    cursor->next->prev = node;
    cursor->next = node;
    // cursor = node;
    n++;
    return;

}

void DeleteImmediate(){
    struct Node* todelete = cursor;
    if (cursor == head){
        todelete = cursor;
        cursor = cursor->next;
        cursor->prev = NULL;
        free(todelete);
        return;
    }
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
        // cursor = curr;
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
    return;
}

struct Stack{
    struct Node* deletedVal;
    struct Stack* next;
    struct Stack* prev;
};
struct Stack* top = NULL;
void push(struct Node* deletedNode){
    struct Stack* add ;

    add->deletedVal = deletedNode;
    if (top == NULL){
        add->next = NULL;
        add->prev = NULL;
        top = add;
        return;
    }

    struct Stack* curr= top;
    curr->next = add;
    add->prev = curr;
    add->next = NULL;
    top = add;
    return;
}

void pop(){
    if (top == NULL){
        return;
    }
    struct Stack* curr= top;
    
    top = curr->prev;
    free(curr);
    return;
}
int main(){
    
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 4/04/Test01.txt";
    string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 4/04/Test02.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 4/04/Test03.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 4/04/Test04.txt";
    // string file = "E:/BSCS-402-Data_Structure_And_Algorithim/Assignments DSA/Assignment 2/TestCases-2/TestCases/Question 4/04/Test05.txt";
    ifstream in(file);
    string line;
    string first_read;
    int val1 ;
    int val2 ;

    if (in.is_open()){
        while(getline(in,line)){
            istringstream iss(line);
            iss>>first_read;
            if (first_read != "Print" && first_read !="Delete" && first_read !="Undo"){
                if (first_read == "Add" || first_read == "Update"){
                    iss>>val1>>val2;
                    if (first_read =="Add" && val2 > 1000){
                        AddNumber(val1);
                    }
                    else if(first_read == "Add"){
                        AddAtindex(val2,val1);
                    }
                    else if (first_read == "Update"){
                        Update_index_number(val1,val2);
                    }
                }  
                else{
                    iss>>val1;
                    if (first_read == "MoveForward"){
                        MoveForward_steps(val1);
                        continue;
                    }
                    else if (first_read == "AddImmediate"){
                        AddImmediate_number(val1);
                    }
                    else if(first_read == "MoveBackward"){
                        MoveBackward_steps(val1);
                        continue;
                    }
                    else if(first_read == "Delete"){
                        DeleteAtIndex(val1);
                    }
                    else if(first_read == "Shift"){
                        Shift_index(val1);
                    }
                    else if(first_read == "UpdateImmediate"){
                        UpdateImmediate_number(val1);
                    }
                    
                }

            }
            else{
                if (first_read == "Print"){
                    PrintAtCursor();
                    continue;
                }
                else if (first_read == "Delete"){
                    Delete();
                }
                else if (first_read == "UpdateImmediate"){
                    DeleteImmediate();
                }
            }
            print();
        }
    }

    in.close();

    return 0;
}