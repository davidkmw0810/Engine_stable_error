#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float anomaly(){ // 엔진 오일 유입으로 인한 오차 발생함수

    float random = (float)(rand()%21 - 5) / 10; // -0.50 ~ 1.50
    return random;
}

float option(float speed){ // speed를 받아서 속도 제어를 위한 acc 발생
    
    float acc = 100 - speed;
    /*
    if(speed < 100){
        acc = 1.0;
    } else if(speed > 100) {
        acc = -1.0;
    } else {
        acc = 0.0;
    }
    */

    return acc;

}

int normal(){ // 정상 차

    int i;
    float acc;
    float speed = 100.00;
    int resist = -1;
    FILE* fp = fopen("./normal.csv", "w+"); // output format "time, speed, acc"
    
    fprintf(fp, "0,100.00,1\n");

    for(i=1; i<=500; i++){
        acc = option(speed);
        speed += (float)resist + acc;
        
        fprintf(fp, "%d,%.2f,%f\n", i, speed, acc);
    }
    
    fclose(fp);
    return 0;
}

int error(){ // 엔진 오일 유입 차량

    int i;
    float acc;
    float speed = 100.0;
    int resist = -1;
    FILE* fp = fopen("./error.csv", "w+");
    fprintf(fp, "0,100.00,1\n");
    
    for(i=1; i<=500; i++){
        acc = option(speed);
        speed += resist + acc*anomaly();
        fprintf(fp, "%d,%.2f,%f\n", i, speed, acc);
    }
    
    fclose(fp);
    return 0;
}

int test(){ // 엔진 오일 유입 차량

    int i, j, t[50];
    float speed = 100.0;
    float acc;
    int resist = -1;
    FILE* fp = fopen("./error.csv", "w+");
    fprintf(fp, "0,100.00,1\n");
    for(j=0; j<50; j++){
        t[j] = rand()%500+1; // 1~500
    }
    for(i=1; i<=500; i++){
        acc = option(speed);
        
        for(j=0; j<50; j++){
            if(t[j] == i){
                speed += resist + acc*anomaly();
                break;
            }
        }
        speed += resist + acc;
        
        fprintf(fp, "%d,%.2f,%f\n", i, speed, acc);
    }
    fclose(fp);
    return 0;
}


int main(){
    
    normal();
    test();
    return 0;
}
