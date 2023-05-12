#include "hashtable.h"

int HashTable::hashFunction(int key)
{
    return key % mHashTable.size();
}

void HashTable::insertKey(int key, std::string& value)
{
    int index { hashFunction(key) };
    std::unique_ptr<HashNode>& node { mHashTable[index] };

    if (node == nullptr) {
        node = std::make_unique<HashNode>(key, value);
        ++mTableCapacity;
    }
    else {
        HashNode* currentNode { node.get() };
        while (currentNode != nullptr) {
            if (currentNode->mKey == key) {
                currentNode->mValue = value;
                return;
            }
            currentNode = currentNode->mNextNode.get();
        }
        std::unique_ptr<HashNode> newNode = std::make_unique<HashNode>(key, value);
        newNode->mNextNode = std::move(node);
        node = std::move(newNode);
        ++mTableCapacity;
    }
}

std::string HashTable::findValue(int key)
{
    std::size_t index = hashFunction(key);
    const std::unique_ptr<HashNode>& node { mHashTable[index] };

    HashNode* currentNode { node.get() };
    while (currentNode != nullptr) {
        if (currentNode->mKey == key) {
            return currentNode->mValue;
        }
        currentNode = currentNode->mNextNode.get();
    }
    std::string notFound {"key not found" };
    return notFound;
}

void HashTable::deleteKey(int key)
{
    std::size_t index = hashFunction(key);
    const std::unique_ptr<HashNode>& node { mHashTable[index] };

    HashNode* currentNode { node.get() };
    while (currentNode != nullptr) {
        if (currentNode->mKey == key) {
            //delete node here
            //reshuffle logic (probably before deleting the node)
            //--mTableCapacity
        }
        currentNode = currentNode->mNextNode.get();
    }
}