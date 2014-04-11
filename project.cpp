#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

void des_encode(char src[8],char dest[8])
{
	int pos[64]={};
	for (int k=4;k<8;k++)
	{
		pos[8*k]=57+2*(k-4);
		for (int i=1;i<=7;i++)
	    pos[8*k+i]=pos[8*k+i-1]-8;
	}

	for (int k=0;k<4;k++)
	{
		pos[8*k]=58+2*k;
		for (int i=1;i<=7;i++)
	    pos[8*k+i]=pos[8*k]-8*i;
	}

	 for (int i=0;i<8;i++)
	   dest[i]=0;

	 for (int i=0;i<64;i++)
	 {
		 int n=(pos[i]-1)%8;
		 int n1=(pos[i]-1);
		 char mask=1<<(7-n1);
		 int bit=mask & src[n];

		 int n2=i/8;
		 int n3=i%8;
		 if (bit!=0)
		 {
			 mask=1<<(7-n3);
			 dest[n2]=dest[n2] | mask;
		 }
	 }
	cout<<"Roflmao";
}



int main()
{
	char src[8],src1[8];

	ifstream in("File1.txt",ios_base::binary);
	ofstream out("File2.txt",ios_base::binary);
	if (!in.is_open()) 
	{
		return 1;
	}

	if (!out.is_open()) 
	{
		return 1;
	}


	while (in.peek()!=EOF)
	{
		char buf[8];
		char dest[8];
		in.read(buf,8);
		int c=in.gcount();
		if (c<8)
			for (int j=c;j<8;j++)
				buf[j]='=';
		des_encode(buf,dest);
		out.write(dest,8);
	}

	in.close();
	out.close();

	_getch();
	return 0;
}
