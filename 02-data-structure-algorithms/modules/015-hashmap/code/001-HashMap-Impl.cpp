#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

using namespace std;

/**
 *  Bucket Node
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
/**
 *  Implementation
 */ 
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

int main(){
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

    return 0;
}