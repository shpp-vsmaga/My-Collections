/* File: dequeshpp.h
 * -----------------------------------------------------
 * This file exports a simple version of the Deque class.
 * Deque is a sequence container with dynamic size that can
 * be expanded or contracted on both ends.
 */

#ifndef DEQUESHPP_H
#define DEQUESHPP_H

#include <iostream>

const int MAX_ARRAY_SIZE = 10;

/* Class: DequeSHPP<ValueType>
 * ---------------------------------------------------
 * This clas implements deque of a specified ValueType
 * elements
 */
template <typename ValueType>
class DequeSHPP{

    /* Public methods prototypes*/
public:

    /**
     * Constructor: DequeSHPP
     * Usage: DequeSHPP<ValueType> deque;
     * -----------------------------------------------
     * Initializes a new empty deque
     */
    DequeSHPP();

    /**
     * Destructor: ~DequeSHPP
     * ----------------------------------------------
     * Frees all allocated memory for the deque elements
     */
    virtual ~DequeSHPP();

    /**
     * Method: push_back
     * Usage: deque.push_back(value);
     * ---------------------------------------------
     * Adds a new element to the end of the deque
     */
    void push_back(ValueType);

    /**
     * Method: push_front
     * Usage: deque.push_front(value);
     * ---------------------------------------------
     * Adds a new element to the beginning of the deque
     */
    void push_front(ValueType);

    /**
     * Method: pop_back
     * Usage: value = deque.pop_back();
     * ---------------------------------------------
     *
     * Returns the value of the last element and removes it
     * from the deque.
     */
    ValueType pop_back();

    /**
     * Method: pop_front
     * Usage: value = deque.pop_front();
     * ---------------------------------------------
     *
     * Returns the value of the first element and removes it
     * from the deque.
     */
    ValueType pop_front();


    /**
     * Method: clear
     * Usage: deque.clear();
     * ---------------------------------------------
     * Removes all elements of the deque
     */
    void clear();

    /**
     * Method: size
     * Usage: int size = deque.size();
     * --------------------------------------------
     * Return current number of the elements of the
     * deque
     */
    int size() const;

    /**
     * Method: empty
     * Usage: if(deque.empty())...
     * --------------------------------------------
     * Returns true if current number of the elements
     * is 0.
     */
    bool empty() const;

    /**
     * Method: front
     * Usage: value = deque.front();
     * -----------------------------------------------
     * Returns the value of the first element without
     * removing it from the deque.
     */
    ValueType& front();

    /**
     * Method: back
     * Usage: value = deque.back();
     * -----------------------------------------------
     * Returns the value of the last element without
     * removing it from the deque.
     */
    ValueType& back();

    /**
     * Operator: []
     * Usage: value = deque[index];
     * -----------------------------------------------------
     * Overloads [] operator to access any element of the deque
     * by it's index.
     */
    ValueType& operator[](int);


    /* Private methods prototypes and instase variables*/
private:

    /* Current number of the elements in the deque*/
    int count;

    /* Structure for saving elements of the deque*/
    struct Cell{
        ValueType *array;
        Cell* next;
        Cell* prev;
        int arrayBegin;
        int arraySize;
    };

    /* Pointers to the first and last cell of the deque*/
    Cell* begin;
    Cell* end;

    /* Private functions prototypes*/

    /**
     * Method: getNewCell
     * -----------------------------------------------
     * Creates new empty cell and array in it and returns
     * pointer to this cell
     */
    Cell* getNewCell();

    /**
     * Method: getCellByIndex
     * -----------------------------------------------
     * Returns pointer to the cell placed in the list
     * by the received index
     */
    Cell* getCellByIndex(int);

    /**
     * Method: clearMemory
     * -----------------------------------------------
     * Frees all memory allocated to the elements of the
     * deque and arrays in them;
     */
    void clearMemory(Cell*);

};


template <typename ValueType>
DequeSHPP<ValueType>::DequeSHPP(){
    count = 0;
    begin = end = 0;
    }

template <typename ValueType>
DequeSHPP<ValueType>::~DequeSHPP(){
    clear();
}

template <typename ValueType>
void DequeSHPP<ValueType>::push_back(ValueType value){
    if (end == 0){
        begin = end = getNewCell();
    }

    if(end->arrayBegin + end->arraySize == MAX_ARRAY_SIZE){
        Cell* newEnd = getNewCell();
        newEnd->prev = end;
        end->next = newEnd;
        end = newEnd;
        end->array[end->arrayBegin] = value;
        end->arraySize++;
        count++;        
    } else {
        end->array[end->arrayBegin + end->arraySize] = value;
        end->arraySize++;
        count++;
    }
}

