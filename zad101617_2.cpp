#include<iostream>
#include<fstream>
using namespace std;

struct Gas
{
    int counterId;
    double quantity;
};

double totalForCounter(int counterId, double pricePerLiter)
{
    ifstream file("sales.txt");
    int id;
    double sum=0;
    double litres;
    while(file>>id>>litres)
    {
        cout<<'\n'<<id<< ' '<<litres<<endl;
        if(id==counterId)
        {
            sum+=litres*pricePerLiter;
        }
    }
    cout<<"counter "<<counterId<<" has produced "<<sum;
}

void writeAverages(int toId)
{

    fstream file("averages.bin", ios::out|ios::binary);
    ifstream file1("sales.txt");
    int id;
    double litres;

        double sum=0;
        int num=0;
        while(file1>>id>>litres) //докато има какво да се чете
        {
            if(id==toId)
            {
                file.write((char*)&litres, sizeof(double));
                sum+=litres;
                num++;
            }

        }

        if(num!=0) //check if sum/num is a correct statement
        {
            double average=sum/num;                       //записваме си реда
            file.write((char*)&average, sizeof(double));
        }

        else
        {
            double average=0;
            file.write((char*)&average, sizeof(double));
        }

    file1.close();
    file.close();

    file.open("averages.bin", ios::in|ios::binary);
    double nums;
    while(file.read((char*)&nums, sizeof(double)))
    {
        cout<<nums<<' ';
    }

}
int main()
{
//   totalForCounter(2,1);
//    totalForCounter(1,2);
for(int i=0;i<3;i++)
writeAverages(i);
    return 0;
}

