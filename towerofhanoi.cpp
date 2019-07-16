#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>

#define MINHEIGHT 1
#define MAXHEIGHT 15

typedef short int16_t;
typedef short pole_t[MAXHEIGHT];

int16_t height = 0; //height variable of original tower
int16_t steps = 1; //number of steps required, or 2 ^ height - 1
pole_t pole1, pole2, pole3;
int16_t pole1_h, pole2_h, pole3_h;

/*
	Gathers user input height of tower
*/
int16_t get_height()
{
	while ((height < MINHEIGHT) || (height % 1 != 0) || (height > MAXHEIGHT)) {
		printf("\nEnter your tower height, please enter an integer value no less than %d and no more than %d: ", MINHEIGHT, MAXHEIGHT);
		scanf(" %d", &height);
		if ((height < MINHEIGHT) || (height % 1 != 0) || (height > MAXHEIGHT)) {
			printf("Tower height number invalid, please try again\n");
		}
		else
			break;
	}
	 
	return height;
}

/*
	Sets initial poles; all disks are placed on the top pole
*/
void set_poles(int16_t height)
{
	int16_t disk_num = height;

	for (int i = 0; i < height; i++) {
		pole1[i] = disk_num--;
		pole1_h++;
	}
}

/*
	Prints pole names
*/
void print_names()
{
	char pole_names[3] = { 'A', 'B', 'C' };

	printf("\n");
	for (int16_t reps = 0; reps < 3; reps++) {
		for (int16_t i = 0; i < MAXHEIGHT; i++)
			printf("%c", 32);
		printf("%c", pole_names[reps]);
		for (int16_t i = 0; i < MAXHEIGHT + 1; i++)
			printf("%c", 32);
	}
	printf("\n");
}
/*
	Prints original position of all disks
*/
void print_original(int16_t height)
{
	int16_t spaces_count;

	printf("Original: \n\n");
	for(int16_t i = 1; i <= height; i++) {
		spaces_count = MAXHEIGHT - i;

		for (int16_t j = 0; j < spaces_count; j++)
			printf("%c", 32);

		for (int16_t j = 0; j < i * 2; j++)
			printf("%c", 219);
		
		for (int16_t j = 0; j < spaces_count; j++)
			printf("%c", 32);

		printf("\n");
	}
	print_names();
}

