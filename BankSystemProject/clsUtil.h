#pragma once

#include<iostream>
#include<cstdlib>

using namespace std;

class clsUtil
{
public:

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    enum enCharType
    {
        SmallLetters = 1,    // Represents lowercase letters (ASCII 97 to 122).
        CapitalLetter = 2,   // Represents uppercase letters (ASCII 65 to 90).
        Digit = 3, // Represents digits (ASCII 48 to 57).
        MixChars = 4
    };

   static int RandomNumber(int From, int To)
   {
        int randNum = rand() % (To - From + 1) + From;

        return randNum;  // Return the generated random number.
   }

   static char GetRandomCharacter(enCharType CharType)
   {
       if (CharType == enCharType::MixChars)
       {
           CharType = (enCharType)RandomNumber(1, 3); // Casting to enum.
       }

       // Use a switch-case to handle the different character types.
       switch (CharType)
       {
         case enCharType::SmallLetters:
         {
           // Generate a random lowercase letter (ASCII codes 97 to 122).
           return char(RandomNumber(97, 122));
           break;  // break is not strictly needed after a return.
         }
         case enCharType::CapitalLetter:
         {
           // Generate a random uppercase letter (ASCII codes 65 to 90).
           return char(RandomNumber(65, 90));
           break;
         }
         case enCharType::Digit:
         {
           // Generate a random digit (ASCII codes 48 to 57).
           return char(RandomNumber(48, 57));
           break;
         }
       }
       // If an invalid type is passed, return a null character.
       return '\0';
   }

   static string GenerateWord(enCharType CharType, short Length)
   {
       string Word = "";

       for (short i = 0; i < Length; i++)
       {
           Word += GetRandomCharacter(CharType);
       }

       return Word;
   }

   static string GenerateKey()
   {
       string Key = "";  // Initialize an empty key string.

       // Concatenate four groups of 4 random uppercase letters, separated by hyphens.
       Key = GenerateWord(enCharType::MixChars, 4) + "-";
       Key = Key + GenerateWord(enCharType::MixChars, 4) + "-";
       Key = Key + GenerateWord(enCharType::MixChars, 4) + "-";
       Key = Key + GenerateWord(enCharType::MixChars, 4);

       return Key;
   }

   static void GenerateKeys(int Length, enCharType CharType)
   {
       string Keys = "";
       short Counter = 0;

       for (int i = 0; i < Length; i++)
       {
           cout << "Key [" << ++Counter << "] : ";
           Keys = GenerateKey();
           cout << Keys << "\n";
       }
   }

   static void Swap(int& a, int& b)
   {
       int Temp = 0;

       Temp = a;
       a = b;
       b = Temp;
   }
   
   static void Swap(double& a, double& b)
   {
       double Temp = 0;

       Temp = a;
       a = b;
       b = Temp;
   }

   static void Swap(string& s1, string& s2)
   {
       string Temp = "";

       Temp = s1;
       s1 = s2;
       s2 = Temp;
   }

   static void ShuffleArray(int arr[100], int Length)
   {
       for (int i = 0; i < Length; i++)
       {
           Swap(arr[RandomNumber(1, Length) - 1], arr[RandomNumber(1, Length) - 1]);
       }
   }

   static void ShuffleArray(string arr[100], int Length)
   {
       int Index1 = 0, Index2 = 0;

       for (int i = 0; i < Length; i++)
       {
           Index1 = RandomNumber(1, Length) - 1;
           Index2 = RandomNumber(1, Length) - 1;

           Swap(arr[Index1], arr[Index2]);
       }
   }

   static void FillArrayWithRandomNumbers(int arr[100], int Length, int From, int To)
   {
       for (int i = 0; i < Length; i++)
       {
           arr[i] = RandomNumber(From, To);
       }
   }

   static void FillArrayWithRandomWords(string arr[100], enCharType CharType, int Length)
   {
       for (int i = 0; i < Length; i++)
       {
           arr[i] = GenerateWord(enCharType::MixChars, 4);
       }
   }

   static void FillArrayWithRandomKeys(string arr[100], int Length)
   {
       for (int i = 0; i < Length; i++)
       {
           arr[i] = GenerateKey();
       }
   }

   static string Taps(int TapLength)
   {
       string tapLength;
       
       for (int i = 0; i < TapLength; i++)
       {
           tapLength += " ";
       }

       return tapLength;
   }

   static string  EncryptText(string Text, short EncryptionKey)
   {

       for (int i = 0; i <= Text.length(); i++)
       {

           Text[i] = char((int)Text[i] + EncryptionKey);

       }

       return Text;

   }

   static string  DecryptText(string Text, short EncryptionKey)
   {

       for (int i = 0; i <= Text.length(); i++)
       {

           Text[i] = char((int)Text[i] - EncryptionKey);

       }
       return Text;

   }

   static string NumberToText(int Number)
   {

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";

       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }
   }

   static string EncryptText(string Text, int EncryptionKey = 2)
   {
       for (int i = 0; i <= Text.length(); i++)
       {
           Text[i] = char((int)Text[i] + EncryptionKey);
       }
       
       return Text;
   }

   static string DecryptText(string Text, int EncryptionKey = 2)
   {
       for (int i = 0; i <= Text.length(); i++)
       {
           Text[i] = char((int)Text[i] - EncryptionKey);
       }

       return Text;
   }
};

