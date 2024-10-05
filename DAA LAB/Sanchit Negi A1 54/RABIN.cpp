#include <bits/stdc++.h>
using namespace std;

// Number of characters in the input alphabet
#define ALPHABET_SIZE 256

// Rabin-Karp Algorithm for Pattern Searching
void rabinKarpSearch(const string &pattern, const string &text, int prime)
{
    int patternLength = pattern.length();
    int textLength = text.length();
    int patternHash = 0; // hash value for pattern
    int textHash = 0;    // hash value for text
    int h = 1;

    // The value of h would be "pow(ALPHABET_SIZE, patternLength-1) % prime"
    for (int i = 0; i < patternLength - 1; i++)
    {
        h = (h * ALPHABET_SIZE) % prime;
    }

    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < patternLength; i++)
    {
        patternHash = (ALPHABET_SIZE * patternHash + pattern[i]) % prime;
        textHash = (ALPHABET_SIZE * textHash + text[i]) % prime;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= textLength - patternLength; i++)
    {
        // Check the hash values of current window of text and pattern
        if (patternHash == textHash)
        {
            // Check for characters one by one
            bool match = true;
            for (int j = 0; j < patternLength; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }

            // If patternHash == textHash and pattern matches the current window
            if (match)
            {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate hash value for next window of text
        // Remove leading digit, add trailing digit
        if (i < textLength - patternLength)
        {
            textHash = (ALPHABET_SIZE * (textHash - text[i] * h) + text[i + patternLength]) % prime;

            // We might get negative value of textHash, convert it to positive
            if (textHash < 0)
            {
                textHash = (textHash + prime);
            }
        }
    }
}

// Driver code
int main()
{
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";

    // Use a large prime number to avoid collisions
    int prime = INT_MAX;

    // Function Call
    rabinKarpSearch(pattern, text, prime);

    return 0;
}
