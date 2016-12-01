/**
* @file randomFuncs.c
* @author Allan Gamboa
* @date 03 NOV 16
* @brief First C competency problem
*
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "myHeader.h"


//Function Declerations
void roll_dice(int inum_dice, int num_sides, int inum_rolls);
double surface_area(double dradius);
double volume_of_cube(double side_length);
void save_to_file(char *filename, char *output_string);

#define strsize 500

int main()
{
	int inum_dice, num_sides, inum_rolls, imenu;
	char csave, crepeat = 'y';
	double dradius, dside_len, darea, dvolume;

	while (crepeat == 'y')
	{
		printf("What would you like to do?\n\n\
	1)Roll Dice\n\
	2)Compute the surface are of a circle\n\
	3)Compute the volume of a cube\n\
	4) Test your the \"other\" function\n\n");

		scanf_s("%i", &imenu);

		switch (imenu)
		{
		case 1:
			printf("Lets Roll Some Dice!\n Please Specify the number of dice, the number of sides and the number of rolls. Space Seperated please:");
			scanf_s("%i%i%i", &inum_dice, &num_sides, &inum_rolls);
			roll_dice(inum_dice, num_sides, inum_rolls);
			printf("\n\n");
			break;
		case 2:
			printf("Lets compute the surface area of a circle. Please provide the radius: ");
			scanf_s("%lf", &dradius);
			darea = surface_area(dradius);
			printf("The surface area of a circle with radius %f is %f", dradius, darea);
			printf("\n\n");
			break;
		case 3:
			printf("Lets compute the volume of a cube. Please provide the side-length: ");
			scanf_s("%lf", &dside_len);
			dvolume = volume_of_cube(dside_len);
			printf("The volume of a cube with side-length %f is %f", dside_len, dvolume);
			printf("\n\n");
			break;
		case 4:
			printf("\n\n");
			printf("Testing mypow func with 3.2 to the 3 power: %f", mypow(3.4, 3));
			break;
		default:
			break;
		}
		

		

		
		/*
		printf("Would you like to save the area and volume results? (y/n): ");
		scanf_s(" %c", &csave, 1);
		getchar();
		if (csave == 'y')
		{
			char path[strsize];
			char output_string[strsize];
			printf("Please specify the path:\n");
			scanf_s("%s", path, strsize);
			//getchar();//Needed to put this here for proper sequence of excecution... not sure why though.
			sprintf_s(output_string, strsize, "The surface area of a circle with radius %f is %f\nThe volume of a cube with side-length %f is %f", dradius, darea, dside_len, dvolume);
			save_to_file(path, output_string);
		}
		*/
		
		printf("\n\n");
		printf("Would you like to go back to the original menu? (y/n): ");
		scanf_s(" %c", &crepeat, 1);

		getchar();

		
	}
	
	return 0;
}


void roll_dice(int inum_dice, int num_sides, int inum_rolls) {
	//Check the input
	if (inum_dice <= 0 || inum_rolls <= 0 || num_sides <= 0)
	{
		printf("0");
	}

	int i,j;
	time_t t;
	int isave;
	//const int isize = 0;
	//int iremaining_len = strsize;
	char caoutput_string[strsize];
	char catemp[strsize];

	/* Intializes random number generator */
	srand((unsigned)time(&t));

	/* Print the outcomes of the rolls */
	//printf("ROLL\t");
	strcpy_s(caoutput_string, strsize, "ROLL\t");
	for (i = 1; i <= inum_dice; i++)
	{
		//printf("DICE_%i\t",i);
		sprintf_s(catemp, strsize, "DICE_%i\t", i);
		strcat_s(caoutput_string, 100, catemp);
	}
	//printf("\n");
	strcat_s(caoutput_string, strsize, "\n");
	for (i = 0; i < inum_rolls; i++)
	{
		//printf("#%i\t", i+1);
		sprintf_s(catemp, strsize, "#%i\t", i + 1);
		strcat_s(caoutput_string, strsize, catemp);
		for (j= 0; j < inum_dice; j++)
		{
			//printf("%d\t", (rand() % (num_sides-1))+1);
			sprintf_s(catemp, strsize, "%d\t", (rand() % num_sides)+1);
			strcat_s(caoutput_string, strsize, catemp);
		}
		//printf("\n");
		strcat_s(caoutput_string, strsize, "\n");
	}
	printf(caoutput_string);
	
	//Possibly saving to file
	printf("\nWould you like to save the results to a file (1 for yes, 0 for no)?\n");
	scanf_s("%d", &isave);
	if (isave == 1)
	{
		char path[strsize];
		printf("Please specify the path:\n");
		scanf_s("%s",path,strsize);
		//getchar();//Needed to put this here for proper sequence of excecution... not sure why though.
		save_to_file(path, caoutput_string);
	}
	//getchar();
}

double surface_area(double dradius) {
	if (dradius<0)
	{
		return -1.0;
	}
	return 3.14*dradius*dradius;
}

double volume_of_cube(double side_length) {
	if (side_length<0)
	{
		return -1.0;
	}

	return pow(side_length,3);
}

void save_to_file(char *cpfilename, char *cpoutput_string) {
	FILE *fpfile;
	errno_t err;
	err = fopen_s(&fpfile, cpfilename, "w");
	if (err == 0)
	{
		fprintf(fpfile, cpoutput_string);
		printf("Results written to:\n");
		printf(cpfilename);
		fclose(fpfile);
	}
	else
	{
		printf("Could not properly open file");
	}
	//getchar();
}