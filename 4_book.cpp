// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au

#include <iostream>
#include <vector>
#include <algorithm>
#include "4_book.hpp"

/**
* Write the function definition for a constructor that takes values for name, 
* author, isbn and price and uses a member initializer list to set the value of 
* each data member. 
*/
Book::Book(const std::string& name, const std::string& author, int isbn, double price) :
	name_{name}, author_{author}, isbn_{isbn}, price_{price}
{}

/** 
* Write the overloaded == operator to compare if two book objects are identical
*/
bool operator==(const Book& a, const Book& b)
{
	return (a.name_ == b.name_) 
	    && (a.author_ == b.author_) 
	    && (a.isbn_ == b.isbn_) 
	    && (a.price_ == b.price_);
}

/*
* Write the overloaded != operator that calls the already 
* overloaded == operator to return true when two book objects are not identical.
*/
bool operator!=(const Book& a, const Book& b)
{
	return !(a == b);
}

/*
* Write the overloaded < operator to allow you to sort books by their isbn number. 
* Test this in your main method using std::sort
*/
bool operator<(const Book& a, const Book& b)
{
	return a.isbn_ < b.isbn_;
}

/*
* Write the overloaded << operator to print out the name, author, isbn and price 
* of a book using std::cout
*/
std::ostream& operator<<(std::ostream& out, const Book& book)
{
	return out << "Name: " << book.name_ << ", " << 
			  	  "Author: " << book.author_ << ", " << 
				  "Isbn: " << book.isbn_ << ", " << 
				  "Price: " << book.price_ ;
}

/*
* Write the overloaded type conversion operator to enable the conversion of the 
* Book class to a std::string in the form of "author, name"
*/
Book::operator std::string() const
{
	std::string temp = author_;
	temp+= ", ";
	temp+= name_;
	return temp;

	/*
    // more flexible apparently
    #include <sstream>
    std::stringstream ss;
    ss << author_ << "," << name_;
    return ss.str();
	*/
}

/*
* Create a main function that creates a std::vector<book>, add a few Book objects into 
* the vector with different isbn numbers and prices
*/
int main()
{
	Book a{"My Book", "Taylor Swift", 197835, 322.22};
	Book b{"2My B2ook", "2Tay2loft2", 2227835, 22.22};
	Book c{"My Book", "Taylor Swift", 197835, 322.22};

	if (a == c)
		std::cout << "a == c is TRUE" << std::endl;
	else
		std::cout << "a == c is FALSE" << std::endl;

	if (a != b)
		std::cout << "a != b is TRUE" << std::endl;
	else
		std::cout << "a != b is FALSE" << std::endl;

	std::cout << a << std::endl;

	std::string test = a;
	std::cout << test << std::endl;

	//////////////////////////////////////////////////

	std::vector<Book> books1 =
	{ 
		Book{"Book1", "Author1", 2222, 12.2},
		Book{"Book2", "Author2", 1111, 11.50},
		Book{"Book3", "Author3", 3333, 10.50} 
	};

	std::vector<Book> books2 =
	{ 
		Book{"Book1", "Author1", 2222, 12.2},
		Book{"Book2", "Author2", 1111, 11.50},
		Book{"Book3", "Author3", 3333, 10.50} 
	};

	std::cout << std::endl << "before sort..." << std::endl;
	for (Book b : books1)
	{
		std::cout << b << std::endl;
	}


	// sort requires #include <algorithm>
	std::sort(books1.begin(), books1.end());

	std::cout << std::endl << "after sort..." << std::endl;
	for (Book b : books1)
	{
		std::cout << b << std::endl;
	}

	// TODO: lambda function (final part);
	// TODO: Call std::sort again with a lamda function as the predicate that sorts the 
	// books by price.

	return 0;
}