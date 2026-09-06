#include<iostream>
using namespace std;

#pragma pack(1)
template<class T>
struct node
{
    T data;
    struct node<T> * next;
    struct node<T> * prev;
    struct node<T> *lchild;
    struct node<T> *rchild;
};

//----------------------------------------------------------------
// Singly Linear Linked List
//----------------------------------------------------------------

//////////////////////////////////////////////////////////////////
// SinglyLL class Declaration
//////////////////////////////////////////////////////////////////

template<class T>
class SinglyLL
{
    private :
        struct node<T> * first;
        int iCount;

    public :
        SinglyLL();
        void Display();
        int Count();
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

//////////////////////////////////////////////////////////////////
// SinglyLL class Definition
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Method Name : SinglyLL()
// Parameter   : None
// Description : It is a constructor of SinglyLL class.
//               It initializes the linked list by setting the 
//               head pointer to NULL and the node count to zero
//               in the Singly linear linked list.
// Author Name : Kranti Laxman Waghamare
// Date        : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
SinglyLL<T> :: SinglyLL()
{
    this->first = NULL;            
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////
// Method Name : Display()
// Parameter   : None
// Description : Displays all elements of the Singly Linear 
//               linked list by traversing the list from the 
//               first node.
// Author Name : Kranti Laxman Waghamare
// Date        : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: Display()
{
    struct node<T> * temp = NULL;

    temp = this->first;

    while(temp != NULL)
    {
        cout<<" | "<<temp->data << " | -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}

//////////////////////////////////////////////////////////////////
// Method Name : Count()
// Parameter   : None
// Description : Returns the total number of nodes currently 
//               present in the Singly Linear linked list.
// Author Name : Kranti Laxman Waghamare
// Date        : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
int SinglyLL<T> :: Count()
{
    return this-> iCount;
}

//////////////////////////////////////////////////////////////////
// Method Name : InsertFirst()
// Parameter   : T iNo
// Description : It is used to Insert the new node from the 
//               begenning of the singly linear linked list
// Author Name : Kranti Laxman Waghamare
// Date        : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: InsertFirst(T iNo)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;

    newn -> data = iNo;
    newn -> next = NULL;

    if(this->first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        newn -> next = this -> first;
        this -> first = newn;
    }

    this -> iCount++;                   
}

//////////////////////////////////////////////////////////////////
// Method Name : InsertLast()
// Parameter   : T iNo
// Description : It is used to Insert the new node from the end
//               of the Singly linear linked list. 
// Author Name : Kranti Laxman Waghamare
// Date        : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: InsertLast(T iNo)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new struct node<T>;

    newn -> data = iNo;
    newn -> next = NULL;

    if(this->first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        temp = this -> first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    this -> iCount++;                  
}

//////////////////////////////////////////////////////////////////
// Method Name : InsertAtPos()
// Parameter   : T iNo
// Description : It is used to Insert the new node from the 
//               Given position of the singly linear linked list. 
// Author Name : Kranti Laxman Waghamare
// Date        : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: InsertAtPos(T iNo, int iPos)
{
    int i = 0;
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    if((iPos < 1) || (iPos > this -> iCount + 1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        this -> InsertFirst(iNo);   
    }
    else if (iPos == this -> iCount + 1)
    {
        this -> InsertLast(iNo);
    }
    else
    {
        newn = new struct node<T>;

        newn -> data = iNo;
        newn -> next = NULL;

        temp = this -> first;

        for(i = 1; i< iPos - 1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        this -> iCount++;
    }
}

//////////////////////////////////////////////////////////////////
// Method Name : DeleteFirst()
// Parameter   : None
// Description : It is used to Delete the existing node from the 
//               beginning of the Singly Linear Linked List. 
// Author Name : Kranti Laxman Waghamare
// Date        : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct node<T> * temp = NULL;

    if(this -> first == NULL)
    {
        return;
    }
    else if(this -> first ->next == NULL)
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;

        this -> first = this -> first -> next;
    
        delete temp;
        
    }

    this -> iCount--;
}

//////////////////////////////////////////////////////////////////
// Method Name : DeleteLast()
// Parameter   : None
// Description : It is used to Delete the existing node from the 
//               End of the singly linear linked list.
// Author Name : Kranti Laxman Waghamare
// Date        : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: DeleteLast()
{
    struct node<T> * temp = NULL;

    if(this -> first == NULL)
    {
        return;
    }
    else if(this -> first ->next == NULL)
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
    }
    this -> iCount--;
}

//////////////////////////////////////////////////////////////////
// Method Name : DeleteAtPos()
// Parameter   : T iNo
// Description : It is used to Delete the Existing element from  
//               the Given Position of Singly linear linked list. 
// Author Name : Kranti Laxman Waghamare
// Date        : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: DeleteAtPos(int iPos)
{
    int i = 0;

    struct node<T> * temp = NULL;
    struct node<T> * target = NULL;

    if((iPos < 1) || (iPos > this -> iCount))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        this -> DeleteFirst();   
    }
    else if (iPos == this -> iCount)
    {
        this -> DeleteLast();
    }
    else
    {
        temp = this -> first;
    
        for(i = 1; i< iPos - 1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp -> next = target -> next;

        delete target;
        
        this -> iCount--;
    }
    
}

//----------------------------------------------------------------
// Singly Circular Linked List
//----------------------------------------------------------------

//////////////////////////////////////////////////////////////////
// SinglyCL class Declaration
//////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyCL
{
    private : 
        struct node<T>  * first;
        struct node<T>  * last;
        int iCount;

    public :
        SinglyCL();
        
        void Display();
        int Count();

        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

//////////////////////////////////////////////////////////////////
// SinglyCL class Definition
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Method Name : SinglyCL()
// Parameter   : None
// Description : It is a constructor of SinglyCL class.
//               It initializes the linked list by setting the 
//               head pointer to NULL and the node count to zero
//               in the Singly circular linked list.
// Author Name : Kranti Laxman Waghamare
// Date        : 03/09/2026
//////////////////////////////////////////////////////////////////
template<class T>
SinglyCL<T> :: SinglyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////
// Method Name : Display()
// Parameter   : None
// Description : Displays all elements of the Singly circular 
//               linked list by traversing the list from the 
//               first node.
// Author Name : Kranti Laxman Waghamare
// Date        : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T> :: Display()
{
    struct node<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    temp = this->first;

    do
    {
        cout<<" | "<<temp->data<<" | ->";
        temp = temp->next;
    } while (this->last->next != temp);

    cout<<"\n";
    
}

//////////////////////////////////////////////////////////////////
// Method Name : Count()
// Parameter   : None
// Description : Returns the total number of nodes currently 
//               present in the Singly circular linked list.
// Author Name : Kranti Laxman Waghamare
// Date        : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
int SinglyCL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////// 
// Method Name : InsertFirst()
// Parameters   : T iNo
// Description  : Inserts a new node at the beginning of the singly
//                circular linked list and maintains the circular 
//                connection.
// Author       : Kranti Laxman Waghamare
// Date         : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T> :: InsertFirst(T iNo)
{
    struct node<T> * newn = NULL;
    
    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->last->next = this->first;
    this->iCount++;
}

//////////////////////////////////////////////////////////////////// 
// Method Name : InsertLast()
// Parameters   : T iNo
// Description  : Inserts a new node at the end of the singly
//                circular linked list and maintains the circular 
//                connection.
// Author       : Kranti Laxman Waghamare
// Date         : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T> :: InsertLast(T iNo)
{
    struct node<T> * newn = NULL;
    
    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next= newn;
        this->last = newn;
    }
    this->last->next = this->first;
    this->iCount++;
}

//////////////////////////////////////////////////////////////////// 
// Method Name : InsertAtPos()
// Parameters   : T iNo
// Description  : Inserts a new node at the Given position of the 
//                singly circular linked list and maintains the  
//                circular connection.
// Author       : Kranti Laxman Waghamare
// Date         : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T> :: InsertAtPos(T iNo, int iPos)
{
    int i = 0;
    int iCount = 0;
    struct node<T> * temp = NULL;
    struct node<T> * newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    iCount = Count();

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos > iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        temp = this->first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////// 
// Method Name : DeleteFirst()
// Parameters   : None
// Description  : It deletes the Existing the node from the 
//                beginning of the Singly circular linked list and
//                maintains the Circular connections.
// Author       : Kranti Laxman Waghamare
// Date         : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T> :: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->last->next;
        this->last->next = this->first;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////// 
// Method Name : DeleteLast()
// Parameters   : None
// Description  : It deletes the Existing the node from the 
//                end of the Singly circular linked list and
//                maintains the Circular connections.
// Author       : Kranti Laxman Waghamare
// Date         : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T> :: DeleteLast()
{
    struct node<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next != this->last)
        {
            temp = temp->next;
        }

        delete this->last;
        this->last = temp;
        this->last->next = this->first;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////// 
// Method Name : DeleteAtPos()
// Parameters   : None
// Description  : It deletes the Existing the node from the 
//                Given Position of the Singly circular linked list 
//                and maintains the Circular connections.
// Author       : Kranti Laxman Waghamare
// Date         : 03/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
    int i = 0;
    int iCount = 0;
    struct node<T> * temp = NULL;
    struct node<T> * target = NULL;

    iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos > iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;

        delete target;

    }
    this->iCount--;
}

//----------------------------------------------------------------
// Doubly Linear Linked List
//----------------------------------------------------------------

//////////////////////////////////////////////////////////////////
// DoublyLL class Declaration
//////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLL
{
    private : 
        struct node<T>  * first;
        struct node<T>  * last;
        int iCount;

    public :
        DoublyLL();
        
        void Display();
        int Count();

        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

//////////////////////////////////////////////////////////////////
// DoublyLL class Definition
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Method Name  : DoublyLL()
// Parameters   : None
// Description  : It is a constructor of DoublyLL class.
//                It initializes the linked list by setting the 
//                head pointer to NULL and the node count to zero
//                in the Doubly Linear linked list.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
DoublyLL<T> :: DoublyLL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////
// Method Name  : Display()
// Parameters   : None
// Description  : Displays all elements of the doubly Linear 
//                linked list by traversing the list from the 
//                first node.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T> :: Display()
{
    struct node<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    temp = this->first;

    do
    {
        cout<<" | "<<temp->data<<" | ->";
        temp = temp->next;
    } while (this->last->next != temp);

    cout<<"\n";
    
}

//////////////////////////////////////////////////////////////////
// Method Name  : Count()
// Parameters   : None
// Description  : Returns the total number of nodes currently 
//                present in the doubly Linear linked list.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
int DoublyLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////
// Method Name : InsertFirst()
// Parameters   : T iNo
// Description  : Inserts a new node at the beginning of the 
//                doubly linear linked list and updates the 
//                previous and next links.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T> :: InsertFirst(T iNo)
{
    struct node<T> * newn = NULL;
    
    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->last->next = this->first;
    this->iCount++;
}

//////////////////////////////////////////////////////////////////
// Method Name : InsertLast()
// Parameters   : T iNo
// Description  : Inserts a new node at the End of the 
//                doubly linear linked list and updates the 
//                previous and next links.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T> :: InsertLast(T iNo)
{
    struct node<T> * newn = NULL;
    
    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next= newn;
        this->last = newn;
    }
    this->last->next = this->first;
    this->iCount++;
}

//////////////////////////////////////////////////////////////////
// Method Name : InsertAtPos()
// Parameters   : T iNo
// Description  : Inserts a new node at the Given Position of the 
//                doubly linear linked list and updates the 
//                previous and next links.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T> :: InsertAtPos(T iNo, int iPos)
{
    int i = 0;
    int iCount = 0;
    struct node<T> * temp = NULL;
    struct node<T> * newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    iCount = Count();

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos > iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        temp = this->first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////
// Method Name  : DeleteFirst()
// Parameters   : None
// Description  : Deletes a Existing node at the beginning of the 
//                doubly linear linked list and updates next links.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->last->next;
        this->last->next = this->first;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////
// Method Name  : DeleteLast()
// Parameters   : None
// Description  : Deletes a Existing node at the end of the 
//                doubly linear linked list and updates the 
//                previous nodes.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T> :: DeleteLast()
{
    struct node<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next != this->last)
        {
            temp = temp->next;
        }

        delete this->last;
        this->last = temp;
        this->last->next = this->first;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////
// Method Name  : DeleteAtPos()
// Parameters   : None
// Description  : Deletes a Existing node at the Given Position  
//                of the doubly linear linked list and updates the 
//                previous nodes and next links.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    int i = 0;
    int iCount = 0;
    struct node<T> * temp = NULL;
    struct node<T> * target = NULL;

    iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos > iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;

        delete target;

    }
    this->iCount--;
}

