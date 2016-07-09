// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au


namespace cs6771
{
	void order3(int *a, int *b, int *c) 
	{
		if (*a < *c) 
		{
			int t = *a;
			*a = *c;
			*c = t;
		}
		if (*a < *b) 
		{
			int t = *a;
			*a = *b;
			*b = t;
		}
		if (*b < *c) 
		{
			int t = *b;
			*b = *c;
			*c = t;
		}
	}
	
	void order3(unsigned int& a, unsigned int& b, unsigned int& c) 
	{
		if (a > c) 
		{
			int t = a;
			a = c;
			c = t;
		}
		if (b > c) 
		{
			int t = b;
			b = c;
			c = t;
		}
		if (a > b) 
		{
			int t = a;
			a = b;
			b = t;
		}
	}

}