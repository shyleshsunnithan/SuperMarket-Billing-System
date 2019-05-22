#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip.h>
int k=7,r=0,flag=0;
struct date
{int mm,dd,yy;
};
ofstream fout;
ifstream fin;
class item
{int itemno;
char name[25];
date d;
public:
void add()
{
cout<<”\n\n item no’;
cin>>itemno;
cout<<”\n\n\t name of the item”;
gets(name);
cout<<”\n\n\t manufacturing date (dd-mm-yy) : “;
cin>>d.mm>>d.dd>>d.yy;
}
 
void show()
{
cout<<”\n\n\t item no:”;
cout<<itemno;
cout<<”\n\n\t name of the item:”;
cout<<name;
cout<<\n\n\t date: “;
cout<<d.mm<<”-“<<d.dd<<”-“<<d.yy;
}
void report()
{ goto xy(3,k);
cout<<itemno;
goto xy(13,k);
puts(name);
}
int retno()
{return(itemno);}
};
class amount : public item 
{ float price,qty,tax,gross,dis,netamt;
public:
void add();
void show();
void report();
void calculate();
void pay();
float retnetamt()
{return(netamt);}
}amt;
void amount :: add()
{item :: add();
cout<<”\n\n\t Price :”;
cin>>price;
cout<<”\n\n\t Quantity :”;
cin>>qty;
cout<<”\n\n\t Tax Percent :”;
cin>>tax;
cout<<”\n\n\t Discount percent :”;
cin>>dis;
calculate();
fout.write((char*)&amt,sizeof(amt));
fout.close();
}
void amount::calculate()
{gross=price+(price*(tax/100));
netamt=qty*(gross-(gross*(dis/100)));
}
void amount::show()
{fin.open(“itemstore.dat”,ios::binary);
fin.fread((char*)&amt,sizeof(amt));
item::show();
cout<<”\n\n\t Net Amount :”;
cout<<netamt;
fin.close();
}

