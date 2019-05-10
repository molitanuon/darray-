/*
	Nuon, Molita 

	CS A250
	April 18, 2018

	Lab 10
*/

#include "DArray.h"

template<typename T>
ostream& operator<<(ostream& out, const DArray<T>& arr)
{
	//Assume array is non-empty.

	for (int i = 0; i < arr.numOfElem; ++i)
		out << arr.a[i] << " ";

	return out;
}

template<typename T>
DArray<T>::DArray()
{
    capacity = CAP;
	a = new T[capacity];	
	numOfElem = 0;
}

template<typename T>
DArray<T>::DArray(int newCapacity)
{
	capacity = newCapacity;
    a = new T[capacity];
	numOfElem = 0;	 
}

template<typename T>
DArray<T>::DArray(const DArray<T>& otherArray)
{
	capacity = otherArray.capacity;	
	a = new T[capacity];
	numOfElem = otherArray.numOfElem;

	for (int i = 0; i < numOfElem; ++i)
		a[i] = otherArray.a[i];
}

template<typename T>
void DArray<T>::addElement(const T& element)
{
	a[numOfElem] = element;
    ++numOfElem;
}

template<typename T>
int DArray<T>:: getCapacity() const
{
	return capacity;
}

template<typename T>
int DArray<T>::getNumOfElem() const
{
	return numOfElem;
}

template<typename T>
T& DArray<T>::operator[](int idx) const
{
	return a[idx];
}

template<typename T>
DArray<T>& DArray<T>::operator=(const DArray<T>& otherArray)
{
	if (&otherArray != this)
	{
		if (capacity != otherArray.capacity)
		{
			delete[] a; //release space
			a = new T[otherArray.capacity];
			capacity = otherArray.capacity;
		}
		for (int i = 0; i < otherArray.numOfElem; ++i)
			a[i] = otherArray.a[i];
		numOfElem = otherArray.numOfElem;
	}
	else
		cerr << "Attempted assignment to itself.";

	return *this;
}

template<typename T>
DArray<T>::~DArray( )
{
    delete [] a;
	a = nullptr;	
}

//*******************************************************************

// Definition deleteElement
// Your code here...
template<typename T>
void DArray<T>::deleteElement(const T& element)
{
	int i = 0;
	bool found = false;

	while (i < numOfElem - 1 && !found)
	{
		if (a[i] == element)
		{
			for (i; i < numOfElem - 1; i++)
			{
				a[i] = a[i + 1];
			}
			found = true;
		}
		else
			i++;
	}

	numOfElem--;
}


// Definition search
// Your code here...
template<typename T>
bool DArray<T>::search(const T& element) const
{
	for (int i = 0; i < numOfElem; i++)
	{
		if (a[i] == element)
			return true;
	}
	return false;
}


// Definition emptyArray
// Your code here...
template<typename T>
void DArray<T>::emptyArray()
{
	numOfElem = 0;
}


// Definition isEmpty
// Your code here...
template<typename T>
bool DArray<T>::isEmpty() const
{
	return (numOfElem == 0);
}


// Definition isFull
// Your code here...
template<typename T>
bool DArray<T>::isFull() const
{
	return (capacity == numOfElem);
}
