#include<stdio.h>
int soma (int n1, int n2){

  int i, somaf = 0;
  if (n1 > n2){


      for (i = n1; i >= n2; i--){

	  somaf = somaf + i;

	}
    }
  else{
     
      for (i = n2; i >= n1; i--){
	 
      somaf = somaf + i;

	}
    }
  return (somaf);
}

int main (){
  int n1, n2, result;

  scanf ("%d %d", &n1, &n2);

  result = soma (n1, n2);

  printf ("o resultado foi: %d", result);


  return (0);
}