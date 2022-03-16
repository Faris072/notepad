<!doctype html>
<html lang="id">
<head>
    <title>Title</title>

    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <!-- Bootstrap CSS -->
    <link rel="stylesheet" type="text/css"href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <!--Font awesome-->
    <script src="https://kit.fontawesome.com/7b5d20839a.js" crossorigin="anonymous"></script>
    <!--sweetalert-->
    <script src="https://unpkg.com/sweetalert/dist/sweetalert.min.js"></script>
    <!--Font Google-->
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Pattaya&display=swap" rel="stylesheet">
        
<style>

    </style>
</head>
<body>
    <!-- kali ini kita akan menggunakan database di uas -->
    <div class="container">
        <br><br><br><br><br>
        <div class="search">
            <form action="" method="POST">
                <input type="text" class="form-control" id="search">
            </form>
        </div>
        <br><br><br>
        <div class="hasil">
            <table cellpadding="10" cellspacing="0" border="1">
                <tr>
                    <th>nama</th>
                    <th>nrp</th>
                    <th>usbjj</th>
                    <th>ips</th>
                    <th>kategori</th>
                </tr>
                <?php 
                    $koneksi=mysqli_connect("localhost","root","","uas");
                    $sql="SELECT * FROM mahasiswa";
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
            <br><br><br><br><br>
        </div>
    </div>
    
    
    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.6.0.js" integrity="sha256-H+K7U5CnXl1h5ywQfKtSj8PCmoN9aaq30gDh27Xc0jk=" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
    <script src="ajaxjquery.js"></script>
</body>
</html>