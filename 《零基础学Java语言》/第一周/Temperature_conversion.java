package hello;

import java.util.Scanner;

public class Temperature_conversion {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int res;
		int f;
		Scanner in=new Scanner(System.in);
		f=in.nextInt();
		res=(int)((f-32)*(5.0/9));
		System.out.println(res);
	}

}
