$('.container input').keyup(function(){
    let ajax = new XMLHttpRequest();
    ajax.onreadystatechange = function(){
        if(this.readyState==4 && this.status==200){
            if($('.container input').val()!=""){
                $('.container .hasil').css('display','block');
            }
            else{
                $('.container .hasil').css('display','none');
            }
            $('div.hasil').html(this.responseText);
        }
    }
    ajax.open('GET','tampungdata.php?search='+$('.container input').val()+'',true);
    ajax.send();
});