<?php $search=$_GET['search']; ?>
<table cellpadding="10" cellspacing="0" border="1" style="width:80%">
    <tr>
        <th>nama</th>
        <th>nrp</th>
        <th>usbjj</th>
        <th>ips</th>
        <th>kategori</th>
    </tr>
    <?php 
        $koneksi=mysqli_connect("localhost","root","","uas");
        $sql="SELECT * FROM mahasiswa WHERE 
        nama LIKE '%".$search."%' OR 
        nrp LIKE '%".$search."%' OR 
        usbjj LIKE '%".$search."%' OR 
        ips LIKE '%".$search."%' OR 
        kategori LIKE '%".$search."%'";

        $query=mysqli_query($koneksi,$sql);
        while($pecah=mysqli_fetch_array($query)){
    ?>
        <tr>
            <td><?php echo $pecah['nama']; ?></td>
            <td><?php echo $pecah['nrp']; ?></td>
            <td><?php echo $pecah['usbjj']; ?></td>
            <td><?php echo $pecah['ips']; ?></td>
            <td><?php echo $pecah['kategori']; ?></td>
        </tr>
    <?php
        }
    ?>
</table>