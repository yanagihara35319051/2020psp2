#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave);
extern double var_online(double val, double ave, double square_ave);
int N;

int main(void)
{   
    double ave = 0,var = 0,square_ave=0;
    double p_var;
    double val;
    double se;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    N = 0;

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
        
        N = N+1;
        var = var_online(val,ave,square_ave);
        ave = ave_online(val,ave);
        square_ave = ave_online(pow(val,2),square_ave); 


        
    } 

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    p_var = ((double)N/((double)N-1.0))* var;
    se = sqrt(p_var/(double)N);
    printf("average=%.2f\n",ave);
    printf("variance=%.2f\n\n",var);
    printf("population variance=%.2f\n",p_var);
    printf("population average=%.2f\n",ave);
    printf("standard error=%.2f\n",se);

    return 0;


}

double ave_online(double val,double ave)
{
    double ave_result;

    ave_result = ((((double)N-1)/(double)N) * ave)+ (1 / (double)N * val) ; 
    
    return ave_result;
}

double var_online(double val, double ave, double square_ave)
{
    double var_result,add_1,add_2;
    //式の前半の計算
    add_1 = ( (( (double)N - 1 ) / (double)N) * square_ave) + ( (1 / (double)N) * pow(val,2));
    //式の後半の計算
    add_2 = (((double)N-1)/(double)N * ave) + ((1/(double)N)*val);
    add_2 = pow(add_2,2);

    var_result = add_1 - add_2;

    return var_result;

}