/*
	Simulates one move and prints out result
*/
void move(int16_t disk_num, pole_t src_pole, pole_t aux_pole, pole_t dest_pole, int16_t* src_pole_height, int16_t* aux_pole_height, int16_t* dest_pole_height, char src_pole_n, char aux_pole_n, char dest_pole_n)
{
	int16_t height_count, spaces_count;

	char pole1_arr[MAXHEIGHT * 2], pole2_arr[MAXHEIGHT * 2], pole3_arr[MAXHEIGHT * 2]; //3 arrays used for printing pole 1, pole 2, pole 3
	int16_t pole1_ind, pole2_ind, pole3_ind;


	dest_pole[*dest_pole_height] = src_pole[*src_pole_height - 1];
	(*src_pole_height)--;
	(*dest_pole_height)++;

	printf("\nStep %d: ", steps); //Prints number of steps 
	printf("Move disk %d from pole %c to pole %c\n\n", disk_num, src_pole_n, dest_pole_n);

	for (height_count = height - 1; height_count >= 0; height_count--) { //Sets height counter to height, decrease in increments
		if (height_count < pole1_h || height_count < pole2_h || height_count < pole3_h) {
			if (height_count < pole1_h) {
				spaces_count = (MAXHEIGHT - pole1[height_count]);
				/*For loop that assigns all spaces before actual blocks*/
				for (pole1_ind = 0; pole1_ind < spaces_count; pole1_ind++)
					pole1_arr[pole1_ind] = ' ';

				/*For loop that assigns squares for printing block, this should be in the middle*/
				for (pole1_ind = spaces_count; pole1_ind < spaces_count + pole1[height_count] * 2; pole1_ind++)
					pole1_arr[pole1_ind] = 219;

				for (pole1_ind = spaces_count + pole1[height_count] * 2; pole1_ind < MAXHEIGHT * 2; pole1_ind++)
					pole1_arr[pole1_ind] = ' ';
			}
			else {
				for (pole1_ind = 0; pole1_ind < MAXHEIGHT * 2; pole1_ind++)
					pole1_arr[pole1_ind] = ' ';
			}

			if (height_count < pole2_h) {
				spaces_count = (MAXHEIGHT - pole2[height_count]);
				/*For loop that assigns all spaces before actual blocks*/
				for (pole2_ind = 0; pole2_ind < spaces_count; pole2_ind++)
					pole2_arr[pole2_ind] = ' ';

				/*For loop that assigns squares for printing block, this should be in the middle*/
				for (pole2_ind = spaces_count; pole2_ind < spaces_count + pole2[height_count] * 2; pole2_ind++)
					pole2_arr[pole2_ind] = 219;

				for (pole2_ind = spaces_count + pole2[height_count] * 2; pole2_ind < MAXHEIGHT * 2; pole2_ind++)
					pole2_arr[pole2_ind] = ' ';
			}
			else {
				for (pole2_ind = 0; pole2_ind < MAXHEIGHT * 2; pole2_ind++)
					pole2_arr[pole2_ind] = ' ';
			}

			if (height_count < pole3_h) {
				spaces_count = (MAXHEIGHT - pole3[height_count]);
				/*For loop that assigns all spaces before actual blocks*/
				for (pole3_ind = 0; pole3_ind < spaces_count; pole3_ind++)
					pole3_arr[pole3_ind] = ' ';

				/*For loop that assigns squares for printing block, this should be in the middle*/
				for (pole3_ind = spaces_count; pole3_ind < spaces_count + pole3[height_count] * 2; pole3_ind++)
					pole3_arr[pole3_ind] = 219;

				for (pole3_ind = spaces_count + pole3[height_count] * 2; pole3_ind < MAXHEIGHT * 2; pole3_ind++)
					pole3_arr[pole3_ind] = ' ';
			}
			else {
				for (pole3_ind = 0; pole3_ind < MAXHEIGHT * 2; pole3_ind++)
					pole3_arr[pole3_ind] = ' ';
			}
		}
		else {
			for (pole1_ind = 0, pole2_ind = 0, pole3_ind = 0; pole1_ind < MAXHEIGHT * 2; pole1_ind++, pole2_ind++, pole3_ind++) {
				pole1_arr[pole1_ind] = ' ';
				pole2_arr[pole2_ind] = ' ';
				pole3_arr[pole3_ind] = ' ';
			}
		}
		for (pole1_ind = 0; pole1_ind < MAXHEIGHT * 2; pole1_ind++)
			printf("%c", pole1_arr[pole1_ind]);
		printf("  ");
		for (pole2_ind = 0; pole2_ind < MAXHEIGHT * 2; pole2_ind++)
			printf("%c", pole2_arr[pole2_ind]);
		printf("  ");
		for (pole3_ind = 0; pole3_ind < MAXHEIGHT * 2; pole3_ind++)
			printf("%c", pole3_arr[pole3_ind]);
		printf("\n");
	}
	print_names();
	steps++;
}

/*
	Algorithm for solving problem
*/
void solve(int16_t disk_num, pole_t src_pole, pole_t aux_pole, pole_t dest_pole, int16_t * src_pole_height, int16_t * aux_pole_height, int16_t * dest_pole_height, char src_pole_n, char aux_pole_n, char dest_pole_n)
{
	if (disk_num == 1) {
		move(disk_num, src_pole, aux_pole, dest_pole, src_pole_height, aux_pole_height, dest_pole_height, src_pole_n, aux_pole_n, dest_pole_n);
		return;
	}
	solve(disk_num - 1, src_pole, dest_pole, aux_pole, src_pole_height, dest_pole_height, aux_pole_height, src_pole_n, dest_pole_n, aux_pole_n);
	move(disk_num, src_pole, aux_pole, dest_pole, src_pole_height, aux_pole_height, dest_pole_height, src_pole_n, aux_pole_n, dest_pole_n);
	solve(disk_num - 1, aux_pole, src_pole, dest_pole, aux_pole_height, src_pole_height, dest_pole_height, aux_pole_n, src_pole_n, dest_pole_n);
}

int main()
{
	get_height();
	set_poles(height);
	print_original(height);
	solve(height, pole1, pole2, pole3, &pole1_h, &pole2_h, &pole3_h, 'A', 'B', 'C');

	return 0;
}


