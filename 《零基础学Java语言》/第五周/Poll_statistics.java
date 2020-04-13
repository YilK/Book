package fifth_week;

import java.util.Scanner;

public class Poll_statistics {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int[] a=new int[10];//自动初始化为0
		int x;
		while(true)
		{
			x=in.nextInt();
			if(x==-1)
				break;
			else if(x>=0&&x<=9)
				a[x]++;
		}
		for(int i=0;i<a.length;i++)
			System.out.println(i+" "+a[i]);
	}

}
