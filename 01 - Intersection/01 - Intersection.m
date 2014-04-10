//
//  intersection.m
//  Intersection
//
//  Created by Muhammad Hussein Nasrollahpour on 10/30/13.
//  Copyright (c) 2013 Chocolate. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Cube.h"

#define MAXLENGTH 100

int main(int argc, const char * argv[])
{

	@autoreleasepool {
		
		// Section 1: Manipulating & gathering input
		NSInteger numberOfCube = 0;
		NSLog(@"Enter number of cube that you want to compute the volume of the intersection of a set of cubes:\n");
		scanf("%ld", &numberOfCube);
		
		NSMutableArray *cubes = [NSMutableArray new];

		char cubeDescription[MAXLENGTH];
		
		NSLog(@"Enter %ld cube description: (x, y, z) and d ", numberOfCube);
		while (fgets(cubeDescription, MAXLENGTH, stdin)) {
			NSInteger  i = 0;
			NSInteger xyzd[4];
			char *newCubeDescription = cubeDescription;
			
			while ('\n' != *newCubeDescription) {
				
				if (isspace(*newCubeDescription)) {
					newCubeDescription++;
				}
				
				NSInteger aCubeDes = [[NSNumber numberWithInt: *newCubeDescription] integerValue];
				aCubeDes -= 48;
				
				xyzd[i] = aCubeDes;
				
				i++;
				newCubeDescription++;
			}
			
			Cube *cube = [Cube new];
			[cube setX: xyzd[0]];
			[cube setY: xyzd[1]];
			[cube setZ: xyzd[2]];
			[cube setD: xyzd[3]];
			
			[cubes addObject: cube];
			
			if (numberOfCube == 0) {
				break;
			}
			
			numberOfCube--;
		}
		
		[cubes removeObjectAtIndex: 0];

		// Section 2: Computing volume of the intersection of a set of cubes
		NSMutableArray *newCubes = [NSMutableArray new];
		// Adds x, y, and z with d to generate new coordinate
		for (Cube *cube in cubes) {
			Cube *newCube = [Cube new];
			
			NSInteger x, y, z;
			
			x = [cube x] + [cube d];
			[newCube setX: x];
			
			y = [cube y] + [cube d];
			[newCube setY: y];
			
			z = [cube z] + [cube d];
			[newCube setZ: z];
			
			[newCubes addObject: newCube];
		}
		
		NSInteger cubesCount = [cubes count];
		NSInteger newCubesCount = [newCubes count];
		
		// Gets two cubes combined to each other
		Cube *cubeA = [newCubes objectAtIndex: newCubesCount - 1];
		Cube *cubeB = [cubes objectAtIndex: cubesCount - 1];
		
		NSInteger result1 = [cubeB y] - [cubeA y];
		NSInteger result2 = [cubeB z] - [cubeA z];
		
		NSInteger result = result1 * result2;
		
		NSLog(@"Result: %ld", result);
	}
	
    return 0;
}
