//  This program calculates the area of a triangle provided by the user.
//  Created by Xavier on 4/9/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main() {
    
    float a, b, c;
    float area, heron, value;
    
    printf("Please enter 3 positive numbers for the sides of a triangle: ");
    scanf("%f%f%f", &a, &b, &c);
    
    heron = (a + b + c) / 2;
    value = heron * (heron - a) * (heron - b) * (heron - c);
    area = sqrt(value);
    
    printf("The area of the triangle you entered is %f\n", area);
    return 0;
}
