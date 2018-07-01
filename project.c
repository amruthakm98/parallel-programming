#include<stdio.h>
#include<math.h>
#include<omp.h>
static int N=10000;
void main()
{ int i,j,rnx[N],rny[N],dx,dy,max;
  srand(time(0));
  for(i=0;i<N;i++)
    { rnx[i]=rand();
      rnx[i]%=N;
    }
  srand(time(0));
  for(i=0;i<N;i++)
   { rny[i]=rand();
     rny[i]%=N;
   }
  printf("Enter degree of x and y ");
  scanf("%d\n%d",&dx,&dy);
  int cfx[dx+1],cfy[dy+1];
  for(i=0;i<=dx;i++)
    { printf("Enter coefficient of x with degree %d ",i);
      scanf("%d",&cfx[i]);
    }
  for(j=0;j<dy+1;j++)
    { printf("Enter coefficient of y with degree %d ",j);
      scanf("%d",&cfy[j]);

 printf("Hello!!");
    }
 /* max=dx;
  if(dy>max)
  max=dy;
   float cfxy[max+1];
   for(i=0;i<=max;i++)
     { printf("Enter coefficient of term where deg(x) is %d and deg(y) is %d ",i,max-i);
       scanf("%f",&cfxy[i]);
     } */

  /*computing value of function at centre and corners of the square*/
 double atime=omp_get_wtime();
 float del=1.0,localmin[N];
 float xpoint[5],ypoint[5];
  for(i=0;i<=N;i++)
   {  xpoint[0]=rnx[i];
      ypoint[0]=rny[i];
    do
    {
      xpoint[1]=xpoint[0]-(del/2);
      ypoint[1]=ypoint[0]+(del/2);
      xpoint[2]=xpoint[0]+(del/2);
      ypoint[2]=ypoint[0]+(del/2);
      xpoint[3]=xpoint[0]-(del/2);
      ypoint[3]=ypoint[0]-(del/2);
      xpoint[4]=xpoint[0]+(del/2);
      ypoint[4]=ypoint[0]-(del/2);
      float minx=xpoint[0],miny=ypoint[0];
      int k;
      float fn[5]={0.0,0.0,0.0,0.0,0.0};
      for(k=0;k<5;k++)
        { for(j=dx;j>=0;j--)
	  fn[k]+=cfx[j]*pow(xpoint[k],j);
        }
      for(k=0;k<5;k++)
        { for(j=dy;j>=0;j--)
	  fn[k]+=cfy[j]*pow(ypoint[k],j);
        }
   //  for(k=0;k<5;k++)
     //   { for(j=max;j>=0;j--)
       //   fn[k]+=cfxy[j]*pow(ypoint[k],max-j)*pow(xpoint[k],max);
	//}
  /*finding the minimum value*/
      float minval=fn[0];
      int pos=0;
      float m=fn[0];
      for(j=1;j<5;j++)
	{ if(fn[j]<minval)
	  { minval=fn[j];
	    pos=j;
	  }
	}
      if(del<0.01)
	{ localmin[i]=minval;
	  break;
  	}
      else if(m==minval)
	{ del=(float)del/2;
          m=minval;
          xpoint[0]=xpoint[j];
	  ypoint[0]=ypoint[j];
        }
     else
        { m=minval;
          xpoint[0]=xpoint[j];
	  ypoint[0]=ypoint[j];
	 
        }
     }while(1);
   }
 /* int freq[N]=0;
   for(i=0;i<N;i++)
	freq[arr[i]]+=freq[arr[i]];
   int max=freq[0];
   for(i=0;i	
*/
float min=localmin[0];
for(i=1;i<N;i++)
 { if(min>localmin[i])
    min=localmin[i];
 }
  double btime=omp_get_wtime();
  printf("Runtime = %lf",btime-atime);
  printf("\nGlobal minimum %f",min);
}

    
     
     
     
