/* CCA */
/*Original Code by Dr. Lin*/
#include<stdio.h>
#include<math.h>

main()
{
   unsigned int a, b;
   int  abit[64], bbit[64], n_bit;
   int sum[64], sum1[64], cin0[64], cout0[64], cin1[64], cout1[64];
   float result;
   int numtest, test, i, j,x,y, done, time, diff;

   printf("number of tests =");  scanf("%d", &numtest);

  for(n_bit=1;n_bit<=48;n_bit++){   
   result=0.0;
   for(test=0;test<numtest;test++){
     for(i=0;i<64;i++){
	 sum[i]=0;cin0[i]=0;cout0[i]=0;cin1[i]=0;cout1[i]=0;
       }
     cin0[0]=1;
     a=lrand48(); b=lrand48();  x=a;y=b;  /* 31-bit rand */
     for(i=0;i<31;i++){         /* extract bits from a and b */
       abit[i]=x%2; bbit[i]=y%2;
       x=x/2; y=y/2;
     }
     a=lrand48(); b=lrand48();  x=a;y=b;  /* 31-bit rand */
       for(i=31;i<62;i++){         /* extract bits from a and b */
       abit[i]=x%2; bbit[i]=y%2;
       x=x/2; y=y/2;
     }
     abit[62]=lrand48()%2; bbit[62]=lrand48()%2; /* MSB generated seperately */
     abit[63]=lrand48()%2; bbit[63]=lrand48()%2; /* MSB generated seperately */
     /*
     for(i=n_bit-1;i>=0;i--)
       printf(" %d",abit[i]);
     printf("\n");
     for(i=n_bit-1;i>=0;i--)
       printf(" %d",bbit[i]);
     printf("\n");
     */
     done=0; time=0;
     while(done==0){  /* per cycle, check if done */

       if(time!=0){ /* not 1st cycle */
	 i=0; done=1;  /* check if carry completion*/
	 while((done==1) && (i<n_bit)){
	   if(cout0[i]==0 && cout1[i]==0)  done=0;
	   i++;
	 }
       }

       for(i=0;i<n_bit;i++){  	/* calculate new sums and new carries */
	   cout0[i]=(!abit[i]&&!bbit[i]) || ((abit[i]^bbit[i])&& cin0[i]);
	   cout1[i]=(abit[i]&&bbit[i]) || ((abit[i]^bbit[i])&& cin1[i]);
	   sum[i]= abit[i] ^ bbit[i] ^ cin1[i];
       }
       /*
       printf("=======================================\n");
       printf("  ");
       for(i=n_bit-1;i>=0;i--)
	 printf("%d ",cin0[i]);
       printf("\n");
       printf("  ");
       for(i=n_bit-1;i>=0;i--)
	 printf("%d ",cin1[i]);
       printf("\n");
       for(i=n_bit-1;i>=0;i--)
	 printf("%d ",cout0[i]);
       printf("\n");
       for(i=n_bit-1;i>=0;i--)
	 printf("%d ",cout1[i]);
       printf("\n");
       printf(" ");
       for(i=n_bit-1;i>=0;i--)
	 printf("%d ",sum[i]);
       printf("\n");
       */

       for(i=1;i<n_bit;i++){
	 cin0[i]=cout0[i-1]; cin1[i]=cout1[i-1]; 
       }
       time++;
     }
     result=result+time;
   }
   printf("n_bit=%2d delay=%f\n", n_bit, result*2/numtest);
 }

 }
