#include<iostream>
using namespace std;

class SLL
{
    struct node
    {
        int data;
        struct node* next;
    }*head;
    
    public:
    SLL()
    {
        head=NULL;
    }
    void insert_beg(int num)
    {
        struct node* newnode=new struct node;
        newnode->data=num;
        newnode->next=head;
        head=newnode;
    }
    void insert_end(int num)
    {
        if(head==NULL)
        {
            insert_beg(num);
        }
        else
        {
            struct node* newnode=new struct node;
            newnode->data=num;
            newnode->next=NULL;
            struct node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    void insert_pos(int num,int pos)
    {
        struct node* newnode=new struct node;
        newnode->data=num;
        struct node *temp=head;
        if(pos==1)
        {
            insert_beg(num);
        }
        else if (pos==count()+1)
        {
            insert_end(num);
        }
        else
        {
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    void delete_beg()
    {
        if(head==NULL)
        {
            cout << "List is empty";
        }
        else
        {
            struct node* temp = head->next;
            free(head);
            head=temp;
        }
    }
    void delete_end()
    {
        if(head==NULL)
        {
            cout << "List is empty";
        }
        else
        {
            struct node *temp=head;
            if(temp->next=NULL)
            {
                delete_beg();
            }
            else
            {
                while(temp->next->next!==NULL)
                {
                    temp=temp->next;
                }
                free(temp->next);
                temp->next=NULL;
            }
        }
    }
    void delete_pos(int pos)
    {
        if(pos==1)
        {
            delete_beg();
        }
        else if (pos==count())
        {
            delete_end();
        }
        else
        {
            struct node *temp=head;
            struct node *temp2;
            for(int i=1;i<pos;i++)
            {
                temp=temp->next;
            }
            temp2=temp->next->next;
            free(temp->next);
            temp->next=temp2;
        }
    }
    void display()
    {
        struct node *temp=head;
        if(head==NULL)
        {
            cout << "List is empty";
        }
        else
        {
            while(temp!=NULL)
            {
                cout << temp->data << " ->";
                temp=temp->next;
            }
            cout << "\n";
        }
    }
    void search(int num)
    {
        struct node *temp=head;
        if(head==NULL)
        {
            cout << "List is empty";
        }
        else
        {
            while(temp!=NULL)
            {
                if(temp->data==num)
                {
                    cout << "Element found\n";
                    return;
                }
                temp=temp->next;
            }
            cout << "Element not found\n";
        }
    }
    int count()
    {
        struct node *temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        return c;
    }
    void reverse_link()
    {
        struct node *temp=head;
        int len=count();
        struct node* arr[len];
        for(int i=0;i<len;i++)
        {
            arr[i]=temp;
            temp=temp->next;
        }
        struct node* arr2[len];
        for(int i=0;i<len;i++)
        {
            arr2[i]=arr[len-1-i];
        }
        head=arr2[0];
        temp=head;
        for(int i=1;i<len;i++)
        {
            temp->next=arr2[i];
            temp=temp->next;
        }
        temp->next=NULL;
    }
    void rev_display()
    {
        int len=count();
        int arr[len];
        struct node *temp=head;
        if(head==NULL)
        {
            cout << "List is empty";
        }
        else
        {   int i=0;
            while(temp!=NULL)
            {
                arr[len-1-i]=temp->data;
                temp=temp->next;
                i++;
            }
            for(int j=0;j<len;j++)
            {
                cout << arr[j] << " ";
            }
        }
    }
    
};

int main()
{
    SLL list;
    int choice,num,pos,exit=0;
    while(exit!=1)
    {
        cout << "1.Insert Beginning\n2.Insert End\n3.Insert Position\n4.Delete Beginning\n5.Delete End\n6.Delete Position\n7.Display\n8.Search\n9.Reverse Link\n10.Reverse Display\n11.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter the number:";
                cin >> num;
                list.insert_beg(num);
                break;
            case 2:
                cout << "Enter the number:";
                cin >> num;
                list.insert_end(num);
                break;
            case 3:
                cout << "Enter the number and position:";
                cin >> num >> pos;
                list.insert_pos(num,pos);
                break; 
            case 4:
                list.delete_beg();
                break;  
            case 5:
                list.delete_end();
                break;  
            case 6:
                cout << "Enter the position:";
                cin >> pos;
                list.delete_pos(pos);
                break; 
            case 7:
                list.display();
                break;
            case 8:
                cout << "Enter the element to search:";
                cin >> num;
                list.search(num);
                break;
            case 9:
                list.reverse_link();
                break;
            case 10:
                list.rev_display();
                break;
            case 11:
                exit=1;
                break;

        }
    }
}