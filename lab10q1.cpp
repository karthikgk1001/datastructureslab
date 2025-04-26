#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    
    
    int test_case;
    cin>>test_case;
    
    
    for(int i  = 0 ; i < test_case;i++)
    {
        int size;
        vector <int> v1;
        unordered_set<int>u1;
        cin >> size;
        for (int j = 0 ; j < size; j ++)
        {
            int element;
            cin >> element;
            v1.push_back(element);
        }

        int count = 1;
        u1.insert(v1[size-1]);
        if(size == 1)
        {
            cout<<0<<endl;
        }
        for (int k = size -2; k >= 0; k--)
        {
            
            if(u1.count(v1[k]) == 0)
            {
                u1.insert(v1[k]);
                count ++;
                if(count == size){
                    cout<<size-count<<endl;
                    break;
                }

            }
            else{
                cout<<(size - count)<<endl;
                break;
            }
        }
        v1.clear();
        u1.clear();
        
    }
    return 0;
}