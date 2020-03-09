#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
class doc{                           //file is doc1
	int did; //d ID
	int dpassword;
	char dname[40];
	char currentpat[40][40];

public:
	void dinput(){cout<<"\nenter doc id";cin>>did;
		cout<<"\nenter doc password";enterdpasswordwrite();
		cout<<"\nenter doc name";gets(dname);
		}
		 enterdpasswordwrite(){
			      fstream fil;
			     fil.open("pass.txt",ios::app);
			     char password[80];
			     fil.getline(password,80);
			     char ch; int i=0;
			     do
			     {
			      ch=getch();
			      cout<<"*";
			      password[i++]=ch;
			     }while(ch!=13);

			  }
     int rdid(){return did;}
     int rdpassword(){return dpassword;}
     char* rdname(){return dname;}
     void enterdid(){cout<<"enter d ID";cin>>did;}
      void enterdpasswordcheck(){ cout<<"enter doc password"; fstream fil;
				  fil.open("pass.txt",ios::in);
				  char password[80],pass[80];
				  fil.getline(pass,80);
				  char ch; int i=0;
				  ch=getch();
				  do
				  {

				   cout<<"*";
				    password[i++]=ch;
				  }while(ch!=13);
				  password[i--]='\0';

			       }
     void editd();
};
void doc::editd(){char choice;
		 cout<<"\n choose what to edit\n ";
		 cout<<"1.name\n2.password\n3.edit all\n";
		 char ch;
		 cin>>ch;
		 switch(ch)
		  {	  case 1: {    cout<<"enter changed name";
				   gets(dname);editd();
				   break;
				  }
			  case 2: {    cout<<"enter changed password";
								   cin>>dpassword;editd();
				   break;
				  }
						  case 3:{  cout<<"enter changed id";
								cin>>did;
								cout<<"enter changed name";
								cin>>dname;
								cout<<"enter changed password";
								cin>>dpassword;
								  editd();break;
							       }
				  }

}
class pat{                           //file is pat1
	int pid; //p ID
	int ppassword;
	char pname[40];
	char prescription[400];

public:
	void pinput(){cout<<"\nenter pat id";cin>>pid;
		cout<<"\nenter pat password";cin>>ppassword;enterppasswordwrite();
		cout<<"\nenter pat name";gets(pname);
		}
		void enterpresc(){gets(prescription);}
     int rpid(){return pid;}
     int rppassword(){return ppassword;}
      char* rpname(){return pname;}
     void enterpid(){cout<<"enter p ID";cin>>pid;}
     void enterppassword(){cout<<"enter p password";cin>>ppassword;}
      void enterppasswordwrite(){
				fstream fil;
			     fil.open("pass.txt",ios::app);
			     char password[80];
			     fil.getline(password,80);
			     char ch; int i=0;
			     do
			     {
			      ch=getch();
			      cout<<"*";
			      password[i++]=ch;
			     }while(ch!=13);
			       }
     void enterppasswordcheck(){ cout<<"enter pat password"; fstream fil;
				 fil.open("pass.txt",ios::in);
				 char password[80],pass[80];
				 fil.getline(pass,80);
				 char ch; int i=0;
				 ch=getch();
                                 do
				 {

				  cout<<"*";
				  password[i++]=ch;
				 }while(ch!=13);
				 password[i--]='\0';

				}
 char* disppresc(){return prescription; }
     void editp();
};
void pat::editp(){char choice;
		 cout<<"\n choose what to edit\n ";
		 cout<<"1.name\n2.ID\n3.password\n4.edit all\n";
		 char ch;
		 cin>>ch;
		 switch(ch)
		  {	  case 1: {    cout<<"enter changed name";
				   gets(pname);editp();
				   break;
				  }
 			  case 2: {    cout<<"enter changed password";
								   cin>>ppassword;editp();
				   break;
				  }
                                                  case 3:{  cout<<"enter changed id";
                                                                cin>>pid; 
                                                                cout<<"enter changed name";
                                                                cin>>pname;
                                                                cout<<"enter changed password";
								cin>>ppassword;editp();
                                                                 break; 
                                                               } 
                                  }


}
void writefildoc1(doc a);
void writefilpat1(pat a);
char mainmenu(doc &,pat &);
void printdmenu();
void printpmenu();
int docmenu(doc &,pat &);
int patmenu(doc &,pat &);
void signind(char ch,doc &);
void signinp(char ch,pat &);
int logind(char ch,doc &);
int loginp(char ch,pat &);
int checkfildoc1(doc &);
int checkfilpat1(pat &);
void prescriptionp(doc &,pat &);
void medarchiveread(doc &,pat &);
void medarchivewrite(doc &,pat &);
void chatread(doc &a,pat &b);
void chatwrite(doc &a,pat &b);
void prescriptiond(doc &,pat &);
void editd(doc a);
void editp(pat a);
void main()
{   fstream fil,fil1,fil2;
    fil.open("chatproj1.txt",ios::out);
    fil.open("pat1.dat",ios::out|ios::binary);
    fil.open("doc1.dat",ios::out|ios::binary);
    fil.close();
    fil1.close();
    fil2.close();
    char a[40]="WELCOME TO HOSPITAL SYSTEM";
    gotoxy(30,30);
    for(int i=0;a[i]!='\0';i++)
    {
     cout<<a[i];
     delay(100);
    }
    gotoxy(30,31); 
   for(int l=0;a[l]!='\0';l++)
    {
     cout<<"_";
     delay(100);
    }
    int z;
    do
    {
     clrscr();
     doc D;pat P;
     char c=mainmenu(D,P);
     if(c=='d')
      {
       z= docmenu(D,P);
      }//void docmenu();

    else if(c=='p')
    {z=patmenu(D,P);}//void patmenu();
    }while(z==1);
    getch();
}

