import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-long-question-panel',
  templateUrl: './long-question-panel.component.html',
  styleUrls: ['./long-question-panel.component.css']
})
export class LongQuestionPanelComponent implements OnInit {

  @Input() questions: String[];
  
  constructor() { }

  ngOnInit() {
  }

}
