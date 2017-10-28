#include<iostream>
#include<math.h>
#include<string>
#include<sstream>
using namespace std;
string arr[3]={"\\|","||","|/"};
int ToTernary(int dec)
{
long rem,i=1,sum=0;
do
{ rem=dec%3;
sum=sum + (i*rem);
dec=dec/3;
i=i*10;
}while(dec>0);
// cout<<"The binary of the given number is:"<<sum<<endl;

return sum;
}
int Todec(string n)
{

int number	=atoi(n.c_str());
int output = 0;
for(int i=0; number > 0; i++)
{
int d= number% 10 ;
output += pow(3,i)*d;
number /= 10;
}
return output;
}
int ConvertToEarth(string lett)
{
string finallet;
for(int i=0;i<2;i++)
{
string ch=lett.substr(i*2,2);
for(int w=0;w<3;w++)
{
if(ch==arr[w])
{
stringstream ss;
ss<<w;
finallet+=ss.str();
break;
}
}
}

return Todec(finallet);
}
string ConvertToMars(int dec)
{

stringstream ss;
ss<<ToTernary(dec);
string ssd=ss.str(),finalres;
for(int i=0;i<ssd.size();i++)
{
string cha=ssd.substr(i,1);
finalres+=arr[atoi(cha.c_str())];

}
return finalres;
}
int main()
{
int sw,earth;
string mars;
cout<<"Press 1 to Convert from Mars system to Earth system\nPress 2 to Convert from Earth system to Mars system\n? ";
cin>>sw;
switch(sw)
{
case 1:
cin>>mars;

cout<<"The number "<<mars<<" in Earth system = "<<ConvertToEarth(mars)<<endl;
break;
case 2:
cin>>earth;
cout<<"The number "<<earth<<" in Mars system = "<<ConvertToMars(earth)<<endl;
break;
default:
cout<<"Invalid Input"<<endl;
break;
}

system("pause");
return 0;
}