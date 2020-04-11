package third_weeks;

import java.util.Scanner;

public class Calculate_the_average {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();//数字的个数
		double num=0;
		double res=0;//保存和
		int i=1;
		while(i<=n)
		{
			num=in.nextDouble();
			res+=num;
			i++;
		}
		System.out.println(res/n);
		
	}

}
