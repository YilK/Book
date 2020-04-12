package third_weeks;

import java.util.Scanner;

public class Parity_number {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int ji=0,ou=0;
		int num;
		while(true)
		{
			num=in.nextInt();
			if(num==-1)
				break;
			else
			{
				if(num%2==1)
					ji++;
				else
					ou++;
			}
		}
		System.out.print(ji+" "+ou);
		
	}

}
