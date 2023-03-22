#include <iostream>
using namespace std;

class Node {
public:
    int Value;
    Node* Next;
    Node* Previous;
};

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

    while (Head != NULL)
    {
        cout << Head->Value << endl;
        Head = Head->Next;
    }
}