char mainmenu(doc &d,pat &p)
{
clrscr();
 cout<<"mainmenu\nenter profession\n1.doc\t\t2.pat\n";
 int z,c1,c2;
do{
   cin>>c1;
   switch(c1)
   {
     case 1:{
	     cout<<"\n1.sign up\t\t2.login\n";
	     cin>>c2;
	     switch(c2){
		case 1:{signind('d',d);
			    z=1;break;}
		case 2:{z=logind('d',d);
			    break;
			   }
		default : {cout<<"run time terminated\n";z=-1;}
		}
	     break;
	    }
      case 2:{
	     cout<<"\n1.sign up\t\t2.login\n";
	     cin>>c2;
	     switch(c2){
		case 1:{signinp('p',p);//void signin(char ch)
			    z=1;break;}
		case 2:{z=loginp('p',p);//int login(char ch)     returns z as 1 if succesful and -1 if not
			    break;
			   }
		default : {cout<<"run time terminated\n";z=-1;}
		}
	     break;
	    }
       default :{cout<<"retry\n";z=-1;}
       }

   }while(z==-1);
delay(500);
if(c1==1)
{return 'd';}
else if(c1==2)
{return 'p';}
else return 'o';
}
int checkfildoc1(doc &b)
{
fstream fil;
fil.open("doc1.dat",ios::in,ios::binary);
doc a;
int z;
while(fil.read((char*)&a,sizeof(a)))
{
if((a.rdid()==b.rdid()) && (a.rdpassword()==b.rdpassword()))
{b=a;
z=0;}
else
z=-1;
}
return z;
fil.close();
}
int checkfilpat1(pat &b)
{
fstream fil;
fil.open("pat1.dat",ios::in,ios::binary);
pat a;
int z;
while(fil.read((char*)&a,sizeof(a)))
{
if(a.rpid()==b.rpid() && a.rppassword()==b.rppassword())
{b=a;
z=0;}
else
z=-1;
}
return z;
fil.close();
}
void printdmenu()
{
	gotoxy(50,4);                                      //   goto  (50,4)(50,5)(50,6)...
	cout<<"1.chatread";
	gotoxy(50,5);                                      //   goto  (50,4)(50,5)(50,6)...
	cout<<"2.chatwrite";
	gotoxy(50,6);
	cout<<"3.prescription";
	gotoxy(50,7);
	cout<<"4.med archive(read only)";
	gotoxy(50,8);
	cout<<"5.med archive(write mode)";
	gotoxy(50,9);
	cout<<"6.update id";
	gotoxy(50,10);
	cout<<"7.logout\n";

}
void printpmenu()
{
	gotoxy(50,4);                             //   goto  (50,4)(50,5)(50,6)...
	cout<<"1.read chat";
	gotoxy(50,5);                                      //   goto  (50,4)(50,5)(50,6)...
	cout<<"2.write chat";
	gotoxy(50,6);
	cout<<"3.read prescription";
	gotoxy(50,7);
	cout<<"4.med archive(read only)";
	gotoxy(50,8);
	cout<<"5.update id";
	gotoxy(50,9);
	cout<<"6.logout\n";

}
void signind(char ch,doc &a)
{
     a.dinput();
     writefildoc1(a);//void writefildoc1(doc a);
}
void signinp(char ch,pat &a)
{
     a.pinput();
     writefilpat1(a);//void writefilpat1(pat a);

}
int logind(char ch,doc &a)
{int z;

			a.enterdid();
			a.enterdpasswordwrite();
		    z= checkfildoc1(a);//int chechfiledoc1()...searches for id and pass

 return z;//z=-1 from int checkfile if not found
}
int loginp(char ch,pat &a)
{int z;


			a.enterpid();//in class
			a.enterppassword();//in class
		    z= checkfilpat1(a);//int checkfilepat1()...searches for id and pass

 return z;//z=-1 from int checkfile if not found
}

