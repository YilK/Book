package Seventh_week;

import java.util.Scanner;

public class sum_part {
	public static int sum(int a,int b)
	{
		int res=0;
		for(int i=a;i<=b;i++)
			res+=i;
		return res;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int n;//有几组数据
		n=in.nextInt();
		int a,b;
		for(int i=1;i<=n;i++)
		{
			a=in.nextInt();
			b=in.nextInt();
			System.out.println(sum(a,b));
		}
		
	}

}
