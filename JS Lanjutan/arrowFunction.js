//arrow function adalah function yang lebih singkat
//function declaration
function mahasiswa(){
    return 'faris';
}
console.log(mahasiswa());

//function expresion
let Mahasiswa = function(){
    return 'Shafwan';
}
console.log(Mahasiswa());

//arrow function tanpa parameter harus ditulis kurung
let mahasiswaPENS = () => {
    return 'saya';
}
console.log(mahasiswaPENS());

//arrow function dengan 1 parameter
let mahasiswaPens = (nama) => {
    return nama;
}
console.log(mahasiswaPens('mufasha'));
//dengan 1 parameter bisa tanpa kurung
let MahasiswaPens = nama => {
    return nama;
}
console.log(MahasiswaPens('desu'));

//dengan 2 parameter harus menggunakan kurung 
let siswaPens = (nama,kelas) => {
    return 'Nama saya ' + nama + ', Kelas saya ' +kelas;
}
console.log('Faris','D3PJJTI-A');

//jika kode program hanya 1 baris atau hanya berisi return maka bisa tanpa kurung kurawal dan tanpa return
let SiswaPens = (nama) => nama;
console.log(SiswaPens('mfs'));

//contoh paling ringkas jika hanya 1 parameter dan 
let MAHASISWA = nama => 'halo nama saya '+nama;
console.log(MAHASISWA('mufasha_desu'));

let mahasiswa2 = ['faris','muh','shafwan'];
//function map
// let jumlahHuruf = mahasiswa2.map(function(nama){
//     return nama.length;
// });
// console.log(jumlahHuruf);

//function map menggunakan arrow function
let jumlahHuruf = mahasiswa2.map(nama => nama.length);
console.log(jumlahHuruf);

//membuat object dengan map dan arrow function
//kurung kurawalnya harus di bungkus dengnan tanda kurung
let jumlahHuruf2 = mahasiswa2.map(nama => ({
    nama:nama,
    jmlHuruf:nama.length
}));
console.log(jumlahHuruf2);


//membuat constructor function menggunakan arrow function 
//function constructor tidak bisa diubah menjadi arrow function 
//hanya method di dalam constructor saja yg bisa 
//di arrow function tidak ada konsep this. tapi di constructor bisa karena saat di console log kita mencari fariable this.nama dan kebetulan ada di propertynya
const Mahasiswa3 = function(){
    this.nama = 'faris',
    this.nrp = 3120510104,
    this.kelas = 'D3PJJTI-A',
    this.umur = 20,
    this.hallo = () => {
        console.log('halo'+this.nama+', selamat anda menang!');
    },
    setInterval( () => {
        console.log(this.umur++);
    },500)
}
const faris = new Mahasiswa3();


//object literal menggunakan arrow 
//tidak ada konsep this di arrow function 
const mhs1 = {
    nama: 'faris',
    kelas: 'D3PJJTI-A',
    halo: () => {
        console.log(this.nama);//ini akan undefined karena tidak ada properti this di dalam object tersebut
    }
}