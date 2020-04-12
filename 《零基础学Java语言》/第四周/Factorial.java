package fourth_week;

import java.util.Scanner;

public class Factorial {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int i=1;
		int fact=1;
		for(i=1;i<=n;i++)
			fact*=i;
		System.out.print(fact);
	}
}
