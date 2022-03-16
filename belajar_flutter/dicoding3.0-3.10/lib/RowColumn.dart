import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main(){
  runApp(ColumnKu());
}

class RowKu extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return MaterialApp(
      title: "Row",
      theme: ThemeData(
        primarySwatch: Colors.deepOrange
      ),
      home: Scaffold(
        appBar: AppBar(
          title: Text("Row"),
        ),
        body: Row(
          //mainAxisAlignment kalau di flexbox seperti justify content
          mainAxisAlignment: MainAxisAlignment.spaceAround,
          // mainAxisAlignment: MainAxisAlignment.spaceBetween,
          // mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          // mainAxisAlignment: MainAxisAlignment.start,
          // mainAxisAlignment: MainAxisAlignment.center,
          // mainAxisAlignment: MainAxisAlignment.end,
          crossAxisAlignment: CrossAxisAlignment.stretch,//terhadap sumbu Y
          children: <Widget>[
            Icon(Icons.share),
            Icon(Icons.thumb_up),
            Icon(Icons.thumb_down)
          ],
        ),
      ),
    );
  }
}

class ColumnKu extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return MaterialApp(
      title: "Column",
      theme: ThemeData(
        primarySwatch: Colors.deepOrange
      ),
      home: Scaffold(
        appBar: AppBar(
          title: Text("Column"),
        ),
        body: Column(
          children: <Widget>[
            Text("Column", style: TextStyle(fontSize: 32,fontWeight: FontWeight.bold)),
            Text("Ini adalah Column")
          ],
        ),
      ),
    );
  }
}