#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);

int main(void)
{
    double val_a,val_b;
    double z_a, z_b, u_a=173.2, u_b=170.5, var_a=33, var_b=32;
    double p_a, p_b , max_val=1, min_val=1;
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

    /*while(fgets(buf,sizeof(buf),fp) != NULL){ */
      /*  sscanf(buf,"%lf",&val);  */
    /*}  */
    while(fscanf(fp, "%lf,%lf",&val_a,&val_b) !=EOF){
      
      z_a = (val_a - u_a)/sqrt(var_a);
      z_b = (val_b - u_b)/sqrt(var_b);

      p_a = p_stdnorm(z_a);
      p_b = p_stdnorm(z_b);
      max_val = max_val * p_a;
      min_val = min_val * p_b;
    }






    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %.9f\n",max_val);
    printf("L_B: %lf\n",min_val);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

