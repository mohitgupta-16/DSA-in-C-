#include <iostream>
#include <string>
using namespace std;

// f(x)= x^2 + 2
int add(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

class Employee
{
public:
    string name;
    int salary;

    Employee(string n, int s, int sp)
    {
        this->name = n;
        this->salary = s;
        this->secretPassword = sp;
    }

    void printDetails()
    {
        cout << "The name of our 1st Employee is " << this->name << " and his salary is " << this->salary << endl;
    }

    void getSecretPassword()
    {
        cout << "The secret password of Employee is " << this->secretPassword;
    }

private:
    int secretPassword;
};

class Programmer : public Employee
{
public:
    int errors;
};

int main()
{
    // cout<<"Hello world"<<endl;
    // cout<<"Next line";
    // int a, b, c;
    // short sa = 9;
    // cout<<sa;

    // camelCase Notation
    // int marksInMaths = 83;
    // cout<<"The marks in maths is "<<marksInMaths;

    // string mohit = "mohit"
    // short a;
    // int b;
    // long c;
    // long long d;
    // float const score = 45.32;
    // double score2 = 45.322;
    // long double score3 = 45.332;
    // // score = 34.2;
    // cout<<"The score is "<<score;

    // int a, b;
    // cout << "Enter first number" << endl;
    // cin >> a;

    // cout << "Enter second number" << endl;
    // cin >> b;

    // cout << "a+b is  " << a + b << endl;
    // cout << "a-b is  " << a - b << endl;
    // cout << "a*b is  " << a * b << endl;
    // cout << "a/b is  " << (float) a / b << endl;

    // int age;
    // cout << "Enter your age" << endl;
    // cin >> age;

    // if (age>150 || age<4)
    // {
    //     cout<<"Invalid age";
    // }
    // else if (age>=18)
    // {
    //     cout<<"You can vote";
    // }
    // else
    // {
    //     cout<<"You cannot vote";
    // }

    // switch (age)
    // {
    // case 12:
    // cout << "You are 12 years old";
    //     break;
    // case 18:
    //     cout << "You are 18 years old";
    //     break;
    // default:
    //     cout << "You are neither 12 nor 18";
    // }

    // int index = 0;
    // while (index < 34)
    // {
    //     cout << "We are at index number " << index << endl;
    //     index++;
    // }

    // do
    // {
    //     cout << "We are at index number " << index << endl;
    //     index++;
    // } while (index > 3453);

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "The value of i is " << i << endl;
    // }

    // int a, b;
    // cout << "Enter first number" << endl;
    // cin >> a;

    // cout << "Enter second number" << endl;
    // cin >> b;

    // cout<<"The function returned "<<add(a,b);

    //     int arr[] = {1, 3, 6};
    // // array index    0  1  2
    //     // cout<<arr[1];
    //     int marks[6];
    //     for (int i = 1; i < 6; i++)
    //     {
    //         cout<<"Enter the marks of "<<i<<"th student"<<endl;
    //         cin>>marks[i];
    //     }
    //     for (int i = 1; i < 6; i++)
    //     {
    //         cout<<"Marks of "<<i<<"th student is "<<marks[i]<<endl;
    //     }

    // int arr2d[2][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6}};
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << "The value at " << i << "," << j << " is " << arr2d[i][j] << endl;
    //     }
    // }

    // int a = 343;
    // float b = 87.34;
    // cout<<(float)a/34<<endl;

    // cout<<(int)b;

    // string name = "Mohit";
    // cout<<"The name is "<<name<<endl;
    // cout<<"The lenght of name is "<<name.length()<<endl;
    // cout<<"The substr of name is "<<name.substr(0,3)<<endl;
    // cout<<"The substr of name is "<<name.substr(2,3)<<endl;

    // int a = 34;
    // int *ptra;
    // ptra = &a;
    // cout<<ptra<<endl;//address
    // cout<<*ptra;//value

    Employee har("Mohit Constructer", 23323, 6668);
    // har.name = "Mohit";
    // har.salary = 10000;
    // cout<<"The name of our 1st Employee is "<<har.name<<" and his salary is "<<har.salary<<endl;
    har.printDetails();
    // cout<<har.secretPassword;
    har.getSecretPassword();

    return 0;
}