#include "pqueueshpp.h"
#include <iostream>
#include <string>


using namespace std;

PQueueSHPP<string> getQueue();


int main(){

    int a = 6;
    int b = a % 2;
    cout << b << endl << endl;

   PQueueSHPP<string> prior = getQueue();


    //PQueueSHPP<string> prior;

//   prior.enqueue("Valik",4);
//   prior.enqueue("Ilona",4);
//   prior.enqueue("Olya", 4);
//   prior.enqueue("Olya", 4);
//   prior.enqueue("Olya", 4);
//   prior.enqueue("Olya", 4);
//   prior.enqueue("Valik",6);


    cout << "size : "<< prior.size() << endl;

    cout << "is empty " << prior.isEmpty() << endl;

    cout << "peek value " << prior.peek() << endl;

    cout << "peek priority " << prior.peekPriority() << endl;

    cout << endl;

    //prior.toStr();
    while(prior.size() != 0){
        double i = prior.peekPriority();
        cout  << i << " " <<prior.dequeue() << endl;
    }

    cout << "End" << endl;

    return 0;
}



PQueueSHPP<string> getQueue(){
    PQueueSHPP<string> prior;

    prior.enqueue("Vlad",5);
    prior.enqueue("Valik",3);
    prior.enqueue("Ilona",10);
    prior.enqueue("Olya", 25);
    prior.enqueue("Olya", 12);
    prior.enqueue("Olya", 11);
    prior.enqueue("Olya", 454);
    prior.enqueue("Olya", 345);
    prior.enqueue("Olya", 75);
    prior.enqueue("Olya", 23);
    prior.enqueue("Olya", 5665);
    prior.enqueue("Olya", 34);
    prior.enqueue("Olya", 34);
    prior.enqueue("Olya", 767);
    prior.enqueue("Olya", 43);
    prior.enqueue("Olya", 45);
    prior.enqueue("Olya", 343);
    prior.enqueue("Olya", 34);
    prior.enqueue("Olya", 43);
    prior.enqueue("Olya", 67);
    prior.enqueue("Olya", 454);
    prior.enqueue("Olya", 743);
    prior.enqueue("Olya", 157);
    prior.enqueue("Olya", 34);
    prior.enqueue("Olya", 76);
    prior.enqueue("Olya", 78);
    prior.enqueue("Olya", 565);
    prior.enqueue("Olya", 565);
    prior.enqueue("Olya", 345);
    prior.enqueue("Olya", 34);
    return prior;

}
