#include <iostream>
#include <xstring.h>
#include <vector.h>
#include <lsd.h>
#include <msd.h>
#include <qs3w.h>


 // EXTENDED_ASCII
//typedef uint8_t Ascii;
const size_t AlogR = 8;
const size_t AR = 256;

// UPPERCASE
//typedef enum {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z} Upper;
const size_t UlogR = 5;
const size_t UR = 26;

// LOWERCASE
//typedef enum {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z} Lower;
const size_t LlogR = 5;
const size_t LR = 26;

// DECIMAL
//typedef enum {0,1,2,3,4,5,6,7,8,9} Dec;
const size_t DlogR = 4;
const size_t DR = 10;

// BINARY
//typedef enum {0,1} Bin;
const size_t BlogR = 1;
const size_t BR = 2;


int main(int argc, char* argv[])
{
	char c = 'z';
	int num = 0;
	size_t max = 0;
	fsu::String in;
	fsu::Vector<fsu::String> stringList;
	fsu::LSDSort lsd;
	fsu::MSDSort msd;
	fsu::QS3Sort qs3;
	
	
	while(1)
	{
	while(c != 'U' && c != 'u' && c != 'A' && c != 'a' && c != 'l' && c != 'l'
			&& c != 'D' && c != 'd' && c != 'B' && c != 'b' && c != 'Q' && c != 'q')
	{
	std::cout << "Alphabet Choices:\n";
	std::cout << "  ASCII (A)\n";
	std::cout << "  Uppercase (U)\n";
	std::cout << "  Lowercase (L)\n";
	std::cout << "  Decimal (D)\n";
	std::cout << "  Binary (B)\n";
	std::cout << "	Quit (Q)\n";
	std::cout << "Please enter your choice: ";
	std::cin >> c;
	if(num != 0)
		std::cout << "Character not recognized\n";
	}
	num = 0;
	
	while(num <= 0)
	{
	std::cout << "Please enter the number of strings to be sorted: ";
	std cin >> num;
	}
	
	for(int i = 1; i < num+1; i++){
		std::cout << "Enter string " << i <<": ";
		in.GetLine(std::cin);
		stringList.PushBack(in);
		if(in.Length() > max)
			max = in.Length();
	}
	for(size_t i = 0; i < stringList.Size(); i++)
		stringList[i].SetSize(max, (char)0);
		
	switch(c)
	{
		case 'A':
		case 'a':
			lsd.Restart('A', 8, 256);
			msd.Restart('A', 8, 256);
			qs3.Restart('A', 8, 256);
			break;
		case 'U':
		case 'u':
			lsd.Restart('U', 5, 26);
			msd.Restart('U', 5, 26);
			qs3.Restart('U', 5, 26)	;		
			break;
		case 'L':
		case 'l':			
			lsd.Restart('L', 5, 26);
			msd.Restart('L', 5, 26);
			qs3.Restart('L', 5, 26);
			break;
		case 'D':
		case 'd':			
			lsd.Restart('D', 4, 10);
			msd.Restart('D', 4, 10);
			qs3.Restart('D', 4, 10);
			break;
		case 'B':
		case 'b':
			lsd.Restart('B', 1, 2);
			msd.Restart('B', 1, 2);
			qs3.Restart('B', 1, 2);		
			break;
		case 'Q':
		case 'q':
			std::cout << "Exiting...\n";
			return 0;
	}
	fsu::Vector<fsu::String> lsdList(stringList);
	fsu::Vector<fsu::String> msdList(stringList);
	fsu::Vector<fsu::String> qs3List(stringList);	
	
	lsd.Sort(lsdList, max, lsdList.Size());
	msd.Sort(msdList, max, msdList.Size());
	qs3.Sort(qs3List, max, qs3List.Size());
	
	std::cout << "LSD Sorted:\n";
	for(size_t i = 0; i < lsdList.Size(); i++)
		std::cout << "   " << lsd[i] << "\n";
	std::cout << "MSD Sorted:\n";
	for(size_t i = 0; i < msdList.Size(); i++)
		std::cout << "   " << msd[i] << "\n";
	std::cout << "QS3W Sorted:\n";
	for(size_t i = 0; i < qs3List.Size(); i++)
		std::cout << "   " << qs3[i] << "\n";
	
	}
}