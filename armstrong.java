import java.util.*;
public class armstrong{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number : ");
        int num=sc.nextInt();
        int n=num;
        int count=0;

        while(num>0){
            int rem=num%10;
            count=count+(rem*rem*rem);
            num=num/10;

        }
        if (count==n) {
            System.out.println("The number is an armstrong");
        }
        else{
            System.out.println("number is not armstrong");
        }

    }
}