// Example program
#include <iostream>
#include <string>
using namespace std;
#include <cmath>
#include <sstream>

string dec2hex(unsigned int deci)
{

    stringstream ss;
    ss << hex << deci;
    string res = ss.str();

    return res;
}

void translateAddress(unsigned int physical, int pageSize)
{

    int pageNumber = ceil(physical / pageSize);
    int pagePhysicalAddress = pageNumber * pageSize;

    int offset = physical - pageSize * pageNumber;

    cout << "Page number            - "
         << pageNumber << endl;

    cout << "Page Physical address  - ";

    cout << "0x" << dec2hex(pagePhysicalAddress) << endl;

    cout << "Page offset            - "
         << offset << endl;
}

int main()
{
    // Page size in KB
    int pageSize = 4096;
    int physicalAddress = 19986;

    cout << "Please provide the page size in KB. \n";
    cin >> pageSize;

    if (pageSize < 0)
    {
        cout << "Negative page size don't exist!!!\n";
        return -1;
    }

    cout << "Please provide the physical address.\n";
    cin >> physicalAddress;

    if (physicalAddress < 0)
    {
        cout << "Negative physical Address don't exist!!!\n";
        return -1;
    }

    cout << endl
         << endl;
    translateAddress(physicalAddress, pageSize);

    cout << endl
         << endl;

    return 0;
}
