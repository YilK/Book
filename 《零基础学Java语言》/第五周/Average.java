package fifth_week;

import java.util.Scanner;

public class Average {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int x;
		int[] numbers=new int[100];//定义数组
		double sum=0;
		int cnt=0;
		x=in.nextInt();
		while(x!=-1)
		{
			numbers[cnt]=x;//填入数组
			sum+=x;
			cnt++;
			x=in.nextInt();
		}
		if(cnt>0)
		{
			double average=sum/cnt;
			for(int i=0;i<cnt;i++)
			{
				if(numbers[i]>average)//使用数组中的元素
				{
					System.out.println(numbers[i]);
				}
			}
			System.out.println(average);
		}
	}

}
