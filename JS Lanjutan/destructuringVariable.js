//destructuring variable / assignment
//ini adalah memecah isi array atau object dan pecahan tersebut langsung dimasukkan ke dalam variable yang baru
//contoh tanpa destructuring 
let perkenalan = ['halo', 'nama', 'saya','faris'];
let salam = perkenalan[0];
let nama = perkenalan[3];
console.log(salam);
console.log(nama);


//dengan destructuring
let [salam1, pembuka1, kenalan1, nama1] = perkenalan;
console.log(salam1);
console.log(pembuka1);
console.log(kenalan1);
console.log(nama1);


//hanya ingin menangkap beberapa isi array saja
//misal saya hanya ingin mengambil 'halo' dan 'faris'
let [salam2, , , nama2] = perkenalan;
console.log(salam2);
console.log(nama2);


//menukar isi variable tanpa membuat variable baru
let a = 1;
let b = 2;

[a , b] = [b, a];//tidak usah di let karena jika di let dikira variable yang atas dan atas sudah di deklarasi
//jika ada variable yang belum di let maka akan otomatis tipenya var
console.log(a);
console.log(b);


//return value pada function yang bertipe array
function coba(){
    return [1, 2];
}
let [satu, dua] = coba();
console.log(satu);

//rest parameter
//parameter yang dinamis dan ada kemungkinan bertambah isi arraynya
[a, ...val] = [1, 2, 3, 4]; //variable a akan berisi 1 dan bariable val akan berisi nilai array sisanya, seperti 2 - 4;
//diatas tidak di kasih let karena a sudah di kasih let. tapi valnya belum maka val akan bertipe var. jika di paksa let maka akan error karena a sudah dideklarasikan sebagai let
console.log(a);
console.log(val[0]);
console.log(val[1]);


//destructuring object
const mhs = {
    nama3: 'faris',
    umur3: 20
}

let {nama3, umur3} = mhs;//variablenya harus sama seperti properti object
//saya menggunakan properti nama3 karena nama sudah dideklarasikan sebelumnya
console.log(nama3);
console.log(umur3);


//kita bisa lagsung mendestructuring saat delarasi dengan ({destructuring} = {deklarasi objectnya})
({nama4, umur4} = {nama4: 'faris', umur4: 20});
console.log(nama4);
console.log(umur4);


//kita bisa mengaliaskan nama variable supaya tidak sama dengan property
const mhs1 = {
    nama: 'shafwan',
    umur: 21
}
let {nama: n, umur: u} = mhs1;
console.log(n);
console.log(u);

//memberikan default value
const mhs2 = {
    nama: 'muh',
    umur: 19,
    // email: 'farisbos.mfs@gmail.com'
}
let {nama: nm, umur: um, email: em = 'faris@it.student.pens.ac.id'} = mhs2;
//jika email di properti ada isinya maka akan di tampilkan yang di property, jika tidak maka akan ditampilkan yang di default value
console.log(nm);
console.log(um);
console.log(em);


//rest parameter object
const mhs3 = {
    nam: 'moh',
    umu: 20,
    email: 'farisbos.mfs@gmail.com'
}
let {nam, ...value} = mhs2;
//jika email di properti ada isinya maka akan di tampilkan yang di property, jika tidak maka akan ditampilkan yang di default value
console.log(nam);
console.log(value);//value akan berisi object yang isinya property umu dan ema


//mengambil property pada object yang di pecah di parameter suatu fungsi
const mhs4 = {
    name: 'mfs',
    age: 20,
    emaile: 'farisbos.mfs@gmail.com'
}
function getDataMhs({name, age}){
    return name;
}
console.log(getDataMhs(mhs4));