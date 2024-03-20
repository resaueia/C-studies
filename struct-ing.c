/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct-ing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:59:23 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/03/20 20:22:35 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*When using typedef, you can 'name' your struct at the end (think alias) 
and not have to initialize via the term 'struct' again in main, instead you
can simply call on the struct's alias instead.*/

typedef struct	Student
{
	char	name[50];
	char	id[10];
	int	age;
	int	grades[5];
} Student;

/*You can also feed a struct to a given function by calling on its alias
and the argument that you want.*/

void	print_student(Student student)
{
	printf("Name: %s\n", student.name);
	printf("ID: %s\n", student.id);
	printf("Age: %d\n", student.age);
	printf("Certification Exam Grades: ");
	int i = 0;
	while (i < 5)
	{
		printf("%d\n", student.grades[i]);
		i++;
	}
}

typedef	struct
{
	int x;
	int y;
} Point;

void	print_points(Point points[])
{
	for (int i = 0; i < 10; i++)
		printf("p%d = (%d, %d)\n", i, points[i].x, points[i].y);
}

/*On the struct below, we have a pointer to a dinamically allocated array.*/

typedef struct
{
	int *array;
} Data;

int	main(void)
{
	Student frieren;

	frieren.age = 1200;
	strcpy(frieren.id, "12345");
	strcpy(frieren.name, "Frieren");
	frieren.grades[0] = 10;
	frieren.grades[1] = 10;
	frieren.grades[2] = 10;
	frieren.grades[3] = 10;
	frieren.grades[4] = 10;

	print_student(frieren);
	
	/*You can initialize a struct in the way below and what that will do is
	it will assign those numbers to the variables inside the struct in the order
	that they appear here, hence x will get 5 and y will get 10.*/
	
	Point p1 = {5, 10};

	/*You can also initialize it in the way below, in a clearer way, pointing
	out which variable gets what. In this way, order doesn't matter because the
	variables are pointed out specifically.*/
	
	Point p2 = { .y = 4, .x = 8};

	printf("p1.x: %d\n", p1.x);
	printf("p1.y: %d\n", p1.y);

	printf("p2.x: %d\n", p2.x);
	printf("p2.y: %d\n", p2.y);

	/*You can also pass an array of struct values to a function like below - refer
	to the 'print_points' function above to understand its course of action.*/
	
	Point points[10];

	for (int i = 0; i < 10; i++)
	{
		points[i].x = i;
		points[i].y = 10 - i;
	}

	print_points(points);

	/*Now, it's important to pay extra attention when utilizing pointers with structs.
	 In the case below, we are going to dinamically allocate space to a given array that
	 resides within a struct.*/

	Data x;
	Data y;

	x.array = malloc(sizeof(int) * 5); //array is a pointer to that dinamically allocated space
	y.array = malloc(sizeof(int) * 5);

	x.array[0] = 1;
	x.array[1] = 2;
	x.array[2] = 3;
	x.array[3] = 4;
	x.array[4] = 5;


	y.array[0] = 9;
	y.array[1] = 9;
	y.array[2] = 9;
	y.array[3] = 9;
	y.array[4] = 9;
	
	/*What will happen, though, when we say that x receives y? We would normally think that
	because this usually works as a memcopy, the values in x will now receive the values in
	y. However, the memory for that struct is actually a pointer to an array. What that struct
	actually holds is not an array, but a pointer to a dinamically allocated int array! So,
	with that in mind, what's gonna be copied is not the array itself, but the pointer to the
	array. In other words, what's gonna be copied into x is not the array of y, but the
	pointer to the array that y is holding.*/
	
	x = y;

	for (int i = 0; i < 5; i++)
		printf("x.array[%d] = %d\n", i, x.array[i]);

	/*You might think that x's array is now holding the values 99999, but actually, x has
	 been set to point to the same array that y is pointing to. What gets copied is the
	 pointer that y has to that array. If you were to modify x (see below), what's gonna
	 get modified is actually y, because they're both pointing to the same array.*/

	x.array[0] = 10;

	for (int i = 0; i < 5; i++)
		printf("y.array[%d] = %d\n", i, y.array[i]);

	return (0);
}
