#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int normal(){
    
    int i, t, press;
    float speed, error;

    FILE* fp = fopen("./normal.csv", "w+");
    fprintf(fp, "no,time,pressue,speed\n");
    
    srand((unsigned int)time(NULL));

    for(i=0; i<10000; i++){
        
        speed = 0;
        for(t=0; t<20; t++){

        
            press = rand()%16 -5; // -5 ~ 10
            speed += press;
            
            fprintf(fp, "%d,%d,%d,%.2f\n", i, t, press, speed);
        }
    }
    
    fclose(fp);
    return 0;
}

int error(){
    int i, t, press;
    float speed, error;

    FILE* fp = fopen("./error.csv", "w+");
    fprintf(fp, "no,time,pressue,speed\n");

    srand((unsigned int)time(NULL));
    
    for(i=0; i<10000; i++){

        speed = 0;
        for(t=0; t<20; t++){
         
            press = rand()%16 - 5; // -5 ~ 10
            error = (float)(rand()%141 - 70)/100; // -0.70 ~ 0.70
            speed += (int)(error*press);
            
            fprintf(fp, "%d,%d,%d,%.2f\n", i, t, press, speed);
        }
    }

    fclose(fp);
    return 0;
}

int main(){

    normal();
    error();

    return 0;
}
