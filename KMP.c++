#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getLPS(string pattern)
{
  int m = pattern.length();
  vector<int> lps(m, 0);

  int len = 0;
  int i = 1;

  while (i < m)
  {
    if (pattern[i] == pattern[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
        len = lps[len - 1];
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }

  return lps;
}

int main()
{
  string text = "AAAAABAAAAABAAAAAB";
  string pattern = "AAAAAB";

  vector<int> lps = getLPS(pattern);

  cout << "Text : " << text << endl;
  cout << "Pattern : " << pattern << endl;

  cout << "\nLPS Array : ";
  for (int x : lps)
    cout << x << " ";

  vector<int> positions;

  int i = 0;
  int j = 0;

  while (i < text.length())
  {
    if (text[i] == pattern[j])
    {
      i++;
      j++;
    }

    if (j == pattern.length())
    {
      positions.push_back(i - j);
      j = lps[j - 1];
    }
    else if (i < text.length() && text[i] != pattern[j])
    {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
    }
  }

  cout << "\n\nMatching positions : ";

  for (int pos : positions)
    cout << pos << " ";

  cout << "\nNumber of matches : "
       << positions.size() << endl;

  return 0;
}