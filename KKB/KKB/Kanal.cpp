#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#define PI 3.141592654
 
float gauss(float mean, float sigma);

//************************************************************************

// Na wejsciu wartosci binarne (0/1) na wyjsciu wartosci w postaci zmiennych rzeczywistych
// Funkcja kanal zamienia warto�ci binarne na symbole -1/+1 i dodaje szum
//es_n0 - Es/N0, dl_kan - liczba bitow wejsciowych *wej-wektor wejsciowy *wyj-wektor wyjsciowy
void kanal(float es_n0, long dl_kan, int *wej, float *wyj)
{
  float mean=0;
  float es=1;
  float sygnal;
  float sigma;
  float s_n;
  long y;

  s_n=(float) pow(10, (es_n0/10));
  sigma=(float) sqrt (es/(2*s_n));

  for (y=0; y<dl_kan; y++)
    {
      sygnal = 2 * *(wej+y)-1; // zamiana z wart binarnej 0/1 na symbole -1/+1
      *(wyj+y)=sygnal+gauss(mean,sigma);  // dodanie szumu
    }
}
//**********************************************************************
float gauss(float mean, float sigma)
{
  float x;
  float z;
  
  z=(float)rand()/RAND_MAX;
  if (z==1.0) z=0.9999999;
  x=sigma*sqrt(2.0*log(1.0/(1.0-z)));

  z=(float)rand()/RAND_MAX;
  if (z==1.0) z=0.9999999;
  return((float)(mean+x*cos(2*PI*z)));
}
//*******************************************************************

