package third_weeks;

import java.util.Scanner;

public class Numeric_figure {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num;
		Scanner in=new Scanner(System.in);
		num=in.nextInt();
		int res=0;
		while(num!=0)
		{
			res++;
			num=num/10;
		}
		System.out.print(res);
	}

}