int docmenu(doc &a,pat &b)
    {   char choice1;int c3;
	do{
	clrscr();
	cout<<"welcome doc";
	char ch1[40];strcpy(ch1,a.rdname());cout<<ch1<<endl;
	printdmenu();
	cout<<"choose required option";//from printmenu
	cin>>c3;
    switch(c3)
    {

	case 1:{     cout<<"opening chatread systemc";delay(500);     //kk
		     chatread(a,b);//void chat()... opens a premade txtfile writes on it
		     break;//file name is chat
		     //imp at the end of every function you write
		     //write:  ****'docmenu()' to go back to docmenu***

	       }

	case 2:{     cout<<"opening chatwrite systemc";delay(500);     //kk
		     chatwrite(a,b);//void chat()... opens a premade txtfile writes on it
		     break;//file name is chat
		     //imp at the end of every function you write
		     //write:  ****'docmenu()' to go back to docmenu***

	       }
	case 3:{ cout<<"opening prescriptiond(write) systemc";delay(500);//kk
		 prescriptiond(a,b);//void prescriptionp();
		 //very important function
		 //1.accepts patients name
		 //2.accepts doctors prescription in a string
		 //3.searches for required patient in file
		 //file name is ...pat1...
		     break;

	       }

	case 4:{ cout<<"opening med archive(read)";delay(500);  //kk
		 medarchiveread(a,b);//void medarchiveread()
		 //prints file
		 //"enter q to exit file"

		     break;//file name is med1(txt file)
	       }
	case 5:{ cout<<"opening med archive(write)";delay(500);//kk
		 medarchivewrite(a,b);//void medarchivewrite()

		     break;//file name is med1(txt file)
	       }
	case 6:{ cout<<"\nedit fields\n";delay(500);
			      char c1,ch;
			      cin>>c1;
			      do{
			      a.editd();
			      cout<<"\nsuccessfully edited name\n";
			      cout<<"do you wish to edit something else(y/n)?";
			      }while(ch=='y');


		     break;}
	 case 7:{ cout<<"opening mainmenu";delay(500);

		    // mainmenu(a,b);
		     break;

		     }

	    }//switch
       if(c3==7)
       choice1='n';
       else
       cout<<"\ndo you wish to do anything else(y/n)\t";cin>>choice1;
       }while(choice1=='y');
if(c3==7)
return 1;
else
return 0;

}

int patmenu(doc &b,pat &a)
{       char choice1;int c3;
	do{
	clrscr();
	cout<<"welcome pat";
	char ch1[40];strcpy(ch1,a.rpname());cout<<ch1<<endl;
	printpmenu();

	cout<<"choose required option";//from printmenu
	cin>>c3;
    switch(c3)
    {

	case 1:{ cout<<"opening chatread systemc";delay(500);
		 chatread(b,a);//void chat()... opens a premade txtfile writes on it
		     break;//file name is chat
		     //imp at the end of every function you write
		     //write:  ****'docmenu()' to go back to docmenu***

	       }
	case 2:{     cout<<"opening chatwrite systemc";delay(500);     //kk
		     chatwrite(b,a);//void chat()... opens a premade txtfile writes on it
		     break;//file name is chat
		     //imp at the end of every function you write
		     //write:  ****'docmenu()' to go back to docmenu***

	       }

	case 3:{ cout<<"opening prescriptionp(write) systemc";delay(500);
		 prescriptionp(b,a);//void prescriptionp();
		 //very important function
		 //1.accepts patients name
		 //2.accepts doctors prescription in a string
		 //3.searches for required patient in file
		 //file name is ...pat1...
		     break;

	       }

	case 4:{ cout<<"opening med archive(read)";delay(500);
		 medarchiveread(b,a);//void medarchiveread()
		 //prints file
		 //"enter q to exit file"

		     break;//file name is med1(txt file)
	       }

	case 5:{ cout<<"\nedit fields\n";delay(500);
			      char c1,ch;
			      cin>>c1;
			      do{
			      a.editp();
			      cout<<"\nsuccessfully edited name\n";
			      cout<<"do you wish to edit something else(y/n)?";
			      }while(ch=='y');

			      break;}
	 case 6:{ cout<<"opening mainmenu";delay(500);

		     //mainmenu(b,a);
		     break;

	    }
	}
	if(c3==6)
	choice1=='n';
	else
       cout<<"\ndo you wish to do anything else(y/n)\t";cin>>choice1;
       }while(choice1=='y');
if(c3==6)
return 1;
else
return 0;
}

