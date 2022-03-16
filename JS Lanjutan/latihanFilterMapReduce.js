//ambil semua element video
let videos = Array.from(document.querySelectorAll('[data-duration]'));//Array.from untuk mengubah collection menjadi array
console.log(videos);

//pilih yang hanya JS Lanjutan
let jsLanjutan = videos.filter(video => video.textContent.includes('JS Lanjutan'));//textContent untuk mengambil isi element dan include seperti 'yang terdapat'
console.log(jsLanjutan);

//ambil durasi masing2 video
//mengubah semua isi array ke jumlah duration dengan menggunakan dataset untuk mengambil nilai dari data-duration
jsLanjutan = jsLanjutan.map(item => item.dataset.duration);
console.log(jsLanjutan);

//ubah durasi menjadi float lalu ubah menit mjd detik
// 10:30 -> [10 , 30]
let parts = jsLanjutan.map(waktu => waktu.split(':'));
console.log(parts);

let durasi = parts.map(waktu => parseFloat(waktu[0] * 60) + parseFloat(waktu[1]));
console.log(durasi);

//jumlah semua detik
let tDurasi = durasi.reduce((total,sementara) => total+sementara,0);
console.log(tDurasi);

//ubah format jadi jam menit detik
let jam = Math.floor(tDurasi / 3600);//floor untuk pembulatan kebawah
let menit = Math.floor((tDurasi - (jam * 3600)) / 60);
let detik = Math.floor((tDurasi - (jam * 3600)) - menit * 60);

//simpan di dom
document.querySelector('.totalDurasi').innerHTML = jam+" Jam, "+menit+" Menit, "+detik+" Detik";
document.querySelector('.jumlahVideo').innerHTML = videos.filter(video => video.textContent.includes('JS Lanjutan')).length;