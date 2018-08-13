#include<iostream>
#include<forward_list>
#include<string>
#include<sstream>
#include<fstream>
#include<stack>
#include<set>
using namespace std;

bool areEqual(string const& open, string const& close) //checks if the opening and closing tag are equal
{
    for(int i=2;i<8;i++)
    {
        if(open[i-1]!=close[i]) return false;
    }
    return true;
}

void returnToStack(forward_list<int>& numbers, stack<string>& fileStack)
{
    for(auto x: numbers)
    {
        stringstream ss;
        ss << x;
        string s=ss.str();
        fileStack.push(s);
    }
    numbers.clear();
}

//gets the number from the MAP-MLT/MAP-INC tag
int getNumber(string const& operation)
{
    istringstream iss(operation);
    char cell;
    int num=0;
    while(iss.get(cell)) //read the number from the operation
    {
        if(isdigit(cell))
            num=num*10 + (cell-'0');
    }
    return num;
}

mapInc(string const& operation, forward_list<int>& numbers,stack<string>& fileStack)
{
    int num=getNumber(operation);

    for(auto& x:numbers)
    {
        x+=num;
    }

    returnToStack(numbers,fileStack);
}

mapMlt(string const& operation, forward_list<int>&numbers,stack<string>& fileStack)
{
    int num=getNumber(operation);

    for(auto& x:numbers)
    {
        x*=num;
    }

    returnToStack(numbers,fileStack);
}

aggSum(string const& operation, forward_list<int>&numbers,stack<string>& fileStack)
{
    int sum = 0;
    for(auto& x:numbers)
    {
        sum+=x;
    }
    numbers.clear();
    numbers.push_front(sum);
    returnToStack(numbers,fileStack);
}

aggPro(string const& operation, forward_list<int>&numbers,stack<string>& fileStack)
{
    int sum = 0;
    for(auto& x:numbers)
    {
        sum*=x;
    }
    numbers.clear();
    numbers.push_front(sum);
    returnToStack(numbers,fileStack);
}

aggAvg(string const& operation, forward_list<int>&numbers,stack<string>& fileStack)
{
    int sum = 0;
    int br=0;
    for(auto& x:numbers)
    {
        sum+=x;
        br++;
    }
    numbers.clear();
    numbers.push_front(sum/br);
    returnToStack(numbers,fileStack);
}

aggFst(string const& operation, forward_list<int>&numbers,stack<string>& fileStack)
{
    int x = numbers.front();
    numbers.clear();
    numbers.push_front(x);
    returnToStack(numbers,fileStack);
}

aggLst(string const& operation, forward_list<int>&numbers,stack<string>& fileStack)
{
    numbers.reverse();
    int x = numbers.front();
    numbers.clear();
    numbers.push_front(x);
    returnToStack(numbers,fileStack);
}

srtRev(string const& operation, forward_list<int>&numbers,stack<string>& fileStack)
{
    numbers.reverse();
    returnToStack(numbers,fileStack);
}

srtOrd(string const& operation, forward_list<int>&numbers,stack<string>& fileStack)
{
    string op = operation.substr(10,3);

    if(op=="ASC")
    numbers.sort();

    if(op=="DSC")
    numbers.sort(greater<int>());

    returnToStack(numbers,fileStack);
}

srtSlc(string const& operation, forward_list<int>&numbers,stack<string>& fileStack)
{
    int num=getNumber(operation);
    for(int i=0;i<num;i++)
    numbers.pop_front();

    returnToStack(numbers,fileStack);
}

srtDst(string const& operation, forward_list<int>&numbers,stack<string>& fileStack)
{
    set<int> s;
    forward_list<int> nums;
    for(auto x: numbers)
    {
        if(s.find(x)==s.end())
        {
            nums.push_front(x);
             s.insert(x);
        }
    }
    nums.reverse();
    returnToStack(nums,fileStack);
}

void doOperation(string const& operation, stack<string>& fileStack)
{

    forward_list<int> numbers; //put all the numbers from the stack in a forward_list
    string curr=fileStack.top();
    while(isdigit(curr[0]))
    {
        numbers.push_front(stoi(curr));
        fileStack.pop();
        curr=fileStack.top();
    }
    fileStack.pop(); //remove the operation from the stack
    string op = operation.substr(1,7);

    if(op=="MAP-INC") mapInc(operation,numbers,fileStack);
    if(op=="MAP-MLT") mapMlt(operation,numbers,fileStack);
    if(op=="AGG-SUM") aggSum(operation,numbers,fileStack);
    if(op=="AGG-PRO") aggPro(operation,numbers,fileStack);
    if(op=="AGG-AVG") aggAvg(operation,numbers,fileStack);
    if(op=="AGG-FST") aggFst(operation,numbers,fileStack);
    if(op=="AGG-LST") aggLst(operation,numbers,fileStack);
    if(op=="SRT-REV") srtRev(operation,numbers,fileStack);
    if(op=="SRT-ORD") srtOrd(operation,numbers,fileStack);
    if(op=="SRT-SLC") srtSlc(operation,numbers,fileStack);
    if(op=="SRT-DST") srtDst(operation,numbers,fileStack);

}

void writeToFile(stack<string>& fileStack, ofstream& file)
{
    stack<string> result;
       while(!fileStack.empty()) //reverse the numbers in the correct order
       {
           result.push(fileStack.top());
           fileStack.pop();
       }

       while(!result.empty()) //and put them in the file
       {
           file<<result.top()<<' ';
           result.pop();
       }
    file.close();
}

readFromFile(stack<string>& fileStack,stack<string>& openTags,ifstream& file,ofstream& outputFile)
{
    string line;
    while(getline(file,line))
    {
        istringstream lineStream(line);
        char cell;
        while(lineStream.get(cell))
        {
            string curr;
            if(isdigit(cell)) //if it is a digit push it directly to the stack
            {
                string c;
                c+=cell;

               while(lineStream.get(cell)&&cell!=' '&&cell!='<')
                    c+=cell;

                fileStack.push(c);
            }

            if(cell=='<') //new tag
            {
                curr.clear();
                while(cell!='>')  //close current tag => push the string to the stack
                {
                     curr+=cell;
                    lineStream.get(cell);
                }

                curr+=cell; //add the symbol '>'
                fileStack.push(curr);  //the tag is already full so we add it to the stack

                if(curr[1]=='/') //separate the opening and closing tags
                  {
                      if(!areEqual(openTags.top(),curr)) //check if the current closing tag is correct
                         {
                             cerr<<"incorrect placement of tags!\n";
                             exit(1);
                         }

                      fileStack.pop();//remove the closing tag from the fileStack
                      doOperation(openTags.top(),fileStack);
                      openTags.pop(); //remove the already used open tag
                  }
                else
                  openTags.push(curr); //push the opening tags in the stack
            }
        }
    }
writeToFile(fileStack,outputFile);
}
int main()
{
    stack<string> fileStack;
    stack<string> openTags;

    ifstream input("input.txt");
    ofstream output("output.txt");
    readFromFile(fileStack,openTags,input,output);

    //check if the fileStack is empty at the end
   /* cout<<endl<<"the Stack"<<endl;
    while(!fileStack.empty())
    {
        cout<<fileStack.top()<<'\n';
        fileStack.pop();
    }

    //check if the open tags stack is empty at the end
   cout<<endl<<"the openTags"<<endl;
    while(!openTags.empty())
    {
        cout<<openTags.top()<<'\n';
        openTags.pop();
    }
*/
    return 0;
}
