let i=1;

    $('#tambah').on('click',function(){
        let sks=$('.sks');
        let nilai=$('.nilai');
        i++;
        $('#table').append('<tr class="data'+i+'"><td>'+i+'</td><td><select class="sks"><option disabled selected>-Pilih-</option><option value="1">1</option><option value="2">2</option></select></td><td><select class="nilai"><option disabled selected>-Pilih-</option><option value="4">A</option><option value="3.5">AB</option><option value="3">B</option><option value="2.5">BC</option><option value="2">C</option><option value="1.5">CD</option><option value="1">D</option></select></td></tr>');
    });

    $('#kurang').on('click',function(){
        if(i!=1){
            let sks=$('.sks');
            let nilai=$('.nilai');
            $('#table tr:eq('+i+')').remove();
            i--;
        }
    });

    $('.col-md-6:eq(0)').change(function(){
        let k=1;
        let jumlahsks=0;
        let jumlahnilai=0;
        for(let j=0;j<i;j++){
            jumlahsks=jumlahsks+parseFloat($('.data'+k+' .sks').val());//.data+k+ tidak saya buat variabel karena K tidak bisa increment saat di variabel
            jumlahnilai=jumlahnilai+parseFloat($('.data'+k+' .nilai').val());
            k++;
        }

        jsks=$('#jsks').text(jumlahsks);
        jnilai=$('#jnilai').text(jumlahnilai);
        hasil=$('#hasil').text(jumlahnilai/i);
    });

    
    
    //kalkulator
    let j = 0;
    let aray = [];
    $(document).on('click','.calc .tombol .row .col-md-3 button',function(){
        
        let val=$(this).val();
        let value=$('.calc input[type="text"]').val();
        let del=value.substr(0,value.length-1);//untuk menghapus karakter terakhir dari string

        if(val=='='){
            let hitung=value;
            $('#bayangan').text(hitung);
        }
        else if(val=='CLEAR'){
            $('.calc input[type="text"]').attr('value','');
            $('#bayangan').text('');
        }
        else if(val=='DEL'){
            value=del;
            $('.calc input[type="text"]').attr('value',value);
        }
        else{
            
            $('.calc input[type="text"]').attr('value',value);
            $('#bayangan').text(parseInt(value));
            j++;
        }
    });

    class Kalkulator{//ini sama dengan object prototype versi java
        count = [];
        angka;
    }

    kalkulator = new Kalkulator();