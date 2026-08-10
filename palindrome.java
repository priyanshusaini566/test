import java.util.*;

public class palindrome {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number : ");
        int a=sc.nextInt();
        int comp=a;
        int count=0;

        while (a>0) {
            int rem=a%10;
            count=count*10+rem;
            a=a/10;
        }
        if (count==comp){
            System.out.println("the given number is a palindrome");
        }
        else{
            System.out.println("the number is not a palindrome");
        }

    }
}
