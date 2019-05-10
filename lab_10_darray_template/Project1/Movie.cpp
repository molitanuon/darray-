/*
	Nuon, Molita

	CS A250
	April 18, 2018

	Lab 10
*/

#include "Movie.h"

ostream& operator<<(ostream& out,
	const Movie& otherMovie)
{
	out << "\"" << otherMovie.title
		<< "\"" << " (" << otherMovie.year 
		<< ")" << endl;

	return out;
}

Movie::Movie()
{
	year = 0;
}

Movie::Movie(const string& newTitle, int newYear)
{
	year = newYear;
	title = newTitle;
}

string Movie::getTitle() const
{
	return title;
}

int Movie::getYear() const
{
	return year;
}

void Movie::setTitle(const string& newTitle)
{
	title = newTitle;
}

void Movie::setYear(int newYear)
{
	title = newYear;
}

bool Movie::operator==(const Movie& otherMovie) const
{
	return (year == otherMovie.year 
		&& title == otherMovie.title);
}

Movie::~Movie() {}