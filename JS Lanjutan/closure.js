//closure function yang memiliki akses ke parent scopenya meskipun scopenya sudah selesai dieksekusi
//lexical scope closure
function init(){
    let nama = 'Faris';//local variable
    function tampilNama(){//inner function bisa memiliki akses ke parent variablenya sampai ketemu variablenya meskipun variable di situ ada di global variable
        console.log(nama);
    }
    tampilNama();
}
init();


//closure
function init(){
    return function(nama){
        console.log(nama);
    }
}
// init();
// init('faris');
let panggilNama = init();
panggilNama('faris');
//kalau hanya di panggil init maka functionnya tidak akan mengembalikan parameter 
//karena parameter init kosong. ketika kita memasukkan ke variabel artinya function itu di jalankan dan menyimpan returnnya yaitu inner functionnya.
//ketika variable tersebut di isi dengan parameter maka sama saja kita memasukkan parameter ke inner function tersebut 



let add = function(){
    let conter = 0;

    return function(){
        return conter++;
    }
}
let a = add();
console.log(a());
console.log(a());
console.log(a());

