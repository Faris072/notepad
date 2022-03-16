//tagged template literals adalah suatu fungsi yang isinya adalah template literals (``) dan saat pemanggilan fungsi tidak perlu function namafungsi(){}
let name = 'Faris';
let umur = 20;

function coba1(strings, nama, umur){//parameter bebas penamaanya
    // return strings; //parameter pertama untuk memanggil string yang telah dipisah dengan ekpresion
    // return nama; //parameter kedua untuk menampilkan ekspresion pertama
    // return umur; //parameter ketiga untuk menampilkan ekspresion kedua 
    //dst
}

const str1 = coba1`Halo nama saya ${name}, umur saya ${umur} tahun`;//pemanggilan fungsi coba
console.log(str1);


//cara supaya parameter bisa dinamis oleh jumlah expresion
function coba2(strings, ...value){//value akan menjadi array dari expresion yang ada saat pemanggilan. value bisa bermacam2 bisa nama dan bisa umur tergantung expresion itu urutan keberapa
    // return strings; //parameter pertama untuk memanggil string yang telah dipisah dengan ekpresion
    // return nama; //parameter kedua untuk menampilkan ekspresion pertama
    // return umur; //parameter ketiga untuk menampilkan ekspresion kedua 
    //dst
}

const str2 = coba2`Halo nama saya ${name}, umur saya ${umur} tahun`;//pemanggilan fungsi coba
console.log(str2);


//cara merangkai dan menampilkan menjadi string utuh adalah dengan looping
//karena di tegged tadi bentuknya adalah array 
function coba3(string, ...val){
    let tampung = '';//untuk menampung string awalnya kosong
    string.forEach((str, i) => {//str untuk mengambil array yang ada di string, dan i untuk indexnya
        tampung += `${str}${val[i] || ''}`;// tampung kita gabungkan dengan looping selanjutnya dst.., kemudian kita kasih OR (||) itu sama saja dengan jika val[i] ada isinya maka tampilkan. jika tidak maka tampilkan '';
    });
    return tampung;
}

const hasil = coba3`Halo nama saya ${name}. umur saya ${umur} tahun`;
console.log(hasil);


//atau menggunakan reduce supaya lebih ringkas
function coba4(string, ...val){
    return string.reduce((tampung, str, i) => `${tampung}${str}${val[i] || ''}`, '');// '' di akhir adalah sebagai nilai awal dari tampung
}

const hasil2 = coba4`Halo nama saya ${name}. umur saya ${umur} tahun`;
console.log(hasil2);


//contoh implementasi. saya akan membuat setiap ekspresion otomatis berwarna merah
function coba5(string, ...val){
    return string.reduce((tampung, str, i) => `${tampung}${str}<span style="color:red;">${val[i] || ''}</span>`, '');// '' di akhir adalah sebagai nilai awal dari tampung
}

const hasil3 = coba5`Halo nama saya ${name}. umur saya ${umur} tahun`;
document.getElementById('implementTagged').innerHTML = hasil3;