import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main(){
  runApp(DekorasiContainer());
}

class ContainerKu extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return MaterialApp(
      title: "Container",
      theme: ThemeData(
        primarySwatch: Colors.amber,
      ),
      home: Scaffold(
        appBar: AppBar(
          leading: IconButton(
            icon: Icon(Icons.menu, color: Colors.black),
            onPressed: (){},
            tooltip: "Sidebar",
          ),
          title: Text("Container"),
        ),
        body: Container(
          child: Center(child: Text("Hai orang lemah!")),
          color: Colors.blue,
          width: 100,
          height: 100,
          // margin: EdgeInsets.all(10),//top,bot,left,right sama 10
          margin: EdgeInsets.symmetric(vertical: 10,horizontal: 50),
        ),
      ),
    );
  }
}

class DekorasiContainer extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return MaterialApp(
      title: "Container Decoration",
      theme: ThemeData(
        primarySwatch: Colors.amber,
      ),
      home: Scaffold(
        appBar:AppBar(
          leading: IconButton(
            icon: Icon(Icons.menu, color: Colors.white),
            onPressed: (){}
          ),
          title: Text("Dekorasi Container"),
        ),
        body: Container(
          child: Center(child: Text("Dekorasi Container")),
          width: 100,
          height: 100,
          decoration: BoxDecoration(
            color: Colors.red,
            // shape: BoxShape.circle,
            border: Border.all(color: Colors.greenAccent),
            borderRadius: BorderRadius.circular(10),
          ),
        ),
      ),
    );
  }
}