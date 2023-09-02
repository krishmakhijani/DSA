import java.util.*;

class _1{

	public static void main(String[] args) {
		int arr[][]=new int[100][100];
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<5;i++){
			arr[i][i]=sc.nextInt();
		}
		for(int i=0;i<5;i++){
			System.out.print(arr[i]);
		}
		System.out.println(arr.length);

		
	}
	
}