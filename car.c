#include <stdio.h>
#include <stdlib.h>

float anomaly(){

    float random = (float)(rand()%21 - 5) / 10; // -0.50 ~ 1.50
    return random;
}

float option(float speed, int normal){
    
    float acc;

    if(speed <= 97){
        acc = 3.0;
    } else if(speed > 103) {
        acc = -3.0;
    } else {
        acc = 0.0;
    }
    
    if(normal == 1)
        return acc;
    else
        return acc*anomaly();
}

int normal(){

    int i;
    float speed = 100.00;
    int resist = -1;
    FILE* fp = fopen("./normal.csv", "w+");
    fprintf(fp, "time,speed\n0,100.00\n");

    for(i=1; i<=500; i++){
        speed += (float)resist + option(speed, 1);
        fprintf(fp, "%d,%.2f\n", i, speed);
    }
    
    fclose(fp);
    return 0;
}

int error(){

    int i;
    float speed = 100.0;
    int resist = -1;
    FILE* fp = fopen("./error.csv", "w+");
    fprintf(fp, "time,speed\n0,100.00\n");
    
    for(i=1; i<=50; i++){
        speed += resist + option(speed, 0);
        fprintf(fp, "%d,%.2f\n", i, speed);
    }
    
    fclose(fp);
    return 0;
}


int main(){

    normal();
    error();

    return 0;
}
