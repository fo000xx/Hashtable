#include <iostream>
#include "hashtable.h"

int main()
{
    HashTable tableTest{10};

    std::string test { "test" };
    std::string result{};
    result = tableTest.insertKey(10, test);
    std::cout << result << '\n';

    result =  tableTest.insertKey(11, test);
    std::cout << result << '\n';
    
    result = tableTest.findValue(10);
    std::cout << result << '\n';
    
    tableTest.printHashTable();

    return 0;
}
