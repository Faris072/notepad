//OBJECT LITERAL
//object yang dibuat langsung saat deklarasi variable
let Mahasiswa = {
    NRP: 3120510104,
    Nama: "Muhammad Faris Shfwan",
    Kelas: "D3PJJTI-A",
    IPS: [3.65,3.98,3.5],
    IPK: function(){
        let hasil = 0;
        for(let i = 0; i<this.IPS.length;i++){    
            hasil = hasil + this.IPS[i];
        }
        hasil = hasil / this.IPS.length;
        return hasil;
    }
}
//memanggil
let nama = Mahasiswa.nama;
let ipk = Mahasiswa.IPK;


//FUNCTION DECLARATION
//object yang dibuat menggunakan fungsi
function Mahasiswa2(nama,NRP,kelas,IPS){
    let mahasiswa = {};
    mahasiswa.nama = nama;
    mahasiswa.NRP = NRP;
    mahasiswa.kelas = kelas;
    mahasiswa.IPS = IPS;
    mahasiswa.IPK = function(){
        let hasil = 0;
        for(let i = 0; i < mahasiswa.IPS.length; i++){
            hasil = hasil + mahasiswa.IPS[i];
        }
        hasil = hasil / this.IPS.length;
        return hasil;
    }
    return mahasiswa;
}
//memanggil
let namaMHS = Mahasiswa2('faris',3120510104,'D3PJJTI-A',[3.65,3.75,3.5]).nama;
let ipkMHS = Mahasiswa2('faris',3120510104,'D3PJJTI-A',[3.65,3.75,3.5]).IPK()


//CONSTRUCTOR
//hampir seperti function declaration tapi tidak ada deklarasi object dan return
function Mahasiswa3(nama,NRP,kelas,IPS){
    //this mengacu pada fungsi/objek yang berkaitan
    //secara otomatis js akan mengenali bahwa function mahasiswa3 adalah object karena ada this
    this.nama = nama;
    this.NRP = NRP;
    this.kelas = kelas;
    this.IPS = IPS;
    this.IPK = function(){
        let hasil = 0;
        for(let i = 0; i < this.IPS.length; i++){
            hasil = hasil + this.IPS[i];
        }
        hasil = hasil / this.IPS.length;
        return hasil;
    }
}
//memanggil
let namaMahasiswa = new Mahasiswa2('faris',3120510104,'D3PJJTI-A',[3.65,3.75,3.5]).nama;
let ipkMahasiswa = new Mahasiswa2('faris',3120510104,'D3PJJTI-A',[3.65,3.75,3.5]).IPK();
