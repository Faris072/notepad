import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main(){
  runApp(PaddingKu());
}

class PaddingKu extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return MaterialApp(
      title: "Padding",
      theme: ThemeData(
        primarySwatch: Colors.green,
      ),
      home: Scaffold(
        appBar: AppBar(
          leading: IconButton(
            icon: Icon(Icons.menu),
            onPressed: (){},
          ),
          title: Text("Padding"),
        ),
        body: Container(
          color: Colors.red,
          child: const Padding(
            padding: EdgeInsets.all(10),
            child: Text("woi"),
          ),
        ),
      ),
    );
  }
}