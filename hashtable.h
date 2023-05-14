#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <memory>
#include <vector>
#include <string>
#include <iostream>

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
    std::string insertKey(int key, std::string& data);
    std::string deleteKey(int key);
    int getCapacity() { return mTableCapacity; }
    void printHashTable();

private:
    std::vector<std::unique_ptr<HashNode>> mHashTable;
    std::size_t mTableCapacity;
    void printKeyValue(HashNode& node);
};

#endif