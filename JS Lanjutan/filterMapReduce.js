const angka = [-1,9,7,3,5,-12,14,19,72,-64];

//filter
//filter adalah menyaring isi array sesuai yang kita inginkan dan nanti nilainya akan ditaruh di variable array yang baru
//contohnya seperti kita akan mencari angka di array yang >= 3
let filter = angka.filter(function(a){//a adalah parameter yang menggambarkan varable angka. ini bebas
    return a >= 3;
});
console.table(filter);

//map
//map adalah melakukan operasi pada setiap nilai dari array dan nilainya akan disimpan di variable baru. 
//misalkan saya akan mengalikan 2 setiap nilai array pada variable angka lalu hasilnya akan saya simpan di variable baru
let map = angka.map(function(a){//a adalah parameter yang menggambarkan varable angka. ini bebas
    return a * 2;
});
console.table(map);

//reduce
//reduce adalah melakukan operasi matematik pada semua nilai dari array.
//misalkan saya akan menjumlahkan semua nilai pada variable array angka dan saya simpan di variable baru.
let reduce = angka.reduce(function(accumulator,current){//nama parameter bebas. parameter pertama dari reduce adalah function(callback).  parameter ketiga adalah function (callback) dan parameter kedua dari reduce adalah nilai awal (opsional bisa di isi atau tidak, kalau tidak brarti nilai awalnya adalah 0). parameter pertama dari function (callback) adalah untuk menyimpan hasil akhir. parameter kedua dari function (callback) adalah sebagai data yang akan dioperasikan ketika di looping. parameter ketigaa dari function (opsional) bisa sebagai index yang akan menunjukkan looping keberapa
    return accumulator + current;//berarti ini akan menjumlahkan seluruh nilai di dalah array angka dan disimpan ke var baru
},0);
console.table(reduce);

//method chaining
//menggabungkan sekaligus beberapa function diatas
//misal saya akan memfilter dulu lalu hasil itu akan saya map dan hasil map tersebut akan saya reduce dan saya masukkan ke var hasil
//disini saya menggunakan arrow function
let hasil = angka.filter(a => a >= 2).map(a => a + 5).reduce((acc,cur) => acc + cur);
console.log(hasil);
