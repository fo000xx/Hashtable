#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <memory>
#include <vector>
#include <string>

class HashNode{
public:
    int mKey;
    std::string mValue;
    std::unique_ptr<HashNode> mNextNode;

    HashNode(int key, const std::string& value)
        : mKey { key }
        , mValue { value }
    {
    }
};

class HashTable {
public:
    HashTable(std::size_t tableSize)
        : mHashTable(tableSize)
        , mTableCapacity{ 0 }
    {
    }

    int hashFunction(int key);
    std::string findValue(int key);
    void insertKey(int key, std::string& data);
    void deleteKey(int key);
    int getCapacity() { return mTableCapacity; }

private:
    std::vector<std::unique_ptr<HashNode>> mHashTable;
    std::size_t mTableCapacity;
};

#endif