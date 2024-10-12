#include<iostream>
#include<math.h>
using namespace std;

void add();
void sub();
void multi();
void divison();
void exit();

int main(){
    while(1){

    cout<<"\t\t\t\t\t\t\t-----------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\t\tSimple Calculator"<<endl;
    cout<<"\t\t\t\t\t\t\t-----------------------------"<<endl;

    cout<<endl;
    cout<<"\t\t\t\t\t\t\t\t  Welcome!!"<<endl;
    cout<<"This is a simple calculator which can perform simple arithmetic operations such as addition, subtraction, multiplication and divison."<<endl;
    cout<<"It allows user to input two numbers and choose and operation to perform."<<endl;
    cout<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;

    int opr;
    cout << "Select any operation from the C++ Calculator"  
     "\n1 = Addition"  
     "\n2 = Subtraction"  
     "\n3 = Multiplication"  
     "\n4 = Divison"  
     "\n5 = Exit"<<endl;
     cout<<endl;
     cout<<"Make a choice: ";
     cin>>opr;
     cout<<endl;

     switch(opr)  
     {  
     case 1:  
        add();   // call add() function to find the Addition  
        break;  
    case 2:  
        sub();   // call sub() function to find the subtraction  
        break;  
    case 3:  
        multi(); // call multi() function to find the multiplication  
        break;  
    case 4:  
        divison(); // call division() function to find the division  
        break;  
    case 5:  
            exit(0);   // terminate the program  
        break;  
    default:  
        cout <<"Something is wrong..!!";  
        break;  
    }  
    cout<<"*********************************************************************************************************************************"<<endl;
}
}
double num1, num2;
double input(){
    
    cout<<"Enter first digit: ";
    cin>>num1;
    cout<<"Enter second dight: ";
    cin>>num2;
    return num1,num2;

}
void add()
{
    input();
    cout<<"Addition of "<<num1<<" and "<<num2<<" is: "<<num1+num2<<endl;
}

void sub()
{
    input();
    cout<<"Subtraction of "<<num1<<" and "<<num2<<" is: "<<num1-num2<<endl;
}

void multi()
{
    input();
    cout<<"Multiplication of "<<num1<<" and "<<num2<<" is: "<<num1*num2<<endl;
}

void divison()
{
    input();
    cout<<"Divison of "<<num1<<" and "<<num2<<" is: "<<num1/num2<<endl;
}
