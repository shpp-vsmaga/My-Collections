#include <iostream>
#include <dequeshpp.h>

using namespace std;

int main(){
    DequeSHPP<int> deque;
    for (int i = 1; i <= 13; i++){
        deque.push_back(i);
        deque.push_front(i);
    }

    cout << "Size: " << deque.size() << endl;

    cout << "Operator []: " << endl;
    for (int i = 0; i < deque.size(); i++){
        cout << deque[i] << " ";
    }
    cout << endl <<"pop_front: " << endl;
    for (int i = 0; i < 5; i++){
        cout << deque.pop_front() << " ";
    }
    cout << endl << "pop_back: " << endl;
    for (int i = 0; i < 7; i++){
        cout << deque.pop_back() << " ";
    }
    cout << endl;
    cout << "Size: " << deque.size() << endl;
    //deque.clear();
    cout << "Size: " << deque.size() << endl;
    cout << "Operator []: " << endl;
    for (int i = 0; i < deque.size(); i++){
        cout << deque[i] << " ";
    }

    cout << endl << "front: " << deque.front() << endl;
    cout << endl << "back: " << deque.back() << endl;
    return 0;
}
