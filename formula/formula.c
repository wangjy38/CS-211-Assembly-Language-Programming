
#include "formula.h"

int main(int argc, char** argv)
{
        
        struct timeval  begin, end;
        if (argc != 2) {
                printf("Usage: formula <positive integer>\n");
                return  0;
        } 
        if (strcmp(argv[1], "-h")==0) {
                printf("Usage: formula <positive integer>\n");
                return  0;
        }
        char *power = argv[1];  
        while (*power != '\0') {
           if ((*power > '9') || (*power < '0')){
                printf("Usage: formula <positive integer>\n");
                return  0;
            }
           power++;
        }
        int n, r;
        n = atoi(argv[1]);
        
        //if (n <=0) {
        //        printf("Usage: formula <positive integer>\n");
        //        return  0;
        //}
 
       
        gettimeofday(&begin, NULL);
         int result = 0;
        result = nCr(n,1);
              if (result == 0){
              fprintf(stderr, "Overflow Detected\n");
              return 0;
              }  
        printf("(1 + x)^%d = 1 ", n);
       
        for (r = 1; r <= n; r++)
        {
              
              printf("+ %d*x^%d ", nCr(n, r), r);
        }
        printf("\n");
        gettimeofday(&end, NULL);
        printf("Time Required = %ld microsecond\n", (end.tv_sec - begin.tv_sec) * 1000000 + (end.tv_usec - begin.tv_usec));

        return  0;
}

