void incrementa(int *ponteiro_numero){
   
    (*numero)++;
    
}
int main(void){
   
    int numero_teste=5;
    
    incrementa(&numero_teste);
   
    printf("%d",numero_teste);
   
    return(0);
}