package hello;

import java.util.Scanner;

public class Calculate_height {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int foot;//Ӣ��
		double inch;//Ӣ��
		int res;//ת��������
		System.out.println("�������:");
		Scanner in=new Scanner(System.in);
		foot=in.nextInt();
		inch=in.nextDouble();
		res=(int)((foot+inch/12)*0.3048*100);
		System.out.println("ת����Ľ��Ϊ:"+res+"cm");
		System.out.println(1.2-1.1);//�������������ڵ�
	}

}