template <typename ValueType>
void DequeSHPP<ValueType>::push_front(ValueType value){

    if (begin == 0){
        begin = end = getNewCell();
        begin->arrayBegin = MAX_ARRAY_SIZE - 1;        
    }

    if(begin->arrayBegin == 0){
        Cell* newBegin = getNewCell();
        begin->prev = newBegin;
        newBegin->next = begin;
        begin = newBegin;
        begin->arrayBegin = MAX_ARRAY_SIZE;
        begin->array[begin->arrayBegin - 1] = value;
        begin->arrayBegin--;
        begin->arraySize++;
        count++;
    } else {
        begin->array[begin->arrayBegin - 1] = value;
        begin->arrayBegin--;
        begin->arraySize++;
        count++;
    }
}

template <typename ValueType>
ValueType DequeSHPP<ValueType>::pop_front(){
    if (empty()){
        std::cout << "pop_front: Deque is empty" << std::endl;
        exit (1);
    }
    ValueType result  = begin->array[begin->arrayBegin];

    if (begin->arrayBegin == MAX_ARRAY_SIZE - 1){        
        Cell* oldBegin = begin;
        begin = begin->next;
        delete[] oldBegin->array;
        delete oldBegin;
        count--;
    } else {
        count--;
        begin->arraySize--;
        begin->arrayBegin++;
    }
    return result;
}


template <typename ValueType>
ValueType DequeSHPP<ValueType>::pop_back(){
    if (empty()){
        std::cout << "pop_back: Deque is empty" << std::endl;
        exit (1);
    }

    ValueType result = end->array[end->arraySize - 1];
    if(end->arraySize == 1){
        Cell* oldEnd = end;
        end = end->prev;
        end->next = 0;
        delete[] oldEnd->array;
        delete oldEnd;
        count--;
    } else {
        end->arraySize--;
        count--;
    }
    return result;
}

template <typename ValueType>
ValueType& DequeSHPP<ValueType>::front(){
    if (empty()){
        std::cout << "front: Deque is empty" << std::endl;
        exit (1);
    }
    return begin->array[begin->arrayBegin];
}

template <typename ValueType>
ValueType& DequeSHPP<ValueType>::back(){
    if (empty()){
        std::cout << "back: Deque is empty" << std::endl;
        exit (1);
    }
    return end->array[end->arrayBegin + end->arraySize - 1];
}

template <typename ValueType>
ValueType& DequeSHPP<ValueType>::operator [](int index){
    if (index >= count){
        std::cout << "operator []: index is out of range" << std::endl;
        exit(1);
    }
    index += begin->arrayBegin;
    int cellIndex = index / MAX_ARRAY_SIZE;
    Cell* currentCell = getCellByIndex(cellIndex);
    int elemIndex = (index % MAX_ARRAY_SIZE);
    return currentCell->array[elemIndex];
}

template <typename ValueType>
int DequeSHPP<ValueType>::size() const{
    return count;
}

template <typename ValueType>
bool DequeSHPP<ValueType>::empty() const{
    return size() == 0;
}

template <typename ValueType>
void DequeSHPP<ValueType>::clear(){
    if (begin != 0){
        clearMemory(begin);
    }
    count = 0;
}


template <typename ValueType>
typename DequeSHPP<ValueType>::Cell* DequeSHPP<ValueType>::getNewCell(){
    Cell* newCell = new Cell;
    newCell->array = new ValueType[MAX_ARRAY_SIZE];
    newCell->next = newCell->prev = 0;
    newCell->arrayBegin = 0;
    newCell->arraySize = 0;
    return newCell;
}

template <typename ValueType>
typename DequeSHPP<ValueType>::Cell* DequeSHPP<ValueType>::getCellByIndex(int index){
    Cell* result = begin;
    for(int i = 0; i < index; i++){
        result = result->next;
    }
    return result;
}


template <typename ValueType>
void DequeSHPP<ValueType>::clearMemory(Cell* cell){
    if(cell->next != 0){
        clearMemory(cell->next);
    }    
    delete[] cell->array;
    delete cell;
}


#endif // DEQUESHPP

