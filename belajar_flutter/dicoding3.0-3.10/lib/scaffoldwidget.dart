import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main(){
  runApp(ScaffoldWidget());
}

class ScaffoldWidget extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return MaterialApp(
      title: "Scaffold Widget",
      theme: ThemeData(
          primarySwatch: Colors.blue,
      ),
      home: ScaffoldKu(),//scaffold juga bisa dipisah menjadi class sendiri
    );
  }
}

class ScaffoldKu extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return Scaffold(
      appBar: AppBar(
        leading: IconButton(//untuk navbar sebelah kiri
          icon: Icon(Icons.menu, color: Colors.white),
          onPressed: (){},
        ),
        title: Text("Scaffold Widget"),
        actions: <Widget>[//untuk navbar sebelah kanan
          IconButton(
            icon: Icon(Icons.wallpaper, color: Colors.white),
            onPressed: (){},
            tooltip: "Wallpaper",
          ),
          IconButton(
            icon: Icon(Icons.search, color: Colors.white),
            onPressed: (){},
            tooltip: "Search",
          ),
        ],
      ),
      body: Center(
        child: Text("Scaffold Widget"),
      ),
      floatingActionButton: FloatingActionButton(//untuk tombol melayang di bawah. kalau extended bisa dikasih label
        backgroundColor: Colors.blue,
        tooltip: "Navigasi",
        child: Icon(Icons.navigation,color: Colors.white),
        // label: Text("Navigator"),
        onPressed: () {},
      ),
    );
  }
}