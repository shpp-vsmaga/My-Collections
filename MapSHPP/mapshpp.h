/* File:: mapshpp.h
 * --------------------------------------------------
 * This interface exports simple version of map
 * based on AVL binary search tree
 */
#ifndef MAPSHPP
#define MAPSHPP

#include <iostream>


/* Class: MapSHPP
 * -------------------------------------------------
 * This class implements a simple  associative
 * array that contains key-value pairs with unique keys.
 */
template<typename KeyType, typename ValueType>
class MapSHPP{

/* Public methods prototypes*/
public:

    /**
     * Constructor: MapSHPP
     * Usage: MapSHPP<KeyType, ValueType> map;
     * -----------------------------------------------------
     * Initializes a new empty MapSHPP
     */
    MapSHPP();

    /* Destructor: ~MapSHPP*/
    virtual ~MapSHPP();

    /**
     * Method: put
     * Usage: map.put(key, value);
     * ----------------------------------------------------
     * Adds a new element to the map with specified index
     * and value. If such index is present in the map, this
     * method changes it's value
     */
    void put(KeyType, ValueType);

    /**
     * Method: get
     * Usage: value = map.get(key);
     * ---------------------------------------------------
     * Returns value of the element with specified key.
     */
    ValueType get(KeyType key);

    /**
     * Method: isEmpty
     * Usage: if (map.isEmpty())...
     * ----------------------------------------------------
     * Returns true if there are no elements in the map`
     */
    bool isEmpty();

    /**
     * Method: clear
     * Usage: map.clear();
     * ----------------------------------------------------
     * Removes all elements in the map
     */
    void clear();

    /**
     * Method: size
     * Usage: int size = map.size();
     * ----------------------------------------------------
     * Returns current number of the elements if the map
     */
    int size();

    /**
     * Method: remove
     * Usage: map.remove(key);
     * ----------------------------------------------------
     * Removes key-value pair with spevified key
     */
    void remove(KeyType);

    /**
     * Method: containsKey
     * Usage: if (map.containsKey(key))...
     * ---------------------------------------------------
     * Returns true if specified key exist in the map
     */
    bool containsKey(KeyType key);

    /**
     * Operator: []
     * Usage: map[key] = value;
     * ---------------------------------------------------
     * Returns link to value by the specfied key.
     */
    ValueType& operator[](KeyType);

/* Private methods prototypes and instase variables*/
private:

    /* Structure for storing key-value pairs and build BST*/
    struct BSTNode {
        KeyType Key;
        ValueType Value;
        int length;
        BSTNode* left;
        BSTNode* right;
    };

    /**
     * Method: balanceTree
     * ---------------------------------------------------
     * Balance the binary tree
     */
    BSTNode* balanceTree(BSTNode* node);

    /**
     * Method: getNodeHeight
     * --------------------------------------------------
     * Returns the height of  current sub-tree or 0
     * if tree is empty
     */
    int getNodeHeight(BSTNode* node);

    /**
     * Method: getBalanceFactor
     * -------------------------------------------------
     * Return the differnce between height of right and
     * left sub-trees
     */
    int getBalanceFactor(BSTNode* node);

    /**
     * Method: fixHeight
     * ------------------------------------------------
     * Recalculates the height of a given node
     */
    void fixHeight(BSTNode* node);

    /**
     * Method: rotateRight
     * -----------------------------------------------
     * Rotates tree right around a given node
     */
    BSTNode* rotateRight(BSTNode* node);

    /**
     * Method: rotateRight
     * -----------------------------------------------
     * Rotates tree left around a given node
     */
    BSTNode* rotateLeft(BSTNode* node);

    /**
     * Method: insertNode
     * -----------------------------------------------
     * Inserts new node with received key and value to
     * the tree and balance it after this
     */
    BSTNode* insertNode(BSTNode* node, KeyType key, ValueType value);

    /**
     * Method: removeNode
     * -----------------------------------------------
     * Removed node with received key and balance tree
     * after this
     */
    BSTNode* removeNode(BSTNode* node, KeyType key);

    /**
     * Method: findMinNode
     * -----------------------------------------------
     * Returns pointer to the node with minimal key in
     * the received sub-tree
     */
    BSTNode* findMinNode(BSTNode* node);

    /**
     * Method: removeMinNode
     * -----------------------------------------------
     * Removes minimal element of thr received sub-tree
     * and balance it after this
     */
    BSTNode* removeMinNode(BSTNode* node);

    /**
     * Method: findNode
     * -----------------------------------------------
     * Returns pointer to the node that contains received
     * key or 0 if such node not found
     */
    BSTNode* findNode(BSTNode* node, KeyType key);

    /**
     * Method: clearBST
     * -----------------------------------------------
     * Frees all memoty allocated for the nodes of
     * the binaty tree
     */
    void clearBST(BSTNode* node);

    BSTNode* root;
    int count;
};


template<typename KeyType, typename ValueType>
MapSHPP<KeyType, ValueType>::MapSHPP(){
    root = 0;
    count = 0;
}

template<typename KeyType, typename ValueType>
MapSHPP<KeyType, ValueType>::~MapSHPP(){
    clearBST(root);
}

template<typename KeyType, typename ValueType>
int MapSHPP<KeyType, ValueType>::getNodeHeight(BSTNode *node){
    if (node != 0){
        return node->length;
    }
    return 0;
}

template<typename KeyType, typename ValueType>
int MapSHPP<KeyType, ValueType>::getBalanceFactor(BSTNode *node){
    return getNodeHeight(node->right) - getNodeHeight(node->left);
}

