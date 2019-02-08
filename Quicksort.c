#include <stdio.h>

int Partition(int A[], int p, int r){
  int x = A[r];
  int tmp;
  int i = p-1;
  for (int j = p; j < r; j++){
    if (A[j] <= x){
      i += 1;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
  return i+1;
}

void Quicksort(int A[], int p, int r){
  if (p < r){
    int q = Partition(A, p, r);
    Quicksort(A, p, q-1);
    Quicksort(A, q+1, r);
  }
}


int main (int arg_num, char** arg){

  FILE *filein = fopen(arg[1], "r");
  int l = 0;
  int c;

  while(fscanf(filein, "%d", &c) != EOF)
	{
		l++;
	}

  int A[l];

  rewind(filein);

  for (int i = 0; i < l; i++){
    fscanf(filein, "%d", &A[i]);
  }
  
  fclose(filein);

  int r = A[l-1];
  int p = A[0];
  Quicksort(A, 0, l-1);
 
  FILE *fileou = fopen(arg[2], "w"); 
  
  for (int i = 0; i < l; i++){
    fprintf(fileou, "%d\n", A[i]);
  }
  
  fclose(fileou);
}
