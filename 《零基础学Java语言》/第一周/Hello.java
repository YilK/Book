package hello;

import java.util.Scanner;

public class Hello {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("你好");
		Scanner in =new Scanner(System.in);
//		System.out.println("echo:"+in.nextLine());//in.nextline()是指把下一行的东西读进来
		int price=0;//变量，初始值为0
//		final int amount=100;//表示一个常量
		int amount;
		System.out.print("请输入票面:");//注意这里是print而不是println
		amount=in.nextInt();
		System.out.print("请输入金额:");
		price=in.nextInt();//in.nextInt()读入用户输入的数字
		System.out.println(amount+"-"+price+"="+(amount-price));
	}

}