template<typename KeyType, typename ValueType>
void MapSHPP<KeyType, ValueType>::fixHeight(BSTNode *node){
    if (getNodeHeight(node->left) > getNodeHeight(node->right)){
        node->length = getNodeHeight(node->left) + 1;
    } else {
        node->length = getNodeHeight(node->right) + 1;
    }
}

template<typename KeyType, typename ValueType>
typename MapSHPP<KeyType, ValueType>::BSTNode* MapSHPP<KeyType, ValueType>::rotateLeft(BSTNode *node){
    BSTNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    fixHeight(newRoot);
    fixHeight(node);
    return newRoot;
}


template<typename KeyType, typename ValueType>
typename MapSHPP<KeyType, ValueType>::BSTNode* MapSHPP<KeyType, ValueType>::rotateRight(BSTNode *node){
    BSTNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    fixHeight(node);
    fixHeight(newRoot);
    return newRoot;
}

template<typename KeyType, typename ValueType>
typename MapSHPP<KeyType, ValueType>::BSTNode* MapSHPP<KeyType, ValueType>::balanceTree(BSTNode *node){
    fixHeight(node);
    if (getBalanceFactor(node) == 2){
        if (getBalanceFactor(node->right) < 0){
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    if (getBalanceFactor(node) == -2){
        if (getBalanceFactor(node->left) > 0){
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    return node;
}


template<typename KeyType, typename ValueType>
typename MapSHPP<KeyType, ValueType>::BSTNode* MapSHPP<KeyType, ValueType>::insertNode(BSTNode* node, KeyType key, ValueType value){
    
    if (node == 0){
        count++;
        node = new BSTNode;
        node->Key = key;
        node->Value = value;
        node->length = 1;
        node->right = node->left = 0;
        return node;
    } else if (key > node->Key){
        node->right = insertNode(node->right, key, value);
    } else if (key < node->Key){
        node->left = insertNode(node->left, key, value);
    } else {
        node->Value = value;
    }
    
    return balanceTree(node);
    
}


template<typename KeyType, typename ValueType>
typename MapSHPP<KeyType, ValueType>::BSTNode* MapSHPP<KeyType, ValueType>::findNode(BSTNode* node, KeyType key){
     if (key > node->Key){
         if(node->right == 0){
             return 0;
         }
         return findNode(node->right, key);
     } else if (key < node->Key){
         if (node->left == 0){
             return 0;
         }
         return findNode(node->left, key);
     }
      return node;
 }

template<typename KeyType, typename ValueType>
typename MapSHPP<KeyType, ValueType>::BSTNode* MapSHPP<KeyType, ValueType>::removeNode(BSTNode* node, KeyType key){
    if (key < node->Key){
        node->left = removeNode(node->left, key);
    } else if (key >node->Key){
        node->right = removeNode(node->right, key);
    } else if (key == node->Key){
        BSTNode* leftNode = node->left;
        BSTNode* rightNode = node->right;
        delete node;
        count--;
        if (rightNode == 0){
            return leftNode;
        }
        BSTNode* minNode = findMinNode(rightNode);
        minNode->right = removeMinNode(rightNode);
        minNode->left = leftNode;
        return balanceTree(minNode);
    }
    return balanceTree(node);
}

template<typename KeyType, typename ValueType>
typename MapSHPP<KeyType, ValueType>::BSTNode* MapSHPP<KeyType, ValueType>::findMinNode(BSTNode *node){
    if (node->left != 0){
        return findMinNode(node->left);
    }
    return node;
}

template<typename KeyType, typename ValueType>
typename MapSHPP<KeyType, ValueType>::BSTNode* MapSHPP<KeyType, ValueType>::removeMinNode(BSTNode *node){
    if(node->left == 0){
        return node->right;
    }
    node->left = removeMinNode(node->left);
    return balanceTree(node);
}

template<typename KeyType, typename ValueType>
void MapSHPP<KeyType, ValueType>::clearBST(BSTNode *node){
    if (node->left != 0){
        clearBST(node->left);
    }
    if (node->right != 0){
        clearBST(node->right);
    }

    delete node;
}

//------------------------------------------------------------------

template<typename KeyType, typename ValueType>
void MapSHPP<KeyType, ValueType>::put(KeyType key, ValueType value){
    root = insertNode(root, key, value);
}

template<typename KeyType, typename ValueType>
ValueType MapSHPP<KeyType, ValueType>::get(KeyType key){
    return findNode(root, key)->Value;
        
}

template<typename KeyType, typename ValueType>
int MapSHPP<KeyType, ValueType>::size(){
    return count;
}

template<typename KeyType, typename ValueType>
void MapSHPP<KeyType, ValueType>::remove(KeyType key){
    root = removeNode(root, key);
}

template<typename KeyType, typename ValueType>
bool MapSHPP<KeyType, ValueType>::isEmpty(){
    return count == 0;
}

template<typename KeyType, typename ValueType>
void MapSHPP<KeyType, ValueType>::clear(){
    clearBST(root);
    count = 0;
    root = 0;
}

template<typename KeyType, typename ValueType>
bool MapSHPP<KeyType, ValueType>::containsKey(KeyType key){
    return findNode(root, key) != 0;
}

template<typename KeyType, typename ValueType>
ValueType& MapSHPP<KeyType, ValueType>::operator [](KeyType key){
    return findNode(root, key)->Value;
}

#endif // MAPSHPP

