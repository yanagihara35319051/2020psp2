#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct human_data{
    int ID;
    int sex;
    double height;
};
int N = 1;           //heights.csvの1行目が文字列のため、配列の1番目から代入をするように調整
int flag = 0;        //データが一致したかの判定

int main(void){
    int i;
    int search_data;
    int val_1;
    int val_2;
    double val_3;
    double se;
    char fname_1[FILENAME_MAX];
    char fname_2[FILENAME_MAX];
    char buf_1[256];
    char buf_2[256];
    FILE* fp_1;
    FILE* fp_2;

    
    struct human_data heights_data[100];

    printf("input the filename of sample_ID:");       //IDのサンプルデータを入力
    fgets(fname_1,sizeof(fname_1),stdin);
    fname_1[strlen(fname_1)-1] = '\0';
    printf("the filename of sample: %s\n",fname_1);

    fp_1 = fopen(fname_1,"r");
    if(fp_1==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf_1,sizeof(buf_1),fp_1) != NULL){
        sscanf(buf_1,"%d",&val_1);
        heights_data[N].ID = val_1;
        N = N + 1;
        
    } 

    N = 0;

    printf("input the filename of sample_heights:");   //身長のサンプルを入力
    fgets(fname_2,sizeof(fname_2),stdin);
    fname_2[strlen(fname_2)-1] = '\0';
    printf("the filename of sample: %s\n",fname_2);

    fp_2 = fopen(fname_2,"r");
    if(fp_2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf_2,sizeof(buf_2),fp_2) != NULL){
        sscanf(buf_2,"%d, %lf",&val_2,&val_3);
        heights_data[N].sex = val_2;
        heights_data[N].height = val_3;
        N = N + 1; 
        
    } 

    printf("Which ID's data do you want? :");
    scanf("%d",&search_data);
    printf("-----\n");
    for(i=1;i<=N;i++){
        if(search_data == heights_data[i].ID){
            printf("ID:%d\n",heights_data[i].ID);   //IDの出力

            if(heights_data[i].sex==1){            //性別の出力
                printf("gender:male\n");  
            }
            else if(heights_data[i].sex==0){
                printf("gender:female\n"); 
            }
            else{
                printf("gender:error/n");
            }

            printf("height:%.2f\n",heights_data[i].height);    //身長の出力

            flag = 1;
        }
    }
    
    if(flag==0){
        printf("no data\n");
    }
    return 0;
}