#include "Header.h"
#include<fstream>

int main()
{
    int main_choice;
    l1:display_main();
    cin>>main_choice;

    switch(main_choice)
    {
        case 1 : {
            int choice;
            string message, result;
            ifstream inputFile;
            string filename;
        do
        {
            display_menu2();
            
            
            
            
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch(choice)
            {
                case 1:
                    cout << "Enter the name of the input file: ";
                    cin >> filename;
                    inputFile.open(filename);

                    if (!inputFile)
                    {
                        cout << "Error: Could not open file.\n";
                        break;
                    }

                    // Read input from file and convert to string
                    while (getline(inputFile,message))
                    {
                        cout << "Encrypted message: " << encrypt(message) << endl;

                    }

                    inputFile.close();

                    
                    break;

                case 2:{
                    cout << "Enter the name of the input file: ";
                    cin >> filename;
                    inputFile.open(filename);

                    if (!inputFile)
                    {
                        cout << "Error: Could not open file.\n";
                        break;
                    }
                    ofstream op("answer.txt");
                    // Read input from file and convert to string
                    while (getline(inputFile,message))
                    {
                        cout<<"Message :"<<message<<endl;
                        cout << "Decrypted message: " << decrypt(message) << endl;
                        op << decrypt(message)<< endl;
                    }
                    op.close();
                    inputFile.close();
                    break;
                }

                case 3:{
                    cout << "Enter message to encrypt: ";
                    cin.ignore();
                    getline(cin, message);
                    result = encrypt(message);
                    cout << "Encrypted message: " << result << endl;
                    break;
                }

                case 4:{
                    cout << "Enter message to decrypt: ";
                    cin.ignore();
                    getline(cin, message);
                    result = decrypt(message);
                    cout << "Decrypted message: " << result << endl;
                    break;
                }

                case 5:
                    goto l1;

                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 5);
        }

        case 2 : {
            int choice;
            string message, result;
            ifstream inputFile;
            string filename;
            Matrix matrix; 

        do
        {
            display_menu();

            cout << "Enter your choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    cout << "Select input source:\n";
                    cout << "1. Console\n";
                    cout << "2. File\n";
                    cout << "Enter your choice: ";
                    int ip_choice;
                    cin >> ip_choice;
                    if (ip_choice == 1)
                    {
                        cout << "Enter the message to encrypt: ";
                        cin.ignore();
                        getline(cin, message);
                        cout << "Enter the shift value: ";
                        int shift;
                        cin >> shift;
                        matrix = createMatrix(); // Initialize matrix inside case 1
                        result = encrypt(message, shift, matrix);
                        cout << "Encrypted message: " << result << endl;
                        break;
                    }
                    else if (ip_choice == 2)
                    {
                        cout << "Enter the name of the input file: ";
                        cin >> filename;
                        inputFile.open(filename.c_str());
                        if (!inputFile)
                        {
                            cout << "Error: Could not open file.\n";
                            break;
                        }
                        cout << "Enter the shift value: ";
                        int shift;
                        cin >> shift;
                        matrix = createMatrix(); // Initialize matrix inside case 2
                        while (getline(inputFile, message))
                        {
                            result = encrypt(message, shift, matrix);
                            cout << result << endl;
                        }
                        inputFile.close();
                    }
                    break;

                case 2:
                    cout << "Select input source:\n";
                    cout << "1. Console\n";
                    cout << "2. File\n";
                    cout << "Enter your choice: ";
                    int input_choice;
                    cin >> input_choice;
                    if (input_choice == 1)
                    {
                        cout << "Enter the message to decrypt: ";
                        cin.ignore();
                        getline(cin, message);
                        cout << "Enter the shift value: ";
                        int shift;
                        cin >> shift;
                        matrix = createMatrix(); // Initialize matrix inside case 2
                        result = decrypt(message, shift, matrix);
                        cout << "Decrypted message: " << result << endl;
                    }
                    else if (input_choice == 2)
                    {
                        cout << "Enter the name of the input file: ";
                        cin >> filename;
                        inputFile.open(filename.c_str());
                        if (!inputFile)
                        {
                            cout << "Error: Could not open file.\n";
                            break;
                        }
                        cout << "Enter the shift value: ";
                        int shift;
                        cin >> shift;
                        matrix = createMatrix(); // Initialize matrix inside case 2
                        while (getline(inputFile, message))
                        {
                            result = decrypt(message, shift, matrix);
                            cout << result << endl;
                        }
                        inputFile.close();
                    }
                    break;

                case 3:
                    goto l1;

                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 3);


    }



    }




}