/*
	Nuon, Molita

	CS A250
	April 18, 2018

	Lab 10
*/

#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

const int CAP = 50;

template<typename T>
class DArray
{
	template<typename T>
	friend ostream& operator<<(ostream& out, const DArray<T>& arr);

public:
    DArray( );
    DArray(int newCapacity);
	DArray(const DArray<T>& otherArray);

    void addElement(const T&);

	int getCapacity() const;
	int getNumOfElem() const;	

	T& operator[](int idx) const;
	DArray<T>& operator=(const DArray<T>& otherArray);
	
	~DArray( ); 

	//*********************************************

	// Declaration deleteElement
	void deleteElement(const T& element);

	// Declaration search
	bool search(const T& element) const;

	// Declaration emptyArray
	void emptyArray();

	// Declaration isEmpty
	bool isEmpty() const;
	
	// Declaration isFull
	bool isFull() const;

private:
    T *a;				
    int capacity;		
    int numOfElem;		

};

#endif