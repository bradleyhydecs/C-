// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au

#ifndef CAR_H
#define CAR_H

class Car 
{	
	private:
		std::string manufacturer_;
		unsigned int num_seats_;
		static int num_objects_;
	public:
		Car(); 
		~Car();
		Car(const std::string& s, unsigned int n); 

		const std::string& getManufacturer() const;
		unsigned int getNumSeats() const;
		static int getNumObjects();

};

#endif