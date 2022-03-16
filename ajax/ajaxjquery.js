let input=$('#search');
let hasil=$('.hasil');

input.keyup(function(){
    //membuat object baru ajax
    let ajax = new XMLHttpRequest();

    //mengechek kesiapan ajax
    ajax.onreadystatechange = function(){
        if(this.readyState==4 && this.status==200){
            hasil.html(this.responseText);
        }
    }

    //eksekusi ajax
    ajax.open("GET","tampungdata.php?search="+ input.val() +"",true);
    ajax.send();
});