//----------------------------------------------------------------
// Doubly Circular Linked List
//----------------------------------------------------------------

//////////////////////////////////////////////////////////////////
// DoublyCL class Declaration
//////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyCL
{
    private :
        struct node<T> * first;
        struct node<T> * last;
        int iCount;

    public :
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

//////////////////////////////////////////////////////////////////
// DoublyCL class Definition
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Method Name  : DoublyCL()
// Parameters   : None
// Description  : It is a constructor of DoublyCL class.
//                It initializes the linked list by setting the 
//                count to zero head and tail pointer to NULL 
//                 and the node in the Doubly Circular linked list.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
DoublyCL<T> :: DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

//////////////////////////////////////////////////////////////////
// Method Name  : Display()
// Parameters   : None
// Description  : Displays all elements of the doubly circular 
//                linked list by traversing the list from the 
//                first node.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T> :: Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    cout<<" <=> "<<endl;

    do
    {
        cout<<" | "<<first->data<<" | <=>";
        first = first->next;
    } while (first != last->next);
    
    cout<<endl;
}

//////////////////////////////////////////////////////////////////
// Method Name  : Count()
// Parameters   : None
// Description  : Returns the total number of nodes currently 
//                present in the doubly circular linked list.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
int DoublyCL<T> :: Count()
{
    struct node<T> * temp = NULL;
    temp = first;

    int iCount = 0;

    if(first == NULL && last == NULL)
    {
        return iCount;
    }

    do
    {
        iCount++;
        temp = temp->next;
    }while(temp != last->next);

    return iCount;
}

