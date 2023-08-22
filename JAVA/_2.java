import java.util.*;

class _2 {
	public static void check(){
		Scanner sc = new Scanner(System.in);
		System.out.println("ENTER THE NUMBER :");
		int n = sc.nextInt();
		if (n<1&&n>9) {
			System.out.println("NOT POSSIBLE");
			System.out.println("RE-ENTER");
			check();
		}
		if(n==6){
			System.out.println("Correct");
		}
		else {
			System.out.println("ENTER AGAIN INCORRECT GUESS");
			check();
		}
		sc.close();
	}
	public static void main(String[] args) {
		check();
		
	}
	
}