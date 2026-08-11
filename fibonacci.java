import java.util.*;
public class fibonacci{
    public static void main(String[] args){
        System.out.println("Enter the number of terms in the series : ");
        Scanner sc=new Scanner(System.in);
        
        int num=sc.nextInt();
        int a=0;
        int b=1;
        int i=1;

        System.out.println("the fourier series will be : ");
        while(i<=num){
            System.out.print(a+ " ");
            int c=a+b;
            a=b;
            b=c;
            i++;

        }



    }
}