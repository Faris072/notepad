import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main(){
  runApp(TempatWisata());
}

class TempatWisata extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return MaterialApp(
      title: "Tempat Wisata",
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: Tampilan(),
    );
  }
}

class Tampilan extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return Scaffold(
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: <Widget>[
          Container(
            child: const Center(
                child: Text("Farm House Bandung", style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold))
            ),
            margin: EdgeInsets.only(top: 50,bottom: 30),
          ),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: <Widget>[
              Column(
               children: <Widget>[
                 Icon(Icons.account_box),
                 Text("Contact")
               ],
              ),
              Column(
                children: <Widget>[
                  Icon(Icons.share),
                  Text("Share")
                ],
              ),
              Column(children: <Widget>[
                Icon(Icons.star),
                Text("Joss")
              ],)
            ],
          ),
          Container(
            child: Text("Halo Nama saya faris. Saya umur 20 tahun. saya adalah mahasiswa Politeknik Elektronika Negeri Surabaya (PENS)"),
            margin: EdgeInsets.symmetric(vertical: 30,horizontal: 10),
          ),
        ],
      ),
    );
  }
}