#include<stdio.h>
float div(float x, float y){

    return(x/y);
    
}
int main(){

float(*pontdiv)(float,float);

pontdiv=div;

printf("%f",pontdiv(10,5));







    return(0);
}