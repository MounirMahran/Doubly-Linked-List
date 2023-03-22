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

   

    //Printing list
    Head = Node1;

    InsertAtBegining(Head, 12);

    PrintList(Head);
    PrintListDetails(Head);
}
