#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MU_A 173.2
#define MU_B 170.5
#define VAR_A 33
#define VAR_B 32
extern double p_stdnorm(double z);

int main(void)
{
    double val;
    double z_a, z_b, mu_a=MU_A, mu_b=MU_B, var_a=VAR_A, var_b=VAR_B;
    double p_a, p_b , val_a_result=1, val_b_result=1;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){ 
      sscanf(buf,"%lf",&val);    
          
      z_a = (val - mu_a)/sqrt(var_a);
      z_b = (val - mu_b)/sqrt(var_b);

      p_a = p_stdnorm(z_a);
      p_b = p_stdnorm(z_b);
      val_a_result = val_a_result * p_a;
      val_b_result = val_b_result * p_b;
    }






    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %.9f\n",val_a_result);
    printf("L_B: %lf\n",val_b_result);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

