#include "Header.h"

int char_to_num(char c)
{
    return c - 'a' + 1;
}

// Converts a number to a character
char num_to_char(int n)
{
    return 'a' + n - 1;
}

string encrypt(string word)
{
    if (word.size() % 2 != 0)
    {
        word += " ";
    }

    int num_pairs = word.size() / 2;
    vector<vector<Matrix>> pairs(num_pairs, vector<Matrix>(1));

    // Create matrices from pairs of characters
    for (int i = 0; i < num_pairs; ++i)
    {
        vector<int> pair(2);
        pair[0] = char_to_num(word[2 * i]);
        pair[1] = char_to_num(word[2 * i + 1]);
        Matrix matrix(pair);
        pairs[i][0] = matrix;
    }

    // Create the encryption matrix
    Matrix C(2,2);
    C.m_data[0][0] = -1;
    C.m_data[0][1] = -1;
    C.m_data[1][0] = 2;
    C.m_data[1][1] = 1;

    // Apply the encryption algorithm to each matrix
    string encrypted;
    for(int i = 0; i < num_pairs; i++)
    {
        Matrix X = pairs[i][0];
        X.m_cols = 2;
        X.m_rows = 1;
        Matrix result = X * C;
        vector<int> pair = result.toVector();
        encrypted += num_to_char(pair[0]);
        encrypted += num_to_char(pair[1]);
    }

    return encrypted;
}

string decrypt(string encrypted)
{
    if (encrypted.size() % 2 != 0)
    {
        encrypted += " ";
    }

    Matrix C(2,2);
    C.m_data[0][0] = -1;
    C.m_data[0][1] = -1;
    C.m_data[1][0] = 2;
    C.m_data[1][1] = 1;

    // Calculate the inverse of the encryption matrix
    Matrix inv = C.inverse();
    int num_pairs = encrypted.size() / 2;
    vector<vector<Matrix>> pairs(num_pairs, vector<Matrix>(1));

    // Create matrices from pairs of characters
    for (int i = 0; i <num_pairs; ++i)
    {
        vector<int> pair(2);
        pair[0] = char_to_num(encrypted[2 * i]);
        pair[1] = char_to_num(encrypted[2 * i + 1]);
        Matrix matrix(pair);
        pairs[i][0] = matrix;
    }
    
    string decrypted;
    for(int i = 0; i < num_pairs; i++)
    {
        Matrix X = pairs[i][0];
        X.m_cols = 2;
        X.m_rows = 1;
        Matrix result = X * inv;
        vector<int> pair = result.toVector();
        decrypted += num_to_char(pair[0]);
        decrypted += num_to_char(pair[1]);
    }

    return decrypted;
}

void display_menu()
{
    cout << "---------- Menu ----------\n";
    cout << "1. Encrypt message\n";
    cout << "2. Decrypt message\n";
    cout << "3. Exit program\n";
    cout << "---------------------------\n";
}

void display_menu2()
{
    cout << "---------- Menu ----------\n";
    cout << "1. Encrypt message in file\n";
    cout << "2. Decrypt message in file\n";
    cout << "3. Encrypt message in console\n";
    cout << "4. Decrypt message in console\n";
    cout << "5. Exit program\n";
    cout << "---------------------------\n";
}