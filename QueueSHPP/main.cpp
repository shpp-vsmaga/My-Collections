#include <iostream>
#include <queueshpp.h>

using namespace std;

int main(){
    QueueSHPP<int> queue;
    for(int i = 0; i < 10; i++){
        queue.enqueue(i);
    }
    cout << "Size: " << queue.size() << endl;
    for(int i = 0; i < 10; i++){
        cout << queue.dequeue()<< endl;
    }
    return 0;
}
