#include<iostream>
using namespace std;

template< class T>
struct node
{
    T data;
    struct node *next;
};
template<class T>
class Queue
{
    private:
        struct node <T> * first;

    public:
        Queue();
        void Enqueue(T no);
        int Dequeue();
        void Display();
};
template <class T>
Queue<T>::Queue()
{
    first = NULL;
}

template <class T>
void Queue<T>::Enqueue(T no)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = first;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)  
    {
        first = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

template <class T>
int Queue<T>::Dequeue()
{
    int value =0;
    struct node<T> * temp = first;
     if(first == NULL)
    {
        cout<<"Queue IS EMPTY.."<<"\n";
    }
    else
    {
        value= first->data;
        first = first->next;
        delete temp;
    }
    return value;
}
template<class T>
void Queue<T> :: Display()
{
    printf("Elements of Queue are : \n");

    struct node<T> * temp = first;
    while( temp!= NULL)
    {
        cout<<"| "<<temp->data<<"|"<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

int main()
{
    
    Queue<int> iobj;
    Queue<float> fobj;
    Queue<double> dobj;
    Queue<char> cobj;

    cout<<"Queue of integers is:"<<"\n";
    iobj.Enqueue(101);
    iobj.Enqueue( 51);
    iobj.Enqueue( 21);
    iobj.Enqueue( 11);
    iobj. Display();
    cout<<"\n";

    cout<<"Queue of Floats is :"<<"\n";
    fobj.Enqueue(101.76);
    fobj.Enqueue( 51.23);
    fobj.Enqueue( 21.46);
    fobj.Enqueue( 11.2);
    fobj. Display();
    cout<<"\n";

    cout<<"Queue of Double is :"<<"\n";
    dobj.Enqueue(101.7687);
    dobj.Enqueue( 51.2375);
    dobj.Enqueue( 21.4634);
    dobj.Enqueue( 11.243);
    dobj. Display();
    cout<<"\n";

    cout<<"Queue of Characters is:"<<"\n";
    cobj.Enqueue('A');
    cobj.Enqueue('B');
    cobj.Enqueue('C');
    cobj.Enqueue('D');
    cobj. Display();

    return 0;
}