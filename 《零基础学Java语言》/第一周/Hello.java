package hello;

import java.util.Scanner;

public class Hello {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("���");
		Scanner in =new Scanner(System.in);
//		System.out.println("echo:"+in.nextLine());//in.nextline()��ָ����һ�еĶ���������
		int price=0;//��������ʼֵΪ0
//		final int amount=100;//��ʾһ������
		int amount;
		System.out.print("������Ʊ��:");//ע��������print������println
		amount=in.nextInt();
		System.out.print("��������:");
		price=in.nextInt();//in.nextInt()�����û����������
		System.out.println(amount+"-"+price+"="+(amount-price));
	}

}
