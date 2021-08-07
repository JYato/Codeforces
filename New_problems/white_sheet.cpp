#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int wx1,wy1,wx2,wy2;
    cin >> wx1 >> wy1 >> wx2 >> wy2;
    for(int i = 0; i < 2; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        if(x1 <= wx1 && x2 >= wx2){
            if(y1 <= wy1)
            wy1 = max(wy1,y2);
            
            if(y2 >= wy2)
            wy2 = min(wy2,y1);
        }
        
        if(y1 <= wy1 && y2 >= wy2){
            if(x1 <= wx1)
            wx1 = max(wx1,x2);
            
            if(x2 >= wx2)
            wx2 = min(wx2,x1);
        }
        
        if(wy1 > wy2 || wx1 > wx2)
        {
            cout << "NO";
            return 0;
        }
        
    }
    
    cout << "YES";
    return 0;
}