// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au

#ifndef BOOK_H
#define BOOK_H

class Book 
{
	public:
		Book(const std::string&, const std::string&, int, double);
		int getIsbn() const { return isbn_; }
		double getPrice() const  { return price_; }

		operator std::string() const;

		friend bool operator==(const Book& a, const Book& b);
		friend bool operator!=(const Book& a, const Book& b);
		friend bool operator<(const Book& a, const Book& b);
		friend std::ostream& operator<<(std::ostream& out, const Book& b);

	private:
		std::string name_;
		std::string author_;
		int isbn_;
		double price_;
};

#endif