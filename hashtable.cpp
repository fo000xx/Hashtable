#include "hashtable.h"

int HashTable::hashFunction(int key)
{
    //basic function for demo purposes.
    return key % mHashTable.size();
}

std::string HashTable::insertKey(int key, std::string& value)
{
    int index { hashFunction(key) };
    std::unique_ptr<HashNode>& node { mHashTable[index] };
    std::string userResponse{};

    if (node == nullptr) {
        node = std::make_unique<HashNode>(key, value);
        ++mTableCapacity;
    }
    else {
        std::unique_ptr<HashNode> currentNode { node.get() };
        while (currentNode != nullptr) {
            if (currentNode->mKey == key) {
                currentNode->mValue = value;
                
                userResponse = "Overwritten existing value\n";
                return userResponse;
            }
            currentNode = std::move(currentNode->mNextNode);
        }
        std::unique_ptr<HashNode> newNode = std::make_unique<HashNode>(key, value);
        newNode->mNextNode = std::move(node);
        node = std::move(newNode);
        ++mTableCapacity;
    }
    userResponse = "Successful insertion\n";
    return userResponse;
}

std::string HashTable::findValue(int key)
{
    std::size_t index = hashFunction(key);
    const std::unique_ptr<HashNode>& node { mHashTable[index] };
    std::string userResponse{};

    std::unique_ptr<HashNode> currentNode { node.get() };
    while (currentNode != nullptr) {
        if (currentNode->mKey == key) {
            return currentNode->mValue;
        }
        currentNode = std::move(currentNode->mNextNode);
    }
    userResponse = "Key not found\n";
    return userResponse;
}

std::string HashTable::deleteKey(int key)
{
    std::size_t index = hashFunction(key);
    std::unique_ptr<HashNode>& node { mHashTable[index] };
    std::string userResponse{};

    std::unique_ptr<HashNode> currentNode { node.get() };
    std::unique_ptr<HashNode> previousNode { nullptr };

    while (currentNode != nullptr) {
        if (currentNode->mKey == key) {
            if (previousNode == nullptr) {
                node = std::move(currentNode->mNextNode);
            }
            else {
            previousNode->mNextNode = std::move(currentNode->mNextNode);
            }
            --mTableCapacity;
            userResponse = "Key/Value deleted\n";
            return userResponse;
        }
        previousNode = std::move(currentNode);
        currentNode = std::move(currentNode->mNextNode);
    }
    userResponse = "Key not found\n";
    return userResponse;
}

/*void HashTable::printKeyValue(HashNode& node)
{
    std
}*/

void HashTable::printHashTable()
{
    std::cout << "Table Capacity: " << mTableCapacity << '\n';

    //for (bucket : HashTable)
    //go to bucket 1 in mHashTable, 
    //if it has a key/value, print key + value
        //while mNextNode != nullptr, 
            //go to next node
            //print key + value()
        //if mNextNode == nullptr, 
            //go to next bucket in hashtable

}