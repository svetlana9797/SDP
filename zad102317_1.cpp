#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
const int MAX=30;
class Client
{
    int id;
    char firstName[MAX];
    char lastName[MAX];
    float balance;

public:

    Client(int id=0, const char* firstName="",const char* lastName="", float balance=0):id(id), balance(balance)
    {
       if(firstName==nullptr)
        this->firstName[0]='\0';
       else
        {
            strncpy(this->firstName,firstName,MAX);
            this->firstName[MAX-1]='\0';
        }
       if(lastName==nullptr)
        this->lastName[0]='\0';
       else
       {
           strncpy(this->lastName,lastName,MAX);
           this->lastName[MAX-1]='\0';
       }
    }
    int getId()const
    {
        return id;
    }
    char const* getFirstName() const
    {
        return firstName;
    }
    char const* getLastName() const
    {
        return lastName;
    }
    float getBalance() const
    {
        return balance;
    }

    void setBalance(float const& b)
    {
        balance=b;
    }

    friend istream& operator>>(istream& is, Client& obj)
    {
        return is>>obj.id>>obj.firstName>>obj.lastName>>obj.balance;
    }

};
 ostream& operator<<(ostream& os, Client const& obj)
    {
        return os<<obj.getId()<<obj.getFirstName()<<obj.getLastName()<<obj.getBalance();
    }

void writeToFile(char const* filename, Client const* arr, int n)
{
    ofstream file(filename,ios::out|ios::binary);
    for(int i=0;i<n;i++)
    {
        file.write((char*)&arr[i], sizeof(Client));
    }
}

void extractFromFile(char const* filename)
{
    cout<<"extracting from file..\n";
    Client c;
    ifstream file(filename,ios::in|ios::binary);
    {
        while(file.read((char*)&c, sizeof(Client)))
        {
            cout<<c<<endl;
        }
        cout<<"...End of extract\n";
    }
}

void append(Client &c,char const* filename)
{
    ofstream file(filename, ios::out|ios::binary|ios::app);
    file.write((char*)&c,sizeof(Client));
}

Client findByAccount(int account,char const* filename)
{
    ifstream file(filename,ios::in|ios::binary);
    {
        Client c;
        while(file.read((char*)&c, sizeof(Client)))
        {
            if(c.getId()==account) return c;
        }
        cout<<"There is no client with such account\n";
    }
}

void changeBalance(int account,float newBalance, char const* filename)
{
    fstream file(filename,ios::in|ios::out|ios::binary);
    {
        Client c;
        while(file.read((char*)&c, sizeof(Client)))
        {
            if(c.getId()==account)
            {
                cout<<"found the id!!\n"<<endl;
                c.setBalance(newBalance);
                //file.seekg( - sizeof(Client),ios::cur);
                file.seekp( file.tellg()- sizeof(Client),ios::cur);
                file.write((char*)&c, sizeof(Client));
                return;
            }
        }
        cout<<"There is no client with such account.Cannot change Balance\n";
    }
}
int main()
{
    int n;
    cin>>n;
    Client arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cout<<arr[i]<<endl;
    }
//    Client d(2,"ivan","peshev",23);
   writeToFile("client.dat",arr,n);
//    extractFromFile("client.dat");
//    append(d,"client.dat");
//    extractFromFile("client.dat");
//    Client c=findByAccount(12,"client.dat");
//    cout<<c<<endl;
//    findByAccount(121,"client.dat");
   changeBalance(12,333,"client.dat");
   extractFromFile("client.dat");
    return 0;
}
