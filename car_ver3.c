#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float anomaly(){

  float error = 0;
  /*
  do{
    error = (float)(rand()%11 - 5); // -5 ~ 5
  }while(error <= 3 && error >= -3);
  error = error / 10; // -0.5 ~ 0.5
  */
  error = (float)(rand()%11 - 5) / 10;
  return error;
}

float resist(){
    
  float resist = (float)(rand()%101 - 50)/10; // -5.0 ~ 5.0
  return resist;
}

float acc(float speed){
    
  float acc = 100 - speed;
  return acc;
}   

void car(){

  // for debug
  int count = 0;

  FILE* fp = fopen("./car.csv", "w+");
  float speed = 100.00;
  float anomal;
  int sw, point[50]; // error event point
  for(int i = 0; i<50; i++){
    point[i] = rand()%500;
    printf("%d ", point[i]);
  }
  printf("\n");

  for(int i = 0; i<500; i++){
    sw = 1;
    speed -= resist();
    fprintf(fp, "%f,", speed);
    
    for(int j = 0; j<50; j++){
      if(point[j] == i){sw = 0;}
    }

    // get acc
    if(sw == 0){
      anomal = anomaly();
      speed += acc(speed)*anomal;
      /*
      if(fabs(anomal) <= 0.3)
        fprintf(fp, "%f,0\n", speed);
      else
        count += 1;
        fprintf(fp, "%f,1\n", speed); // 1 means error
      */
      count += 1;
      fprintf(fp, "%f,1\n", speed); // 1 means error
    }else{
      speed += acc(speed);
      fprintf(fp, "%f,0\n", speed); // 0 means not event
    }
  }
  printf("error number = %d\n", count);
  fclose(fp);
}

float detect(){
  FILE* fp = fopen("./car.csv", "r");
  int count = 0; //wrong count
  int sw;
  float resist_speed, acc_speed, nor_acc, real_acc, error;

  for(int i = 0; i < 500; i++){
    fscanf(fp, "%f,%f,%d\n", &resist_speed, &acc_speed, &sw);
    nor_acc = 100 - resist_speed;
    real_acc = acc_speed - resist_speed;
    if(nor_acc != real_acc && sw == 0) // detect error
      count += 1;
    if(nor_acc == real_acc && sw == 1)
      count += 1;
    /*
    error = nor_acc * 0.3;
    if(nor_acc+error < real_acc || real_acc < nor_acc-error){ // detect error
      if(sw == 0)
        count += 1;
    }else{
      if(sw == 1)
        count += 1;
    }
    */
  }
  printf("detect %d\n", count);
  return (500-(float)count)/500*100;
}

int main(){

  car();
  printf("event'number : 500\nfound event : %f\n", detect());

  return 0;
}
