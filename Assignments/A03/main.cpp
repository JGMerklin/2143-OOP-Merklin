/*****************************************************************************
*
*  Author:           Julia Merklin
*  Email:            jgmerklin0525@my.msutexas.edu
*  Label:            A03
*  Title:            Basic Project Organization
*  Course:           CMPS 2143
*  Semester:         Spring 2023
*
*  Description:
*        This program implements a queue using an array. It creates a class called CircularArrayQue
*        that contains the necessary variables and functions. Using this class, the user can create
         a queue, "push" an integer variable to the rear of the queue, and "pop" an integer variable
         from the front of the queue. 
*
*
*  Files:            main.cpp
*****************************************************************************/

#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 *
 * Description:
 *      This class allows the user to create a queue using an array.
 *
 * Public Methods:
 *      CircularArrayQue()
 *      CircularArrayQue(int size)
 *      void Push(int item)
 *      int Pop()
 *      ostream& operator<<(ostream& os, const CircularArrayQue& other)
 *
 * Private Methods:
 *      void init(int size)
 *      bool Full()
 * 
 * Usage:
 *
 *      CircularArrayQueue q1;              //Create a queue of the default size 10
 *      CircularArrayQueue q2(5);           //Create a queue of a chosen size
 * 
 *      q1.Push(27);                        //Push an integer on the queue
 *      int i = q1.Pop();                   //Pop an integer off the queue
 *
 */
class CircularArrayQue {
private:
    int* Container; //The Queue
    int Front;      //First place in the queue
    int Rear;       //Last place in the queue
    int QueSize;    //items in the queue
    int CurrentSize;//Current size of the queue

  /**
   * Private : init
   *
   * Description:
   *      Initializes the queue
   *
   * Params:
   *      int size : size of queue
   *
   * Returns:
   *      void
   */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

  /**
   * Private : Full
   *
   * Description:
   *      Checks if the queue is full
   *
   * Params:
   *      none
   *
   * Returns:
   *      bool : Whether or not the queue is full
   */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
   /**
   * Public : CircularArrayQue
   *
   * Description:
   *      Default constructor
   *
   * Params:
   *      none
   *
   * Returns:
   *      none
   */
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }

   /**
   * Public : CircularArrayQue
   *
   * Description:
   *      Constructor
   *
   * Params:
   *      int size : size of queue
   *
   * Returns:
   *      none
   */
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
     * Public : Push
     *
     * Description:
     *      Adds an item to the rear of the queue
     *
     * Params:
     *      int item : The item added to the queue
     *
     * Returns:
     *      void
     */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        }
        else {
            cout << "FULL!!!!" << endl;
        }
    }

    /**
     * Public : Pop
     *
     * Description:
     *      Removes an item from the front of the queue
     *
     * Params:
     *      none
     *
     * Returns:
     *      int : the item removed from the queue
     */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream& operator<<(ostream& os, const CircularArrayQue& other);
};

    /**
     * Public : operator<<
     *
     * Description:
     *      Overloads the << operator to allow us to print the queue by simply using cout
     *
     * Params:
     *      ostream& os
     *      CircularArrayQue& other
     *
     * Returns:
     *      ostream&
     */
ostream& operator<<(ostream& os, const CircularArrayQue& other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 *
 * For this program, the main driver was used to test the CircularArrayQue class
 *
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}