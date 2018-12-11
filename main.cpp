// Ryan Evans
// read and write to a file

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::map;

void readFile(map<string, int> &m)
{
    ifstream fileIn;
    string word;

    fileIn.open("example.txt");

    if (!fileIn.is_open())
    {
        cout << "Could not open file";
        return;
    }

    while (fileIn >> word)
    {
        m[word]++;
    }

    fileIn.close();
}

void writeFile(map<string, int> &m)
{
    ofstream fileOut;
    fileOut.open("output.txt");

    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        int i = it -> second;
        while (i > 0)
        {
            fileOut << it -> first << " ";
            i--;
        }
    }
    fileOut.close();
}

int main()
{
    map<string, int> map;
    readFile(map);
    writeFile(map);

    return 0;
}