#include<stdio.h>
int x[101], n, ap[101];

int validare(int k)
{
    if(ap[x[k]])
        return 0;
    if(k>1&&x[k-1]==x[k]-1)
        return 0;
    return 1;
}

void afisare()
{
    FILE *f=fopen("date.out","a");
    int i;
    for(i=1;i<=n;i++)
    {
        fprintf(f,"%d ",x[i]);
    }
    fprintf(f,"\n");
    fclose(f);
}

void bkt(int k)
{
    if(k==n+1)
        afisare();
    else
        {
            int i;
            for(i=1;i<=n;i++)
            {
                x[k]=i;
                if(validare(k))
                {
                    ap[x[k]]=1;
                    bkt(k+1);
                    ap[x[k]]=0;
                }
            }
        }
}

int main()
{
    FILE *f=fopen("date.in","r");
    fscanf(f,"%d",&n);
    bkt(1);
    fclose(f);
    return 0;
}
