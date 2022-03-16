//template literals adaalah string yang menggunakan backtick (``)
//template literals bisa membuat tag html yang di js menjadi tag html di file html tanpa konfersi ke dalam html()
document.getElementById('html').innerHTML= `<h1>Judul</h1>`;

//template literals bisa membuat element menjadi enter di setiap beda tag html
document.getElementById('enter').innerHTML= 
`<h3>Mahasiswa 1</h3>
<p>
    Nama: Muhammad Faris Shafwan
    NRP: 3120510104
    Kelas: D3PJJTI-A 
</p>`;

//template literals bisa menyisipkan variable tanpa concate
let nama = 'faris';
document.getElementById('concat').innerHTML = `halo nama saya ${nama}`;

//template literals bisa menyisipkan data dari object
let objek = {
    nama:'faris',
    NRP : 3120510104,
    Kelas: 'D3PJJTI-A'
}

document.getElementById('objek').innerHTML= `
<p>Nama: ${objek.nama}</p>
<p>NRP: ${objek.NRP}</p>
<p>Kelas: ${objek.Kelas}</p>
`;

//looping menggunakan template literals
let looping = ['faris','shafwan','Muhammad'];
document.getElementById('looping').innerHTML=`
    <h3>Daftar Mahasiswa</h3>
    <ul>
        ${looping.map(loop => `<ul>
            <li>${loop}</li>
        </ul>`).join('')}
    </ul>
`;//.join untuk menghilangkan koma


//pengkondisian dengan menggunakan template literals
let pengkondisian = {
    judul: 'dunia busuk',
    penyanyi: 'shafwan',
    // feat: 'faris'
}
document.getElementById('pengkondisian').innerHTML = `
    <h3>Pengkondisian</h3>
    <p>Judul: ${pengkondisian.judul}</p>
    <p>Penyanyi: ${pengkondisian.penyanyi}</p>
    <p>${(pengkondisian.feat) ? `Feat: ${pengkondisian.feat}` : ``}</p>
`;//jika pengkondisian.feat ada isinya maka tampilkan feat. jika tidak maka kosongkan

//