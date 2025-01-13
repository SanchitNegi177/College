#include <iostream>
#include <vector>
#include <string>

// Function to compute the Longest Prefix Suffix (LPS) array
void computeLPSArray(const std::string &pattern, std::vector<int> &lps)
{
    int length = 0;
    int i = 1;
    int M = pattern.length();

    lps[0] = 0; 

    while (i < M)
    {
        if (pattern[i] == pattern[length])
        {
            lps[i++] = ++length;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i++] = 0;
            }
        }
    }
}

// Function to perform KMP pattern searching algorithm
void KMPSearch(const std::string &pattern, const std::string &text)
{
    int M = pattern.length();
    int N = text.length();
    std::vector<int> lps(M);

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pattern, lps);

    int i = 0; // index for text[]
    int j = 0; // index for pattern[]
    while ((N - i) >= (M - j))
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            std::cout << "Found pattern at index " << (i - j) << std::endl;
            j = lps[j - 1];
        }
        else if (i < N && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

// Driver code
int main()
{
    std::string text = "ABABDABACDABABABCABABABABCABAB";
    std::string pattern = "ABAB";
    KMPSearch(pattern, text);
    return 0;
}
