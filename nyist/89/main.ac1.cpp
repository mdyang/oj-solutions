#include<stdio.h>
#include<string.h>
int step[33],num[33];
void find()
{
	step[0]=1;
	for(int i=1;i<=33;i++)
		step[i]=step[i-1]*2;
}
int main()
{
	find();
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		int t=3,i,sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		for(i=n-1;i>=0;i--)
		{
			if(num[i]!=t)
			{
				sum+=step[i];
				t=6-num[i]-t;//当n-1时，如果第n-1小的（也就是最大的）不在3号针上，比如在2上，则会把小于第n-1个盘的其他盘移到1号针上去
                                //然后判断第n-2小的盘在不在1号针上，依次类推......也就是针的总和数6减去num[i]所在的号数，减去n-1个盘所在的位置（自己模拟画画图）
			}
		}
		printf("%d\n",sum);
	}
}