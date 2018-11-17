/*
 ============================================================================
 Name        : PI1_4_FernandezCalatayudFernando.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "primeros_ejemplos.h"

int_list juntaListasOrdenadaWHile(int_list,int_list);
int_list  juntaListasOrdenadaRec(int_list,int_list);
int_list juntaListasOrdenadasRecAux(int_list,int_list,int_list,int,int,int);

int main(void) {
	int d[] = {  1, 7, 8, 9 };
	int b[]={ 2,3,10,11};
	int_list m=create_int_list(d,4,4);
	int_list n=create_int_list(b,4,4);
	int_list res2=juntaListasOrdenadaRec(m,n);
	int_list res=juntaListasOrdenadaWHile(m,n);
	printf("la cadena es:");
	printf("[ ");
	for(int j=0;j<res.tam;j++){
		printf("%d,",res.data[j]);
	}
	printf(" ]\n");
	printf("la cadena Recursiva es:");
		printf("[ ");
		for(int j=0;j<res2.tam;j++){
			printf("%d,",res2.data[j]);
		}
		printf(" ]\n");
	return EXIT_SUCCESS;
}

int_list juntaListasOrdenadaWHile(int_list m,int_list n){
	int_list res=empty_int_list(m.tam+n.tam);
	int i=0;
	int k=0;
	int j=0;
	while (i<m.size && j<n.size){
		if(m.data[i]<n.data[j]){
			res.data[k]=m.data[i];
			i++;
			k++;
		}else if(m.data[i]>n.data[j]){
			res.data[k]=n.data[j];
			j++;
			k++;
		}else if(m.data[i]==n.data[j]){
			res.data[k]=m.data[i];
			i++;
			k++;
			res.data[k]=n.data[j];
			j++;
			k++;
		}
		if(i==m.size){
			while(j<n.size){
				res.data[k]=n.data[j];
				k++;
				j++;
			}
		}
		if(j==n.size){
			while(i<m.size){
				res.data[k]=m.data[i];
				k++;
				i++;
			}
		}
	}
	return res;
}
int_list  juntaListasOrdenadaRec(int_list m,int_list n){
		int i=0;
		int k=0;
		int j=0;
		int_list res=empty_int_list(m.tam+n.tam);
		int_list s=juntaListasOrdenadasRecAux(m,n,res,i,j,k);
		return s;
}
int_list juntaListasOrdenadasRecAux(int_list m,int_list n,int_list s, int i,int j, int k){
	int_list res;
	if(!(i<m.size && j<n.size)){
		res=s;
	}else{
		if(m.data[i]>n.data[j]){
			s.data[k]=n.data[j];
			s=juntaListasOrdenadasRecAux(m,n,s,i,j+1,k+1);
		}
		if(m.data[i]<n.data[j]){
			s.data[k]=m.data[i];
			s=juntaListasOrdenadasRecAux(m,n,s,i+1,j,k+1);
		}
		if(m.data[i]==n.data[j]){
			s.data[k]=m.data[i];
			s.data[k+1]=n.data[j];
			s=juntaListasOrdenadasRecAux(m,n,s,i+1,j+1,k+2);
		}

	}
	if(i==m.size){
		if(j<n.size){
			s.data[k]=n.data[j];
			s=juntaListasOrdenadasRecAux(m,n,s,i,j+1,k+1);
		}
				}
	if(j==n.size){
		if(i<m.size){
			s.data[k]=m.data[i];
			s=juntaListasOrdenadasRecAux(m,n,s,i+1,j,k+1);
		}
	}

	return res;
}

