// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au

#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <list>
#include <algorithm>
#include <iterator>
#include <initializer_list>

int main()
{
	// vector
	std::vector<std::string> vec = {"one", "two", "three"};
	for (std::string s : vec)
		std::cout << s << " ";
	std::cout << std::endl;

	// array
	std::array<int,3> arr = {3, 2, 1};
	for (int i : arr)
		std::cout << i << " ";
	std::cout << std::endl;

	// sort both
	std::sort(vec.begin(), vec.end());

	// vector
	for (std::string s : vec)
		std::cout << s << " ";
	std::cout << std::endl;

	// array
	std::sort(arr.begin(), arr.end());
	for (int i : arr)
		std::cout << i << " ";
	std::cout << std::endl;

	// list
	std::list<int> lis;
	std::sort(arr.begin(), arr.end(), std::greater<int>());

	// back insert iterator
	std::back_insert_iterator<std::list<int>> back_iter(lis);

	for (auto item = arr.begin(); item != arr.end(); item++)
		*back_iter = *item;

	for (auto item : lis)
		std::cout << item << " ";
	std::cout << std::endl;

	// sort list
	lis.sort();

	for (auto item : lis)
		std::cout << item << " ";
	std::cout << std::endl;

	// map
	std::map<std::string, int> m;
	//std::vector<std::string>::const_iterator iter;

	int i = 0;
	for (auto item : vec)
	{
		m.insert(std::make_pair(item, i));
		i++;
	}

	for (const auto item : m)
    {
        std::cout << item.first << ": " << item.second << std::endl;
    }

	return 0;
}