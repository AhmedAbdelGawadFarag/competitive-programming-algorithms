#include <bits/stdc++.h>

using namespace std;

#define endl "\n"


class Node {
public:
    Node *arr[26];
    bool isWord = false;
    char c;

    Node(char c, bool isWord) {
        this->c = c;
        this->isWord = isWord;
        for (int i = 0; i < 26; i++)arr[i] = 0;
    }

    Node() {
        for (int i = 0; i < 26; i++)arr[i] = 0;
    }

};


class Trie {
public:
    Node *root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *temp = root;

        for (int i = 0; i < word.size(); i++) {

            if (temp->arr[word[i] - 'a'] == NULL)
                temp->arr[word[i] - 'a'] = new Node(word[i], 0);

            temp = temp->arr[word[i] - 'a'];

        }
        temp->isWord = true;

    }

    bool search(string word) {

        Node *temp = root;
        bool isWord = false;

        int i;
        for (i = 0; i < word.size(); i++) {

            if (temp->arr[word[i] - 'a'] == NULL) {
                break;
            }

            temp = temp->arr[word[i] - 'a'];

        }

        return i == word.size() && temp->isWord;

    }

    bool startsWith(string prefix) {
        Node *temp = root;

        int i;

        for (i = 0; i < prefix.size(); i++) {
            if (temp->arr[prefix[i] - 'a'] == NULL)break;

            temp = temp->arr[prefix[i] - 'a'];

        }

        return i == prefix.size();
    }

};


int main() {


    Trie t;

    t.insert("apple");
    cout << t.search("apple") << endl;   // return True
    cout << t.search("app") << endl;     // return False

    cout << t.startsWith("app") << endl; // return True

    t.insert("app");
    cout << t.search("app") << endl;     // return True

}