//////////////////////////////////////////////////////////////////
// Method Name  : InsertFirst()
// Parameters   : T iNo
// Description  : Inserts a new node at the beginning of the 
//                doubly circular linked list and maintains the 
//                previous and next circular connections.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T> :: InsertFirst(T iNo)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        newn->next = newn;
        newn->prev = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        newn->prev = last;
        last->next = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last; 
    iCount++;   
}

//////////////////////////////////////////////////////////////////
// Method Name  : InsertLast()
// Parameters   : T iNo
// Description  : Inserts a new node at the end of the doubly 
//                circular linked list and maintains the circular 
//                connections.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T> :: InsertLast(T iNo)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        newn->next = newn;
        newn->prev = newn;
    }
    else
    {
       newn->prev = last;
       last->next = newn;
       newn->next = first;
       first->prev = newn;
       last = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;    
}

//////////////////////////////////////////////////////////////////
// Method Name  : InsertAtPos()
// Parameters   : T iNo
// Description  : Inserts a new node at the specified position 
//                in the doubly circular linked list while 
//                maintaining both previous and next circular links.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T> :: InsertAtPos(T iNo, int iPos)
{
    int i = 0;

    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((iPos < 1)||(iPos > iCount + 1))
    {
        cout<<"Invalid position"<<endl;
        return;
    }
   
    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(iNo);
    }
    else 
    {
        temp = first;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp->next;
        }

        newn->next= temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}

