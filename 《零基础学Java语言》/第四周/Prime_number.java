package fourth_week;

public class Prime_number {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n=100;
		for(int i=2;i<=n;i++)
		{
			int isprime=1;
			for(int j=2;j*j<=i;j++)
			{
				if(i%j==0)
				{
					isprime=0;
					break;
				}
			}
			if(isprime==1)
				System.out.println(i);
		}
	}

}
