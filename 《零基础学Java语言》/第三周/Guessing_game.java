package third_weeks;

import java.util.Scanner;

public class Guessing_game {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int count=0;//���еĴ���
		int num=(int)(Math.random()*100+1);
		int a;
		while(true)
		{
			count++;//����+1;
			a=in.nextInt();
			if(a==num)
			{
				System.out.println("���� "+"time: "+count);
				break;
			}
			else
			{
				if(a>num)
					System.out.println("��");
				else
					System.out.println("С");
			}
		}
	}

}
