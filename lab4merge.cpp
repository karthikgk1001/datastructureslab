#include<iostream>
#include "list.h"
using namespace std;

int main()
{
    List l1,l2,l3;
    int choice,num,exit=0;
    while(exit!=1)
    {
        cout << "1.Insert in list 1\n2.Insert in list 2\n3.Merge lists\n4.Display list 1\n5.Display list 2\n6.Display merged list\n7.Exit\n";
        cin >> choice;
        switch(choice)
        {
            case 1: 
                cout << "Enter number to insert in list 1: ";
                cin >> num;
                l1.insert_ascending(num);
                break;
            case 2: 
                cout << "Enter number to insert in list 2: ";
                cin >> num;
                l2.insert_ascending(num);
                break;
            case 3: 
                l3=l3.merge(l1,l2);
                break;
            case 4: 
                l1.display();
                break;
            case 5: 
                l2.display();
                break;
            case 6: 
                l3.display();
                break;
            case 7: 
                exit=1;
                break;
            default: 
                cout << "Invalid choice\n";
        }
    }
}