//////////////////////////////////////////////////////////////////
// Method Name  : DeleteFirst()
// Parameters   : None
// Description  : Deletes the first node from the doubly circular 
//                linked list and maintains the circular connections.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        free(first);
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////
// Method Name  : DeleteLast()
// Parameters   : None
// Description  : Deletes the last node from the doubly circular 
//                linked list and maintains the previous and next 
//                circular links.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T> :: DeleteLast()
{
    struct node<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        temp = last;

        last = last->prev;
        delete temp;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////
// Method Name  : DeleteAtPos()
// Parameters   : None
// Description  : Deletes a node from the specified position in the
//                doubly circular linked list and maintains both
//                previous and next circular connections.
// Author       : Kranti Laxman Waghamare
// Date         : 04/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T> :: DeleteAtPos(int iPos)
{
    int i = 0;
    struct node<T> * temp = NULL;

    if((iPos < 1)||(iPos > iCount))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for(i = 1; i < iPos; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
    iCount--;
}

//----------------------------------------------------------------
// Stack Data Structure
//----------------------------------------------------------------

//////////////////////////////////////////////////////////////////
// Stack Function Declaration
//////////////////////////////////////////////////////////////////

template<class T>
class Stack
{
    private : 
        struct node<T> * first;
        int iCount;

    public :
        Stack();
        void Push(T No);         
        T Pop();                  
        T Peep();                 
        void Display();
        int Count(); 
};

//////////////////////////////////////////////////////////////////
// Stack Function Definition
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Method Name   : Stack()
// Parameter     : None
// Description   : It is a constructor of Stack class.
//                 It initializes the Stack by setting the 
//                 count to zero head pointer to NULL in Stack
// Author Name   : Kranti Laxman Waghamare
// Date          : 05/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
Stack<T> :: Stack()
{
    first = NULL;
    iCount = 0;
}

//////////////////////////////////////////////////////////////////
// Method Name   : Push()
// Parameter     : T iNo
// Description   : It is used to push the element inside the stack.
// Author Name   : Kranti Laxman Waghamare
// Date          : 05/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: Push(T iNo)   
{
    struct node<T> * newn = NULL;

    newn = new  struct node<T>();

    newn->data = iNo;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}      

//////////////////////////////////////////////////////////////////
// Method Name   : Pop()
// Parameter     : None
// Description   : It is used to remove the element from the stack.
// Author Name   : Kranti Laxman Waghamare
// Date          : 05/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: Pop()    
{
    T iValue = 0;
    struct node<T> * temp = NULL;

    if(first == NULL)
    {
        cout<<"Stack is empty";
        return -1;
    }
    else
    {
        iValue = first->data;
        temp = first;

        first = first->next;
        
        delete(temp);

        iCount--;
        return iValue;
    }
}

//////////////////////////////////////////////////////////////////
// Method Name   : Peek()
// Parameter     : None
// Description   : It return the value of the top element without 
//                 removing it from the stack.
// Author Name   : Kranti Laxman Waghamare
// Date          : 05/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: Peep()  
{
    T iValue = 0;

    if(first == NULL)
    {
        cout<<"Stack is empty";
        return -1;
    }
    else
    {
        iValue = first->data;

        return iValue;
    }
}

//////////////////////////////////////////////////////////////////
// Method Name   : Display()
// Parameter     : None
// Description   : It display the all element present inside the 
//                 stack.
// Author Name   : Kranti Laxman Waghamare
// Date          : 05/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: Display()
{
    struct node<T> * temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |\n";
        temp = temp->next;
    }
}
//////////////////////////////////////////////////////////////////
// Method Name   : Count()
// Parameter     : None
// Description   : It returns the total number of elements 
//                 currently present inside the stack.
// Author Name   : Kranti Laxman Waghamare
// Date          : 05/09/2026
//////////////////////////////////////////////////////////////////
template<class T>
int Stack<T> :: Count()
{
    return iCount;
}

//----------------------------------------------------------------
// Queue Data Structure
//----------------------------------------------------------------

//////////////////////////////////////////////////////////////////
// Queue Function Declaration
//////////////////////////////////////////////////////////////////

template<class T>
class Queue
{
    private : 
        struct node<T> * first;
        int iCount;

    public :
        Queue();
        void Enqueue(T iNo);         
        T Dequeue();                  
        void Display();
        int Count(); 
};

//////////////////////////////////////////////////////////////////
// Queue Function Definition
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Method Name   : Queue()
// Parameter     : None
// Description   : It is a constructor of Queue class.
//                 It initializes the Queue by setting the 
//                 count to zero head pointer to NULL in Queue.
// Author Name   : Kranti Laxman Waghamare
// Date          : 05/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
Queue<T> :: Queue()
{
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////
// Method Name   : Enqueue()
// Parameter     : T iNo
// Description   : It is used to insert the new element in the 
//                 queue.
// Author Name   : Kranti Laxman Waghamare
// Date          : 05/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: Enqueue(T iNo)   
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new  struct node<T>();

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}      

//////////////////////////////////////////////////////////////////
// Method Name   : Dequeue()
// Parameter     : T iNo
// Description   : It is used to Delete the element from the queue.
// Author Name   : Kranti Laxman Waghamare
// Date          : 05/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
T Queue<T> :: Dequeue()    
{
    T iValue = 0;
    struct node<T> * temp = NULL;

    if(this->first == NULL)
    {
        cout<<"Queue is empty";
        return -1;
    }
    else
    {
        iValue = first->data;
        temp = first;

        first = first->next;
        
        delete(temp);

        iCount--;
        return iValue;
    }
}

//////////////////////////////////////////////////////////////////
// Method Name   : Display()
// Parameter     : None
// Description   : It display the all element present inside the 
//                 Queue.
// Author Name   : Kranti Laxman Waghamare
// Date          : 05/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: Display()
{
    struct node<T> * temp = NULL;
    temp = this->first;

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |\n";
        temp = temp->next;
    }
}

