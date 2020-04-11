package seconds_weeks;

public class double_vs_double {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double a=1.0;
		double b=0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1;
		System.out.println(a==b);
		System.out.println("a="+a+";b="+b);
		//比较的方法
		System.out.println(Math.abs(a-b)<1e-6);
	}

}
