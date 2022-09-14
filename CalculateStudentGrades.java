// Igor Esipov 
// 5 Febuary, 2020 
// Program to calculate percentage to letter grade

import java.util.Scanner;

public class CalculateStudentGrades {
   private static Scanner sc;

public static void main(String args[]) {
      sc = new Scanner(System.in);
      System.out.println("Enter percentage of your grade:");
      int percent = sc.nextInt();
   
      if(percent >= 90 && percent <= 100){
    	  System.out.print("You have earned the letter grade A");
         
      }else if(percent >= 80 && percent <= 89){
    	  System.out.print("You have earned the letter grade B");
      }
      else if(percent >= 70 && percent <= 79){
    	  System.out.print("You have earned the letter grade C");
      }
      else if(percent >= 60 && percent <= 69) {
    	  System.out.print("You have earned the letter grade D");
      }
      else if (percent > 0 && percent < 60) {
    	  System.out.print("You have earned the letter grade F");
      }
      else {
    	  System.out.print("ERROR – You have entered an invalid input");
      }
}
}