//////////////////////////////////////////////////////////////////
// Method Name   : Count()
// Parameter     : None
// Description   : It returns the total number of elements 
//                 currently present inside the Queue.
// Author Name   : Kranti Laxman Waghamare
// Date          : 05/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
int Queue<T> :: Count()
{
    return iCount;
}

//----------------------------------------------------------------
// Binary Search Tree Data Structure
//----------------------------------------------------------------

//////////////////////////////////////////////////////////////////
// Binary Search Tree Declaration
//////////////////////////////////////////////////////////////////

template<class T>
class BST
{
    private :
        struct node<T> * first;
        int iCount;

        void Inorder(node<T> *first);
        void Preorder(node<T> *first);
        void Postorder(node<T> *first);
        int Count(node<T> *first);
        int CountLeaf(node<T> *first); 
        int CountParent(node<T> *first);

    public :
        BST();
        
        void Inorder();
        void Preorder();
        void Postorder();
        void Insert(T iNo); 
        int Count();
        bool Search(T iNo); 
        int CountLeaf(); 
        int CountParent();

};

//////////////////////////////////////////////////////////////////
//Binary Search Tree Definition
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Method Name   : BST()
// Parameter     : None
// Description   : Initializes the Binary Search Tree by setting 
//                 the root pointer to NULL and initializing the 
//                 node count to zero.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
BST<T> :: BST()
{   
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////
// Method Name   : Inorder()
// Parameter     : node<T> *first
// Description   : Performs recursive inorder traversal of the 
//                 Binary Search Tree in Left-Data-Right order.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
//  L   D   R
void BST<T> :: Inorder(node<T> *first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        cout<<first->data<<endl;
        Inorder(first->rchild);
    }
}

