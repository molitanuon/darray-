/*
	Nuon, Molita

	CS A250
	April 18, 2018

	Lab 10
*/

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
using namespace std;

class Movie
{
	friend ostream& operator<<(ostream& out,
		const Movie& otherMovie);
public:
	Movie();
	Movie(const string& newTitle, int newYear);

	string getTitle() const;

	int getYear() const;

	void setTitle(const string& newTitle);
	void setYear(int newYear);

	bool operator==(const Movie& otherMovie) const;

	~Movie();

private:
	string title;
	int year;
};

#endif
