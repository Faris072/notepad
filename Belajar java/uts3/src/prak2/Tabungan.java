package prak2;

public class Tabungan {
    int saldo;

    public Tabungan(int initsaldo){
        this.saldo = initsaldo;
    }

    public boolean ambilUang(int jumlah){
        saldo = saldo - jumlah;
        if(saldo < 0){
            saldo = saldo + jumlah;
            return false;
        }
        else{
            return true;
        }
    }

    public void tambahUang(int jumlah){
        if(jumlah > 0){
            saldo = saldo + jumlah;
        }
        else{
            System.out.println("Jumlah tidak sesuai");
        }
    }

    public int getSaldo(){
        return saldo;
    }
}
