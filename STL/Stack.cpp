#include<iostream>
using namespace std;

template< class T>
struct node
{
    T data;
    struct node *next;
};
template<class T>
class stack
{
    private:
        struct node <T> * first;

    public:
        stack();
        void Push(T no);
        int Pop();
        void Display();
};
template <class T>
stack<T>::stack()
{
    first = NULL;
}

template <class T>
void stack<T>::Push(T no)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)  
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
}

template <class T>
int stack<T>::Pop()
{
    int value =0;
     if(first == NULL)
    {
        cout<<"STACK IS EMPTY..";
    }
    else
    {
        struct node<T> * temp = first;
        value= first->data;
        first = first->next;
        delete temp;
    }
    return value;
}
template<class T>
void stack<T> :: Display()
{
    struct node<T>* temp = first;
    printf("Elements of Stack are : \n");

    while( temp!= NULL)
    {
        cout<<"| "<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"\n";
}

int main()
{
    stack<int> iobj;
    stack<float> fobj;
    stack<double> dobj;
    stack<char> cobj;

    cout<<"Stack of integers is:"<<"\n";
    iobj.Push(101);
    iobj.Push( 51);
    iobj.Push( 21);
    iobj.Push( 11);
    iobj. Display();
    cout<<"\n";

    cout<<"Stack of Floats is :"<<"\n";
    fobj.Push(101.76);
    fobj.Push( 51.23);
    fobj.Push( 21.46);
    fobj.Push( 11.2);
    fobj. Display();
    cout<<"\n";


    cout<<"Stack of Double is :"<<"\n";
    dobj.Push(101.7687);
    dobj.Push( 51.2375);
    dobj.Push( 21.4634);
    dobj.Push( 11.243);
    dobj. Display();
    cout<<"\n";

    cout<<"Stack of Characters is:"<<"\n";
    cobj.Push('A');
    cobj.Push('B');
    cobj.Push('C');
    cobj.Push('D');
    cobj. Display();
    
    
    return 0;
}