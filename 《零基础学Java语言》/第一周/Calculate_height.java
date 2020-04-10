package hello;

import java.util.Scanner;

public class Calculate_height {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int foot;//英尺
		double inch;//英寸
		int res;//转换后的身高
		System.out.println("输入身高:");
		Scanner in=new Scanner(System.in);
		foot=in.nextInt();
		inch=in.nextDouble();
		res=(int)((foot+inch/12)*0.3048*100);
		System.out.println("转换后的结果为:"+res+"cm");
		System.out.println(1.2-1.1);//表明是有误差存在的
	}

}
