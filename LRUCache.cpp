/*
 Author:     physician
 Date:       Aug 23, 2014
 Update:     Aug 23, 2014
 Problem:    LRU Cache
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/lru-cache/

 Problem Description:
 LRU Cache: 

 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

 Notes:
 1. First implementation, unordered_map and list.
 2. List::iterator is not random access iterator, so cannot do it +/- n. 
    It's bidirectional iterator, so the only movement operations allowed are ++/--. Or use std::advance(it, +n)/std::advance(it, -n).
    For C++11 there is also std::next/std::prev which gives you it +/- 1. 
 3. Compile using g++: g++ -std=c++0x LRUCache.cpp -o LRUCache.
*/

 
# include <iostream>
# include <list>
# include <unordered_map>
# include <iterator>

using namespace std;
 
struct CacheNode {
    int key;
    int val;
    CacheNode(int k, int v) : key(k), val(v) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheList.splice(cacheList.end(), cacheList, cacheMap[key]);
            return cacheMap[key] -> val;
        }
        else
            return -1;
    }
    
    void set(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key] -> val = value;
            cacheList.splice(cacheList.end(), cacheList, cacheMap[key]);
        }
        else {
            if (cacheList.size() == capacity) {
                cacheMap.erase(cacheList.front().key);
                cacheList.pop_front();
            }
            cacheList.push_back(CacheNode(key, value));
            //cacheMap[key] = prev(cacheList.end());
            cacheMap[key] = cacheList.end();
            advance(cacheMap[key], -1);  //or cacheMap[key]--;
        }
    }

    friend void printCache(LRUCache&);

private:
    int capacity;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    list<CacheNode> cacheList;
};

void printCache(LRUCache& cache) {
    list<CacheNode>::iterator iter = cache.cacheList.begin();
    cout << "Current status of cache:" << endl;
    while(iter != cache.cacheList.end()) {
        cout << "(" << iter->key << "," << iter->val << ") ";
        iter++;
    }
    cout << "<--- Most Recently Used" << endl;
}

int main() {
    bool again = true;
    char yn;
    int key, value;
    int cap;
    string operation;
    cout << "Input cache capacity: " << endl;
    cin >> cap;
    LRUCache cache = LRUCache(cap);
    while (again) {
        cout << "Cache operation(get or set)?" << endl;
        cin >> operation;
        if(operation == "get") {
            cout << "Input key: " << endl;
            cin >> key;
            value = cache.get(key);
            cout << "Value for key = " << key << " is " << value << endl;
            printCache(cache);
        }
        else if(operation == "set") {
            cout << "Input key: " << endl;
            cin >> key;
            cout << "Input value: " << endl;
            cin >> value;
            cout << "key = " << key << ", value = " << value << endl; 
        
            cache.set(key, value);
            printCache(cache);
        }
        else 
            cout << "Invalid input! Input \"get\" or \"set\"!" << endl;

        cout << "Again(y or n)?" << endl;
        cin >> yn;
        while(yn != 'y' && yn != 'n') {
            cout << "Invalid input! Input \"y\" or \"n\":" << endl;
            cout << "Again(y or n)?" << endl;
            cin >> yn;
        }
        if (yn == 'n')
            again = false;
    }
}
