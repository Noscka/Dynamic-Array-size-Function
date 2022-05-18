#include <iostream>

int ArraySize = 1;
char* CharArray = new char[ArraySize]();
int CharArrayIndexPointer;

void AddToDynamicArray(char CharaterToAdd)
{
    std::cout << "Adding To array: " << CharaterToAdd << std::endl;

    if (CharArrayIndexPointer >= ArraySize) // if Current Index pointer is more then the array size (trying to add to OutOfRange space)
    {
        printf("Expanding\n");

        char* TempArray = new char[ArraySize](); // Create new array which will store the original values

        for (int i = 0; i < ArraySize; i++) // assign/copy all values from CharArray to Temp
        {
            char ch = CharArray[i];
            TempArray[i] = CharArray[i];
            std::cout << "TempArray[" << i << "] <- " << ch << std::endl;
        }

        ArraySize += 2; // expand the Array size
        CharArray = new char[ArraySize](); // over ride CharArray with new, bigger, array

        /*
        ArraySize-2 calculates TempArray size
        Copy all values from Temp array to "old" expanded array
        */
        for (int i = 0; i < ArraySize-2; i++)
        {
            char ch = TempArray[i];
            CharArray[i] = TempArray[i];
            std::cout << "CharArray[" << i << "] <- " << ch << std::endl;
        }

        delete[] TempArray;
    }

    CharArray[CharArrayIndexPointer] = CharaterToAdd;
    CharArrayIndexPointer++;

}

int main()
{
    char array[24] = "TestTextWhichMakesSense";

    std::cout << CharArray << std::endl;
    for (char ch : array)
    {
        std::cout << "=============================================" << std::endl;
        AddToDynamicArray(ch);
        std::cout << "Char Array after adding: " << CharArray << std::endl;
        std::cout << "=============================================" << std::endl;
    }

    std::cout << "Char Array at end: " << CharArray << std::endl;
    std::cout << "Char Array Size at end: " << ArraySize << std::endl;
    std::cout << "Char Array Index Pointer at end: " << CharArrayIndexPointer << std::endl;
    return 0;
}