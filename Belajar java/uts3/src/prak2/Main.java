package prak2;

import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        Tabungan tabungan = new Tabungan(100000);
        System.out.println("Saldo anda adalah Rp100.000");
        String lagi = "t";

        while(lagi != "y"){
            System.out.println("Masukkan menu: \n1. Tambah Saldo\n2. Ambil Uang\n3. Cek Saldo");
            System.out.print("Menu: ");
            int pilihan = input.nextInt();
            switch(pilihan) {
                case 1:
                    System.out.print("Masukkan jumlah saldo: ");
                    int jumlah = input.nextInt();
                    tabungan.tambahUang(jumlah);
                    System.out.println("Jumlah tabungan anda sekarang adalah: Rp" + tabungan.getSaldo());
                    break;
                case 2:
                    System.out.print("Masukkan jumlah ambil uang: ");
                    jumlah = input.nextInt();
                    tabungan.ambilUang(jumlah);
                    System.out.println("Saldo anda sekarang adalah: " + tabungan.getSaldo());
                    break;
                case 3:
                    System.out.println("Saldo anda sekarang adalah: "+tabungan.getSaldo());
                    break;
                default:
                    System.out.println("Perintah tidak sesuai!");
            }
            System.out.print("Lagi? (y/t): ");
            lagi = input.nextLine();
            System.out.println();
        }
    }
}
