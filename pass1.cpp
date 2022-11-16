
//Assignment-1
/*Program 1: Implementation of 2 pass assemblers for x86 machine.*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>

int main(void)
{
	system("clear");

	const char* code[9][4] =
	{
		{"PRG1", "START", "", ""},
		{"", "USING", "*", "15"},
		{"", "L", "", ""},
		{"", "A", "", ""},
		{"", "ST", "", ""},
		{"FOUR", "DC", "F", ""},
		{"FIVE", "DC", "1F", ""},
		{"TEMP", "DS", "1F", ""},
		{"", "END", "", ""}
	};
	
	char av[2], avail[15] = {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'};
	int i, j, k, count[3], lc[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, loc = 0;
	
	std::cout << "-----------------------\n";
	std::cout << "LABEL\t\tOPCODE\n";
	std::cout << "-----------------------\n";

	for(i=0; i<=8; i++)
	{
		for(j=0; j<=3; j++)
		{
			std::cout << code[i][j] << "\t\t";
		}
		j = 0;
		std::cout << '\n';
	}
	std::cout << "---------------\n";
	std::cout << "VALUES FOR LC:\n\n";
	
	for(j=0; j<=8; j++)
	{
		if((strcmp(code[j][1], "START") != 0) && (strcmp(code[j][1], "USING") != 0) && (strcmp(code[j][1], "L") != 0))
		{
			lc[j] = lc[j - 1] + 4;
		}
		std::cout << lc[j] << '\t';
	}
	std::cout << "\n\n" << "SYMBOL TABLE:\n";
	std::cout << "----------------------------------------------------\n";
	std::cout << "SYMBOL\t\tVALUE\t\tLENGTH\t\tR/A\n";
	std::cout << "----------------------------------------------------\n";
	
	for(i=0; i<9; i++)
	{
		if(strcmp(code[i][1], "START") == 0)
		{
			std::cout << code[i][0] << "\t\t" << loc << "\t\t" << "4" << "\t\t" << "R\n";
		}
		else if(strcmp(code[i][0], "") != 0)
		{
			std::cout << code[i][0] << "\t\t" << loc << "\t\t" << "4" << "\t\t" << "R\n";
		}
		else
		{
			loc = 4 + loc;
		}
	}
	std::cout << "---------------------------------------------------------------\n";
	std::cout << "REG NO\t\tAVAILABILITY\t\tCONTENTS OF BASE TABLE\n";
	std::cout << "---------------------------------------------------------------\n";
	
	for(j=0; j<=8; j++)
	{
		if(strcmp(code[j][1], "USING") != 0)
		{
			//EMPTY if STATEMENT
		}
		else
		{
			strcpy(av, code[j][3]);
		}
	}
	count[0] = (int)av[0] - 48;
	count[1] = (int)av[1] - 48;
	count[2] = count[0] * 10 + count[1];
	
	avail[count[2] - 1] = 'Y';
	
	for(k=0; k<16; k++)
	{
		std::cout << k << "\t\t" << avail[k - 1] << '\n';
	}
	std::cout << "---------------------------------------------------------------\n";
	std::cout << "CONTINUE...??\n";
	std::cin.get();
	std::cout << "PASS2 TABLE:\n\n";
	std::cout << "LABEL\t\tOP1\t\tLC\t\t\n";
	std::cout << "---------------------------------------------------------------\n";
	
	loc = 0;
	
	for(i=0; i<=8; i++)
	{
		for(j=0; j<=3; j++)
		{
			std::cout << code[i][j] << "\t\t";
		}
		j = 0;
		
		std::cout << '\n';
		std::cin.get();
	}
	std::cout << "---------------------------------------------------------------\n";
}