//////////////////////////////////////////////////////////////////
// Method Name   : Inorder()
// Parameter     : None
// Description   : Performs inorder traversal of the Binary Search 
//                 Tree by calling the private recursive Inorder 
//                 helper function.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void BST<T> :: Inorder()
{
    Inorder(first);
}

//////////////////////////////////////////////////////////////////
// Method Name   : Preorder()
// Parameter     : node<T> *first
// Description   : Performs recursive preorder traversal of the 
//                 Binary Search Tree in Data-Left-Right order.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

//  D   L   R
template<class T>
void BST<T> :: Preorder(node<T> *first)
{
    if(first != NULL)
    {
        cout<<first->data<<endl;
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

//////////////////////////////////////////////////////////////////
// Method Name   : Preorder()
// Parameter     : None
// Description   : Performs preorder traversal of the Binary 
//                 Search Tree by calling the private recursive 
//                 Preorder helper function.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void BST<T> :: Preorder()
{
    Preorder(first);
}

//////////////////////////////////////////////////////////////////
// Method Name   : Postorder()
// Parameter     : node<T> *first
// Description   : Performs recursive postorder traversal of the 
//                 Binary Search Tree in Left-Right-Data order.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

//  L   R   D
template<class T>
void BST<T> :: Postorder(node<T> *first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        cout<<first->data<<endl;
    }
}

//////////////////////////////////////////////////////////////////
// Method Name   : Postorder()
// Parameter     : None
// Description   : Performs postorder traversal of the Binary 
//                 Search Tree by calling the private recursive 
//                 Postorder helper function.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void BST<T> :: Postorder()
{
    Postorder(first);
}

//////////////////////////////////////////////////////////////////
// Method Name   : Insert()
// Parameter     : T iNo
// Description   : Inserts a new element into the Binary Search 
//                 Tree according to the BST property. Duplicate 
//                 elements are not inserted.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
void BST<T> :: Insert(T iNo)        
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(1)
        {
            if(iNo > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(iNo < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(iNo == temp->data)
            {
                cout<<"Unable to insert as element is duplicate"<<endl;
                delete newn;
                break;
            }
        }
    }

}

//////////////////////////////////////////////////////////////////
// Method Name   : Count()
// Parameter     : node<T> *first
// Description   : Recursively counts and returns the total number 
//                 of nodes present in the Binary Search Tree.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
int BST<T> :: Count(node<T> *first)
{
    int iCount = 0;

    if(first != NULL)
    {
        iCount++;
        iCount = iCount + Count(first->lchild);
        iCount = iCount + Count(first->rchild);
    }
    return iCount;
}

//////////////////////////////////////////////////////////////////
// Method Name   : Count()
// Parameter     : None
// Description   : Returns the total number of nodes present in 
//                 the Binary Search Tree by calling the private 
//                 recursive Count function
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
int BST<T> :: Count()
{
    return Count(first);
}

//////////////////////////////////////////////////////////////////
// Method Name   : Search()
// Parameter     : T iNo
// Description   : Searches for the specified element in the Binary 
//                 Search Tree and returns true if the element is
//                 present, otherwise false.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
bool BST<T> :: Search(T iNo)
{
    bool bFlag = false;
    struct node<T> * temp = first;
    
    while(temp != NULL)
    {
        if(iNo == temp->data)
        {
            bFlag = true;
            break;
        }
        else if(iNo > temp->data)
        {
            temp = temp->rchild;
        }
        else if(iNo < temp->data)
        {
            temp = temp->lchild;
        }
    }
    return bFlag;
}

//////////////////////////////////////////////////////////////////
// Method Name   : CountLeaf()
// Parameter     : node<T> *first
// Description   : Recursively counts and returns the total number 
//                 of leaf nodes present in the Binary Search Tree.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
int BST<T> :: CountLeaf(node<T> *first)
{
    int iCount = 0;

    if(first != NULL)
    {
        if((first->rchild == NULL) && (first->lchild == NULL))
        {
            iCount++;
        }
        iCount = iCount + CountLeaf(first->lchild);
        iCount = iCount + CountLeaf(first->rchild);
    }
    return iCount;
}

//////////////////////////////////////////////////////////////////
// Method Name   : CountLeaf()
// Parameter     : None
// Description   : Returns the total number of leaf nodes in the 
//                 Binary Search Tree by calling the private 
//                 recursive CountLeaf function.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
int BST<T> :: CountLeaf()
{
    return CountLeaf(first);
}

//////////////////////////////////////////////////////////////////
// Method Name   : CountParent()
// Parameter     : node<T> *first
// Description   : Recursively counts and returns the total number 
//                 of parent nodes having at least one child in 
//                 the Binary Search Tree.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
int BST<T> :: CountParent(node<T> *first)
{
    int iCount = 0;

    if(first != NULL)
    {
        if((first->rchild != NULL) || (first->lchild != NULL))
        {
            iCount++;
        }
        iCount = iCount + CountParent(first->lchild);
        iCount = iCount + CountParent(first->rchild);
    }
    return iCount;
}

//////////////////////////////////////////////////////////////////
// Method Name   : CountParent()
// Parameter     : None
// Description   : Returns the total number of parent nodes in 
//                 the Binary Search Tree by calling the private 
//                 recursive CountParent function.
// Author Name   : Kranti Laxman Waghamare
// Date          : 06/09/2026
//////////////////////////////////////////////////////////////////

template<class T>
int BST<T> :: CountParent()
{
    return CountParent(first);
}

