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
				t=6-num[i]-t;//��n-1ʱ�������n-1С�ģ�Ҳ�������ģ�����3�����ϣ�������2�ϣ�����С�ڵ�n-1���̵��������Ƶ�1������ȥ
                                //Ȼ���жϵ�n-2С�����ڲ���1�����ϣ���������......Ҳ��������ܺ���6��ȥnum[i]���ڵĺ�������ȥn-1�������ڵ�λ�ã��Լ�ģ�⻭��ͼ��
			}
		}
		printf("%d\n",sum);
	}
}