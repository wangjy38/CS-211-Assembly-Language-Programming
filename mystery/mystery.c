#include "mystery.h"
int num[200];
int     add(int num1, int num2)
{
        return  num1 + num2;
}
int dothething(int n) {
	int i;
	if (num[n] != -1) {   
	    return num[n];
	}else {
	       if (n == 0){     
			   i = 0;
	       }else if (n == 1) { 
			   i = 1;
	       }else {
                      i = add(dothething(n-1),dothething(n-2));	
	       }
	 }
         
       num[n] = i;
       return num[n];
}	

int main(int argc, char** argv) {
    int n = atoi(argv[1]);
    int i;	
	for (i = 0; i<= 199; i++) { 
		num[i] = -1;
	}
	
	printf("Value: %d\n", dothething(n));
 	return 0;
} 

