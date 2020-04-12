package fourth_week;

import java.util.Scanner;

public class greatest_common_divisor {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int a=in.nextInt();
		int b=in.nextInt();
		int gcd=1;
		for(int i=2;i<=a&&i<=b;i++)
		{
			if(a%i==0&&b%i==0)
				gcd=i;
		}
		System.out.println("最大公约数是："+gcd);
	}

}
