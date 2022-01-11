/**
Author Belle Erhardt
Last Edited 9/21/2020
Objective: Import sodoku Board and Solve it
*/

#include <iostream>
#include <fstream>

using namespace std;
#define MAX_DIM 9
int numbers[9][9];
string filename;
ifstream fileC;


/**
getNumbers() asks user to input a sudoku text file
from here it converts into an array of intergers
numbers[][]
*/
void getNumbers() 		
	{		  
	cout << "What is the name of the sudoku file you would like to solve? \n";
	cin >> filename;
	fileC.open(filename.c_str());	
	cout<<"+---+---+---+\n|";

	for(int row=0; row<MAX_DIM; row++)
		for(int col=0; col<MAX_DIM;col++)
			fileC >> numbers[row][col];

	fileC.close();
	}
	
bool checkZeros()
	{ 
	for(int row=0; row< MAX_DIM; row++)
		for(int col =0; col<MAX_DIM; col++)
			{
			if(numbers[row][col] == 0)
				{
					return false;
				}
			}
			
			return true;
	}	
	
/**
when called replaceZero() replaces all zeros from 
the numbers[][] replaces them with * when printed
but NOT actually in the array
*/
void prompt()
	{
	cout<<"\nSolving Board... \nOne Moment..."<<endl;
	cout<<"--------------------\nHere you Go!\n\n";
	}

/**
k = current number being checked
smallBox is a boolean method which 
takes the column and row and sees if there
are any doubles within the same box
*/

bool smallBox(int Row, int Col, int k)
{
	for(int row = 0; row < 3; row++)	
		for(int col = 0; col < 3; col++)
			{
			if(numbers[row+Row][col+Col] == k)
				return false;
			}
		return true;
}
/**
canPlace() takes which number is being checked and 
attempts to place it were it should be going
will return true once it has been placed
*/
bool canPlace(int k) 
	{
	int row;
	int col;
	//read my Row, return false if you find a repeated number
	for(row = 0; row < MAX_DIM; row++)	
		for(col = 0; col < MAX_DIM; col++)
			{
			if(numbers[row][col] == k)
				return false;
			}
		
	//read my Col, return false if you find a repeated number
	for(int row = 0; row < MAX_DIM; row++)	
		for(int col = 0; col < MAX_DIM; col++)
			{
			if(numbers[row][col] == k)
				return false;
			}
		
	if(!smallBox(row%3, col%3, k))
		{
		return false;
		}
	
	
	    
    	return true;
	}
/**
print() prints the array numbers[][]
*/
void print()
	{
		int counter=1;	
		for(int row=0; row<MAX_DIM; row++)
			for(int col=0; col<MAX_DIM;col++)
				{	 
				counter++;
				if(numbers[row][col]==0)
					{
					cout << '*';
					}else
				cout << numbers[row][col];
				 				 
				 if(counter%9==1 && counter%27!=1)
				 	cout << "|\n";
				 if(counter%3 == 1)
    					cout<<"|";
 				 if(counter%27 == 1 )
 					{
 					cout<<"\n+---+---+---+\n";
 					if(counter<60)
 					{
 					cout<<"|";
 					}
 					}  
				}
		counter=0;		 
	}
/**
solveBoard()
*/	
bool solveBoard()				
	{
	int col;
	int row;
	if(checkZeros())
		{
			return true;
		}
		
	for(int g=1; g < MAX_DIM; g++)
	{
		if(canPlace(g))
			{
			numbers[row][col]= g;
			
			if(solveBoard())
			{
				return false;
			}
		numbers[row][col] = 0;
			
		}

	}
		
		return false;
	}	

int main(int argc, char *argv[])
	{

	getNumbers();
	print();
	prompt();
	 if(!solveBoard())
	 {
	 	cout<<"+---+---+---+\n|";
	 	print();
	 }
	
	return 0;
	} 

