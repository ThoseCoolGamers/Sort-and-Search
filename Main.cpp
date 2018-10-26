#include <iostream>
#include <random>
#include <time.h>
#include <string>

using namespace std;

//  FUNCTION:  Get Index Algorithm
//
//  PURPOSE:   return a vector with index(es) of a specified number.
//
//  ALGORITHM: Loops through a vector and every time the specified number appears
//             it will push the index of the number to a vector. After the loop
//             is finished the algorithm returns the index(es).

vector<int> GetIndex(int searchnumber, int startpos, vector<int> numbervector)
{

    vector<int> indexvector;

    for(unsigned int i = startpos; i < numbervector.size(); i++)
        if(numbervector.at(i) == searchnumber)
            indexvector.push_back(i);

    return indexvector;
}

//  FUNCTION:  Linear Search Algorithm
//
//  PURPOSE:   Tells the user the index(es) of a specified number that was found in a vector
//
//
//  ALGORITHM: Creates an index vector using the GetIndex function (see above for more information)
//             then we check if the size of the index vector is greater than zero if it is then the
//             algorithm loops through the index vector printing out all the indexes, however if
//             the index vector is zero then we print that the number was not found.

void LinearSearch(int searchnumber, vector<int> numbervector, int startpos)
{
    vector<int> index;
    index = GetIndex(searchnumber, 0, numbervector);

    if(index.size() > 0)
        for(unsigned int j = 0; j < index.size(); j++)
            cout << "found the number: " << searchnumber << " at index: " << index.at(j) << endl;
    else
        cout << "number not found :(" << endl;
}

//  FUNCTION:  Vector Sort Algorithm
//
//  PURPOSE:   Sorts an int vector from biggest to smallest
//
//  ALGORITHM: The algorithm works by pushing back the biggest
//             number in the unsorted vector into the sorted vector.
//             Then it does the same with the next biggest number
//             until it reaches the smallest number.

vector<int> VecSort(vector<int> unsortedvector)
{
    int biggestnumber = 0;
    int offset = 0;

    vector<int> sortedvector;

    for(unsigned int i = 0; i < unsortedvector.size(); i++)
        if(unsortedvector.at(i) > biggestnumber)
            biggestnumber = unsortedvector.at(i);

    for(;sortedvector.size() < unsortedvector.size();)
    {
        for(unsigned int x = 0; x < unsortedvector.size(); x++)
            if(unsortedvector.at(x) == biggestnumber - offset)
                sortedvector.push_back(unsortedvector.at(x));

        offset += 1;
    }

    return sortedvector;

}

//  FUNCTION:  Binary Search Algorithm
//
//  PURPOSE:   This searches through a sorted vector and tells the user
//             all the index were a specified number was found.
//
//  ALGORITHM: It preforms a normal linear search if the search number
//             is greater than half the sorted vector, If its not then
//             preform a linear search starting at half the sorted vector.
void BinarySearch(int searchnumber, std::vector<int> sortedvector)
{
    if(sortedvector.at(sortedvector.size()/2) < searchnumber)
        LinearSearch(searchnumber, sortedvector, 0);
    else
        LinearSearch(searchnumber, sortedvector, sortedvector.size()/2);
}

int main()
{
    int wantednumber;
    int seed;

    string usersearch;

    vector<int> unsortedvector;
    vector<int> sortedvector;


    cout << "What number do you want to look for (0-9): " << endl;
    cin >> wantednumber;

    cout << "Please enter a seed: " << endl;
    cin >> seed;

    srand(time_t(seed));

    for(int i = 0; i < 10; i++)
        unsortedvector.push_back(rand() % 10);

    system("CLS");
    sortedvector = VecSort(unsortedvector);

    cout << "What type of search would you like to preform? \n\nLinearSearch\nor\nBinarySearch?\n\ntype which one you want" << endl;
    cin >> usersearch;

    if(usersearch == "LinearSearch")
        LinearSearch(wantednumber, sortedvector, 0);

    if(usersearch == "BinarySearch")
        BinarySearch(wantednumber, sortedvector);

    return 0;

}
