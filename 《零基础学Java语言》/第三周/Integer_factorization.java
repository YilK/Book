package third_weeks;

import java.util.Scanner;

public class Integer_factorization {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int num;
		num=in.nextInt();
		int res=0;
		while(num!=0)
		{
			res=res*10+num%10;
			num/=10;
		}
		System.out.println(res);
		
	}

}
