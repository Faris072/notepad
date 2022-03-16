//PROTOTYPE
//PROTOTYPE harus menggunakan object dengan metode constructor
//prototype bisa untuk membuat property baru tanpa ada di dalam fungsinya
function siswa(nama,kelas,absen){
    this.nama = nama;
    this.kelas = kelas;
    this.absen = absen;
}

let uts = 95;
let uas = 100;

siswa.prototype.UTS = uts;
siswa.prototype.UAS = uas;
siswa.prototype.raport = function(){
    return (this.UTS + this.UAS) / 2; 
}
//pemanggilan
let faris = new siswa('Muhammad Faris Shafwan','D3PJJTI-A',3120510104);
console.log(faris.raport());
console.log(faris.uts);


//CLASS
//class di js sama dengan di java dan fungsinya juga sama dengan prototype yang dikemas dalam bentuk class seperti di java
class siswa1{
    constructor(nama,absen,kelas){
        this.nama = nama;
        this.kelas = kelas;
        this.absen = absen;
    }
    
    uts = 100;//tidak usah menggunakan this karena bukan di dalam function atau constructor
    uas = 95;//variable di class tidak usah menggunakan let
    //function di class js tidak usah mengguanakan function
    raport(){
        return (this.uts+this.uas) / 2;
    }
}
//pemanggilan
let faris1 = new siswa1('Muhammad Faris Shafwan',3120510104,'D3PJJTI-A');