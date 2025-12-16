#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void menu();
Node* createNode();
int listSize(Node* head);
Node* insert_head(Node* head, Node* nn);
Node* insert_tail(Node* head, Node* nn);
Node* insertAtPosition(Node* head, Node* nn, int size, int position);
void printList(Node* head);
Node* deleteHead(Node* head);
Node* deleteTail(Node* head);
Node* deleteFromPosition(Node* head, int size, int position);
void searchData(Node* head, int key);
Node* updateData(Node* head, int position, int newValue);

int main(){
     Node* head = NULL;
     Node* nn;

    int choice;
    
    
    while (choice != 0){
        cout << "\n";
        menu();
   
    cout << "Enter Choice: ";
    cin >> choice;
    
    
    if(choice == 1){                 //Insert at head
        nn = createNode();
        head = insert_head(head, nn);

    } else if(choice == 2){         //Insert at tail
        nn = createNode();
        head = insert_tail(head, nn);
    }
    else if(choice == 3){           //Insert at nth position
        nn = createNode();

        int position;
        cout << "Enter Position: ";
        cin >> position;

        int size = listSize(head);

        if(position >= 1 && position <= size+1){
            head = insertAtPosition(head, nn, size, position);
        } else{
            cout << "Invalid Position" << "\n";
        }

    } else if (choice == 4){           //Print the Linked List
        printList(head);
    } else if(choice == 5){                     //List Size
        int size = listSize(head);
        cout << "List Size is: " << size << "\n";
    } else if (choice == 6){            //Delete from head
        head = deleteHead(head);
    } else if(choice == 7){             //Delete from tail
        head = deleteTail(head);
    } else if(choice == 8){                //Delete from nth Position
        int size = listSize(head);
        int position;
        cout << "Enter Position: ";
        cin >> position;

        if(position >= 1 && position <= size ){
            head = deleteFromPosition(head, size, position);
        } else {
            cout << "Invalid Position!" << "\n";
        }
    } else if(choice == 9){             //Search data
        int key;
        cout << "Enter the key: ";
        cin >> key;
        searchData(head, key);
    } else if(choice == 10){            //Update data
        int position;
        cout << "Enter position: ";
        cin >> position;

        int newValue;
        cout << "Enter the new value: ";
        cin >> newValue;

        head = updateData(head, position, newValue);

    } else{
        cout << "Invalid Choice!" << "\n";
    }

}


}
void menu(){
   
    cout << "1.Insert at Head" << "\n";
    cout << "2.Insert at Tail" << "\n";
    cout << "3.Insert at nth Position" << "\n";
    cout << "4.Print the List" << "\n";
    cout << "5.List Size" << "\n";
    cout << "6.Delete from Head" << "\n";
    cout << "7.Delete from Tail" << "\n";
    cout << "8.Delete from nth Position" << "\n";
    cout << "9.Search a data" << "\n";
    cout << "10.Update data" << "\n";
}

int listSize(Node* head){
    int counter = 0;
    Node* temp = head;
    while(temp != NULL){
        counter++;
        temp = temp->next;
    }
    return counter;
}

Node* createNode(){
    Node* nn = new Node();
    cout << "Enter Data: ";
    cin >> nn->data;
    nn->next = NULL;
    return nn;

}

Node* insert_head(Node* head, Node* nn){
    nn->next = head;
    cout << "Inserted at Head!" << "\n";
    return nn;

}

Node* insert_tail(Node* head, Node* nn){
    if(head == NULL){
        return insert_head(head, nn);
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = nn;
    cout << "Inserted at Tail" << "\n";
    return head;
}

Node* insertAtPosition(Node* head, Node* nn, int size, int position){
    if(position == 1){
        return insert_head(head,nn);
    } else if( position == size+1){
        return insert_tail(head, nn);
    }

    Node* temp = head;
    for(int i = 1; i <= position - 2; i++){
        temp = temp->next;
    }

    nn->next = temp->next;
    temp->next = nn;

    cout << "Node inserted at " << position << "\n";
    return head;

}

void printList(Node* head){
    Node* temp = head;
    cout << "The Linked List is : ";
    if(temp == NULL){
        cout << "No List Found" << "\n";
    }

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";

}

Node* deleteHead(Node* head){
    if(head == NULL){
        cout << "The is no list to delete!" << "\n";
        return head;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "Head Node Deleted" << "\n";
    return head;

}

Node* deleteTail(Node* head){
    int size = listSize(head);
    if(size <= 1){
        return deleteHead(head);
    }

    Node* temp = head;
    for(int i = 1; i <= size-2; i++){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    cout << "Tail Node Deleted!" << "\n";
    return head;
}

Node* deleteFromPosition(Node* head, int size, int position){
    if(position == 1){
        return deleteHead(head);
    }
    if (position == size){
        return deleteTail(head);
    }

    Node* temp = head;
    for(int i = 1; i <= position-2; i++){
        temp = temp->next;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Node at position " << position << " is deleted" << "\n";
    return head;
}

void searchData(Node* head, int key){
    if(head == NULL){
        cout << "No data to search!" << "\n";
    }
    Node* temp = head;
    int position = 1;
    while(temp!= NULL){
        if(temp->data == key){
            cout << "Data found at position " << position << "\n";
            return;
        }
        temp = temp->next;
        position++;
    }
    if(temp == NULL){
    cout << "Data Not Found!" << "\n";
    }
}

Node* updateData(Node* head, int position, int newValue){
    if(head == NULL){
        cout << "Nothing to update!";
        return head;
    }

    int size = listSize(head);
    if(position < 1 || position > size){
        cout << "Invalid Position!" << "\n";
    }

    Node* temp = head;
    for(int i = 1; i < position; i++){
        temp = temp->next;
    }
    temp->data = newValue;

    cout << "Data updated at position " << position << "\n";
    return head;
}