#include "pqueueshpp.h"
#include <iostream>
#include <string>

using namespace std;

int main(){

    PQueueSHPP<string> prior;
    prior.enqueue("Vlad",5);
    prior.enqueue("Valik",3);
    prior.enqueue("Ilona",10);
    prior.enqueue("Olya", -3);

    prior.changePriority("Olya", 15);

    cout << "size : "<< prior.size() << endl;

    cout << "is empty " << prior.isEmpty() << endl;

    cout << "peek value " << prior.peek() << endl;

    cout << "peek priority " << prior.peekPriority() << endl;


    for(int i = 0; i < 4; i++){
        cout << prior.dequeue() << endl;
    }
    return 0;
}
