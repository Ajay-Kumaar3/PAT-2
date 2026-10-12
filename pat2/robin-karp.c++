#include <iostream>
#include <string>
using namespace std;

int main()
{
  string text = "ABABABAB";
  string pattern = "AB";

  int n = text.length();
  int m = pattern.length();

  int base = 256;
  int prime = 101;

  int patternHash = 0;
  int textHash = 0;
  int h = 1;

  // h = base^(m-1) % prime
  for (int i = 0; i < m - 1; i++)
    h = (h * base) % prime;

  // Calculate initial hashes
  for (int i = 0; i < m; i++)
  {
    patternHash = (base * patternHash + pattern[i]) % prime;
    textHash = (base * textHash + text[i]) % prime;
  }

  cout << "Matching positions : ";

  for (int i = 0; i <= n - m; i++)
  {
    // If hash values match
    if (patternHash == textHash)
    {
      bool match = true;

      // Check actual characters
      for (int j = 0; j < m; j++)
      {
        if (text[i + j] != pattern[j])
        {
          match = false;
          break;
        }
      }

      if (match)
        cout << i << " ";
    }

    // Calculate hash for next window
    if (i < n - m)
    {
      textHash = (base * (textHash - text[i] * h) + text[i + m]) % prime;

      if (textHash < 0)
        textHash += prime;
    }
  }

  cout << endl;

  return 0;
}

// Algorithm
// Calculate hash of pattern.
// Calculate hash of first text window.
// Compare hashes.
// If hashes match, compare actual characters.
// Move the window one position.
// Calculate the new hash using rolling hash.
// Repeat.

// RabinKarp(text, pattern)

//     calculate patternHash

//     calculate hash of first window

//     for i = 0 to n-m

//         if patternHash == textHash

//             compare actual characters

//             if equal
//                 print match

//         calculate hash of next window

// Average = O(n+m)
// Worst   = O(nm)
// Space   = O(1)