void amount::report()
{item::report();
goto xy(23,k);
cout<<price;
goto xy(44,k);
cout<<tax;
goto xy(52,k);
cout<<dis;
goto xy(64,k);
cout<<netamt;
k=k+1;
if(k==50)
{goto xy(25,50);
cout<<”PRESS ANY KEY TO CONTINUE…”;
getch();
k=7;
clrscr();
goto xy(30,3);
cout<<”ITEM DETAILS”;
goto xy(3,5);
cout<<”NUMBER”;
goto xy(13,5);
cout<<”NAME”;
goto xy(23,5);
cout<<”PRICE”;
goto xy(33.5);
cout<<”QUANTITY”;
goto xy(44,5)
cout<<”TAX”;
goto xy(52,5);
cout<<”DEDUCTION”;
goto xy(64,5);
cout<<”NET AMOUNT”;
}
}
void amount::pay()
{
show();
cout<<”\n\n\t\t ***********************************************************”;
cout<<”\n\n\t\t                DETAILS                “;
cout<<”\n\n\t\t                PRICE                    “<<price;
cout<<”\n\n\t\t                QUANTITY            “<<qty;
cout<<”\n\n\t\t                TAX PERCENTAGE “<<tax;
cout<<”\n\n\t\t                DISCOUNT PERCENTAGE”<<dis;
cout<<”\n\n\t\t                NET AMOUNT
:Rs. “<<netamt;
cout<<”\n\n\t\t******************************************”;
}
void main()
{
textbackground(BLUE);
textcolor(YELLOW);
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout<<setprecision(2);
menu:
clrscr();
cout<<”SUPER MARKET BILLING”;
goto xy(25,3);
cout<<”*****************”\n\n”;
cout<<”\n\t\t 1.Bill Report\n\n”;
cout<<”\t\t 2.Add/Remove/Edit Item\n\n”;
cout<<”\t\t 3.Show Item Details\n\n”;
cout<<”\t\t 4.Exit\n\n”;
cout<<”\t\t Please Enter Required Option:”;
int ch,ff;
float gtotal;
cin>>ch;
switch(ch)
{
case 1 :ss:
clrscr();
goto xy(25,2);
textcolor(YELLOW);
cout<<”Bill Details”;
goto xy(25,3);
cout<<”***********\n\n”;
cout<<”\n\t\t 1.All Items\n\n”;
cout<<”\t\t 2.Back to Main Menu\n\n”;
cout<<”\t\t Please Enter Required Option:”;
int cho;
cin>>cho;
if(cho==1)
{clrscr();
goto xy(30,3);
cout<<”Bill Details”;
goto xy(3,5);
cout<<”Item No”;
goto xy(13,5);
cout<<”Name”;
goto xy(23,5);
cout<<”Price”;
goto xy(33,5);
cout<<”Quantity”;
goto xy(44,5);
cout<<”Tax%”;
goto xy(52,5);
cout<<”Discount%”;
goto xy(64,5);
cout<<”Net Amount”;
fin.open(“itemstore.dat”,ios::binary);
if(!fin)
{cout<<”\n\n File Not Found….”;
goto  menu:}
fin.seekg(0);
gtotal=0;
while(!fin.eof())
{fin.read((char*)&amt,sizeof(amt));
if(!fin.eof())
{amt.report();
gtotal+=amt.retnamt();
ff=0;
}
if(ff!=0)
gtotal=0;
}
goto xy(17,k);
cout<<”\n\n\n\n\t\t\t\t Grand Total”<<gtotal;
getch();
fin.close();
}
if(cho==2)
{goto  menu;}
goto ss:
case 2:
db:
clrscr();
goto xy(25,2);
cout<<”Bill Editor”;
goto xy(25,3);
cout<<”***********\n\n”;
cout<<”\n\t\t 1.Add Item Details \n\n”;
cout<<”\t 2.Edit Item Details \n\n”;
cout<<”\t\t 3.Delete Item Details \n\n”;
cout<<”\t\t 4.Back To Main Menu \n\n”;
cout<<”\t\t Enter Required Option: “;
int apc;
cin>>apc;
switch(apc)
{case 1 : fout.open(“itemstore.dat”,ios::binary|ios::app);
amt.add();
cout<<”\n\t item added successfully!”;
goto db;
case 2: 
int ino;
flag+0;
cout<<”\n\n\t Enter Item Number To Be Edited :”;
cin>>ino;
fin.open(“itemstore.dat”,ios::binary);
fout.open(“itemstore.dat”,ios::binary|ios::app);
if(!fin)
{cout<<”\n\n File Not Found…”;
goto  menu;
}
fin.seekg(0);
r=0;
while(!fin.eof())
{fin.read((char*)&amt,sizeof(amt));
if(!fin.eof())
{int x=amt.item::retno();
if(x==ino)
{flag =1;
fout.seekp(r*sizeof(amt));
clrscr();
cout<<”\n\t\t Current Details are \n”;
amt.show();
cout<<”\n\n\t\t Enter New Details\n”;
amt.add();
cout<<”\n\t\t Item Details edited”;
}
}r++;
}
if(flag==0)
{cout<<”\n\t\n Item No doesn’t Exist... Please Retry!”;
getch();
goto db;
}
fin.close();
getch();
goto db;
case 3:
flag=0;
cout<<”\n\n\t Enter Item Number To be deleted:”;
cin>>ino;
fin.open(“itemstore.dat”,ios::binary);
if(!fin)
{cout<<”\n\n File Not Found…”;
goto  menu;
}
fstream
tmp(“temp.dat”,ios::binary|ios::out);
fin.seekg(0);
while(fin.read((char*)&amt,sizeof(amt)))
{
int x=amt.item::retno();
if(x!=ino)
tmp.write((char*&amt,size of(amt));
else
{flag=1;
}
}
fin.close();
tmp.close();
fout.open(“itemstore.dat”,ios::trnc|ios::binary);
fout.seekp(0);
tmp.open(“temp.dat,ios::binary|ios::in);
if(!tmp)
{cout<<”Error in File”;
goto  db;
}
while(tmp.read((char*)&amt,sizeof(amt)))
fout.write((char*)&amt,sizeof(amt));
tmp.close();
fout.close();
if(flag==1)
cout<<”Item Successfully Deleted”;
else if(flag==0)
cout<<”Item Does not Exist!!! Please retry”;
getch();
goto  db;
case 4: goto  menu;
default:cout<<”Wrong Choice:;
getch();
goto  db;
}
case 3: clrscr();
flag=0;
int ino;
cout<<”Enter Item no.”;
cin>>ino;
fin.open(“itemstore.dat”,ios::binary);
if(!fin)
{
cout<<”File Not Found Program terminated”;
goto  menu;
}
fin seekg(0);
while(fin.read((char*)&amt,sizeof(amt)))
{int x=amt.item::retno();
if(x==ino)
{amt.pay();
flag=1;
break;
}
}
if(flag==0)
cout<<”Item Does not Exist Please Retry”;
getch();
fin.close();
goto  menu;
case 4:
clrscr();
goto xy(20,20);
cout<<”Are You Sure You Want To Exit”;
char yn;
cin>>yn;
if((yn==’y’)||(yn==’Y’))
{
goto xy(12,20);
cout<<”Special Thanks To All our Friends and Teachers for their Help”;
getch();
clrscr();
goto xy(17,20);
cout<<”Thank You For Using”;
getch();
clrscr();
goto xy(17,20);
cout<<”CREATED BY SHYLESH AND RIJO”;
getch();
exit(0);
}
else if((yn==’n’)||(yn==’N”))
goto  menu;
else
{
goto  menu;
default:
cout<<”Wrong Choice Please Retry”<<endl;
getch();
goto  menu;
}
}
