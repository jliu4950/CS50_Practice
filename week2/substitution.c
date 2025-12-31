#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    const int a = 26;
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    };

    // not containing 26 characters
    if (strlen(argv[1]) != a)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    };

    // containing any character that is not an alphabetic character
    for (int i = 0, cnt = strlen(argv[1]); i < cnt; i++)
    {
        if (argv[1][i] < 'A' || (argv[1][i] > 'Z' && argv[1][i] < 'a') || argv[1][i] > 'z')
        {
            printf("containing any character that is not an alphabetic character\n");
            return 1;
        };
    };
    // convert to lowercase
    // string cipher = argv[1];
    // for (int i = 0; i < a; i++)
    // {
    //     cipher[i] = tolower(cipher[i]);
    // };
    // // not containing each letter exactly once
    // for (int i = 0; i < a; i++)
    // {
    //     // for (int j = i + 1, n = a - i - 1; j < n; j++)
    //     for (int j = i + 1; j < a; j++)
    //     {
    //         if (cipher[i] == cipher[j])
    //         {
    //             printf("not containing each letter exactly once\n");
    //             return 1;
    //         }
    //     };
    // };

    // judge duplicated character
    // convert to lowercase
    string cipher = argv[1];
    int index[26];
    for (int i = 0; i < a; i++)
    {
        cipher[i] = tolower(cipher[i]);
        index[cipher[i]-'a']=1;
    };
    // not containing each letter exactly once
    int sum=0;
    for(int i=0;i<26;i++){
        sum+=index[i];
    };
    if(sum<26)
    {
        printf("not containing each letter exactly once\n");
        return 1;
    }
    // get input
    char *plaintext = get_string("please type a string:");
    // cipher plaintext
    char ciphertext[strlen(plaintext)];
    strcpy(ciphertext, plaintext);
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // if uppercase
        if (plaintext[i] <= 'Z'&&plaintext[i] >= 'A')
        {
            int j = plaintext[i] - 'A';
            ciphertext[i] = toupper(cipher[j]);
        }
        else if (plaintext[i] <= 'z'&&plaintext[i] >= 'a')//
        {
            int j = plaintext[i] - 'a';
            ciphertext[i] = tolower(cipher[j]);
        }
        else
        {
            ciphertext[i]=plaintext[i];
        };
    };
    printf("plaintext:%s\nciphertext:%s\n", plaintext, ciphertext);
    return 0;
}