void medarchiveread(doc &a,pat &b)
{
		 fstream fil;
		fil.open("med1.txt",ios::in);
	      char lin[80];
	      while(fil.getline(lin,80))
	 {
		puts(lin);                                        //very important function
						   //1.accepts patients name
	 }
					  //2.accepts doctors prescription in a string
 delay(500);
 fil.close();
}					     //3.searches for required patient in file
					       //file name is ...pat1...
void medarchivewrite(doc &a,pat &b)
{
		 fstream fil;
		fil.open("med1.txt",ios::out);
	      char lin[80];
	      char ch;
	      do
	      {
	      cout<<"\nenter data\t";
	      gets(lin);
	      fil<<lin<<endl;
	      cout<<"do you wish to write more(y\n) ";
	      cin>>ch;
	      }while(ch=='y');
					  //2.accepts doctors prescription in a string
    delay(500);
    fil.close();
}					     //3.searches for required patient in file
					       //file name is ...pat1...



void prescriptionp(doc &a,pat &b)
{
  fstream fil;
  fil.open("pat1.dat",ios::binary|ios::in);
  char pname[80];
  cout<<"\nenter patient name\t"<<endl;
  gets(pname);
  pat p;
  if(strcmpi(pname,p.rpname())==0)
  p.disppresc();
  delay(500);
fil.close();
}


void chatwrite(doc &a,pat &b)
{
fstream fil;
fil.open("chatproj1.txt",ios::app);
char lin[100];
char choice1;
do
{
 cout<<"\nenter chat\n";
 gets(lin);
 fil<<lin<<endl;
 cout<<"do you wish to write more(y/n)\t";cin>>choice1;
}while(choice1=='y');
fil.close();
}
void chatread(doc &a,pat &b)
{
fstream fil;
fil.open("chatproj1.txt",ios::in);
 char lin[100];
 cout<<"\nread chat \n";
 while(!fil.eof())		     //display all chat
 {fil.getline(lin,100);
  cout<<lin<<endl;
 }
delay(500);
fil.close();
}

void writefildoc1(doc a)
{
 fstream fil;
 fil.open("doc1.dat",ios::app|ios::binary);
 fil.write((char*)&a,sizeof(a));
 fil.close();
 delay(500);
}

void writefilpat1(pat a)
{
 fstream fil;
 fil.open("pat1.dat",ios::app|ios::binary);
 fil.write((char*)&a,sizeof(a));
 fil.close();
 delay(500);
}
void prescriptiond(doc &a,pat &b)
{
  cout<<"\nenter patients name for prescribing\t";
  char xh[40];
  gets(xh);
  fstream fil;
  fil.open("pat1.dat",ios::in|ios::out|ios::binary);
  int f=0;
  pat s;
  while(f==0 && fil.read((char*)&s,sizeof(s)))
  {
   if(strcmpi(xh,s.rpname())==0)
   {
    fil.seekg(fil.tellg()-sizeof(s));
    cout<<"enter the prescription"<<endl;
    s.enterpresc();
    fil.write((char*)&s,sizeof(s));
    f++;
   }
  }
  if (f==0)
  cout<<"pat name not found no change made"<<endl;
  fil.close();
}
void editd(doc a)
{
 fstream fil;
 doc s;
fil.open("doc1.dat",ios::in|ios::out|ios::binary);
int found=0;
while(fil.read((char*)&s,sizeof(s)) && found==0)
 {
  if(s.rdid()==a.rdid())
  {
   fil.seekg(fil.tellg()-sizeof(s));
   fil.write((char*)&a,sizeof(a));
   found++;
  }
 }
fil.close();
}
void editp(pat a)
{
 fstream fil;
 pat s;
fil.open("pat1.dat",ios::in|ios::out|ios::binary);
int found=0;
while(fil.read((char*)&s,sizeof(s)) && found==0)
 {
  if(s.rpid()==a.rpid())
  {
   fil.seekg(fil.tellg()-sizeof(s));
   fil.write((char*)&a,sizeof(a));
   found++;
  } 
 }
fil.close();
}