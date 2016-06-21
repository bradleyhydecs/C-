using namespace std;
#include <vector>
#include <iostream>

int mem_f[5000];

int f(int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;

    if (mem_f[num] != 0)
        return mem_f[num];

    mem_f[num] = f(num-2) + f(num-1);
    return mem_f[num];
}

int main()
{
    vector<int> input;
    int temp;

    while (cin >> temp)
        input.push_back(temp);

    for (int num : input)
        cout << "(yes memzorzed) f(" << num << ") = " << f(num) << endl;

    return EXIT_SUCCESS;
}



