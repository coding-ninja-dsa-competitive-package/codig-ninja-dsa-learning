#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>

using namespace std;

/**
 *  Iterators
 *  ========= 
 *  -   We need iterators to iterate over vector, list, map, set, unordered_map,
 *      unordered_set etc.
 */
void problem1(){
    unordered_map<string, int> mp;
    mp["abc"] = 1;
    mp["def"] = 2;
    mp["ghi"] = 3;
    mp["jkl"] = 4;
    
    unordered_map<string, int>::iterator it=mp.begin();
    while(it != mp.end()){
        cout << "Key : " << it->first << " , Value : " << it->second << endl;
        it++;
    }

    // find & erase using iterator
    unordered_map<string, int>::iterator it2=mp.find("abc");
    mp.erase(it2);
    // mp.erase(it2, it2 + 2 ); // erase range of elements (exclusive end)
}

/**
 *  Hash Function:
 *  ==============
 *  -   An array of limited size is used as bucket.
 *  -   Hashcode is calculated for the key and value is put at that address.
 *  -   Consist of 2 functions :
 *      1.  hashcode : this function can be implemented in many ways. 
 *      2.  compression function : We can use modulus (%) to fit our key in 
 *              bucket size range.
 * 
 *  -   Collision : If 2 different keys produce same hash, it will go to same
 *          address in the bucket array/ hash table.
 *      1.  Closed Hashing: all the entries in collision will go to same location
 *              and data will be stored in linked list. Also called as  
 *              separate chaining.
 *      2.  Open Addressing: if the location is occupied with other data, we
 *              need to find alternate place for the data storage.
 *                  hi(a) = h.f.(a) + f(i)
 *          -   f(i) depends on the type of open addressing technique:
 *          1.  Linear Probing : check the next position i.e. i+1
 *          2.  Quadratic probing : check the quadratic position i.e. i^2
 *          3.  Double Hashing :  f(i) = i * h'(a)
 *      -   In practice, separate chaining works fine as open addressing.
 *  
 *  -   Load Factor:
 *      -   Consider, we are entering data in map and all entries are going
 *          to same bucket index, so to maintain the O(1) time for insertion/
 *          deletion, load factor is maintained so that linked list doesn't 
 *          become large.
 *          Ex: load factor 0.75 signifies - if the bucket contains 3/4 of the
 *              total number of elements - rehashing will be done which will 
 *              increase the array size and load factor will decrease.
 */
template<typename V>
class Node{
    public:
        string key;
        V value;
        Node* next;

        Node(string key, V value){
            this->key = key;
            this->value = value;
            this->next = NULL;
        }

        ~Node(){
            delete next;
        }
};
template<typename V>
class MapImpl{
    Node<V>** buckets;
    int count;
    int numBuckets;

    int getBucket(string key){
        int hashcode=0;
        int currCoeff = 1;
        for(int i=key.length()-1; i>=0; i--){
            hashcode += key[i] * currCoeff;
            hashcode %= numBuckets;
            currCoeff *= 31;
            currCoeff %= numBuckets;
        }
        return hashcode%numBuckets;
    }

    void rehash(){
        Node<V>** temp = buckets;
        buckets = new Node<V>*[2*numBuckets];
        for(int i=0; i<2*numBuckets; i++){
            buckets[i] = NULL;
        }
        int oldBucketSize = numBuckets;
        numBuckets *= 2;
        count = 0;
        for(int i=0; i<oldBucketSize; i++){
            Node<V>* head = temp[i];
            while(head != NULL){
                string key = head->key;
                V val = head->value;
                insert(key, val);
                head = head->next;
            }
        }
        for(int i=0; i<oldBucketSize; i++){
            Node<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
    }

    public:
        MapImpl(){
            this->count = 0;
            this->numBuckets = 5;
            this->buckets = new Node<V>*[numBuckets];
            for(int i=0; i<numBuckets; i++){
                buckets[i] = NULL;
            }
        }

        ~MapImpl(){
            for(int i=0; i<numBuckets; i++){
                delete buckets[i];
            }
            delete [] buckets;
        }

        int size(){
            return count;
        }

        double loadFactor(){
            return (1.0*count)/numBuckets;
        }

        V get(string key){
            int bucketIndex = getBucket(key);
            Node<V>* head = buckets[bucketIndex];
            while(head != NULL){
                if(head->key == key){
                    return head->value;
                }
                head = head->next;
            }
            return 0;
        }

        void insert(string key, V value){
            int bucketIndex = getBucket(key);
            Node<V>* head = buckets[bucketIndex];
            while(head != NULL){
                if(head->key == key){
                    head->value = value;
                    return;
                }
                head = head->next;
            }
            head = buckets[bucketIndex];
            Node<V>* newNode = new Node<V>(key, value);
            newNode->next = head;
            buckets[bucketIndex] = newNode;
            count++;
            double loadFactor = (1.0*count)/numBuckets;
            if(loadFactor > 0.7){
                rehash();
            }
        }

        V remove(string key){
            int bucketIndex = getBucket(key);
            Node<V>* head = buckets[bucketIndex];
            Node<V>* prev = NULL;
            while(head != NULL){
                if(head->key == key){
                    if(prev != NULL){
                        prev->next = head->next;
                    } else{
                        buckets[bucketIndex] = head->next;
                    }
                    V val = head->value;
                    head->next = NULL;
                    delete head;
                    count--;
                    return val;
                }
                prev = head;
                head = head->next;
            }
            return 0;
        }
};
void problem2(){
    MapImpl<int> mp;
    for(int i=0; i<10; i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i+1;
        mp.insert(key, value);
        cout << "load factor : " << mp.loadFactor() << endl;
    }
    mp.remove("abc3");
    mp.remove("abc5");
    for(int i=0; i<10; i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << " getValue for "<< key << " : " << mp.get(key) << endl;
    }
    cout << "map size : " << mp.size() << endl;
}



int main() {
    // iterators - find & erase function
    // problem1();

    // hashmap implementation
    problem2();

    return 0;
}