#include <stdio.h>
#include <math.h>
typedef long int Elemtype;
typedef struct{
	Elemtype numerator;
	Elemtype denominator;
	Elemtype integer;
}Fraction;
void simplify(Fraction *f){
	int sign = 0;
	if(f->numerator == 0) {
		f->integer = 0;
		return;
	}
	if(f->numerator < 0){
		sign = 1;
		f->numerator = 0 - f->numerator;
	}
	Elemtype n1 = f->numerator, n2 = f->denominator;
	while(1){
		if(n1 > n2){
			n1 = n1 - n2;
		}
		else if(n1 < n2){
			n2 = n2 - n1;
		}
		else break;
		if(n1 == 1 || n2 == 1) break;
	}
	if(n1 == n2){
		f->numerator = f->numerator / n1;
		f->denominator = f->denominator / n1;
	}
	f->integer = f->numerator / f->denominator;
	f->numerator = f->numerator%f->denominator;
	if(sign){
		f->integer = 0 - f->integer;
		f->numerator = 0 - f->numerator;
	}
}

int calculate(Fraction f1, Fraction f2, Fraction * rf,int type){
	if(f2.numerator == 0 && type == 4) return 0;
	switch(type){
		case 1:
			rf->denominator = f1.denominator * f2.denominator;
			rf->numerator = f1.numerator*f2.denominator + f2.numerator*f1.denominator;
			break;
		case 2:
			rf->denominator = f1.denominator * f2.denominator;
			rf->numerator = f1.numerator*f2.denominator - f2.numerator*f1.denominator;
			break;
		case 3:
			rf->denominator = f1.denominator * f2.denominator;
			rf->numerator = f1.numerator * f2.numerator;
			break;
		case 4:
			rf->denominator = f1.denominator * f2.numerator;
			rf->numerator = f1.numerator * f2.denominator;
			break;
		default: break;
	}
	if(rf->denominator < 0){
		rf->denominator = 0 - rf->denominator;
		rf->numerator = 0 - rf->numerator;
	}
	simplify(rf);
	return 1;
}
void print(Fraction f){
	if(f.integer == 0 && f.numerator == 0){
		printf("0");
	}
	else if(f.integer == 0 && f.numerator > 0){
		printf("%ld/%ld",f.numerator,f.denominator);
	}
	else if(f.integer == 0 && f.numerator < 0){
		printf("(%ld/%ld)",f.numerator,f.denominator);
	}
	else if(f.integer > 0 && f.numerator == 0){
		printf("%ld", f.integer);
	}
    else if(f.integer < 0 && f.numerator == 0){
		printf("(%ld)", f.integer);
	}
	else if(f.integer > 0 && f.numerator > 0){
		printf("%ld %ld/%ld", f.integer, f.numerator,f.denominator);
	}
	else if(f.integer < 0 && f.numerator < 0){
		printf("(%ld %ld/%ld)",f.integer,-f.numerator,f.denominator);
	}
}
int main(){
	Elemtype n1,d1,n2,d2;
	scanf("%ld/%ld",&n1,&d1);
	scanf("%ld/%ld",&n2,&d2);
	Fraction f1,f1_co,f2,f2_co;
	f1.numerator = n1;
	f1_co.numerator = n1;
	f1.denominator = d1;
	f1_co.denominator = d1;
	f2.numerator = n2;
	f2_co.numerator = n2;
	f2.denominator = d2;
	f2_co.denominator = d2;
	Fraction rf;
	simplify(&f1_co);
	simplify(&f2_co);
	calculate(f1, f2, &rf, 1);
	print(f1_co);
	printf(" + ");
	print(f2_co);
	printf(" = ");
	print(rf);
	printf("\n");
	calculate(f1, f2, &rf, 2);
	print(f1_co);
	printf(" - ");
	print(f2_co);
	printf(" = ");
	print(rf);
	printf("\n");
	calculate(f1, f2, &rf, 3);
	print(f1_co);
	printf(" * ");
	print(f2_co);
	printf(" = ");
	print(rf);
	printf("\n");
	int state = calculate(f1, f2, &rf, 4);
	print(f1_co);
	printf(" / ");
	print(f2_co);
	printf(" = ");
	if(state){
		print(rf);
	}
	else printf("Inf");
	printf("\n");
	return 0;
}