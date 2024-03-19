#include "Header.h"

Matrix createMatrix()
{
    Matrix matrix(26, 26);

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++) 
        {
            matrix.m_data[i][j] = 'A' + ((i + j) % 26);
        }
    }

    return matrix;
}

string encrypt(string message, int shift, const Matrix& matrix)
{
    string encryptedMessage = "";

    for (int i = 0; i < message.length(); i++)
    {
        if (isalpha(message[i])) 
        {
            char encryptedChar = matrix.m_data[toupper(message[i]) - 'A'][shift];
            encryptedMessage += encryptedChar;
        }
        else
        {
            encryptedMessage += message[i];
        }
    }

    return encryptedMessage;
}

string decrypt(string message, int shift, const Matrix& matrix)
{
    string decryptedMessage = "";

    for (int i = 0; i < message.length(); i++)
    {
        if (isalpha(message[i]))
        {
            char decryptedChar = 'A';
            for (int j = 0; j < 26; j++)
            {
                if (matrix.m_data[shift][j] == toupper(message[i]))
                {
                    decryptedChar = 'A' + j;
                    break;
                }
            }
            decryptedMessage += decryptedChar;
        }
        else
        {
            decryptedMessage += message[i];
        }
    }

    return decryptedMessage;
}

void display_main()
{
    cout << "---------- Menu ----------\n";
    cout << "1. INVERSE ENCRYPTION\n";
    cout << "2. CAESAR ENCRYPTION\n";
    cout << "3. EXIT\n";
    cout << "---------------------------\n";
}