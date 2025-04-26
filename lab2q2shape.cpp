#include <iostream>
using namespace std;
class Area{
    private:
    int length;
    int breadth;
    int height;

    public:
    Area(int l,int b , int h){
        length=l;
        breadth=b;
        height=h;
    }
    
    int area_square();
    int area_cube();
    int area_rect();
    int area_cuboid();

};

int main(){
    int l,b,h;
    cout << "\nEnter the length";
    cin >> l;
    cout << "\nEnter the breadth";
    cin >> b;
    cout << "\nEnter the height";
    cin >> h; 

    Area shape(l,b,h);

    int choice;

    while (true){
        cout << "\n1.Square";
        cout << "\n2.Cube";
        cout << "\n3.Rectangle";
        cout << "\n4.Cuboid";
        cout << "\n5.Exit";
        cout << "\nEnter your choice";
        cin >> choice;

        if (choice==5){
            cout << "Exiting Program";
            break;
        }
        switch (choice){
            case 1:
            cout << shape.area_square();
            break;

            case 2:
            cout << shape.area_cube();
            break;
            case 3:
            cout << shape.area_rect();
            break;
            case 4:
            cout << shape.area_cuboid();
            break;
        }

    }
}
int Area::area_square(){
    return length*length;
}
int Area::area_cube(){
    return 6*length*length;
}
int Area::area_rect(){
    return length*breadth;
}
int Area::area_cuboid(){
    return 2*((length*breadth)+ (breadth*height)+(height*length));
}

