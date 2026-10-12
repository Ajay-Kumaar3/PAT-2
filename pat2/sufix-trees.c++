#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Node
{
  map<char, pair<string, Node *>> child;
};

Node *root = new Node();

void insertSuffix(string suffix)
{
  Node *current = root;

  while (!suffix.empty())
  {
    char first = suffix[0];

    // No edge starting with this character
    if (current->child.find(first) == current->child.end())
    {
      current->child[first] = {suffix, new Node()};
      return;
    }

    string edge = current->child[first].first;
    Node *next = current->child[first].second;

    int i = 0;

    // Find common part
    while (i < edge.length() &&
           i < suffix.length() &&
           edge[i] == suffix[i])
    {
      i++;
    }

    // Complete edge matched
    if (i == edge.length())
    {
      suffix = suffix.substr(i);
      current = next;
    }
    else
    {
      // Split the edge
      Node *split = new Node();

      string oldPart = edge.substr(i);
      string newPart = suffix.substr(i);

      current->child[first] = {
          edge.substr(0, i), split};

      split->child[oldPart[0]] = {
          oldPart, next};

      split->child[newPart[0]] = {
          newPart, new Node()};

      return;
    }
  }
}

bool search(string pattern)
{
  Node *current = root;
  int pos = 0;

  while (pos < pattern.length())
  {
    char first = pattern[pos];

    if (current->child.find(first) == current->child.end())
      return false;

    string edge = current->child[first].first;
    Node *next = current->child[first].second;

    int i = 0;

    while (i < edge.length() &&
           pos < pattern.length() &&
           edge[i] == pattern[pos])
    {
      i++;
      pos++;
    }

    if (i < edge.length())
      return false;

    current = next;
  }

  return true;
}

int main()
{
  string text = "BANANA$";

  // Insert every suffix
  for (int i = 0; i < text.length(); i++)
  {
    insertSuffix(text.substr(i));
  }

  string pattern = "ANA";

  if (search(pattern))
    cout << "Pattern found" << endl;
  else
    cout << "Pattern not found" << endl;

  return 0;
}

// Algorithm
// Generate all suffixes of the text.
// Insert every suffix into a trie.
// Compress paths that contain only one child.
// The resulting compressed trie is the suffix tree.
// To search, start from the root.
// Follow edges matching the pattern.
// If the complete pattern is matched → found.
// Otherwise → not found.

// BuildSuffixTree(text)

//     create empty root

//     for i = 0 to length(text)-1

//         suffix = text[i ... end]

//         insert suffix into tree

//     compress tree

//     return tree

// Search(tree, pattern)

//     current = root
//     i = 0

//     while i < pattern.length

//         find edge starting with pattern[i]

//         if edge does not exist
//             return NOT FOUND

//         compare pattern with edge

//         if mismatch
//             return NOT FOUND

//         move to next node

//     return FOUND

// Construction = O(n)
// Search       = O(m)