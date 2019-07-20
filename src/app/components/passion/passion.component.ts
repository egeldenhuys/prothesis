import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-passion',
  templateUrl: './passion.component.html',
  styleUrls: ['./passion.component.css']
})
export class PassionComponent implements OnInit {

  questions = ['A', 'B', 'C'];
  roles = ['Kik', 'Teh', 'Dog'];
  
  constructor() { }

  ngOnInit() {
  }

}
