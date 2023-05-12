# Implementing a hashtable

Implementing a chaining hashtable. The class HashTable is used to traverse a linked list of HashNode objects.

Traversing the table is done by finding the index using the hashFunction, heading to the node at that index, if the index doesn't exist do work.

If the index does exist, the functions will move to the mNextNode, verify if there is a valid pointer and either continue checking down the list, or do work if there is no pointer in the nextnode.