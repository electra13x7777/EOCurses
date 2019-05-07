// File: map.c
// Author: Alex Barney
//
// Description:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"

#define BUFFER 999

// Function: parse_map
// Return: char*
// Description:
void parse_map(char* fn, char arr[35][30])
{
	char str[BUFFER*10];
	FILE *fp;
	fp = fopen(fn, "r");
	if(fp != NULL)
	{
		for(int i = 0; i < 35; i++)
		{
			fgets(str, sizeof(str), fp);
			char *tok = strtok(str, ",");
			for(int j = 0; j < 30; j++)
			{
				if(tok == "0")
				{
					arr[i][j] = ' '; // EMPTY
				}
				if(tok == "1")
				{
					arr[i][j] = 178 + '0'; // WALL
				}
				if(tok == "2")
				{
					arr[i][j] = 'S';
				}
				if(tok == "3")
				{
					arr[i][j] = 'T';
				}
				if(tok == "4")
				{
					arr[i][j] = 'G';
				}
				if(tok == "5")
				{
					arr[i][j] = 175 + '0';
				}
				if(tok == "6")
				{
					arr[i][j] = 'F';
				}
				if(tok == "7")
				{
					arr[i][j] = '<';
				}
				if(tok == "8")
				{
					arr[i][j] = '>';
				}
				if(tok == "9")
				{
					arr[i][j] = '^';
				}
				if(tok == "E")
				{
					arr[i][j] = 'E';
				}
				tok = strtok("NULL", ",");
			}
		}
	}
	fclose(fp);
}

void print_map(char arr[35][30])
{
	for(int i = 0; i < 35; i++)
	{
		printf("\n");
		for(int j = 0; j < 30; j++)
		{
			printf("%c", arr[i][j]);
		}
	}
}

int main()
{
	char map[35][30];
	//memset(map, ' ', sizeof(map));
	parse_map("src/maps/bf1.txt", map);
	print_map(map);
}
