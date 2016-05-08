//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//                  | HEADER FILE USED IN PROJECT |
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*

#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<iomanip.h>
#include<ctype.h>

//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//            | FUNCTIONS USED FOR MOUSE OPERATION|
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
void showmouse()
{    
	_AX=1;
	geninterrupt(0x33);
}
  void getmouse(int *button,int *x,int *y)
  {    
  	_AX=3;
	geninterrupt(0x33);
	*button=_BX;
	*x=_CX;
	*y=_DX;
  }
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//                  | CLASS USED IN PROJECT |
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
	 class bank { public: int ano;char name[30];
			      char unicode[10];
			      char pass[10];
			      float bal;float m;
			      char atype;
    //*+*+*+|FUNCTION TO GET INFO FROM USER|+*+*+*
	    void Getinfo();
    //*+*+*+|FUNCTION TO DIPOSIT MONEY BY USER|+*+*+*
	    void Dep_mony();
    //*+*+*+|FUNCTION TO DISPLAY INFO OF USER|+*+*+*
	    void Dispinfo();
    //*+*+*+|FUNCTION TO WITHDRAW MONEY|+*+*+*
	    void Wthd_mony();
    //*+*+*+|FUNCTION TO GET THE BALANCE|+*+*+*
	    float Get_bal();
    //*+*+*+|FUNCTION TO GET AC/No. OF USER|+*+*+*
	   int Get_ano();
    //*+*+*+|FUNCTION TO MODIFY USER ACCOUNT|+*+*+*
	   void modify();
    //*+*+*+|CONSTRUCTOR|+*+*+*
	   bank()
	   { 
	   		ano = 0;
	    	bal = 0.0;
	   }
	};

	void bank :: Getinfo()
	{
		cout<<"\nEnter Details\n";
	  	cout<<"Enter a Account Number of your choice :";
	  	cin>>ano;
					  cout<<"\nType of Account Current or Saving (C/S) : ";
					  cin>>atype;
					  atype=toupper(atype);
					  cout<< "\n\nNAME Of The Account Holder:- ";
					  gets(name);
					  if(name[0]>=97)
					  	name[0]-=32;
					  for(int i=0;i<=strlen(name);i++)
					  {
					   		if(name[i]==' '&& name[i+1]>=97)
					     		name[i+1]-=32;
					   }
					  cout<<"\n\nAccount PASSWORD (min 4 characters):- ";
					  gets(pass);
					if(strlen(pass)<4)
					{
						cout<<"\nPassword should contain atleast 4 characters";
					  	cout<<"\n\nEnter PASSWORD again :";
						gets(pass);
					}
					cout<<"\n\nOpening BALANCE Of The Account : Rs.";
					cin>>bal;
					cout<<"\n\nEnter A UNIQUE CODE To Recover Your Account : ";
					gets(unicode);
					clrscr();
	}
	void bank :: Dispinfo()
	{
	 cout<<"\nTYPE of Account :- ";
	 if(atype=='c'||atype=='C')
	 cout<<"CURRENT";
	 else
	 cout<<"SAVINGS";
	 cout<<"\n\nAccount Holder NAME :- "<<name;
	 cout<<"\n\nAccount NUMBER :- "<<ano;
	 cout<<"\n\nBALANCE in Account : Rs."<<bal;
	}
	float bank :: Get_bal()
	{
	return bal;
	}
	void bank :: Wthd_mony()
	{
	 cout<<"\nEnter The AMOUNT To Withdraw : Rs. " ;
	 cin>>m;
	 bal-=m;
	 cout<<"\n\nBALANCE of Your Account After Transaction : Rs."<<bal;
	}
	int bank :: Get_ano()
	{
	 return ano;
	}
	void bank :: Dep_mony()
	{
	 cout<<"\nEnter The AMOUNT To Diposit : Rs."   ;
	 cin>> m;
	 bal+=m;
	 cout<<"\n\nBALANCE of Your Account After Transaction : Rs."<<bal;
	}
	void bank::modify()
	{
	 char new_name[20],new_pass[10],new_unicode[10];
	 char new_atype;
	 textbackground(LIGHTCYAN);
	 textcolor(LIGHTGRAY);
	 cprintf("Please Enter '.' To Retain Old Values");
	 textcolor(YELLOW);
	 cout<<"\nNew Name : ";
	 gets(new_name);
	 cout<<"\nNew Account type : ";
	 cin>>new_atype;
	 cout<<"\nNew Password(Minimum Four Characters): ";
	 gets(new_pass);
	 if(strcmp(new_pass,".")!=0&&strlen(new_pass)<4)
	  {
	  cout<<"\nEnter a new password with min 4 charactes :";
	  gets(new_pass);
	  }
	 cout<<"\nNew Unicode : ";
	 cin>>new_unicode;
	 if(strcmp(new_name,".")!=0)
	 {
	  if(new_name[0]>=97)
	    new_name[0]-=32;
	  for(int i=0;i<=strlen(new_name);i++)
	   { if(new_name[i]==' '&& new_name[i+1]>=97)
	       new_name[i+1]-=32;
	   }
	 strcpy(name,new_name);}
	 if(strcmp(new_pass,".")!=0)
	   strcpy(pass,new_pass);
	 if(new_atype!='.')
	   atype=toupper(new_atype);

	}

	void main()
	{
	clrscr();
	//*** FOR TIME AND DATE ***
	struct date d;
	getdate(&d);
	struct time t;
	gettime(&t);
	textbackground(LIGHTCYAN+BLINK);
	textcolor(YELLOW);
	//*+*+* |VARIABLES USED IN THE PROGRAM|*+*+*+*
	int x,y,button,a,no,b,n,z,not1,not2,nt1,nt2=0;
	char password[10];
	char s;
	float c,c1,c2;
	bank l[8];//*+*+*|CLASS bank OBJECT|*+*+*
	fstream trans;
	ifstream about;
	fstream file( "BANK.dat" , ios :: in | ios :: binary);
	file.seekg(0);
	//*+*+* |READING USER INFORMATION FROM FILE BANK.dat| *+*+*
	for( int i=0 ; i<5 ; i++ )
	{
	  file.read((char*)&l[i],sizeof(l[i]));
	  if(l[i].bal==0)
	  break;
	}
	file.close();
	showmouse();

	// *+*+*+*+*|MAIN MENU|*+*+*+*+*
	m:{clrscr();
	  cout<<"\n";
	  textcolor(LIGHTGRAY);
	  cout<<"                       ";
	  cprintf("***********************************");
	  cout<<"\n";
	  textcolor(YELLOW+BLINK);
	  cout<<"                       ";
	  cprintf(" $ ");
	  textcolor(BLACK);
	  cprintf("W E L C O M E    T O    S B I ");
	  textcolor(YELLOW+BLINK);
	  cprintf("$");
	  cout<<"\n";
	  textcolor(LIGHTGRAY);
	  cout<<"                       ";
	  cprintf("***********************************");
	  cout<<"\n\n";
	  textcolor(LIGHTGRAY);
	  cprintf("              *+*+*+*+*+* ");
	  textcolor(LIGHTRED);
	  cprintf("|| -- ");
	  textcolor(BLACK);
	  cprintf("M A I N   M E N U");
	  textcolor(LIGHTRED);
	  cprintf(" -- ||  ");
	  textcolor(LIGHTGRAY);
	  cprintf("*+*+*+*+*+* ");
	  textcolor(YELLOW);
	  cout<<"\n\n";
	  cout<<"\n    |M A K E    A   N E W   A C C O U N T| ";
	  delay(100);
	  cout<<"\n\n\n    |L O G   I N   TO   Y O U R   A C C O U N T| ";
	  delay(100);
	  cout<<"\n\n\n    |S H O W   B A N K   T R A N S A C T I O N| ";
	  delay(70);
	  cout<<"\n\n\n    |S H O W   A l l   A C C O U N T   D E T A I L S|  ";
	  delay(100);
	  cout<<"\n\n\n    |E X I T| ";
	  delay(100);
	  cout<<"\n\n\n    |H E L P|"  ;
	  }
	  //*+*+*+* |USING MOUSE TO GET CHOICE FROM USER| *+*+*+*
	  while(a)
	  { getmouse(&button,&x,&y);
	    gotoxy(55,1);
	    printf("Coordinates:-(%d,%d)  ",x,y);
	    textcolor(LIGHTGRAY);
	    gotoxy(0,1);cout<<"\n";
	    cprintf("DATE:%d/%d/%d",d.da_day,d.da_mon,d.da_year);
	    gotoxy(0,3);
	    gettime(&t);
	    cout<<"\n";
	    cprintf("TIME-%d:%d:%d",t.ti_hour-12,t.ti_min,t.ti_sec);
	    textcolor(YELLOW);
	    cout<<"\n";

	  if(x>=32&&x<=320&&y==64&&button==1)
	  {
	   a=1;
	   textbackground(LIGHTGRAY);
	   gotoxy(2,9);
	   cout<<"   ";
	   cprintf("|M A K E    A   N E W   A C C O U N T|");
	   delay(300);
	   break;
	  }
	  if(x>=32&&x<=368&&y==88&&button==1)
	  {
	   a=2;
	   textbackground(LIGHTGRAY);
	   gotoxy(2,12);
	   cout<<"   ";
	   cprintf("|L O G   I N   TO   Y O U R   A C C O U N T|");
	   delay(300);
	   break;
	  }
	  if(x>=32&&x<=368&&y==112&&button==1)
	  {
	   a=3;
	   textbackground(LIGHTGRAY);
	   gotoxy(2,15);
	   cout<<"   ";
	   cprintf("|S H O W   B A N K   T R A N S A C T I O N|");
	   delay(300);
	   break;
	  }
	  if(x>=32&&x<=472&&y==136&&button==1)
	  {
	   a=4;
	   textbackground(LIGHTGRAY);
	   gotoxy(2,18);
	   cout<<"   ";
	   cprintf("|S H O W   A l l   A C C O U N T   D E T A I L S|");
	   delay(300);
	   break;
	  }
	  if(x>=32&&x<=88&&y==160&&button==1)
	  {
	    a=5;
	    textbackground(LIGHTGRAY);
	    gotoxy(2,21);
	    cout<<"   ";
	    cprintf("|E X I T|");
	    delay(500);
	    break;
	  }
	  if(x>=32&&x<=88&&y==184&&button==1)
	  {
	   a=6;
	   textbackground(LIGHTGRAY);
	   gotoxy(2,24);
	   cout<<"   ";
	   cprintf("|H E L P|");
	   delay(200);
	   break;
	  }

	  }
	  textbackground(LIGHTCYAN);
	  clrscr();
	  textcolor(LIGHTRED+BLINK);
	  textbackground(WHITE);
	  gotoxy(39,22);
	  cprintf("BACK");
	  textcolor(YELLOW);
	  textbackground(LIGHTCYAN);
	  gotoxy(1,1);

	  //***** |TO SHOW ALL USER INFO|
       if(a==4)
	{
	  textcolor(LIGHTRED);
	  cprintf("===============================================");
	  cout<<"\nA/c No.\t NAME    \t     TYPE\tBALANCE\n";
	  cprintf("===============================================");
	  textcolor(YELLOW);
	  for( int i=0 ; i<10 ; i++ )
	   { if( l[i].bal==0)
	      break;
	      cout << "\n" ;
	      cout<<l[i].ano<<"\t "<<l[i].name;
	      int d=20-strlen(l[i].name);
	      for(int q=0;q<=d;q++)
	      {cout<<" ";}
	      cout<<l[i].atype<<"\t        "<<l[i].bal;
	      cout<<"\n";
	      textcolor(LIGHTRED);
	      cprintf("-----------------------------------------------");
	      textcolor(YELLOW);
	      delay(200);
	      }

	  }
	  //**** |SHOWING TRANSACTION|
	 if(a==3)
	 { char line[200];
	   trans.open("TRANS.dat",ios::in);
	   trans.seekg(0);
	  cout<<" BANK TRANSACTION -\n\n";

	 while(1)
	 { trans.getline(line,200,'.');
	  if(trans.eof())
	  break;
	  cout<<"\n * < "<<line<<" >\n   ";
	  for(int i=0;i<strlen(line);i++)
	  {cout<<"-";}
	  delay(200);
	 }
	 trans.close();
	 }
	  //**** |MAKING NEW ACCOUNT|
	 if(a==1)
	  { for(int i=0;i<6;i++)
	     {
	      if(l[i].bal==0.0)
	      { b=i;
		break;
	      }
	     }
	   clrscr();
	    z=b;
	   file.open("BANK.dat",ios::app|ios::binary);
	   l[b].Getinfo();
	   file.write((char*)&l[b],sizeof(l[b]));
	   file.close();
	    textcolor(LIGHTMAGENTA);
	    cout<<"Creating your account Please wait";
	    delay(200);
	    cout<<".";
	    delay(500);
	    cout<<".";
	    delay(500);
	    cout<<".";
	    delay(500);
	    clrscr();
	    cout<<"\n\n";
	    cprintf("                 **** ");
	    textcolor(LIGHTGRAY+BLINK);
	    cprintf("| C O N G R A T U L A T I O N | ");
	    textcolor(LIGHTMAGENTA);
	    cprintf("****" );
	    cout<<"\n\n\n\t\t";
	    textcolor(BLACK);
	    cprintf("       ++++|" );
	    textcolor(LIGHTGRAY);
	    cprintf("  W E L C O M E  ");
	    cout<<l[b].name;
	    textcolor(BLACK);
	    cprintf(" |++++" );
	    cout<<"\n\n\t\t";
	    textcolor(LIGHTGRAY);
	    cprintf("  T h a n k   Y o u , F o r   O p e n i n g");
	    cout<<"\n\t\t";
	    cprintf("  Y o u r   A c c o u n t   I n   S B I .");
	    cout<<"\n\n\n\n  ";
	    textbackground(WHITE+BLINK);
	    textcolor(LIGHTRED);

	    cprintf("| LOGIN | | BACK |");
	    textbackground(LIGHTCYAN);
	    while(1)
	     { getmouse(&button,&x,&y);
	       gotoxy(55,1);
	       printf("Coordinates:-(%d,%d)  ",x,y);
	       textcolor(YELLOW);

	      if(x>=32&&x<=64&&y==96&&button==1)
	      {clrscr();goto g;}
	      if(x>=112&&x<=136&&y==96&&button==1)
	      {clrscr();goto m;}
	   }

	    }
	  //**** |LOGING IN|
	  if(a==2)
	  { l:{clrscr();
	     cout<<"\n\nEnter Your Account NUMBER :-  ";
	     cin>>no;
	     cout<<"\n\nEnter Your PASSWORD :-  ";
	     gets(password);
	     for(int i=0;i<10;i++)
	     {
	      if(l[i].Get_ano()==no)
	     { z=i; goto check;}
	     }
	    cout<<"\n\nERROR:|ACCOUNT Does Not Exits \nCheck Account Number \nAND\nTry Again|.... ";
	    sleep(2);
	    clrscr();
	    goto m;
	      }
	  }
	 if(a==5)
	 exit(0);
	 //**** |INFO|
	 if(a==6)
	 {
	  cout<<"\n\n";
	  char line[200];
	  about.open("About.dat",ios::in);
	  about.seekg(0);
	  while(1)
	 { about.getline(line,200,'/');
	   cout<<"\n"<<line;
	   if(about.eof())
	   break;
	   delay(100);
	 }
	 about.close();
	 }

	 while(1)
	 { getmouse(&button,&x,&y);
	   gotoxy(50,1);
	   printf("Coordinates:-(%d,%d)  ",x,y);
	 if(x>=304&&x<=328&&y==168&&button==1)
	  { clrscr();
	   goto m;
	  }
	 }
	//**** |MONEY TRANSFER|
	s:{cout<<"Enter the AMOUNT To Transfer :-";
	   cin>>c;
	   if(c>l[z].bal)
	    {
	     cerr<<"\n!! WARNING : |You Dont Have SUFFICIENT Balance In Your Account|" ;
	     cerr<<"\nPlease Try AGAIN.... \n";
	     goto s;
	    }
	  else
	  l[z].bal-=c;
	  }

	o:{ k:{ cout<<"\n\nEnter The Account NUMBER On Which MONEY Will Be Transferred :-";
		cin>>no;
		for(int i=0;i<10;i++)
		  { if(l[i].Get_ano()==no)
		     {no=i;break;}
		  }
		if(l[no].bal==0.0)
		 {cout<<"ERROR:|ACCOUNT Does Not Exits \n";
		  cout<<"Check Account Number \nAND\nTry Again|.... ";
		 goto k;
		 }
	      }
	 if(no==z)
	  {cout<<"\n\n ERROR!! |You Cannot Transfer Money To Your Own Account| \nTRY AGAIN....\n";
	   goto s;
	  }
	 if(l[no].bal!=0)
	  {
	   l[no].bal+=c;
	   if(n==1)
	    {
	    not2=no;
	    c2=c;
	    nt2=z;
	    }
	   else
	    {
	    not1=no;
	    c1=c;
	    nt1=z;
	    }

	  }
	    n=1;
	  file.open("BANK.dat",ios::trunc|ios::app|ios::binary);
	  file.seekg(0);
	  for(int i=0;i<6;i++)
	  { file.write((char*)&l[i],sizeof(l[i]));}
	  file.close();
	  trans.open("TRANS.dat",ios::app);
	  struct date d;
	  getdate(&d);
	  int day=d.da_day;
	  int mon=d.da_mon;
	  int year=d.da_year;
	  trans<<"On "<<day<<"/"<<mon<<"/"<<year<<" : Rs"<<c<<" Transferred by Ac/no "<<l[z].ano<<" To Ac/no "<<l[no].ano<<".";
	  trans.close();
	  cout<<"\n\n|Money Transferred Sucessfully|";
	  sleep(2);
	  clrscr();
	  goto g;

       }


      //*+*+*+* |HOME| *+*+*+*
    g:{
	do{
	  cout<<"\n";
	  textcolor(LIGHTGRAY);
	  cout<<"                       ";
	  cprintf("***********************************");
	  cout<<"\n";
	  textcolor(YELLOW+BLINK);
	  cprintf("                        $ ");
	  textcolor(BLACK);
	  cprintf("W E L C O M E    T O    S B I ");
	  textcolor(YELLOW+BLINK);
	  cprintf("$");
	  cout<<"\n";
	  textcolor(LIGHTGRAY);
	  cout<<"                       ";
	  cprintf("***********************************");
	  cout<<"\n\n";
	  textcolor(LIGHTGRAY);
	  cprintf("              *+*+*+*+*+* ");
	  textcolor(LIGHTRED);
	  cprintf("|| -- ");
	  textcolor(BLACK+BLINK);
	  cprintf("H O M E   M E N U");
	  textcolor(LIGHTRED);
	  cprintf(" -- ||  ");
	  textcolor(LIGHTGRAY);
	  cprintf("*+*+*+*+*+* ");
	  textcolor(YELLOW);
	  cout<<"\n\n    |C h e c k   Y o u r   B A L A N C E| \n\n" ;
	  delay(50);
	  cout<<"    |W I T H D R A W   M o n e y $|\n\n" ;
	  delay(50);
	  cout<<"    |D I P O S I T   M o n e y $|\n\n";
	  delay(50);
	  cout<<"    |T R A N S F E R   M o n e y $|\n\n";
	  delay(50);
	  cout<<"    |S I G N   O U T| \n\n";
	  delay(50);
	  cout<<"    |M O D I F Y   A C C O U N T| \n\n";
	  delay(50);
	  cout<<"    |D E L E T E   A C C O U N T| \n\n";
	  delay(50);
	  cout<<"    |E X I T| \n";
	  while(1)
	  {  getmouse(&button,&x,&y);
	     gotoxy(50,1);
	   printf("Coordinates:-(%d,%d)  ",x,y);
	   textcolor(BLACK);
	   gotoxy(0,1);
	   cout<<"\n";
	   cprintf("DATE:%d/%d/%d\n",d.da_day,d.da_mon,d.da_year);
	   gotoxy(0,3);
	   gettime(&t);
	   cout<<"\n";
	   cprintf("TIME-%d:%d:%d\n",t.ti_hour-12,t.ti_min,t.ti_sec);
	   textcolor(YELLOW);
	  if(x>=32&&x<=312&&y==56&&button==1)
	  {a=1;
	   textbackground(LIGHTGRAY);
	   gotoxy(2,8);
	   cout<<"   ";
	   cprintf("|C h e c k   Y o u r   B A L A N C E|");
	   delay(300);
	  break;}
	  if(x>=32&&x<=264&&y==72&&button==1)
	  {a=2;
	  textbackground(LIGHTGRAY);
	  gotoxy(2,10);
	  cout<<"   ";
	  cprintf("|W I T H D R A W   M o n e y $|");
	  delay(300);
	  break;}
	  if(x>=32&&x<=248&&y==88&&button==1)
	  {a=3;
	  textbackground(LIGHTGRAY);
	  gotoxy(2,12);
	  cout<<"   ";
	  cprintf("|D I P O S I T   M o n e y $|");
	  delay(300);
	  break;}
	  if(x>=32&&x<=264&&y==104&&button==1)
	  {a=4;
	  textbackground(LIGHTGRAY);
	  gotoxy(2,14);
	  cout<<"   ";
	  cprintf("|T R A N S F E R   M o n e y $|");
	  delay(300);
	  break;}
	  if(x>=32&&x<=152&&y==120&&button==1)
	  {a=5;
	  textbackground(LIGHTGRAY);
	  gotoxy(2,16);
	  cout<<"   ";
	  cprintf("|S I G N   O U T|");
	  delay(200);
	  break;}
	  if(x>=32&&x<=264&&y==136&&button==1)
	  {a=6;
	  textbackground(LIGHTGRAY);
	  gotoxy(2,18);
	  cout<<"   ";
	  cprintf("|M O D I F Y   A C C O U N T|");
	  delay(300);
	  break;}
	  if(x>=32&&x<=248&&y==152&&button==1)
	  {a=7;
	  textbackground(LIGHTGRAY);
	  gotoxy(2,20);
	  cout<<"   ";
	  cprintf("|D E L E T E   A C C O U N T|");
	  delay(300);
	  break;}
	  if(x>=32&&x<=88&&y==168&&button==1)
	  {a=8;
	  textbackground(LIGHTGRAY);
	  gotoxy(2,22);
	  cout<<"   ";
	  cprintf("|E X I T|");
	  delay(300);
	  break;}
	  }
	  textbackground(LIGHTCYAN);
	  clrscr();
	 if(a==8)
	 {trans.close();exit(0);}
	 if(a==5)
	{clrscr();
	 goto m;}
	 if(a!=4)
	 {
	  textcolor(LIGHTRED+BLINK);
	  textbackground(WHITE);
	  gotoxy(20,19);
	  cprintf("| H O M E |   | L O G O U T |   | E X I T |");
	 }
	  textcolor(YELLOW);
	  textbackground(CYAN);
	  gotoxy(1,1);
	 switch(a)
	   {
	      case 1:l[z].Dispinfo();
		       break;
	      case 2:{l[z].Wthd_mony();
		      file.open("BANK.dat",ios::trunc|ios::app);
		      file.seekg(0);
		      for(int i=0;i<5;i++)
			{ file.write((char*)&l[i],sizeof(l[i]));
			}
		      file.close();
		      trans.open("TRANS.dat",ios::app);
		      trans<<"Rs "<<l[z].m<<" Withdrawn by Ac/no "<<l[z].ano<<".";
			trans.close();
			}
		     break;

	      case 3:{l[z].Dep_mony();
		       file.open("BANK.dat",ios::trunc|ios::app);
		      file.seekg(0);
		      for(int i=0;i<5;i++)
			{ file.write((char*)&l[i],sizeof(l[i]));
			}
		      file.close();
		       trans.open("TRANS.dat",ios::app);
		       trans<<"Rs"<<l[z].m<<" Deposited by Ac/no "<<l[z].ano<<".";
		       trans.close();
		       }
		      break;
	      case 4:goto s;
	      case 6:{l[z].modify();
		       file.open("BANK.dat",ios::trunc|ios::app);
		      file.seekg(0);
		      for(int i=0;i<5;i++)
			{ file.write((char*)&l[i],sizeof(l[i]));
			}
		      file.close();
		       }
		     break;
	      case 7:{l[z].bal=0;
		      file.open("BANK.dat",ios::trunc|ios::app);
		      file.seekg(0);
		      for(int i=0;i<5;i++)
			{  if(i!=z)
			{file.write((char*)&l[i],sizeof(l[i]));}
			}
		      file.close();
		      clrscr();
		     cout<<"Your Account Has Been Deleted......\nOpening Main Menu ";
		     sleep(2);
		     goto m;
		     }
	      default:break;
	      }
	 cout<<"\n\n--------------------------------------";

	 a=0;
	while(1){
		getmouse(&button,&x,&y);
		gotoxy(50,1);
		printf("Coordinates:-(%d,%d)  ",x,y);
	  if(x>=152&&x<=232&&y==144&&button==1)
	  {break;}
	  if(x>=264&&x<=376&&y==144&&button==1)
	  {clrscr();goto m;}
	  if(x>=408&&x<=488&&y==144&&button==1)
	  {exit(0);}
		}
    clrscr(); goto g;
      }
      while(1);
     }

    check:{
		if(strcmp(password,l[z].pass)==0)
		 {cout<<"LOGGING IN please wait ";
		 cout<<".";
		 delay(500);
		 cout<<"." ;
		 delay(200);
		 cout<<".";
		 delay(500);
		 cout<<".";
		 delay(200);
		 cout<<".";
		 delay(100);
		 cout<<".";
		 cout<<"\n| L O G I N   ";
		 delay(200);
		 cout<<"S U C E S S F U L |\n";
		 delay(500);
		 goto noti;
		}

	   else
	    {   cout<<"\nWrong Password !!!";
		textcolor(BLUE);
		textbackground(WHITE);
		cout<<"\n\n";
		cprintf("|Try Again|");
		cout<<"\n\n";
		cprintf("|Recover Your Account|");
		textcolor(YELLOW);
		textbackground(CYAN);
		while(1)
		{ getmouse(&button,&x,&y);
		  gotoxy(50,1);
		  printf("Coordinates:-(%d,%d)  ",x,y);
	  if(x>=0&&x<=80&&y==72&&button==1)
	  {clrscr();goto l;}
	  if(x>=0&&x<=168&&y==88&&button==1)
	  {     clrscr();
		cout<<"\nEnter your Unique Code : ";
		gets(password);
		if(strcmp(password,l[z].unicode)==0)
		{cout<<"\nYour Password Is : "<<l[z].pass;
		cout<<"\nPress any key to Open Home menu ....";
		getch();
		clrscr();
		 goto g;
		 }
		cout<<"\n\nINVALID TRY LOG IN AGAIN...\n";
		cout<<"\n\nPress any key ";
		getch();
		clrscr();
		goto l;
		}
	  if(x>=304&&x<=328&&y==168&&button==1)
	  {clrscr();goto m;}
	  }
		}
      }
       //**** |NOTIFICATION|
    noti:{
	  if(z==not1 || z==not2)
	   {    textcolor(LIGHTGRAY);
		cout<<"\n";
		cprintf("||NEW NOTIFICATION !!!!!|| ");
		cout<<"\n";
		textbackground(WHITE);
		textcolor(LIGHTRED);
		cprintf("|VEIW|");
		cout<<"\n\n";
		cprintf("|HOME|");
		textbackground(CYAN);}
		else
	       {clrscr();
		goto g;}

		while(1){
		getmouse(&button,&x,&y);
		gotoxy(50,1);
		printf("Coordinates:-(%d,%d)  ",x,y);
		if(button==1)
		textcolor(BLACK);
	  if(x>=0&&x<=40&&y==80&&button==1)
	  {clrscr();
		 if(z==not1)
		{cout<<"\n\n\n| Rs. "<<c1<<" Has Been Transferred To Your Account By "<<l[nt1].name<<" |";
		 not1=0;}
		 if(z==not2)
		 {cout<<"\n\n| Rs. "<<c2<<" Has Been Transferred To Your Account By "<<l[nt2].name<<" |";
		  not2=0;}
		textcolor(YELLOW);
		cout<<"\n";
		cprintf("| Press ANY KEY To Go Back To Home |");
		getch();
		clrscr();
		goto g;}
	  if(x>=0&&x<=40&&y==96&&button==1)
	  {goto g;}
	  if(x>=304&&x<=328&&y==168&&button==1)
	  {clrscr();goto m;}
		}

	       }

     }
//***************************************************************
//    			END OF PROJECT
//***************************************************************
