#include <iostream>
#include <string>
using namespace std;

int main()
{
  string text = "ABABABABABABACABABAB";
  string pattern = "ABABAC";

  int n = text.length();
  int m = pattern.length();

  int comparisons = 0;
  int matches = 0;

  cout << "Text : " << text << endl;
  cout << "Pattern : " << pattern << endl;

  cout << "\nMatching positions : ";

  for (int i = 0; i <= n - m; i++)
  {
    int j;

    for (j = 0; j < m; j++)
    {
      comparisons++;

      if (text[i + j] != pattern[j])
        break;
    }

    if (j == m)
    {
      cout << i << " ";
      matches++;
    }
  }

  cout << "\nNumber of matches : " << matches;
  cout << "\nCharacter comparisons : " << comparisons << endl;

  return 0;
}

// Algorithm
// Align pattern at the beginning of text.
// Compare pattern characters with text characters.
// If all characters match → pattern found.
// If mismatch occurs → shift pattern by one position.
// Repeat until the pattern reaches the end.

// NaiveSearch(text, pattern)

//     n = length(text)
//     m = length(pattern)

//     for i = 0 to n-m

//         j = 0

//         while j < m
//               and text[i+j] == pattern[j]

//             j++

//         if j == m
//             print "Pattern found at i"

// Best:  O(n)
// Worst: O(nm)
// Space: O(1)