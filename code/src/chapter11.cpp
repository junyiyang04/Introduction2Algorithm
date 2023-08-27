#include <chapter11.h>


// ******************************************************************
// *                                                                *
// *                    chained-hash tables                         *
// *              - insert search delete                            *
// *                                                                *
// ******************************************************************

int hashFunc(int key, HashFunc func)
{

    switch (func)
    {
    case DIRECT: 
        break;
    case DIVISION:
        /*division method*/
        break;
    case MULTIPLICATION:
        /*multiplication method*/
        break;
    default:
        abort();
        break;
    }
    return key;
}

void createChainedHashTbl(int* T, int size)
{
    T = (int*)malloc(size * sizeof(int));
    // maybe need to init hash table
}

void insertChainedHashTbl(int* T, Key_Value element)
{

}



#include <iostream>
#include <list>
#include <string>

using namespace std;

const int HASH_TABLE_SIZE = 10;

class HashTable {
public:
    HashTable() {}
    ~HashTable() {}

    void set(const string &key, const string &value) {
        int index = hash(key);
        for (auto &p : table[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[index].push_back(make_pair(key, value));
    }

    string get(const string &key) {
        int index = hash(key);
        for (auto &p : table[index]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return "";
    }

    void remove(const string &key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }

private:
    int hash(const string &key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % HASH_TABLE_SIZE;
    }

    list<pair<string, string>> table[HASH_TABLE_SIZE];
};

// int main() {
//     HashTable ht;
//     ht.set("hello", "world");
//     cout << ht.get("hello") << endl; // 输出 "world"
//     ht.remove("hello");
//     cout << ht.get("hello") << endl; // 输出 ""
//     return 0;
// }
