#include <iostream>
#include "vectorshpp.h"

using namespace std;

int main(){
    VectorSHPP<int> sv;

    for(int i = 0; i < 10; i++){
        sv.add(i);
    }

    sv.insert(3, 25);

    for(int i = 0; i < sv.size(); i++){
        cout << sv.get(i) << endl;
    }
    sv.remove(3);

    cout << endl;

    for(int i = 0; i < sv.size(); i++){
        cout << sv[i] << endl;
    }
    sv.remove(77);
    return 0;
}
