#include<iostream>
using namespace std;
class complex_number
{
float r,i;  //data members of class
public:
void set_val (float templ, float temp2)  //sets value of complex number
{ r=templ;i=temp2; }

void print_number() //printing the complex number as per representation a + ib
{cout<<"\n"<<r<<" +"<<i<<"i"<<endl;}


//Overloading the binary operators ( + , -) 
complex_number operator+(complex_number); //adding two complex numbers
complex_number operator-(complex_number);  //subtracting two complex numbers
};

complex_number complex_number::operator +(complex_number A) //adding two complex number instances
{
complex_number B;
B.r=r+A.r;
B.i=i+A.i;
return B;
}

complex_number complex_number::operator - (complex_number A) //subtracting two complex number instances
{
complex_number B;
B.r=r-A.r;
B.i=i-A.i;
return B;
}

//main function
int main()
{
cout<<"\n Overloading binary operators";
cout<<"\n Addition of two complex number";\
complex_number first_num, second_num, sum, sub, diff;
first_num.set_val(10,10.5);
second_num.set_val(20,20.2);

sum=first_num+second_num;
sum.print_number();

diff=first_num-second_num;
diff.print_number();
return 0;
}