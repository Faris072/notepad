import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

//nama class diawali dengan huruf kapital
//parameter construct dari class seperti appBar:, diawali huruf kecil dan value construct yang memanggil class diawali huruf kapiital
//nama class bawaan flutter diawali huruf kapital

void main(){
  runApp(HelloWorld());
}

class HelloWorld extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return MaterialApp(//ibarat bangunan, MaterialApp menjadi tanahnya
      title: "Flutter Hello World",
      theme: ThemeData(
        primarySwatch: Colors.red
      ),
      home: Scaffold(//untuk membuat tampilan dasar material design => ibarat sebagai bangunannya
        appBar: AppBar(
          title: const Text("Hello World!"),
        ),
        body: const Center(
          child: Text("Hello World!"),
        ),
      ),
    );
  }
}