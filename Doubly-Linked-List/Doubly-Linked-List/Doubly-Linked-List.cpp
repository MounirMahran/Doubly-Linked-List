#include <iostream>
using namespace std;

class Node {
public:
    int Value;
    Node* Next;
    Node* Previous;
};

void InsertAtBegining(Node*& Head, int Value) {
    Node* NewNode = new Node();

    NewNode->Value = Value;
    NewNode->Previous = NULL;

   
    if (Head != NULL) {
        NewNode->Next = Head;
        Head->Previous = NewNode;
    }

    Head = NewNode;
}

void PrintNodeDetails(Node* Head)
{

    if (Head->Previous != NULL)
        cout << Head->Previous->Value;
    else
        cout << "NULL";

    cout << " <--> " << Head->Value << " <--> ";

    if (Head->Next != NULL)
        cout << Head->Next->Value << "\n";
    else
        cout << "NULL";

}

void PrintListDetails(Node* Head)

{
    cout << "\n\n";
    while (Head != NULL) {
        PrintNodeDetails(Head);
        Head = Head->Next;
    }
}

void PrintList(Node* Head)

{
    cout << "NULL <--> ";
    while (Head != NULL) {
        cout << Head->Value << " <--> ";
        Head = Head->Next;
    }
    cout << "NULL";

}

Node* Find(Node* Head, int Value) {
    while (Head != NULL) {
        if (Head->Value == Value) return Head;

        Head = Head->Next;
    }
    return NULL;
}

void InsertAfter(Node* CurrentNode, int Value) {
    Node* NewNode = new Node();

    NewNode->Value = Value;
    NewNode->Previous = CurrentNode;
    NewNode->Next = CurrentNode->Next;

    CurrentNode->Next = NewNode;
}

void InsertAtEnd(Node*& Head, int Value) {
    Node* NewNode = new Node();

    NewNode->Next = NULL;
    NewNode->Value = Value;

    if (Head == NULL) {
        NewNode->Previous = NULL;
        Head = NewNode;
    }
    else {
        Node* Current = Head;

        while (Current->Next != NULL) {
            Current = Current->Next;
        }

        NewNode->Previous = Current;
        Current->Next = NewNode;
    }

}

int main()
{
    Node* Head;

    Node* Node1; 
    Node* Node2; 
    Node* Node3; 

    Node1 = new Node();
    Node2 = new Node();
    Node3 = new Node();

    Node1->Value = 1;
    Node2->Value = 2;
    Node3->Value = 3;

    Node1->Next = Node2;
    Node1->Previous = NULL;

    Node2->Next = Node3;
    Node2->Previous = Node1;

    Node3->Next = NULL;
    Node3->Previous = Node2;

    Head = Node1;

    //Insert A Node At Beginging
   
    InsertAtBegining(Head, 12);

    PrintList(Head);
    

    //Find A Node

    Node* NewNode = Find(Head, 2);

    if (NewNode != NULL) cout << "\nNode Found :-)" << endl;
    else cout << "\nNode Is Not Found :-(" << endl; 

    //Insert After A Node

    InsertAfter(Find(Head, 2), 12);
    PrintList(Head);
    PrintListDetails(Head);

    //Insert At End
    InsertAtEnd(Head, 10);
    PrintList(Head);
    PrintListDetails(Head);
}
