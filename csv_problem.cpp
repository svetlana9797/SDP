#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

bool hasPhoneNumber(ifstream &file, string phoneNumber)
{
    string inf[4];
    string line;
    int sum=0;
    //read row by row
    while(getline(file,line))
    {

        istringstream lineStream(line);
        string cell;
        int i=0;
        while(getline(lineStream,cell,','))
        {
            inf[i++] = cell;
        }
        if(inf[1]==phoneNumber) sum+=stoi(inf[3]);//return true;
    }
    cout<<sum;//return false;
}

int main()
{
    ifstream file("phones.csv");
    string phoneNumber="0886408666";

   hasPhoneNumber(file,phoneNumber);

    return 0;
}
