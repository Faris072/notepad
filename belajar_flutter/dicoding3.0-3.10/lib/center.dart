import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main(){
  runApp(CenterKu());
}

class CenterKu extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return MaterialApp(
      title: "Center",
      theme: ThemeData(
        primarySwatch: Colors.purple
      ),
      home: Scaffold(
        appBar: AppBar(
          leading: IconButton(
            icon: Icon(Icons.menu),
            onPressed: (){},
          ),
          title: Text("Center"),
        ),
        body: Center(
          child: Text("Hello"),
        ),
      ),
    );
  }
}