let key = document.getElementById('search');
let hasil = document.getElementsByClassName('hasil')[0];//className wajib diberi index

key.addEventListener('keyup',function(){
    //buat object baru ajax
    var ajax = new XMLHttpRequest();

    //cek kesiapan ajax
    ajax.onreadystatechange = function(){//onreadystatechange untuk mengecek kesiapan ajax
        if(ajax.readyState == 4 && ajax.status == 200){ 
            //readystate untuk mengechek apakah ajax ready atau tidak. ready ada empat tahapan maka dari itu di chek apakah ready state == 4
            //status untuk mengechek kesiapan ajax
            hasil.innerHTML = ajax.responseText; //responseText untuk mengambil apapun dari sumbernya
        }
    }

    //eksekusi ajax
    ajax.open('GET','tampungdata.php?search='+ key.value +'',true);//parameter 1 untuk method & parameter 2 untuk sumber data. parameter 3 jika true maka asincronus (tanpa refresh), jika false sincronus(refresh/sama tanpa ajax)
    ajax.send();

});
