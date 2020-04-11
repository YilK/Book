package seconds_weeks;

import java.util.Scanner;

public class Time_conversion {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int bjt;
		Scanner in=new Scanner(System.in);
		bjt=in.nextInt();
		int hour=bjt/100;
		int minutes=bjt%100;
		hour=hour-8;
		if(hour==0)
			System.out.println(minutes);
		else
		{
			if(hour<0)
				hour+=24;
			 System.out.printf("%d%02d\n", hour, minutes);
		}
	}

}
