/* AUTHORE: JOHNS JOSE
   ROLL NO: 45
   CLASS  : CSE A
*/

#include <stdio.h>
#define max 100

struct poly
{
    int coeff;
    int expo;
};

int main()
{
    struct poly p1[max],p2[max],sum[max];
    int m,n,i,k,j;

    printf("\nEnter the number of terms of the first polynomial:\n");
    scanf("%d",&m);

    printf("Enter the number of terms of the second polynomial:\n");
    scanf("%d",&n);

    printf("Enter the Coefficient & Exponent of first polynomial:\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&p1[i].coeff,&p1[i].expo);
    }

    printf("Enter the Coefficient & Exponent of second polynomial:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&p2[i].coeff,&p2[i].expo);
    }

    
    k=j=i=0;
    
    while(i<m && j<n)
    {
        if(p1[i].expo == p2[j].expo)
        {
            sum[k].coeff=p1[i].coeff+p2[j].coeff;
            sum[k].expo=p1[i].expo;
            i++;
            j++;
            k++;
        }
        else if(p1[i].expo>p2[j].expo)
        {
            sum[k].coeff=p1[i].coeff;
            sum[k].expo=p1[i].expo;
            i++;
            k++;
        }
        else
        {
            sum[k].coeff=p2[j].coeff;
            sum[k].expo=p2[j].expo;
            j++;
            k++;
        }

    }

    printf("The Resultant Polynomial is:\n");
    for(i=0;i<k;i++)
    {
        if(sum[i].coeff!=0)
        {
            printf("%dx^%d",sum[i].coeff,sum[i].expo);
        
            if(i != k-1)
            {
                printf("+");
            }
        
        }
    }
    printf("\n");
    
return 0;
}

