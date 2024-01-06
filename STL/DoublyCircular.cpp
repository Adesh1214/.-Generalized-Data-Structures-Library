// DoublyCircular
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
class DoublyCL
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int Count;

    public:
        DoublyCL();
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
DoublyCL<T>::DoublyCL()
{
    cout<<"inside Constructor"<<"\n";
    first = NULL;
    last = NULL;
    Count = 0;
}

template<class T>
void DoublyCL<T>::InsertFirst(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T> ;

    newn-> data = no;
    newn->next =NULL;
    newn->prev = NULL;

    if((first ==NULL) &&(last ==NULL))
    {
         first =newn;
         last = newn;
    }
    else
    {
        newn->next= first ;
        first->prev = newn;
        first =newn;
        
    }
    last->next = first;
    first->prev = last;
    Count++;

}

template<class T>
void DoublyCL<T>::InsertLast(T no)
{
    struct node<T> * newn =NULL;
    newn =new struct node<T> ;

    newn->data =no;
    newn->next= NULL;
    newn->prev = NULL;

    if((first ==NULL)&& (last==NULL))
    {
        first = newn;
        last =  newn;
    }
    else
    {   
        newn->prev = last;
        last->next = newn;
        last= newn;
        

    }
    last->next = first;
    first->prev = last;
    Count++;
}

template<class T>
void DoublyCL<T>::Display()
{
    struct node<T> * temp = first;

    if((temp != NULL) && (last != NULL))
    {
        do
        {
            cout<<"| "<<temp->data <<"| <=>";
            temp  = temp->next;

        } while (temp != first && temp!= NULL);

        cout<<" Address of first node\n";       
        
    }
}

template<class T>
int DoublyCL<T>::CountNode()
{
    return Count;
}

template<class T>
void DoublyCL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first= NULL;
        last =NULL;
    }
    else
    {
        struct node<T> * temp = first;
        first = first->next;

        delete temp;
    }
    last->next = first;
    first->prev = last;
    Count--;
}

template<class T>
void DoublyCL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first= NULL;
        last =NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        last->next = first;
        first->prev = last;

    }
    Count--;
    
}

template<class T>
void DoublyCL<T>::InsertAtPos(T no,int ipos)
{
    if((ipos < 1) || (ipos > Count + 1))
    {
        return;
    }
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    if(ipos == Count +1)
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
        int i= 0;

        for(i =1; i< ipos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

    }
    last->next =first;
    Count++;
    
}

template<class T>
void DoublyCL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > Count ))
    {
        return;
    }
    if(ipos == 1)
    {
        DeleteFirst();
    }
    if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp = first;
        int i=0;

        for(i = 1; i < ipos -1; i++)
        {
            temp = temp->next;
        }
     
        temp->next= temp->next->next;
        delete temp->next->prev;
        temp->next->prev= temp;

        last->next = first;
    }
    
    Count--;
}

int main()
{
    DoublyCL <int>iobj;
   DoublyCL<float>fobj;
   DoublyCL<double>dobj;
   DoublyCL<char>cobj;

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