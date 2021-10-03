/* * *
Given an input string and a dictionary of  words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.
 * * */

#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  bool endOfWord;
  TrieNode* children[26];
  TrieNode() {
    endOfWord = false;
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }
};
void insert(TrieNode* root, string& word) {

  for (char c : word) {
    int index = c - 'a';

    if (root->children[index] == nullptr) {
      root->children[index] = new TrieNode();
    }
    root = root->children[index];
  }

  root->endOfWord = true;
}

bool check(TrieNode* root, string word) {

  for (char c : word) {
    int index = c - 'a';
    if (root->children[index] == nullptr) return false;

    root = root->children[index];
  }

  return root->endOfWord == true;
}

bool wordBreak(TrieNode* root, string word) {
  if (word.length() == 0) return true;

  for (int i = 1; i <= word.length(); i++) {
    if (check(root, word.substr(0, i)) && wordBreak(root, word.substr(i)))
      return true;
  }

  return false;
}

int main() {
  vector<string> words = {
    "i", "like", "sam", "sung", "samsung", "mobile", "ice",
  "cream", "icecream", "man", "go", "mango"
  };
  TrieNode* root = new TrieNode();
  for (auto& word : words) insert(root, word);

  string input = "ilike";

  cout << wordBreak(root, input);
}