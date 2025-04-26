#include <iostream>
using namespace std;

class ListADT{
    private:
    int arr[5];
    int size;
    
    public:
    ListADT():size(0){}

    void insertBeginning(int value){
        if (size==5){
            cout << "List is full\n";
            return;
        }
        for (int i = size;i>0;i--){
            arr[i]=arr[i-1];
            arr[0]=value;
            size++;

        }

    }

    void insertEnd(int value){
        if (size==5){
            cout << "List is full\n";
            return;
        }
        arr[size++]=value;
    }
    void insertPosition(int value,int pos){
        if (size==5){
            cout << "List is full\n";
            return;
        }
        if (pos < 1 || pos >size+1){
            cout << "Invalid position\n";
            return;
        }
        for (int i = size ; i>=pos;i--){
            arr[i]=arr[i-1];
            arr[pos-1]=value;
            size++;
        }
        
    }

    void deleteBeginning(){
        if ( size == 0){
            cout << "List is empty\n";
            return;
        }
        for (int i = 0;i<size-1;i++){
            arr[i]=arr[i+1];
            size -- ;
        }
    }

    void deleteEnd(){
        if (size==0){
            cout << "List is Empty\n";
            return;
        }
        size--;

    }

    void deletePosition(int pos){
        if (size==0){
            cout << "List is empty\n";
            return;
        }
        if ( pos < 1 || pos > size ){
            cout << "Invalid position\n";

        }
        for ( int i =pos-1;i<size-1;i++){
            arr[i]=arr[i+1];
            size--;

            }
        }
    
    void search(int value){
        for(int i = 0 ; i <size ; i ++){
            if (arr[i]==value){
                cout<<"Element found\n";
                return;            
            }
     
        }
        cout<<"Element not found\n";
    }

    void display(){
        if (size == 0){
            cout << "List is empty\n";
            return;

        }
        cout << "List: ";
        for (int i = 0 ; i < size ; i++){
            cout << arr[i] << " ";

        }
        cout<<endl;
    }

    void rotate(int k){

        if (size==0){
            cout << "Empty list\n";
            return;
        }
        k=k%size;

        if ( k == 0){
            return;

        }
        reverse(0,size -1); //reverse entire array

        reverse(0,k-1); //reverse first k elements
        reverse(k,size-1); // reverse remaining elements
    }
    private:
    void reverse (int l,int r){
        while ( l<r ){
            swap(arr[l++],arr[r--]);
        }
    }
};
int main(){
    ListADT list;
    int choice , value , pos , k ;
    do {
        cout << "1.Insert Beginning\n2.Insert End\n3.Insert Position\n";
        cout << "4.Delete Beginning\n5.Delete End\n6.Delete Position\n";
        cout << "7.Search\n8.Display\n9.Rotate\n10.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            cout << "Enter value; ";
            cin >> value;
            list.insertBeginning(value);
            break;

            case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
            break;

            case 3:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> pos;
            list.insertPosition(value,pos);
            break;


            case 4:
            list.deleteBeginning();
            cout << "Deletion successful\n";
            break;


            case 5:
            list.deleteEnd();
            cout << "Deletion successful\n";
            break;


            case 6:
            cout << "Enter position: ";
            cin >> pos;
            list.deletePosition(pos);
            cout << "Deletion successful\n";
            break;


            case 7:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;


            case 8:
            list.display();
            break;


            case 9 :
            cout << "Enter k (rotation times): ";
            cin >> k;
            list.rotate(k);
            break;

            
            case 10:
            cout << "Exiting program\n";
            break;

            default:
            cout << "Invalid choice";
        }

    }while (choice != 10);
    
    
    return 0;
           

}