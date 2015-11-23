#include <iostream>
#include "stackshpp.h"

using namespace std;

main(){
    StackSHPP<int> stack;

    for (int i = 0; i < 10; i++){
        stack.push(i);
        cout << "Size: " << stack.size() << endl;
    }

    //stack.clear();
    for (int i = 0; i < 10; i++){
        int a = stack.pop();
        cout << "Pop: " << a << endl;
        cout << "isEmpty: " << stack.isEmpty() << endl;
        cout << "Peek: " << stack.top() << endl;
    }

    stack.clear();


    return 0;
}
