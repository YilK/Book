package fourth_week;

import java.util.Scanner;

public class Prime_sum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int n,m;
		n=in.nextInt();
		m=in.nextInt();
		int all=0;
		int sum=0;
		for(int i=2;;i++)
		{
			int isprime=1;
			for(int j=2;j*j<=i;j++)
			{
				if(i%j==0)
				{
					isprime=0;
					break;
				}
			}
			if(isprime==1)
			{
				all++;
				if(all>=n&&all<=m)
				{
					sum+=i;
				}
				else if(all>m)
					break;
			}
		}
		System.out.print(sum);
	}

}
