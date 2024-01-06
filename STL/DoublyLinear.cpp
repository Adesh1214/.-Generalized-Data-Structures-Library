// doubly linear
#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node * prev;
};

template<class T>
class DoublyLL
{
    private:
        struct node<T> * first;
        int Count;

    public:
        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    cout<<"Inside constructor\n";
    first = NULL;
    Count = 0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T> ;   
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = first;

    newn = new struct node<T> ;   
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        //Type 2 loop
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::Display()
{
    struct node<T> * temp = first;

    cout<<"Elements of the linked list are : \n";
    cout<<"NULL <==>";
    while(temp != NULL) // Type 1
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp ->next;
    }
    cout<<"NULL \n";
}

template<class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if((first->next == NULL) && (first->prev == NULL))
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T> * temp = first;
        temp = first->next;  
        temp->prev =NULL;
        delete first;
        first = temp;
    }
    Count--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T> * temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}

template<class T>
void DoublyLL<T>::InsertAtPos(T no,int ipos)
{
    if((ipos < 1) || (ipos > Count+1))
    {
        return;
    }
     
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new struct node<T> ;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev =temp;

        Count++;
    }
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }
     
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp =first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        Count--;
    }
}

int main()
{

   DoublyLL <int>iobj;
   DoublyLL<float>fobj;
   DoublyLL<double>dobj;
   DoublyLL<char>cobj;

    iobj.InsertLast(101);
    iobj.InsertLast(51);
    iobj.InsertLast(21);
    iobj.InsertLast(11);

cout<<"Linked list of Integers:"<<"\n";
    iobj.Display();

    fobj.InsertLast(101.32);
    fobj.InsertLast(51.54);
    fobj.InsertLast(21.65);
    fobj.InsertLast(11.89);
cout<<"Linked list  float:"<<"\n";
    fobj.Display();

    dobj.InsertLast(101.9899);
    dobj.InsertLast(51.5678);
    dobj.InsertLast(21.456);
    dobj.InsertLast(11.321);
 cout<<"Linked list of double:"<<"\n";
    dobj.Display();

    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');
 cout<<"Linked list of character:"<<"\n";
    cobj.Display();

    return 0;
}
    