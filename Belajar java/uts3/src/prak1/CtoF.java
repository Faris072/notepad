package prak1;

import java.util.*;

public class CtoF {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.print("Masukkan suhu (Celcius)! : ");
        float C = input.nextFloat();
        float F = (C*9/5)+32;
        System.out.println("Fahrenheit: "+F);
    }
}
